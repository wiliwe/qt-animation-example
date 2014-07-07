/***************************************************************************
 *
 *  Timeline-Porgressbar
 *
 ***************************************************************************/

#include "mainwin.h"

MainWin::MainWin (QWidget*p, Qt::WFlags f)
    :QWidget (p)
{
        //setFixedSize (200,50);
	
        // Create a QProgressBar instance.
        progressBar = new QProgressBar (this);
        progressBar->setRange (0, 100);
        progressBar->setFixedSize (150, 50);

        // Construct a 1-second timeline with a frame range of 0 - 100
        timeline = new QTimeLine (1000, this);    // Total duration of the timeline in milliseconds.
                                                                           // Here is 1000 ms, e.g. 1 seconds

        timeline->setFrameRange (0, 100);    // Set the start and end frame
        //timeline->setUpdateInterval (40);    // Set the interval to update current time.
        //timeline->setLoopCount (0);    // Set the number of times the timeline should loop before it's finished ; 0 means loop forever.
        timeline->setCurveShape (QTimeLine::LinearCurve);    // Set the velocity changing of timeline

        // Connect QTimeLine's frameChanged() signal to a slot, here is QProgressBar's setValue() method.
        connect ( timeline, SIGNAL(frameChanged(int)),
                       progressBar, SLOT(setValue(int)) );

        timeline->start();
}

void MainWin::connectAppQuitSlot (void)
{
      // To connect QTimeline's finished() signal to QApplication's quti() slot,
     //  e.g. when timeline finish its work, the application will be terminated.
      connect (timeline, SIGNAL(finished()),
                    app, SLOT(quit()));
 }
