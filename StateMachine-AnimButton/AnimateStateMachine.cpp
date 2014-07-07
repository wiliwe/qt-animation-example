#include <QApplication>
#include <QPushButton>
#include <QStateMachine>
#include <QState>
#include <QFinalState>
#include <QSignalTransition>
#include <QPropertyAnimation>

int main(int argc,char *argv[])
{
   QApplication app(argc,argv);
 
    // Create a widget to be animated.
   QPushButton *button = new QPushButton("Animated Button");
   button->show();

   /* Set state machine's states */
   QStateMachine *machine = new QStateMachine;  // Create a state machine.
   QState *state1 = new QState(machine);
   state1->assignProperty(button, "geometry", QRect(200, 100, 150, 30));

   QState *state2 = new QState(machine);
   state2->assignProperty(button, "geometry", QRect(450, 450, 150, 50));

   QState *state3 = new QState(machine);
   state3->assignProperty(button, "geometry", QRect(700, 100, 150, 30));  //Here it will enlarge the button widget.

    machine->setInitialState(state1);

   QFinalState *state4 = new QFinalState(machine);    /* The final state. */

   /* Set the state transition animations. */
   QSignalTransition *transition1 = state1->addTransition(button, SIGNAL(clicked()), state2);
   transition1->addAnimation(new QPropertyAnimation(button, "geometry"));

   QSignalTransition *transition2 = state2->addTransition(button, SIGNAL(clicked()), state3);
   transition2->addAnimation(new QPropertyAnimation(button,"geometry"));

   QSignalTransition *transition3 = state3->addTransition(button, SIGNAL(clicked()), state4);
   transition3->addAnimation(new QPropertyAnimation(button,"geometry"));

   /* Connects the signal finished() from the state machine to the quit() slot
     from the QApplication. So the application is going to quit when the state
     machine will be finished. */
   QObject::connect(machine, SIGNAL(finished()),
                                QApplication::instance(), SLOT(quit()));

   machine->start();
   return app.exec();
}
