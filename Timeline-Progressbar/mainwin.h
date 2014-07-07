/***************************************************************************
 *
 *  Timeline-Porgressbar
 *
 ***************************************************************************/

#ifndef LABEL_H
#define LABEL_H

#include <QWidget>
#include <QApplication>
#include <QProgressBar>
#include <QTimeLine>

class MainWin: public QWidget
{
Q_OBJECT

public:
	MainWin(QWidget*p = NULL, Qt::WFlags f = 0);

private:
        QProgressBar *progressBar;
        QTimeLine  *timeline;
        QApplication *app;

public:
        void setAppHandle(QApplication *appMain) { app = appMain; }
        void connectAppQuitSlot(void);
};

#endif
