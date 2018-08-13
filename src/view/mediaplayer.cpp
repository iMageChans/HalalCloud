#include "mediaplayer.h"
#include "ui_mediaplayer.h"
#include <QDebug>
#include <QFileDialog>
#include <QDir>

MediaPlayer::MediaPlayer(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::MediaPlayer)
{


    m_pInstance = libvlc_new(0,NULL);

    if(m_pInstance == NULL){
        qDebug()<<"Instance NULL";

    }else{
        qDebug()<<"Instance call ok...";
    }

    ui->setupUi(this);
}

MediaPlayer::~MediaPlayer()
{
    if (m_pInstance != NULL){
        libvlc_release(m_pInstance);
        m_pInstance = NULL;
    }
    delete ui;
}

void MediaPlayer::on_pushButton_clicked()
{
    if (m_pInstance == NULL){
        return;
    }

    QString filePath = QFileDialog::getOpenFileName(this,tr("Open media file"),".",tr("Media Files (*.avi *.mp4 *.mkv *.ogg *.mp3 *.wma *.wma *.m4a)"));
    if (filePath.length() != 0){
        filePath = QDir::toNativeSeparators(filePath);
        libvlc_media_t* media=libvlc_media_new_path(m_pInstance,filePath.toUtf8().data());
        m_pVlcPlayer=libvlc_media_player_new_from_media(media);
        libvlc_media_release(media);

        this->MediaPlayerSetDrawableWindow(m_pVlcPlayer);
        this->MediaPlayerPlay();
    }
}

void MediaPlayer::MediaPlayerSetDrawableWindow(libvlc_media_player_t *player)
{

//    libvlc_media_player_set_nsobject(player, (void*)ui->videoWidget);

//#if defined(Q_OS_WIN32)
//    libvlc_media_player_set_hwnd(player,(void*)m_pRenderWidget->drawableId());
//#elif defined(Q_OS_MAC)
//    libvlc_media_player_set_nsobject(player, (void*)ui->videoWidget);
//#elif defined(Q_OS_UNIX)
//    libvlc_media_player_set_xwindow(player,(int)ui->videoWidget->winId());
//#endif
}

void MediaPlayer::MediaPlayerPlay()
{
    if(m_pInstance == NULL){
        return;
    }


}
