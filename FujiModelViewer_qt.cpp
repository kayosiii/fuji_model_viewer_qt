#include "FujiModelViewer_qt.h"

#include <QtGui/QLabel>
#include <QtGui/QMenu>
#include <QtGui/QMenuBar>
#include <QtGui/QAction>

FujiModelViewer_qt::FujiModelViewer_qt()
{
    QLabel* l = new QLabel( this );
    l->setText( "Hello World!" );
    setCentralWidget( l );
    QAction* a = new QAction(this);
    a->setText( "Quit" );
    connect(a, SIGNAL(triggered()), SLOT(close()) );
    menuBar()->addMenu( "File" )->addAction( a );
}

FujiModelViewer_qt::~FujiModelViewer_qt()
{}

#include "FujiModelViewer_qt.moc"
