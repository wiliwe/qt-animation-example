#include <QGraphicsItem>
#include <QGraphicsLineItem>
#include <QSize>
#include <QPen>
#include <QDebug>

#include "MainWindow.h"

#define START_X 20
#define START_Y 20
#define MOVE_INCREMENT 1

MainWindow::MainWindow() {
  /* Create a  pen object for the line item. */
  QPen pen;
  pen.setStyle(Qt::DashDotLine); // use dash-do-line style : "-.--"
  pen.setWidth(3);
  pen.setBrush(Qt::green);  // use Green color
  pen.setCapStyle(Qt::RoundCap);  // set round style of  end points of line.

  m_view = new QGraphicsView(this);
  this->setCentralWidget(m_view); // Add the view object into main window.

  QObject::connect(&m_timeLine, SIGNAL(frameChanged(int)), this, SLOT(animate(int)));
  m_timeLine.setDuration(5000);  // 5 seconds
  m_timeLine.setFrameRange(0, 100);
  m_timeLine.setCurveShape(QTimeLine::LinearCurve); // set the velocity change mode of animation

  m_scene.addText("Hello, world!")->setPos(5.0, 5.0);  // Create a Text item.
  QGraphicsLineItem *line = m_scene.addLine(10, 90, 250, 250, pen);   // Create a Line item.

  m_rect_x = START_X;
  m_rect_y = START_Y;
  m_rect = m_scene.addRect(QRectF(m_rect_x, m_rect_y, 50, 50));    // Create a Rectangle item.

   /* Create a brush object to paint the Rectangle item. */
  QBrush brush;
  brush.setColor(Qt::darkGray);
  brush.setStyle(Qt::SolidPattern);
  m_rect->setBrush(brush);

  /* Set the Rectangle's opacity */
  m_opacity = 1;
  m_rect->setOpacity(m_opacity);

  m_view->setScene(&m_scene);  // Add scene into the view object

  m_timeLine.start();
}

/* To animate the Rectangle item to move and fade-out. */
void MainWindow::animate (int frame) {
  qDebug("%s()", __FUNCTION__);

  m_rect_x += MOVE_INCREMENT;
  m_rect_y += MOVE_INCREMENT;

  m_rect->setPos(m_rect_x, m_rect_y);

  m_opacity -= 0.01;
  m_rect->setOpacity(m_opacity);
}
