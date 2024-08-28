#ifndef PICPLAYERWIDGET_H
#define PICPLAYERWIDGET_H

#include <QWidget>
#include <QLabel>
#include <QFileDialog>
#include <QPushButton>
#include <QComboBox>
#include <QImage>
#include <QDir>
#include <QScrollArea>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QImageReader>
#include <QMap>
#include <QPixmap>
#include <QVector>

QT_BEGIN_NAMESPACE
namespace Ui {
class PicPlayerWidget;
}
QT_END_NAMESPACE



class PicPlayerWidget : public QWidget
{
    Q_OBJECT


public:
    explicit PicPlayerWidget();
    ~PicPlayerWidget();

private:
    Ui::PicPlayerWidget *ui;

    QPixmap pix;
    QPixmap crtPix;
    //实现动作
    int action;
    int pixW;
    int pixH;
    //图片展示区域
    QRect paint;
    //打开图片
    QImage image;

    //图片缩放比例
    float ration;
    //图片偏移值
    QPoint offset,ALLoffset;
    qreal angel;
    QStringList imagePaths;
    int currentImageIndex;

    QPushButton button_min;
    QPushButton button_max;

    QPushButton button_left;

    QPushButton button_right;

    QPushButton button_reset;
    QPushButton button_open;

    QPushButton button_prev;
    QPushButton button_next;

    bool dragging;           // 是否正在拖动
    QPoint lastPos;          // 上一次鼠标位置
    QPoint imageOffset;      // 图片位置偏移

    QVector<QString> imagePath;

    QScrollArea *scrollArea;
    QWidget *thumbnailWidget;
    QHBoxLayout *thumbnailLayout;

    void createThumbnailView();
    QMap<QString, QPixmap> imageCache; // 图片缓存


private slots:
    void Onbutton_min_Clicked();
    void Onbutton_max_Clicked();
    void Onbutton_left_Clicked();
    void Onbutton_right_Clicked();


    void Onbutton_reset_Clicked();
    void Onbutton_open_Clicked();
    void Onbutton_prev_Clicked();
    void Onbutton_next_Clicked();

    void paintEvent(QPaintEvent *event);

    void mousePressEvent(QMouseEvent *event);
    void mouseMoveEvent(QMouseEvent *event);
    void mouseReleaseEvent(QMouseEvent *event);



public:
    // 图片状态
    enum Type{
        None=0,
        Amplification,
        Shrink,
        Left,
        Right,
        Up,
        Down,
        Move,
        Reset
    };
    // 鼠标滑轮
    void wheelEvent(QWheelEvent *e);
    // 判断鼠标操作
    bool event(QEvent *event);
    void loadImage();


protected:



};
#endif // WIDGET_H
