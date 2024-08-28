#include "picplayerwidget.h"
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


PicPlayerWidget::PicPlayerWidget():
    paint(5,5,960,600),
    ALLoffset(30,50),
    angel(0),
    button_min("缩小",this),
    button_max("放大",this),
    button_left("左旋",this),
    button_right("右旋",this),
    button_reset("重置",this),
    button_open("导入",this),
    button_prev("上一张",this),
    button_next("下一张",this),
    dragging(false) // 初始化拖动状态
{
    this->setWindowIcon(QIcon(":/logo/favicon.ico"));
    ration = 0.6;
    action = PicPlayerWidget::None;
    // 设置窗口大小
    resize(960,600);
    // 固定窗口
    setFixedSize(960,600);
    this->setWindowTitle("图片浏览器");
    imageOffset = QPoint(0, 0); // 初始化图片偏移

    // 设置按钮样式
    QString buttonStyle = "QPushButton { background-color: gray; color: black; font-weight: bold; }";
    button_open.setGeometry(843,10,100,30);
    button_open.setStyleSheet(buttonStyle);
    connect(&button_open,SIGNAL(clicked(bool)),this,SLOT(Onbutton_open_Clicked()));

    button_reset.setGeometry(726,10,100,30);
    button_reset.setStyleSheet(buttonStyle);
    connect(&button_reset,SIGNAL(clicked(bool)),this,SLOT(Onbutton_reset_Clicked()));

    button_left.setGeometry(375,10,100,30);
    button_left.setStyleSheet(buttonStyle);
    connect(&button_left,SIGNAL(clicked(bool)),this,SLOT(Onbutton_left_Clicked()));

    button_right.setGeometry(258,10,100,30);
    button_right.setStyleSheet(buttonStyle);
    connect(&button_right,SIGNAL(clicked(bool)),this,SLOT(Onbutton_right_Clicked()));

    button_max.setGeometry(141,10,100,30);
    button_max.setStyleSheet(buttonStyle);
    connect(&button_max,SIGNAL(clicked(bool)),this,SLOT(Onbutton_max_Clicked()));

    button_min.setGeometry(24,10,100,30);
    button_min.setStyleSheet(buttonStyle);
    connect(&button_min,SIGNAL(clicked(bool)),this,SLOT(Onbutton_min_Clicked()));

    button_prev.setGeometry(492,10,100,30);
    button_prev.setStyleSheet(buttonStyle);
    connect(&button_prev, SIGNAL(clicked(bool)), this, SLOT(Onbutton_prev_Clicked()));

    button_next.setGeometry(609,10,100,30);
    button_next.setStyleSheet(buttonStyle);
    connect(&button_next, SIGNAL(clicked(bool)), this, SLOT(Onbutton_next_Clicked()));


    // Create and configure scroll area
    scrollArea = new QScrollArea(this);
    scrollArea->setFixedHeight(100); // 设置滚动区域的固定高度
    scrollArea->setStyleSheet("background: white; border: none;");

    // Create thumbnail widget and layout
    thumbnailWidget = new QWidget(scrollArea);
    thumbnailLayout = new QHBoxLayout(thumbnailWidget); // 使用水平布局
    thumbnailLayout->setSpacing(5);
    thumbnailLayout->setContentsMargins(0, 0, 0, 0);
    thumbnailWidget->setLayout(thumbnailLayout); // 将布局应用于 thumbnailWidget

    // Set the thumbnail widget as the scroll area widget
    scrollArea->setWidget(thumbnailWidget);
    scrollArea->setWidgetResizable(true); // 使 scrollArea 可调整大小

    // Create layout for main widget
    QVBoxLayout *mainLayout = new QVBoxLayout(this);
    mainLayout->addStretch(); // 确保滚动区域在底部
    mainLayout->addWidget(scrollArea);
    setLayout(mainLayout);
}

PicPlayerWidget::~PicPlayerWidget()
{
}

void PicPlayerWidget::Onbutton_min_Clicked()
{
    ration *= 0.9; // 缩小比例
    update();
}
void PicPlayerWidget::Onbutton_max_Clicked()
{
    ration *= 1.1; // 放大比例
    update();
}
void PicPlayerWidget::Onbutton_left_Clicked()
{
    angel -= 90;
    update();
}
void PicPlayerWidget::Onbutton_right_Clicked()
{
    angel += 90;
    update();
}
void PicPlayerWidget::Onbutton_reset_Clicked()
{

    ration = 0.5; // 恢复比例
    ALLoffset = QPoint(10, 45); // 恢复偏移
    angel = 0;
    imageOffset = QPoint(0, 0); // 初始化图片偏移
    update();
}

void PicPlayerWidget::loadImage()
{
    if (currentImageIndex >= 0 && currentImageIndex < imagePaths.size()) {
        QString path = imagePaths[currentImageIndex];
        image.load(path);
        pix = QPixmap::fromImage(image);
        crtPix = pix;
        pixW = image.width();
        pixH = image.height();

        this->setWindowTitle("图片浏览器(" + path + ")");
        ration = 0.5;
        ALLoffset = QPoint(10, 45);
        angel = 0;
        Onbutton_reset_Clicked(); // 重置缩放和偏移
        update();
        // createThumbnailView();
    }
}

void PicPlayerWidget::createThumbnailView()
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
void PicPlayerWidget::Onbutton_open_Clicked()
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
void PicPlayerWidget::Onbutton_prev_Clicked()
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

void PicPlayerWidget::Onbutton_next_Clicked()
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

void PicPlayerWidget::paintEvent(QPaintEvent *event)
{
    QPainter painter(this);
    painter.setRenderHint(QPainter::Antialiasing, true);
    painter.setRenderHint(QPainter::SmoothPixmapTransform, true);
    painter.fillRect(rect(), Qt::white);

    if (!pix.isNull()) {
        // 目标分辨率 1080p
        const QSize targetSize(1920, 1080);

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
void PicPlayerWidget::wheelEvent(QWheelEvent *e)
{
    int numDegrees = e->angleDelta().y() / 8;
    int numSteps = numDegrees / 15;
    ration *= (1.0 + numSteps * 0.05); // 根据滚轮滚动的步数调整缩放比例
    update();
}
bool PicPlayerWidget::event(QEvent *event)
{
    return QWidget::event(event);
}


void PicPlayerWidget::mousePressEvent(QMouseEvent *event)
{
    if (event->button() == Qt::LeftButton) {
        dragging = true;
        lastPos = event->pos();
    }
}
void PicPlayerWidget::mouseMoveEvent(QMouseEvent *event)
{
    if (dragging) {
        QPoint delta = event->pos() - lastPos;
        imageOffset += delta;
        lastPos = event->pos();
        update();
    }
}
void PicPlayerWidget::mouseReleaseEvent(QMouseEvent *event)
{
    if (event->button() == Qt::LeftButton) {
        dragging = false;
    }
}
