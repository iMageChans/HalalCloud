/*****************************************************************************
 * RenderWidget: Vout render widget
 *****************************************************************************
 * Copyright (C) 2008-2011 VideoLAN
 *
 * Authors: Rohit Yadav <rohityadav89@gmail.com>
 *
 * This program is free software; you can redistribute it and/or
 * modify it under the terms of the GNU General Public License
 * as published by the Free Software Foundation; either version 2
 * of the License, or (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston MA 02110-1301, USA.
 *****************************************************************************/

#ifndef RENDERWIDGET_H
#define RENDERWIDGET_H

#include <QtGlobal>
#include <QWidget>
 #if defined( Q_WS_MAC ) && defined( QT_MAC_USE_COCOA )
#include <QMacCocoaViewContainer>
#else
#endif

class RenderWidget : public QWidget
{
    Q_OBJECT

public:
 #if defined( Q_WS_MAC ) && defined( QT_MAC_USE_COCOA )
    RenderWidget( QWidget* parent = NULL );
    virtual ~RenderWidget();

    void* drawableId() const;

private:

    QMacCocoaViewContainer*  m_container;

#else
    RenderWidget( QWidget* parent = 0 ):QWidget(parent){}
    void* drawableId() const{ return winId();}
#endif

};

#endif // RENDERWIDGET_H
