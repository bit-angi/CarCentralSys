#ifndef CLICKABLELABEL_H
#define CLICKABLELABEL_H

#include <QLabel>
#include <QMouseEvent>

class ClickableLabel : public QLabel
{
    Q_OBJECT

public:
    using QLabel::QLabel; // 继承 QLabel 的构造函数

signals:
    void clicked(); // 自定义信号

protected:
    void mousePressEvent(QMouseEvent *event) override
    {
        if (event->button() == Qt::LeftButton) { // 检查是否是左键点击
            emit clicked(); // 发射 clicked() 信号
        }
        QLabel::mousePressEvent(event); // 调用父类的 mousePressEvent 以保持 QLabel 的默认行为
    }
};

#endif // CLICKABLELABEL_H
