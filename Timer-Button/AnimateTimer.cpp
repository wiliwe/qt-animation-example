#include <QApplication>

#include "MovingButton.h"

int main(int argc,char *argv[])
{
   QApplication app(argc,argv);

    // Create a widget to be animated.
   MovingButton *movingButton = new MovingButton();
   movingButton->show();

   return app.exec();
}
