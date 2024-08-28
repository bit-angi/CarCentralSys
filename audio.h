#ifndef AUDIO_H
#define AUDIO_H

#include <QObject>
#include <QAudioFormat>
#include <QMediaDevices>
#include <QAudioDevice>
#include <QMessageBox>
#include <QAudioInput>
#include <QFile>
#include <QAudioSource>

class Audio : public QObject
{
    Q_OBJECT
public:
    explicit Audio(QObject *parent = nullptr);

    void startAudio(QString fileName);
    void stopAudio();



signals:

public slots:

private:
    QAudioSource *m_audio;
    QFile *m_file;

};

#endif // AUDIO_H
