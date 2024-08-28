#include "audio.h"
#include <QAudioSource>
Audio::Audio(QObject *parent) : QObject(parent)
{

}

void Audio::startAudio(QString fileName)
{
    QAudioDevice device = QMediaDevices::defaultAudioInput();
    if(device.isNull())
    {
        QMessageBox::warning(NULL, "QAudioDeviceInfo", "录音设备不存在");
    }
    else
    {
        //音频编码要求
        QAudioFormat m_format;
        //设置采样频率
        m_format.setSampleRate(16000);
        m_format.setChannelCount(1);
        m_format.setSampleFormat(QAudioFormat::Int16);
        // //设置编码格式

        //判断设备是否支持该格式

        if(!device.isFormatSupported(m_format))
        {
            qDebug() << "777";
            m_format = device.preferredFormat();
        }

        //打开文件
        m_file = new QFile;
        m_file->setFileName(fileName);
        m_file->open(QIODevice::WriteOnly);

        //创建录音对象
        m_audio = new QAudioSource(device,m_format, this);

        m_audio->start(m_file);


    }

}

void Audio::stopAudio()
{
    //停止录音
    m_audio->stop();

    //关闭文件
    m_file->close();

    //删除文件对象
    delete m_file;
    m_file = NULL;
}
