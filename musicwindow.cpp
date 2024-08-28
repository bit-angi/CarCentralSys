#include "musicwindow.h"
#include "ui_musicwindow.h"
#include "ui_lrcwidget.h""
#include<QDebug>
#include <QFileDialog>
#include "lrcwidget.h"
#include <QJsonArray>
#include <QJsonDocument>
#include <QJsonObject>
#include <QMessageBox>
#include <QMediaPlayer>
#include <QMediaMetaData>
#include <QListWidget>

bool MusicWindow::eventFilter(QObject *watched, QEvent *event)
{

    // 处理键盘按键事件
    if (event->type() == QEvent::KeyPress) {
        QKeyEvent *keyEvent = static_cast<QKeyEvent *>(event);
        if (keyEvent->key() == Qt::Key_Delete && watched == ui->listWidget) {
            delete ui->listWidget->takeItem(ui->listWidget->currentRow());
            return true;
        }
    }

    // 处理滑块点击事件
    if (event->type() == QEvent::MouseButtonPress && watched == ui->sliderPosition) {

        QMouseEvent *mouseEvent = static_cast<QMouseEvent *>(event);
        // 计算鼠标点击位置对应的值

        if (mouseEvent->button() == Qt::LeftButton)	//判断左键
        {

            int clickedValue = ui->sliderPosition->minimum() + ((ui->sliderPosition->maximum() - ui->sliderPosition->minimum()) * mouseEvent->pos().x() / ui->sliderPosition->width());
            qDebug() << "触发了点击事件，位置为:" << clickedValue << Qt::endl;
            ui->sliderPosition->setValue(clickedValue);
            player->setPosition(clickedValue); // 设置播放器位置

            return true;

        }

    } else if (event->type() == QEvent::MouseMove && watched == ui->sliderPosition) {
        qDebug() << "触发了移动事件" << Qt::endl;
        QMouseEvent *mouseEvent = static_cast<QMouseEvent *>(event);
        if (mouseEvent->buttons() & Qt::LeftButton) {
            int draggedValue = ui->sliderPosition->minimum() + ((ui->sliderPosition->maximum() - ui->sliderPosition->minimum()) * mouseEvent->pos().x() / ui->sliderPosition->width());
            ui->sliderPosition->setValue(draggedValue); // 更新滑块的值
            player->setPosition(draggedValue); // 设置播放器位置
            return true;
        }
    }

    return QMainWindow::eventFilter(watched, event);
}

MusicWindow::MusicWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MusicWindow)
{
    ui->setupUi(this);
    initializeFavorites();

    QPixmap pixmap(":/images/images/KK.jpg");
    ui->label->setPixmap(pixmap.scaled(ui->label->size(), Qt::KeepAspectRatio, Qt::SmoothTransformation));

    isDragging == false;
    setWindowFlags(Qt::FramelessWindowHint);
    loadSavedMusic();
    ui->listWidget->installEventFilter(this);
    ui->sliderPosition->installEventFilter(this);
    player = new QMediaPlayer(this);
    lrcWidget = new lrcwidget(this);
    //lrcWidget->raise();
    lrcWidget->hide();
    QAudioOutput *audioOutput = new QAudioOutput(this);
    player->setAudioOutput(audioOutput);

    searchWidget = new searchwidget(this);
    searchWidget->resize(760, 405);  // 设置宽度和高度为500像素
    searchWidget->move(11, 52);  // 将searchWidget移动到(100, 100)的位置
    searchWidget->hide();
    networkManager = new QNetworkAccessManager(this);


    connect(player, &QMediaPlayer::positionChanged, this, &MusicWindow::do_positionChanged);
    connect(player, &QMediaPlayer::durationChanged, this, &MusicWindow::do_durationChanged);
    connect(player, &QMediaPlayer::sourceChanged, this, &MusicWindow::do_sourceChanged);
    connect(player, &QMediaPlayer::playbackStateChanged, this, &MusicWindow::do_playbackStateChanged);
    connect(player, &QMediaPlayer::metaDataChanged, this, &MusicWindow::do_metaDataChanged);

    //链接歌词界面
    connect(player, &QMediaPlayer::positionChanged, lrcWidget, &lrcwidget::updateLyrics);


    connect(networkManager, &QNetworkAccessManager::finished, this, &MusicWindow::onSearchFinished);

    // 链接 lrcwidget 的控件与 MusicWindow 的槽函数
    connect(lrcWidget->getSlider(), &QSlider::sliderMoved, this, &MusicWindow::lrcWidget_sliderMoved);
    connect(lrcWidget->getPlayButton(), &QPushButton::clicked, this, &MusicWindow::lrcWidget_playPauseToggled);
    connect(lrcWidget->getPrevButton(), &QPushButton::clicked, this, &MusicWindow::lrcWidget_prevClicked);
    connect(lrcWidget->getNextButton(), &QPushButton::clicked, this, &MusicWindow::lrcWidget_nextClicked);
    connect(lrcWidget->getSoundSlider(), &QSlider::valueChanged, this, &MusicWindow::lrcWidget_volumeChanged);
    connect(lrcWidget->getSpeedSpinBox(), QOverload<double>::of(&QDoubleSpinBox::valueChanged), this, &MusicWindow::lrcWidget_speedChanged);
    connect(lrcWidget->getModeButton(), &QPushButton::clicked, this, &MusicWindow::lrcWidget_modeChanged);

    // 连接 lrcwidget 的控件与 MusicWindow 的槽函数
    connect(lrcWidget, &lrcwidget::sliderMoved, this, &MusicWindow::lrcWidget_sliderMoved);
    connect(lrcWidget, &lrcwidget::sliderPressed, this, &MusicWindow::lrcWidget_sliderPressed);
    connect(lrcWidget, &lrcwidget::sliderReleased, this, &MusicWindow::lrcWidget_sliderReleased);
}

