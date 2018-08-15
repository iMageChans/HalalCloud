#ifndef MEDIAPLAYER_H
#define MEDIAPLAYER_H

#include <QWidget>
#include <vlc/vlc.h>
#include "view/displywidget.h"

#include "RenderWidget.h"

enum MediaPlayStatus{
    MEDIA_STATUS_PLAY,
    MEDIA_STATUS_PAUSE,
    MEDIA_STATUS_STOPED
};

class QTimer;

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

    void on_Player_clicked();

    void on_VideoSlider_valueChanged(int value);

    void on_AudioSlider_valueChanged(int value);

    void on_Subtitle_clicked();

    void on_Resolution_clicked();

    void on_Big_clicked();

    void UpdateUserInterface();

private:

    Ui::MediaPlayer *ui;

    void MediaPlayerSetDrawableWindow(libvlc_media_player_t* player);
    void MediaPlayerPlay();
    void MediaPlayerStop();

    libvlc_instance_t *m_pInstance;
    libvlc_media_player_t *m_pVlcPlayer;

    int image_width;
    int image_height;

    int GetImageWidth(){return image_width;}
    int GetImageHeight(){return image_height;}

    MediaPlayStatus m_eMediaPlayStatus;
    QTimer *m_updateTimer;

    RenderWidget *m_pRenderWidget;

protected:
    void resizeEvent(QResizeEvent *event);
};

#endif // MEDIAPLAYER_H
