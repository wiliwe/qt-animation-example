#include <QApplication>
#include "MainWindow.h"

int main (int argc, char* argv[])
{
   QApplication app(argc, argv);

   MainWindow mainWin;
   mainWin.resize (QSize(600, 600));
   mainWin.show();

   return app.exec();
}
