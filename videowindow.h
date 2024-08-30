#ifndef VIDEOWINDOW_H
#define VIDEOWINDOW_H

#include <QMainWindow>

#include <QMediaPlayer>
#include <QVideoWidget>
#include <QAudioOutput>

QT_BEGIN_NAMESPACE
namespace Ui {
class VideoWindow;
}
QT_END_NAMESPACE

class VideoWindow : public QMainWindow
{
    Q_OBJECT

public:
    VideoWindow(QWidget *parent = nullptr);
    ~VideoWindow();

private slots:
    void on_pushButton_clicked();

    void on_openButton_clicked();

    void on_playButton_clicked();

    void on_stopButton_clicked();

    void updateProgressBarPosition();

    void on_progressBar_sliderReleased();

    void on_progressBar_sliderMoved(int position);

    QString getTime(qint64 time);

    void updateTotalTime();

    void on_forwardButton_clicked();

    void on_backwardButton_clicked();

    void on_speedOptionBox_valueChanged(double arg1);

    void on_voiceButton_clicked();

    void on_voiceSlider_sliderReleased();

    void on_voiceSlider_valueChanged(int value);

    void endPlay(QMediaPlayer::PlaybackState state);

public:
    Ui::VideoWindow* ui;
    QMediaPlayer* pPlayer;
    QVideoWidget* pVideoWidget;
    QAudioOutput* audiooutput;
    bool isplaying = false;
    qint64 duration;
    qint64 position;
};
#endif // videowindow_H
