#ifndef FujiWidget_H
#define FujiWidget_H

#include <QtGui/QMainWindow>
#include <Fuji/Fuji.h>
#include <Fuji/MFModel.h>

class FujiWidget : public QWidget
{
Q_OBJECT
public:
    FujiWidget();
    virtual ~FujiWidget();
    void loadModel(char *);
    void removeModel();
protected:
  void resizeEvent(QResizeEvent *);
  void paintEvent(QPaintEvent *);
private:
  MFModel *pmodel;
};

#endif // FujiWidget_H
