#ifndef MOVINGBUTTON_H
#define MOVINGBUTTON_H

#include  <QWidget>
#include  <QString>
#include <QPushButton>
#include <QPoint>
#include <QTimer>

class MovingButton : public QPushButton {
     Q_OBJECT

public:
     MovingButton ();

private:
      int m_x;
      int m_y;
      QRect m_butn_geometry;
      QPoint m_butn_start_point;
      char m_direction;

private slots:
     void moveButton();
};

#endif // MOVINGBUTTON_H
