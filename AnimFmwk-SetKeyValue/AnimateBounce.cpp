#include <QApplication>
#include <QPushButton>
#include <QPropertyAnimation>
#include <QRect>

int main(int argc, char* argv[])
{
 QApplication app(argc, argv);
 
 QPushButton *button = new QPushButton("Animated Button");
 //button->move(250, 250); // Set the initial postion
 button->show();

 QPropertyAnimation animation(button, "geometry"); // Create an animation
 animation.setDuration(10000); // Set the animating duration

 animation.setKeyValueAt(0, QRect(250, 250, 100, 30));
 animation.setKeyValueAt(0.25, QRect(250, 450, 100, 30));
 animation.setKeyValueAt(0.5, QRect(500, 450, 100, 30));
 animation.setKeyValueAt(0.75, QRect(500, 250, 100, 30));
 animation.setKeyValueAt(1, QRect(250, 250, 100, 30));

 animation.start();

 app.exec();
}
