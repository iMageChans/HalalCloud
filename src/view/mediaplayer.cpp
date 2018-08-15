#include "mediaplayer.h"
#include "ui_mediaplayer.h"
#include <QMutex>
#include <QTimer>
#include <QTime>
#include <QDebug>
#include <QFileDialog>
#include <QResizeEvent>
#include <QDir>
#include <vlc/libvlc.h>

MediaPlayer::MediaPlayer(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::MediaPlayer)
{
    ui->setupUi(this);

    m_pInstance = libvlc_new(0,nullptr);

    if(m_pInstance == nullptr){
        qDebug()<<"Instance NULL";
    }else{
        qDebug()<<"Instance call ok...";
    }

    image_width = 1280;
    image_height = 740;

    m_eMediaPlayStatus=MEDIA_STATUS_STOPED;
    m_updateTimer = new QTimer(this);
    connect(m_updateTimer, SIGNAL(timeout()), this, SLOT(UpdateUserInterface()));

    ui->VideoSlider->setMaximum(1000);
    ui->AudioSlider->setMaximum(100);

    QVBoxLayout *vLayout = new QVBoxLayout(ui->videoWidget);
    vLayout->setContentsMargins(0,0,0,0);

    m_pRenderWidget = new RenderWidget();
    vLayout->addWidget(m_pRenderWidget);
    ui->videoWidget->setLayout(vLayout);
}

MediaPlayer::~MediaPlayer()
{
    if (m_pInstance != nullptr){
        libvlc_release(m_pInstance);
        m_pInstance = nullptr;
    }

    if( m_pRenderWidget != nullptr){
        delete  m_pRenderWidget;
        m_pRenderWidget=nullptr;
    }

    if(m_pVlcPlayer != nullptr){
        libvlc_media_player_release(m_pVlcPlayer);
        m_pVlcPlayer=nullptr;
    }

    if(m_updateTimer !=nullptr){
        m_updateTimer->stop();
        m_updateTimer=nullptr;
    }

    delete ui;
}

void MediaPlayer::resizeEvent(QResizeEvent *event)
{
    m_pRenderWidget->resize(event->size());
}

void MediaPlayer::on_Player_clicked()
{

    if (m_pInstance == nullptr){
        return;
    }

    QString filePath = "http://221.228.226.23/11/t/j/v/b/tjvbwspwhqdmgouolposcsfafpedmb/sh.yinyuetai.com/691201536EE4912BF7E4F1E2C67B8119.mp4";
    if (filePath.length() != 0){
        libvlc_media_t* media=libvlc_media_new_location(m_pInstance,filePath.toUtf8().data());
        m_pVlcPlayer=libvlc_media_player_new_from_media(media);
        libvlc_media_release(media);

        this->MediaPlayerSetDrawableWindow(m_pVlcPlayer);
        this->MediaPlayerPlay();
    }
}

void MediaPlayer::on_VideoSlider_valueChanged(int value)
{
    if(m_pVlcPlayer ==nullptr){
        return;
    }

    if(libvlc_media_player_is_playing(m_pVlcPlayer)){
        float pos= (float)value / (float)ui->VideoSlider->maximum();
        libvlc_media_player_set_position(m_pVlcPlayer,pos);
    }
}

void MediaPlayer::on_AudioSlider_valueChanged(int value)
{
    if(m_pVlcPlayer ==nullptr){
        return;
    }

    if(libvlc_media_player_is_playing(m_pVlcPlayer)){
        int volume=value;
        libvlc_audio_set_volume(m_pVlcPlayer,volume);
    }
}

void MediaPlayer::UpdateUserInterface()
{

    if(m_pVlcPlayer==nullptr){
        return;
    }

    if(libvlc_media_player_is_playing(m_pVlcPlayer))
    {
        int progressPos = libvlc_media_player_get_position(m_pVlcPlayer)*ui->VideoSlider->maximum();
        int volumePos = libvlc_audio_get_volume(m_pVlcPlayer);


        bool states=ui->VideoSlider->blockSignals(true);
        ui->VideoSlider->setValue(progressPos);
        ui->VideoSlider->blockSignals(states);

        bool statesVolume=ui->AudioSlider->blockSignals(true);
        ui->AudioSlider->setValue(volumePos);
        ui->AudioSlider->blockSignals(statesVolume);

        QTime startTime;
        startTime = startTime.addMSecs(int(libvlc_media_player_get_time(m_pVlcPlayer)));
        qDebug() << startTime;
        QString startTimeString = startTime.toString("hh:mm:ss");

        QTime remainTime;
        remainTime = remainTime.addMSecs(int(libvlc_media_player_get_length(m_pVlcPlayer) - libvlc_media_player_get_time(m_pVlcPlayer)));
        qDebug() << remainTime;
        QString endTimeSTring = remainTime.toString("hh:mm:ss");

        ui->Timer->setText(startTimeString + " / " + endTimeSTring);

    }
}

void MediaPlayer::on_Subtitle_clicked()
{

}

void MediaPlayer::on_Resolution_clicked()
{

}

void MediaPlayer::on_Big_clicked()
{

}

void MediaPlayer::MediaPlayerSetDrawableWindow(libvlc_media_player_t *player)
{

#if defined(Q_OS_WIN32)
    libvlc_media_player_set_hwnd(player,(void*)m_pRenderWidget->drawableId());
#elif defined(Q_OS_MAC)
    libvlc_media_player_set_nsobject(player, m_pRenderWidget->drawableId());
#elif defined(Q_OS_UNIX)
    libvlc_media_player_set_xwindow(player,(int)ui->videoWidget->winId());
#endif

    if(m_updateTimer!=nullptr){

        m_updateTimer->start(100);
    }
}

void MediaPlayer::MediaPlayerPlay()
{
    if(m_pInstance == nullptr){
        return;
    }

    if(m_eMediaPlayStatus==MEDIA_STATUS_PLAY)
    {
        libvlc_media_player_pause(m_pVlcPlayer);
        m_eMediaPlayStatus=MEDIA_STATUS_PAUSE;
    }
    else if(m_eMediaPlayStatus==MEDIA_STATUS_PAUSE)
    {
        libvlc_media_player_play(m_pVlcPlayer);
        m_eMediaPlayStatus=MEDIA_STATUS_PLAY;
        resize(ui->videoWidget->frameSize());

    }
    else{
        libvlc_media_player_play(m_pVlcPlayer);
        m_eMediaPlayStatus=MEDIA_STATUS_PLAY;
        resize(ui->videoWidget->frameSize());
    }
}

void MediaPlayer::MediaPlayerStop()
{
    if(m_pVlcPlayer != nullptr)
    {
        libvlc_media_player_release(m_pVlcPlayer);
        m_pVlcPlayer = nullptr;
        m_eMediaPlayStatus = MEDIA_STATUS_STOPED;
    }
}
