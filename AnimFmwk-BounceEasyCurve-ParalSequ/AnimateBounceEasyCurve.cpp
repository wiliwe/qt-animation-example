#include <QApplication>
#include <QPushButton>
#include <QPropertyAnimation>
#include <QEasingCurve>
#include <QParallelAnimationGroup>
#include <QSequentialAnimationGroup>
#include <QRect>

int main(int argc, char* argv[])
{
 QApplication app(argc, argv);
 
 QPushButton *button = new QPushButton("Animated Button");
 button->show();

 QPropertyAnimation animation(button, "geometry");
 animation.setDuration(3000);  // 3 seconds
 animation.setStartValue(QRect(250, 250, 100, 30));
 animation.setEndValue(QRect(500, 500, 100, 30));
 animation.setEasingCurve(QEasingCurve::OutInQuint);
 // animation.start();
 
 QPushButton button2("Animated Button -2 ");
 button2.show();
 QPropertyAnimation animation2(&button2, "geometry");
 animation2.setDuration(5000);  // 5 seconds
 animation2.setStartValue(QRect(100, 100, 100, 30));
 animation2.setEndValue(QRect(350, 450, 100, 30));
 animation2.setEasingCurve(QEasingCurve::OutInQuart);
 // animation2.start();
 
 // Construct a parallel animation containg "animation" and "animation2"
 QParallelAnimationGroup *animgroupPara = new QParallelAnimationGroup;
 animgroupPara->addAnimation(&animation);
 animgroupPara->addAnimation(&animation2);
 //animgroup->start();

 QPushButton button3("Animated Button -3 ");
 button3.show();
 QPropertyAnimation animation3(&button3, "geometry");
 animation3.setDuration(2000);   // 2 seconds
 animation3.setStartValue(QRect(100, 200, 100, 30));
 animation3.setEndValue(QRect(300, 500, 100, 30));
 animation3.setEasingCurve(QEasingCurve::OutInBounce);
 // animation3.start();
 
 // Construct a sequential animation conating "parallel animation" and "animation3"
 QSequentialAnimationGroup animgroupSeq;
 animgroupSeq.addAnimation(&animation3);
 animgroupSeq.addAnimation(animgroupPara);
 animgroupSeq.start();
 
 return app.exec();
}