MusicWindow::~MusicWindow()
{
    delete ui;
}


void MusicWindow::lrcWidget_sliderMoved(int value)
{
    qDebug() << "Slider moved to" << value;
    player->setPosition(value);
}

void MusicWindow::lrcWidget_playPauseToggled()
{
    qDebug() << "Play/Pause toggled";
    if (player->playbackState() == QMediaPlayer::PlayingState) {
        player->pause();
    } else {
        player->play();
    }
}

void MusicWindow::lrcWidget_sliderPressed()
{
    player->pause();
}

void MusicWindow::lrcWidget_sliderReleased()
{
    player->play();
}

void MusicWindow::lrcWidget_prevClicked()
{
    qDebug() << "Previous clicked";
    on_btnPrevious_clicked();
}

void MusicWindow::lrcWidget_nextClicked()
{
    qDebug() << "Next clicked";
    on_btnNext_clicked();
}

void MusicWindow::lrcWidget_volumeChanged(int value)
{
    qDebug() << "Volume changed to" << value;
    player->audioOutput()->setVolume(value / 100.0);
}

void MusicWindow::lrcWidget_speedChanged(double value)
{
    qDebug() << "Speed changed to" << value;
    player->setPlaybackRate(value);
}

void MusicWindow::lrcWidget_modeChanged()
{
    qDebug() << "Mode changed";
    on_btnLoop_clicked(!loopPay);
}



void MusicWindow::mousePressEvent(QMouseEvent *event)
{
    if (event->button() == Qt::LeftButton) {
        isDragging = true;
        lastMousePosition = event->globalPos() - frameGeometry().topLeft();
        event->accept();
    }
    QMainWindow::mousePressEvent(event);
}

void MusicWindow::mouseMoveEvent(QMouseEvent *event)
{
    if (isDragging && (event->buttons() & Qt::LeftButton)) {
        move(event->globalPos() - lastMousePosition);
        event->accept();
    }
    QMainWindow::mouseMoveEvent(event);
}

void MusicWindow::mouseReleaseEvent(QMouseEvent *event)
{
    if (event->button() == Qt::LeftButton) {
        isDragging = false;
        event->accept();
    }
    QMainWindow::mouseReleaseEvent(event);
}

