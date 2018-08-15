/*****************************************************************************
 * RenderWidget.mm: A NSView Vout render widget for Mac OS
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

#include <QtGlobal>
#if defined( Q_WS_MAC ) && defined( QT_MAC_USE_COCOA )

#include "RenderWidget.h"
#include <QPalette>
#include <QColor>
#include <QVBoxLayout>
#include <QDebug>

#import <Cocoa/Cocoa.h>
#import <QuartzCore/QuartzCore.h>
#import <AppKit/NSView.h>

@interface VLCNSView : NSView
@property BOOL bstretches;
- ( void ) setStretchesVideo : ( BOOL ) value;
- ( BOOL ) stretchesVideo;
- (void )enterFullscreen:(NSView*)aView;
- ( void ) addVoutSubview:( NSView * ) aView;
- ( void ) removeVoutSubview:( NSView * ) aView;
@end

@implementation VLCNSView
- ( id ) initWithFrame:( NSRect ) frameRect
{
    if ((self = [super initWithFrame:frameRect]) == nil){ return nil; }
    return self;
}
- ( void ) dealloc
{
    [super dealloc];
}
- ( void ) setStretchesVideo : ( BOOL ) value
{
    self.bstretches = value;
}
- ( BOOL ) stretchesVideo
{
    return self.bstretches;
}

- ( void ) addVoutSubview:( NSView * ) aView
{
    [aView setFrame:[self bounds]];
    [self addSubview:aView];
    [aView setAutoresizingMask:NSViewHeightSizable | NSViewWidthSizable];
}
- (void) removeVoutSubview:(NSView *)aView { return;}
@end

RenderWidget::RenderWidget( QWidget *parent ) :
    QWidget( parent )
{

    m_container = new QMacCocoaViewContainer( 0, this);
     m_container->setAutoFillBackground( true );

     QVBoxLayout* vLayout= new QVBoxLayout(this);
     vLayout->setContentsMargins(0,0,0,0);


     vLayout->addWidget( m_container);
     setLayout(vLayout);

}
RenderWidget::~RenderWidget()
{

}


void* RenderWidget::drawableId() const
{
    VLCNSView*    m_video = [[VLCNSView alloc] init];
    m_container->setCocoaView(m_video);
    [m_video release];

    return (void*)m_video;

}


#endif
