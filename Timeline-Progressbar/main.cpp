/***************************************************************************
 *
 *  Timeline-Porgressbar
 *
 ***************************************************************************/

#ifdef HAVE_CONFIG_H
#include <config.h>
#endif

#include "mainwin.h"

int main(int argc, char *argv[])
{
    QApplication app (argc,argv);

    MainWin* mw = new MainWin ();
    mw->setAppHandle (&app);  // pass the QApplication instance into MainWin.
    mw->connectAppQuitSlot ();
    mw->setGeometry (250, 250, 150, 100);
    mw->show ();

  return app.exec ();
}
