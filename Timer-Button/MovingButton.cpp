#include <QtDebug>
//#include <QDebug>

#include "MovingButton.h"

#define TIMER_INTERVAL  500

#define DIRECTION_UP          0
#define DIRECTION_DOWN  1


MovingButton::MovingButton ()
    :QPushButton("MovButn"),
      m_x(100), m_y(100),
      m_direction(DIRECTION_DOWN)
{
          qDebug("%s()", __FUNCTION__);

    // Set the initial position
    this->move(m_x, m_y);

    // Setup the  QTimer instance.
    QTimer *m_timer = new QTimer(this);
    
    /* Connects QTimer's signal() to the MovingButton's slot moveButton(). */
    QObject::connect(m_timer, SIGNAL(timeout()),
                                   this, SLOT(moveButton()) );
                                   
    m_timer->start(TIMER_INTERVAL);
}

void MovingButton::moveButton()
{
      qDebug("--------%s()-------", __FUNCTION__);

      /* Increase the starting X-axis and Y-axis values. */
      if (m_direction == DIRECTION_DOWN)
      {
           m_x += 10;
           m_y += 10;
      }
      else if (m_direction == DIRECTION_UP)
      {
           m_x -= 10;
           m_y -= 10;
       }

      if (m_x == 300)
            m_direction = DIRECTION_UP;
      else  if (m_x == 100)
            m_direction = DIRECTION_DOWN;

     /* Update the latest starting position */
      m_butn_start_point.setX(m_x);
      m_butn_start_point.setY(m_y);

      /* Move to the new starting position */
      this->move(m_butn_start_point);
}
