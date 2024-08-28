#include "littlepicwidget.h"
#include "ClickableLabel.h"
#include <QPainter>
#include <QFileDialog>
#include <QWheelEvent>
#include <QPushButton>
#include <QMessageBox>
#include <QDir>
#include <QScrollArea>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QImageReader>
#include <QScrollBar>
#include <QDirIterator>
#include <QFileInfo>
#include <QImage>
#include <QPixmap>
#include <QLabel>


LittlePicWidget::LittlePicWidget():
    paint(5,5,500,400),
    button_min("",this),
    button_max("",this),
    button_left("",this),
    button_right("",this),
    button_reset("",this),
    button_open(" ",this),
    button_prev("",this),
    button_next("",this),
    ALLoffset(30,50),
    angel(0),
    dragging(false) // 初始化拖动状态
{
    this->setWindowIcon(QIcon(":/logo/favicon.ico"));
    ration = 0.6;
    action = LittlePicWidget::None;
    // 设置窗口大小
    resize(500,400);
    // 固定窗口
    setFixedSize(500,400);
    // 设置窗口背景透明
    setAttribute(Qt::WA_TranslucentBackground);
    this->setWindowTitle("图片浏览器");
    imageOffset = QPoint(0, 0); // 初始化图片偏移

    // 设置按钮样式
    QString buttonStyle = "QPushButton { background-color: gray; color: black; font-weight: bold; }";
    QString buttonStyle_next = "QPushButton { image: url(:/images/images/right.png);}";
    QString buttonStyle_prev = "QPushButton { image: url(:/images/images/left.png);}";
    QString buttonStyle_left = "QPushButton { image: url(:/images/images/turn_left.png);}";
    QString buttonStyle_right = "QPushButton { image: url(:/images/images/turn_right.png);}";
    QString buttonStyle_reset = "QPushButton { image: url(:/images/images/reset.png);}";
    QString buttonStyle_open = "QPushButton { image: url(:/images/images/file.png);}";
    QString buttonStyle_min = "QPushButton { image: url(:/images/images/small.png);}";
    QString buttonStyle_max = "QPushButton { image: url(:/images/images/large.png);}";
    button_open.setGeometry(410,370,30,30);
    button_open.setStyleSheet(buttonStyle_open);
    connect(&button_open,SIGNAL(clicked(bool)),this,SLOT(Onbutton_open_Clicked()));

    button_reset.setGeometry(340,370,30,30);
    button_reset.setStyleSheet(buttonStyle_reset);
    connect(&button_reset,SIGNAL(clicked(bool)),this,SLOT(Onbutton_reset_Clicked()));

    button_left.setGeometry(200,370,30,30);
    button_left.setStyleSheet(buttonStyle_left);
    connect(&button_left,SIGNAL(clicked(bool)),this,SLOT(Onbutton_left_Clicked()));

    button_right.setGeometry(270,370,30,30);
    button_right.setStyleSheet(buttonStyle_right);
    connect(&button_right,SIGNAL(clicked(bool)),this,SLOT(Onbutton_right_Clicked()));

    button_max.setGeometry(60,370,30,30);
    button_max.setStyleSheet(buttonStyle_max);
    connect(&button_max,SIGNAL(clicked(bool)),this,SLOT(Onbutton_max_Clicked()));

    button_min.setGeometry(130,370,30,30);
    button_min.setStyleSheet(buttonStyle_min);
    connect(&button_min,SIGNAL(clicked(bool)),this,SLOT(Onbutton_min_Clicked()));

    button_prev.setGeometry(0,150,50,60);
    button_prev.setStyleSheet(buttonStyle_prev);
    connect(&button_prev, SIGNAL(clicked(bool)), this, SLOT(Onbutton_prev_Clicked()));

    button_next.setGeometry(450,150,50,60);
    button_next.setStyleSheet(buttonStyle_next);
    connect(&button_next, SIGNAL(clicked(bool)), this, SLOT(Onbutton_next_Clicked()));


    // Create and configure scroll area
    scrollArea = new QScrollArea(this);
    scrollArea->setFixedHeight(50); // 设置滚动区域的固定高度
    scrollArea->setStyleSheet("background: transparent; border: none;");

    // Create thumbnail LittlePicWidget and layout
    thumbnailLittlePicWidget = new QWidget(scrollArea);
    thumbnailLayout = new QHBoxLayout(thumbnailLittlePicWidget); // 使用水平布局
    thumbnailLayout->setSpacing(5);
    thumbnailLayout->setContentsMargins(0, 0, 0, 0);
    thumbnailLittlePicWidget->setLayout(thumbnailLayout); // 将布局应用于 thumbnailLittlePicWidget
    thumbnailLittlePicWidget->setStyleSheet("background: transparent;");

    // Set the thumbnail LittlePicWidget as the scroll area LittlePicWidget
    scrollArea->setWidget(thumbnailLittlePicWidget);
    scrollArea->setWidgetResizable(true); // 使 scrollArea 可调整大小

    // Create layout for main LittlePicWidget
    QVBoxLayout *mainLayout = new QVBoxLayout(this);
    mainLayout->addWidget(scrollArea);
    mainLayout->addStretch(); // 确保滚动区域在底部

    setLayout(mainLayout);
}