QStringList MusicWindow::getSavedMusicPaths()
{
    // 获取应用程序的目录
    QString appDir = QCoreApplication::applicationDirPath();

    // 相对于应用程序目录的音乐文件目录
    QString musicDirectory = appDir + "/sound";

    qDebug() << "Music directory:" << musicDirectory;
    // 使用 QDir 类来获取指定路径下的所有音乐文件
    QDir directory(musicDirectory);
    QStringList musicFiles = directory.entryList(QStringList() << "*.mp3" << "*.wav" << "*.wma" << "*.flac", QDir::Files);

    // 将文件名转换成完整路径
    QStringList musicPaths;
    foreach (const QString& fileName, musicFiles) {
        QString filePath = musicDirectory + "/" + fileName;
        musicPaths.append(filePath);
    }

    return musicPaths;
}


void MusicWindow::loadSavedMusic()
{

    QStringList savedMusicPaths = getSavedMusicPaths();

    if(savedMusicPaths.isEmpty())
        return;

    foreach (const auto& item, savedMusicPaths) {
        QFileInfo fileInfo(item);
        QListWidgetItem *aItem = new QListWidgetItem(fileInfo.fileName());
        aItem->setIcon(QIcon(":/images/images/musicFile.png"));
        aItem->setData(Qt::UserRole, QUrl::fromLocalFile(item));
        ui->listWidget->addItem(aItem);
    }
}

void MusicWindow::do_positionChanged(qint64 position)
{
    if(ui->sliderPosition->isSliderDown())
        return;
    ui->sliderPosition->setSliderPosition(position);
    int secs = position/1000;
    int mins = secs/60;
    secs %= 60;
    positionTime = QString::asprintf("%d:%02d", mins, secs);
    ui->labRatio->setText(positionTime + "/" + durationTime);


    // 更新歌词界面的进度条
    lrcWidget->getSlider()->setValue(position);

    // 更新 lrcWidget 的 labProcess 的值
    QTime currentTime(0, 0);
    currentTime = currentTime.addMSecs(position);
    QString timeStr = currentTime.toString("mm:ss");

    int duration = player->duration();
    QTime totalTime(0, 0);
    totalTime = totalTime.addMSecs(duration);
    QString totalTimeStr = totalTime.toString("mm:ss");

    lrcWidget->updateLabProcess(timeStr + "/" + totalTimeStr);

}

void MusicWindow::do_durationChanged(qint64 duration)
{
    ui->sliderPosition->setMaximum(duration);
    int secs = duration / 1000;
    int mins = secs/60;
    secs %= 60;
    durationTime = QString::asprintf("%d:%02d", mins, secs);
    ui->labRatio->setText(positionTime + "/" + durationTime);

    // 更新歌词界面的进度条最大值
    lrcWidget->getSlider()->setMaximum(duration);
}

void MusicWindow::do_sourceChanged(const QUrl &media)
{
    ui->labCurMedia->setText(media.fileName());

    // 重置封面为默认封面
    lrcWidget->resetCoverImage();

    // 清空当前歌词
    lrcWidget->clearLyrics();

    QString musicPath = media.toLocalFile();
    QFileInfo fileInfo(musicPath);
    QString lyricsPath = fileInfo.path() + "/" + fileInfo.completeBaseName() + ".lrc";
    qDebug() << "lyrics path :  " << lyricsPath;
    lrcWidget->loadLyrics(lyricsPath);
}

void MusicWindow::do_playbackStateChanged(QMediaPlayer::PlaybackState newState)
{
    ui->btnPlay->setEnabled(newState != QMediaPlayer::PlayingState);
    ui->btnPause->setEnabled(newState == QMediaPlayer::PlayingState);
    ui->btnStop->setEnabled(newState == QMediaPlayer::PlayingState);


    if((newState == QMediaPlayer::StoppedState) && loopPay)
    {
        //循环播放: 1、自动下一首。2、从最后一首跳到第一首
        int count = ui->listWidget->count();
        int curRow = ui->listWidget->currentRow();
        ++curRow;
        curRow = curRow >= count ? 0 : curRow;
        ui->listWidget->setCurrentRow(curRow);
        player->setSource(ui->listWidget->currentItem()->data(Qt::UserRole).value<QUrl>());
        player->play();
    }
    //如果不是循环播放,播完一首就暂停
}

void MusicWindow::resizeEvent(QResizeEvent *event)
{
    //qDebug() << "MusicWindow_size_changed" << Qt::endl;
    QMainWindow::resizeEvent(event);
    qDebug() << "MusicWindow_size_changed" << Qt::endl;
    updateCoverArtSize();
}


