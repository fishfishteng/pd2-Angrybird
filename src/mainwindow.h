#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QGraphicsScene>
#include <QList>
#include <QDesktopWidget>
#include <QTimer>
#include <Box2D/Box2D.h>
#include <QMouseEvent>
#include <iostream>
#include <QMediaPlayer>

#include <gameitem.h>
#include <land.h>
#include <bird.h>
#include <blackbird.h>
#include <whitebird.h>
#include <yellowbird.h>
#include <pig.h>
#include <obstacle.h>
#include <catapult.h>
#include <background.h>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
    void showEvent(QShowEvent *);
    void Object();
    bool eventFilter(QObject *,QEvent *event);
    void closeEvent(QCloseEvent *);
signals:
    // Signal for closing the game
    void quitGame();

private slots:
    void tick();
    void NextBird();
    // For debug slot
    void QUITSLOT();

    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

private:
    Ui::MainWindow *ui;
    QGraphicsScene *scene;
    b2World *world;
    QMediaPlayer *music;
    QList<GameItem *> itemList;
    QList<Pig *> pigList;
    QList<Obstacle *> obstacleList;
    QList<Bird *> birdList;
    QList<Bird *> eggList;
    QTimer timer;
    QPoint press;
    QPoint release;

    int bird_num;
    bool flag;
};

#endif // MAINWINDOW_H