LittlePicWidget::~LittlePicWidget()
{
}

void LittlePicWidget::Onbutton_min_Clicked()
{
    ration *= 0.9; // 缩小比例
    update();
}
void LittlePicWidget::Onbutton_max_Clicked()
{
    ration *= 1.1; // 放大比例
    update();
}
void LittlePicWidget::Onbutton_left_Clicked()
{
    angel -= 90;
    update();
}
void LittlePicWidget::Onbutton_right_Clicked()
{
    angel += 90;
    update();
}
void LittlePicWidget::Onbutton_reset_Clicked()
{

    ration = 0.5; // 恢复比例
    ALLoffset = QPoint(10, 45); // 恢复偏移
    angel = 0;
    imageOffset = QPoint(0, 0); // 初始化图片偏移
    update();
}

void LittlePicWidget::loadImage()
{
    if (currentImageIndex >= 0 && currentImageIndex < imagePaths.size()) {
        QString path = imagePaths[currentImageIndex];
        image.load(path);
        pix = QPixmap::fromImage(image);
        crtPix = pix;
        pixW = image.width();
        pixH = image.height();

        this->setWindowTitle("图片浏览器(" + path + ")");
        ration = 0.3;
        ALLoffset = QPoint(10, 45);
        angel = 0;
        Onbutton_reset_Clicked(); // 重置缩放和偏移
        update();

    }
}

void LittlePicWidget::createThumbnailView()
{
    // Clear existing thumbnails
    QLayoutItem *item;
    while ((item = thumbnailLayout->takeAt(0))) {
        delete item->widget();
        delete item;
    }

    // Get the directory of the current image
    QFileInfo fileInfo(imagePaths[currentImageIndex]);
    QDir directory(fileInfo.absolutePath());

    // Iterate through all image files in the directory
    QDirIterator it(directory.absolutePath(), QDir::Files | QDir::NoDotAndDotDot, QDirIterator::Subdirectories);
    while (it.hasNext()) {
        QFileInfo fileInfo(it.next());
        QString filePath = fileInfo.absoluteFilePath();


        if (QImageReader::supportedImageFormats().contains(fileInfo.suffix().toLower().toLatin1())) {
            QImage img(filePath);
            QPixmap pixmap = QPixmap::fromImage(img).scaled(100, 100, Qt::KeepAspectRatio, Qt::SmoothTransformation);
            ClickableLabel *thumbnailLabel = new ClickableLabel;
            thumbnailLabel->setPixmap(pixmap);
            // Connect the click event to the slot
            connect(thumbnailLabel, &ClickableLabel::clicked, [this, filePath]() {
                int index = imagePaths.indexOf(filePath);
                if (index != -1) {
                    currentImageIndex = index;
                    loadImage(); // Load the selected image
                }
            });
            thumbnailLayout->addWidget(thumbnailLabel);
        }
    }
}
void LittlePicWidget::Onbutton_open_Clicked()
{
    QString dirPath = QFileDialog::getExistingDirectory(this, "选择文件夹", "C:");
    if (!dirPath.isEmpty()) {
        QDir dir(dirPath);
        QStringList nameFilters;
        nameFilters << "*.jpg" << "*.png";
        QStringList fileNames = dir.entryList(nameFilters, QDir::Files);

        if (!fileNames.isEmpty()) {
            imagePaths.clear();
            imageCache.clear(); // Clear existing cache
            for (const QString &fileName : fileNames) {
                imagePaths.append(dir.filePath(fileName));
            }
            currentImageIndex = 0;
            loadImage();
            createThumbnailView(); // Create thumbnails for the loaded images
        }
    }
}
void LittlePicWidget::Onbutton_prev_Clicked()
{
    if (imagePaths.isEmpty()) return;
    // 检查是否已经到达第一张
    if (currentImageIndex <= 0) {
        QMessageBox::information(this, "提示", "已经是第一张图片了！");
        return;
    }
    --currentImageIndex;
    loadImage();
}