void MusicWindow::displayCurrentTrackInfo() {

}


void MusicWindow::do_metaDataChanged()
{

    //元数据发生变化，修改显示的图片

    QMediaMetaData metaData = player->metaData();
    qDebug() << metaData.value(QMediaMetaData::ThumbnailImage) << Qt::endl;
    qDebug() << metaData.value(QMediaMetaData::CoverArtImage) << Qt::endl;
    QVariant metaImg = metaData.value(QMediaMetaData::ThumbnailImage);
    if(metaImg.isValid())
    {
        qDebug() << "封面图片加载成功！" << Qt::endl;
        QImage img = metaImg.value<QImage>();
        QPixmap musicPixmp = QPixmap::fromImage(img);

        ui->labPic->setPixmap(musicPixmp);
        ui->btnCover->setIcon(musicPixmp);
        ui->btnCover->setIconSize(ui->btnCover->size()); // 图像大小与按钮相同
        ui->btnCover->setFlat(true); // 使按钮背景透明
        ui->btnCover->setStyleSheet("border: none;"); // 移除按钮的边框

        updateCoverArtSize();
    } else{
        qDebug() << "未找到封面图片!";
        // 未找到封面图片时，使用默认封面
        QPixmap defaultCover(":/images/images/KK.jpg");
        ui->labPic->setPixmap(defaultCover);
        ui->btnCover->setIcon(defaultCover);
        ui->btnCover->setIconSize(ui->btnCover->size());
        ui->btnCover->setFlat(true);
        ui->btnCover->setStyleSheet("border: none;");

        updateCoverArtSize();
        //ui->labPic->clear();
    }

}



void MusicWindow:: updateCoverArtSize()
{
    // 获取当前窗口大小
    QSize newSize = ui->scrollArea->size();

    // 获取加载的封面图片
    QPixmap pixmap = ui->labPic->pixmap(Qt::ReturnByValue);
    if (!pixmap.isNull())
    {
        // 根据窗口大小调整封面图片大小
        QSize scaledSize = newSize - QSize(30, 30); // 适当减去一些边距
        QPixmap scaledPixmap = pixmap.scaled(scaledSize, Qt::KeepAspectRatio, Qt::SmoothTransformation);
        ui->labPic->setPixmap(scaledPixmap);
    }
}

void MusicWindow::on_btnAdd_clicked()
{
    QString curPath = QDir::homePath();
    QString dlgTitle = "选择音频文件";
    QString filter = "音频文件(*.mp3 *.wav *.wma);;所有文件(*.*)";

    QStringList fileList = QFileDialog::getOpenFileNames(this, dlgTitle, curPath, filter);
    if(fileList.isEmpty())
        return;

    foreach (const auto& item, fileList) {
        QFileInfo fileInfo(item);
        QListWidgetItem *aItem = new QListWidgetItem(fileInfo.fileName());
        aItem->setIcon(QIcon(":/images/images/musicFile.png"));
        aItem->setData(Qt::UserRole, QUrl::fromLocalFile(item));
        ui->listWidget->addItem(aItem);
    }

    //如果现在没有正在播放，就开始播放第一个文件
    if(player->playbackState() != QMediaPlayer::PlayingState){
        ui->listWidget->setCurrentRow(0);
        QUrl source = ui->listWidget->currentItem()->data(Qt::UserRole).value<QUrl>();
        player->setSource(source);
        player->play();
    }
}


void MusicWindow::on_btnRemove_clicked()
{
    //只是从Widget移除
    int index = ui->listWidget->currentRow();
    if(index < 0) return;

    delete ui->listWidget->takeItem(index);
    if(ui->listWidget->count() <= 0)
        loopPay = false;

}


void MusicWindow::on_btnClear_clicked()
{
    loopPay = false;
    ui->listWidget->clear();
    player->stop();

}


void MusicWindow::on_btnPlay_clicked()
{
    if(player->playbackState() == QMediaPlayer::PausedState)
    {
        player->play();
        return;
    }
    if(ui->listWidget->count() <= 0)
        return;
    if(ui->listWidget->currentRow() < 0)
        ui->listWidget->setCurrentRow(0);
    player->setSource(ui->listWidget->currentItem()->data(Qt::UserRole).value<QUrl>());

    player->play();
}


