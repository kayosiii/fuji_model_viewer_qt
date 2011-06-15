#include <QtGui/QApplication>
#include "FujiModelViewer_qt.h"
#include <Fuji/Fuji.h>
#include <Fuji/MFModel.h>
#include <Fuji/MFFileSystem.h>
#include "FujiWidget.h"

MFModel *pmodel;
  // MFSystemCallbackFunction pInitFujiFS = NULL;

int main(int argc, char** argv)
{
    QApplication app(argc, argv);
    FujiModelViewer_qt foo;
    foo.show();
    return app.exec();
}
