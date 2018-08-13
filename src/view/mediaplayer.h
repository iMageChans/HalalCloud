#ifndef MEDIAPLAYER_H
#define MEDIAPLAYER_H

#include <QWidget>
#include <vlc/vlc.h>

enum MediaPlayStatus{
    MEDIA_STATUS_PLAY,
    MEDIA_STATUS_PAUSE,
    MEDIA_STATUS_STOPED
};

namespace Ui {
class MediaPlayer;
}

class MediaPlayer : public QWidget
{
    Q_OBJECT

public:
    explicit MediaPlayer(QWidget *parent = nullptr);
    ~MediaPlayer();

private slots:
    void on_pushButton_clicked();

private:
    Ui::MediaPlayer *ui;

    void MediaPlayerSetDrawableWindow(libvlc_media_player_t* player);
    void MediaPlayerPlay();

    libvlc_instance_t *m_pInstance;
    libvlc_media_player_t *m_pVlcPlayer;

    int image_width;
    int image_height;

//    RenderWidget *m_pRenderWidget;
    MediaPlayStatus m_eMediaPlayStatus;
};

#endif // MEDIAPLAYER_H