void MusicWindow::on_btnPause_clicked()
{
    player->pause();

}


void MusicWindow::on_btnStop_clicked()
{
    loopPay = false;
    player->stop();
}


void MusicWindow::on_btnPrevious_clicked()
{
    int curRow = ui->listWidget->currentRow();
    --curRow;
    curRow = curRow < 0 ? ui->listWidget->count()-1 : curRow;
    ui->listWidget->setCurrentRow(curRow);
    loopPay = false;
    player->setSource(ui->listWidget->currentItem()->data(Qt::UserRole).value<QUrl>());
    player->play();
    loopPay = ui->btnLoop->isChecked();
}


void MusicWindow::on_btnNext_clicked()
{
    int count = ui->listWidget->count();
    int curRow = ui->listWidget->currentRow();
    ++curRow;
    curRow = curRow >= count ? 0 : curRow;
    ui->listWidget->setCurrentRow(curRow);
    loopPay = false;
    player->setSource(ui->listWidget->currentItem()->data(Qt::UserRole).value<QUrl>());
    player->play();
    loopPay = ui->btnLoop->isChecked();
}


void MusicWindow::on_doubleSpinBox_valueChanged(double arg1)
{
    //player->setPlaybackRate(arg1);
    // 先暂停播放
    if (player->playbackState() == QMediaPlayer::PlayingState)
        player->pause();

    // 设置播放速率
    player->setPlaybackRate(arg1);

    // 如果之前是播放状态，恢复播放
    if (player->playbackState() == QMediaPlayer::PausedState)
        player->play();
}


void MusicWindow::on_btnLoop_clicked(bool checked)
{
    loopPay = checked;
}


void MusicWindow::on_btnSound_clicked()
{
    bool mute = player->audioOutput()->isMuted();
    player->audioOutput()->setMuted(!mute);
    if(mute)
        ui->btnSound->setIcon(QIcon(":/images/images/volumn.bmp"));
    else
        ui->btnSound->setIcon(QIcon(":/images/images/mute.bmp"));

}


void MusicWindow::on_sliderVolumn_valueChanged(int value)
{
    player->audioOutput()->setVolume(value/100.0);
}


void MusicWindow::on_sliderPosition_valueChanged(int value)
{
    player->setPosition(value);
}


void MusicWindow::on_listWidget_doubleClicked(const QModelIndex &index)
{
    Q_UNUSED(index);
    loopPay = false;
    player->setSource(ui->listWidget->currentItem()->data(Qt::UserRole).value<QUrl>());
    player->play();
    loopPay = true;
}


void MusicWindow::on_btnCover_clicked()
{
    qDebug() << 1 << Qt::endl;
    //lrcwidget *lrc_widget = new lrcwidget(this);

    qDebug() << 2 << Qt::endl;
    lrcWidget->setAttribute(Qt::WA_DeleteOnClose);
    qDebug() << 3 << Qt::endl;
    lrcWidget->setWindowTitle("歌词窗口");
    QMediaMetaData metaData = player->metaData();
    QVariant metaImg = metaData.value(QMediaMetaData::ThumbnailImage);
    if(metaImg.isValid())
    {
        qDebug() << "封面图片2加载成功！" << Qt::endl;
        QImage img = metaImg.value<QImage>();
        QPixmap musicPixmp = QPixmap::fromImage(img);
        lrcWidget->setCoverImage(musicPixmp);

    }
    qDebug() << 4 << Qt::endl;
    lrcWidget->setGeometry(0, height(), width(), height());
    qDebug() << 5 << Qt::endl;
    lrcWidget->show();
    lrcWidget->showLyric();
    qDebug() << 6 << Qt::endl;
}


void MusicWindow::on_btnSearch_clicked()
{
}

void MusicWindow::onSearchFinished(QNetworkReply *reply)
{
}


void MusicWindow::on_pushButton_clicked()
{
    searchWidget->hide();
}


void MusicWindow::on_label_linkActivated(const QString &link)
{

}


void MusicWindow::on_btnmin_clicked()
{

}


