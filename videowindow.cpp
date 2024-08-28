#include "videowindow.h"
#include "ui_videowindow.h"
#include <QFileDialog>


VideoWindow::VideoWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::VideoWindow)
{
    ui->setupUi(this);
    setWindowFlags(Qt::CustomizeWindowHint|Qt::FramelessWindowHint);
    //窗口标题
    // setWindowTitle("MediaPlayer");

    pPlayer = new QMediaPlayer(this);

    //设置播放器显示窗口
    pVideoWidget = new QVideoWidget(ui->label);
    pVideoWidget->resize(ui->label->size());
    pPlayer->setVideoOutput(pVideoWidget);

    //设置音频输出设备
    audiooutput = new QAudioOutput(this);
    pPlayer -> setAudioOutput(audiooutput);

    //未打开文件时禁止使用播放键
    ui->playButton->setEnabled(false);
    ui->forwardButton->setEnabled(false);
    ui->backwardButton->setEnabled(false);

    //设置进度条
    connect(pPlayer, &QMediaPlayer::positionChanged, this, &VideoWindow::updateProgressBarPosition);
    connect(pPlayer,&QMediaPlayer::durationChanged, this, &VideoWindow::updateTotalTime);

    //结束播放
    connect(pPlayer, &QMediaPlayer::playbackStateChanged, this, &VideoWindow::endPlay);
}

VideoWindow::~VideoWindow()
{
    delete ui;
    delete pVideoWidget;
}

//空
void VideoWindow::on_pushButton_clicked()
{

}

//打开文件
void VideoWindow::on_openButton_clicked()
{
    QString fileName=
        QFileDialog::getOpenFileName(this,"打开","C:/Users/Lenovo/Desktop",
                                     "allfiles(*.*);;"
                                     "MP3(*.mp3);;"
                                     "MP4(*.mp4);;"
                                     "MKV(*.mkv);;"
                                     "AVI(*.AVI)");
    pPlayer->setSource(QUrl::fromLocalFile(fileName));

    ui->playButton->setEnabled(true);
    ui->playButton->setStyleSheet("QPushButton#playButton{border-image:url(:/play.png);}");
    ui->forwardButton->setEnabled(true);
    ui->forwardButton->setStyleSheet("QPushButton#forwardButton{border-image:url(:/forward.png);}");
    ui->backwardButton->setEnabled(true);
    ui->backwardButton->setStyleSheet("QPushButton#backwardButton{border-image:url(:/backward.png);}");

    //显示最初几帧
    pPlayer->play();
    pPlayer->pause();
}

//播放源时长发生变化后运行，更新总时间，放在其他函数中会有奇妙的bug
void VideoWindow::updateTotalTime()
{
    duration = pPlayer->duration();
    ui->time_total->setText(getTime(duration));
}

//播放，暂停
void VideoWindow::on_playButton_clicked()
{
    if(!isplaying){
        pPlayer->play();
        ui->playButton->setStyleSheet("QPushButton#playButton{border-image:url(:/pause.png);}");
        isplaying = true;
    }
    else{
        pPlayer->pause();
        ui->playButton->setStyleSheet("QPushButton#playButton{border-image:url(:/play.png);}");
        isplaying = false;
    }
}

//停止
void VideoWindow::on_stopButton_clicked()
{
    pPlayer->stop();
    isplaying = false;
    ui->time_total->setText(getTime(0));
    ui->playButton->setEnabled(false);
    ui->playButton->setStyleSheet("QPushButton#playButton{border-image:url(:/cannotplay.png);}");
    ui->forwardButton->setEnabled(false);
    ui->forwardButton->setStyleSheet("QPushButton#forwardButton{border-image:url(:/cannotforward.png);}");
    ui->backwardButton->setEnabled(false);
    ui->backwardButton->setStyleSheet("QPushButton#backwardButton{border-image:url(:/cannotbackward.png);}");
}

//进度条自动更新
void VideoWindow::updateProgressBarPosition()
{
    //滑条正在被鼠标拖动
    if (ui->progressBar->isSliderDown()){
        return;
    }
    duration = pPlayer->duration();
    position = pPlayer->position();
    // 更新当前播放时间
    int sliderPosition = static_cast<int>(position * 100 / duration);
    if(true){
        ui->progressBar->setValue(sliderPosition);
    }
    ui->time_now->setText(getTime(position));
}

//改变进度条后播放对应位置
void VideoWindow::on_progressBar_sliderReleased()
{
    position = ui->progressBar->value();
    qint64 newPos = position * duration / 100;
    pPlayer->setPosition(newPos);
}

//拖动进度条
void VideoWindow::on_progressBar_sliderMoved(int position)
{
    //释放鼠标才执行视频位置的变更，所以下面只是为了计算时间
    duration = pPlayer->duration();
    qint64 newPos = position * duration / 100;
    ui->time_now->setText(getTime(newPos));
}

//时间计算函数
QString VideoWindow::getTime(qint64 time)
{
    int hours = (time / (1000 * 60 * 60)) % 24;
    int minutes = (time / (1000 * 60)) % 60;
    int seconds = (time / 1000) % 60;
    //qDebug() << "视频时长：" << hours << "小时" << minutes << "分钟" << seconds << "秒";
    QString allTime=QString::number(hours)+":"+QString::number(minutes)+":"+QString::number(seconds);
    return allTime;
}

//快进5s
void VideoWindow::on_forwardButton_clicked()
{
    duration = pPlayer->duration();
    position = pPlayer->position();
    position += 5000;
    if (position > duration) {
        position = duration;
    }
    pPlayer->setPosition(position);
}

//快退5s
void VideoWindow::on_backwardButton_clicked()
{
    position = pPlayer->position();
    position -= 5000;
    if (position < 0) {
        position = 0;
    }
    pPlayer->setPosition(position);
}

//倍速选择,bug
void VideoWindow::on_speedOptionBox_valueChanged(double arg1)
{
    pPlayer->setPlaybackRate(arg1);
}

//静音
void VideoWindow::on_voiceButton_clicked()
{
    bool mute= pPlayer->audioOutput()->isMuted();
    if (mute){
        ui->voiceButton->setStyleSheet("QPushButton#voiceButton{border-image:url(:/notmuted.png);}");
    }
    else{
        ui->voiceButton->setStyleSheet("QPushButton#voiceButton{border-image:url(:/muted.png);}");
    }
    pPlayer->audioOutput()->setMuted(!mute);
}

//音量
void VideoWindow::on_voiceSlider_sliderReleased()
{
    int value = ui->voiceSlider->value();
    pPlayer->audioOutput()->setVolume(value/100.0);
}
void VideoWindow::on_voiceSlider_valueChanged(int value)
{
    pPlayer->audioOutput()->setVolume(value/100.0);
}

//结束播放
void VideoWindow::endPlay(QMediaPlayer::PlaybackState state)
{
    if (state == QMediaPlayer::StoppedState)
    {
        isplaying = false;
        ui->playButton->setStyleSheet("QPushButton#playButton{border-image:url(:/play.png);}");
    }
}
