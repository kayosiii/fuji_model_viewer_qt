#include "FujiWidget.h"


#include <QtGui/QLabel>
#include <QtGui/QMenu>
#include <QtGui/QMenuBar>
#include <QtGui/QAction>
#include <Fuji/MFSystem.h>
#include <Fuji/MFRenderer.h>
#include <QX11Info>
#ifdef Q_WS_X11
#include <X11/Xlib.h>
#endif

FujiWidget::FujiWidget() {
    setAttribute(Qt::WA_PaintOnScreen);
    MFInitParams initParams;
    MFZeroMemory(&initParams, sizeof(MFInitParams));
    MFRand_Seed((uint32)MFSystem_ReadRTC());
    loadModel("astro");

}

FujiWidget::~FujiWidget(){
  removeModel();
}

void FujiWidget::loadModel(char * modelname){
  removeModel();
  MFCALLSTACK;
  pmodel = MFModel_Create(modelname);
}

void FujiWidget::removeModel() {
  if (pmodel == NULL)return;
  MFModel_Destroy(pmodel);
  pmodel = NULL;
}

void FujiWidget::resizeEvent(QResizeEvent *ev ) {
    QWidget::resizeEvent(ev);
}
void FujiWidget::paintEvent(QPaintEvent* ev) {
#ifdef Q_WS_X11
    // Make sure we're not conflicting with drawing from the Qt library
    XSync(QX11Info::display(), FALSE);
#endif
    MFCALLSTACK;
    MFRenderer_SetClearColour(0.f, 0.f, 0.2f, 1.f);
    MFRenderer_ClearScreen();

}



#include "FujiWidget.moc"