void MusicWindow::on_love_button_clicked()
{
    QJsonArray favorites = readFavorites();
    QJsonObject currentSong = getCurrentSong();

    // 检查是否已经收藏
    for (const QJsonValue &value : favorites) {
        if (value.toObject() == currentSong) {
            QMessageBox::information(this, "Info", "Song already in favorites.");
            return;
        }
    }

    favorites.append(currentSong);
    writeFavorites(favorites);
    loadFavorites();  // 更新显示


}

void MusicWindow::loadFavorites(){
    QJsonArray favorites = readFavorites();
    ui->listWidget_2->clear();
    for (const QJsonValue &value : favorites) {
        QJsonObject song = value.toObject();
        QListWidgetItem *item = new QListWidgetItem(song["title"].toString());
        item->setIcon(QIcon(":/images/images/musicFile.png"));
        item->setData(Qt::UserRole, QUrl::fromLocalFile(song["filePath"].toString()));
        ui->listWidget_2->addItem(item);
    }
}


QJsonArray MusicWindow::readFavorites()
{
    QFile file("favorites.json");
    if (!file.exists()) {
        // 如果文件不存在，创建一个空的 JSON 文件
        QFile newFile("favorites.json");
        if (newFile.open(QIODevice::WriteOnly)) {
            QJsonArray emptyArray;
            QJsonDocument doc(emptyArray);
            newFile.write(doc.toJson());
            newFile.close();
        }
    }

    if (!file.open(QIODevice::ReadOnly)) {
        return QJsonArray();
    }

    QByteArray data = file.readAll();
    QJsonDocument doc(QJsonDocument::fromJson(data));
    return doc.array();
}

void MusicWindow::writeFavorites(const QJsonArray &favorites)
{
    QFile file("favorites.json");
    if (!file.open(QIODevice::WriteOnly)) {
        return;
    }

    QJsonDocument doc(favorites);
    file.write(doc.toJson());
}

QJsonObject MusicWindow::getCurrentSong()
{


    QJsonObject songInfo;

    // 获取当前播放的音频文件路径
    QUrl currentSource = player->source();
    QString currentFilePath = currentSource.toLocalFile();

    // 获取音频文件的元数据

    QString title;
    if (title.isEmpty()) {
        title = QFileInfo(currentFilePath).baseName(); // 如果标题为空，则使用文件名作为标题
    }

    // 填充 QJsonObject
    songInfo["title"] = title;

    songInfo["filePath"] = currentFilePath;

    return songInfo;

}




void MusicWindow::on_listWidget_2_itemClicked(QListWidgetItem *item)
{
    QUrl musicUrl = item->data(Qt::UserRole).value<QUrl>();

    // 设置播放器的源
    player->setSource(musicUrl);

    // 播放音乐
    player->play();
}


void MusicWindow::initializeFavorites()
{
    QString jsonFilePath = QCoreApplication::applicationDirPath() + "/favorites.json";
    qDebug() << "JSON file path:" << jsonFilePath;

    QFile file(jsonFilePath);
    if (!file.exists()) {
        qDebug() << "Favorites JSON file does not exist.";
        return;
    }

    if (!file.open(QIODevice::ReadOnly)) {
        qDebug() << "Failed to open JSON file:" << file.errorString();
        return;
    }

    QByteArray data = file.readAll();
    file.close();

    QJsonDocument jsonDoc(QJsonDocument::fromJson(data));
    if (!jsonDoc.isArray()) {
        qDebug() << "Invalid JSON format.";
        return;
    }

    QJsonArray jsonArray = jsonDoc.array();
    for (const QJsonValue &value : jsonArray) {
        if (!value.isObject()) {
            qDebug() << "Invalid JSON object.";
            continue;
        }

        QJsonObject obj = value.toObject();
        QString title = obj["title"].toString();
        QString filePath = obj["filePath"].toString();

        qDebug() << "Adding item:" << title << filePath;

        QListWidgetItem *item = new QListWidgetItem(title);
        item->setIcon(QIcon(":/images/images/musicFile.png"));
        item->setData(Qt::UserRole, QUrl::fromLocalFile(filePath));

        ui->listWidget_2->addItem(item);
    }
}



