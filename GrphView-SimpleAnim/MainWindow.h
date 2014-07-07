#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QGraphicsScene>
#include <QGraphicsView>
#include <QGraphicsRectItem>
#include <QTimeLine>

class MainWindow : public QMainWindow
{
    Q_OBJECT

private:
    QTimeLine m_timeLine;
    QGraphicsView *m_view;
    QGraphicsScene m_scene;
    QGraphicsRectItem *m_rect;

    int m_rect_x;    // rectangle start point's x-axis
    int m_rect_y;    // rectangle start point's y-axis
    qreal m_opacity;  // rectangle's opacity

public:
    MainWindow();

private slots:
    void animate(int frame);
};

#endif // MAINWINDOW_H