void LittlePicWidget::Onbutton_next_Clicked()
{
    if (imagePaths.isEmpty()) return;

    // 检查是否已经到达最后一张
    if (currentImageIndex >= imagePaths.size() - 1) {
        QMessageBox::information(this, "提示", "已经是最后一张图片了！");
        return;
    }
    ++currentImageIndex;
    loadImage();
}

void LittlePicWidget::paintEvent(QPaintEvent *event)
{
    QPainter painter(this);
    painter.setRenderHint(QPainter::Antialiasing, true);
    painter.setRenderHint(QPainter::SmoothPixmapTransform, true);
    // painter.fillRect(rect(), Qt::white);

    if (!pix.isNull()) {
        // 目标分辨率 1080p
        const QSize targetSize(1000, 800);

        // 计算缩放比例以将图片缩放到 1080p 分辨率
        QSize imageSize = pix.size();
        qreal scaleFactor = qMin(targetSize.width() / static_cast<qreal>(imageSize.width()),
                                 targetSize.height() / static_cast<qreal>(imageSize.height()));

        // 根据比例缩放图片
        QPixmap scaledPix = pix.scaled(imageSize * scaleFactor, Qt::KeepAspectRatio, Qt::SmoothTransformation);

        // 计算目标矩形区域
        QSize scaledSize = scaledPix.size() * ration;
        QRect targetRect(0, 0, scaledSize.width(), scaledSize.height());

        // 计算窗口中心
        QPoint center = rect().center();

        // 计算目标矩形在窗口中的中心点
        QRect target(center.x() - targetRect.width() / 2 + imageOffset.x(),
                     center.y() - targetRect.height()/2 + 15 +imageOffset.y(),
                     targetRect.width(),
                     targetRect.height());

        // 应用旋转变换
        painter.translate(center);
        painter.rotate(angel);
        painter.translate(-center);

        // 绘制缩放后的图片
        painter.drawPixmap(target, scaledPix);
    }
}
void LittlePicWidget::wheelEvent(QWheelEvent *e)
{
    int numDegrees = e->angleDelta().y() / 8;
    int numSteps = numDegrees / 15;
    ration *= (1.0 + numSteps * 0.05); // 根据滚轮滚动的步数调整缩放比例
    update();
}
bool LittlePicWidget::event(QEvent *event)
{
    return QWidget::event(event);
}


void LittlePicWidget::mousePressEvent(QMouseEvent *event)
{
    if (event->button() == Qt::LeftButton) {
        dragging = true;
        lastPos = event->pos();
    }
}
void LittlePicWidget::mouseMoveEvent(QMouseEvent *event)
{
    if (dragging) {
        QPoint delta = event->pos() - lastPos;
        imageOffset += delta;
        lastPos = event->pos();
        update();
    }
}
void LittlePicWidget::mouseReleaseEvent(QMouseEvent *event)
{
    if (event->button() == Qt::LeftButton) {
        dragging = false;
    }
}
