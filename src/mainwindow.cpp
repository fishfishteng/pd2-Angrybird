#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    // Enable the event Filter
    qApp->installEventFilter(this);

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::showEvent(QShowEvent *)
{
    // Setting the QGraphicsScene
    scene = new QGraphicsScene(0,0,width()-2,ui->graphicsView->height()-2);
    ui->graphicsView->setScene(scene);


    // Create world
    world = new b2World(b2Vec2(0.0f, -9.8f));

    // Setting Size
    GameItem::setGlobalSize(QSizeF(32,18),size());

    //Set background
    Background *background = new Background(0.0f,0.0f,QPixmap(":/bg.png").scaled(height()*2,height()),world,scene);
    itemList.push_back(background);

    // Create ground (You can edit here)
    Land *land = new Land(16,1.5,32,3,QPixmap(":/land.png").scaled(width(),height()/6),world,scene);
    itemList.push_back(land);

    //Create a catapult
    Catapult *catapult = new Catapult(12.0f,5.0f,QPixmap(":/catapult.png").scaled(height()/5.2,height()/3.7),world,scene);
    itemList.push_back(catapult);

    //Create animals and obstacles
    Object();

    // Setting the Velocity
    //birdList[0]->setLinearVelocity(b2Vec2(10,8));

    // Timer
    connect(&timer,SIGNAL(timeout()),this,SLOT(tick()));
    connect(this,SIGNAL(quitGame()),this,SLOT(QUITSLOT()));
    timer.start(100/6);
}

void MainWindow::Object(){

    bird_num = 0;
    flag = true;
    ui->label_3->hide();

    //play the background music
    music = new QMediaPlayer();
    music->setMedia(QUrl("qrc:/Angry Birds Theme Song HD.mp3"));
    music->play();

    //Create pigs
    Pig *pig1 = new Pig(16.5f,7.0f,0.3f,&timer,QPixmap(":/pig4.png").scaled(height()/9.0,height()/9.0),world,scene);
    Pig *pig2 = new Pig(19.5f,7.0f,0.3f,&timer,QPixmap(":/pig2.png").scaled(height()/9.0,height()/9.0),world,scene);
    Pig *pig3 = new Pig(22.5f,13.0f,0.3f,&timer,QPixmap(":/pig5.png").scaled(height()/9.0,height()/9.0),world,scene);
    Pig *pig4 = new Pig(25.5f,7.0f,0.3f,&timer,QPixmap(":/pig6.png").scaled(height()/9.0,height()/9.0),world,scene);
    pigList.push_back(pig1);
    pigList.push_back(pig2);
    pigList.push_back(pig3);
    pigList.push_back(pig4);

    //Create obstacles
    Obstacle *wood1 = new Obstacle(22.0f,10.0f,1.4f,1.4f,&timer,QPixmap(":/wood1.png").scaled(height()/6.1,height()/6.1),world,scene);
    Obstacle *wood2 = new Obstacle(22.0f,7.0f,1.4f,1.4f,&timer,QPixmap(":/wood1.png").scaled(height()/6.1,height()/6.1),world,scene);
    obstacleList.push_back(wood1);
    obstacleList.push_back(wood2);


    // Create birds
    Bird *birdie = new Bird(5.0f,7.0f,0.27f,&timer,QPixmap(":/red.png").scaled(height()/9.0,height()/9.0),world,scene);
    Bird *black = new BlackBird(7.0f,7.0f,0.27f,&timer,QPixmap(":/black.png").scaled(height()/9.0,height()/9.0),world,scene);
    Bird *white = new WhiteBird(9.0f,7.0f,0.3f,&timer,QPixmap(":/white.png").scaled(height()/9.0,height()/9.0),world,scene);
    Bird *yellow = new YellowBird(11.0f,7.0f,0.27f,&timer,QPixmap(":/yellow.png").scaled(height()/9.0,height()/9.0),world,scene);
    birdList.push_back(birdie);
    birdList[bird_num]->ReadyToShoot(birdList[bird_num]);
    birdList.push_back(black);
    birdList.push_back(white);
    birdList.push_back(yellow);

}

void MainWindow::NextBird()
{
    delete birdList[bird_num];
    birdList[bird_num] = NULL;
    flag = true;
    if(bird_num < 3)
    {
    bird_num++;
    birdList[bird_num]->ready = false;
    birdList[bird_num]->shoot = false;
    birdList[bird_num]->ReadyToShoot(birdList[bird_num]);
    }
}

bool MainWindow::eventFilter(QObject *, QEvent *event)
{
    // Hint: Notice the Number of every event!
    QMouseEvent *keyEvent = static_cast<QMouseEvent *>(event);

    if(event->type() == QEvent::MouseButtonPress)
    {
        /* TODO : add your code here */
        //std::cout << "Press !" << std::endl ;

        if(!flag){
            birdList[bird_num]->SuperPower();
            if(bird_num == 2)
            {
                Bird *egg1 = new Bird(2.0f,21.0f,0.1f,&timer,QPixmap(":/egg1.png").scaled(height()/15.0,height()/10.0),world,scene);
                Bird *egg2 = new Bird(4.0f,22.0f,0.1f,&timer,QPixmap(":/egg2.png").scaled(height()/15.0,height()/10.0),world,scene);
                Bird *egg3 = new Bird(6.0f,23.0f,0.1f,&timer,QPixmap(":/egg3.png").scaled(height()/15.0,height()/10.0),world,scene);
                Bird *egg4 = new Bird(8.0f,24.0f,0.1f,&timer,QPixmap(":/egg4.png").scaled(height()/15.0,height()/10.0),world,scene);
                Bird *egg5 = new Bird(10.0f,25.0f,0.1f,&timer,QPixmap(":/egg5.png").scaled(height()/15.0,height()/10.0),world,scene);
                eggList.push_back(egg1);
                eggList.push_back(egg2);
                eggList.push_back(egg3);
                eggList.push_back(egg4);
                eggList.push_back(egg5);
                eggList[0]->setLinearVelocity(b2Vec2(50,-50));
                eggList[1]->setLinearVelocity(b2Vec2(50,-50));
                eggList[2]->setLinearVelocity(b2Vec2(50,-50));
                eggList[3]->setLinearVelocity(b2Vec2(50,-50));
                eggList[4]->setLinearVelocity(b2Vec2(50,-50));

            }
            if(bird_num == 3)
            {
                ui->label_3->show();
            }
            flag = true;
        }
        if(110 < keyEvent->x() && keyEvent->x()< 205 && 360 < keyEvent->y() && keyEvent->y() < 460)
        if(flag){
            press.setX(keyEvent->x());
            press.setY(keyEvent->y());
            birdList[bird_num]->ready = true;
        }
    }
    if(event->type() == QEvent::MouseMove)
    {
        /* TODO : add your code here */
        //std::cout << "Move !" << std::endl ;
           if(birdList[bird_num]->ready && !birdList[bird_num]->shoot && flag == true)
           {
               float x = 3.0 - ((press.x()-keyEvent->x())/40.0);
               float y = 8.5 + ((press.y()-keyEvent->y())/40.0);
               birdList[bird_num]->g_body->SetTransform(b2Vec2(x,y),0);
           }
    }
    if(event->type() == QEvent::MouseButtonRelease)
    {
        /* TODO : add your code here */
        //std::cout << "Release !" << std::endl ;
        if(birdList[bird_num]->ready && !birdList[bird_num]->shoot && flag == true)
        {
            birdList[bird_num]->shoot = true;
            flag = false;
            if(bird_num == 0)
                flag = true;
            release.setX(keyEvent->x());
            release.setY(keyEvent->y());
            birdList[bird_num]->g_body->SetType(b2_dynamicBody);
            birdList[bird_num]->setLinearVelocity(b2Vec2((press.x()-release.x())/10.0,-(press.y()-release.y())/10.0));

            if(bird_num < 3)
                QTimer::singleShot(4000, this, SLOT(NextBird()));
            /*connect(&delaytime,SIGNAL(timeout()),this,SLOT(NextBird()));
            delaytime.start(6000);
            if(timer.isActive()){
                std::cout<<"Delay time up"<<std::endl;
                delaytime.stop();
            }*/
        }
    }
    return false;
}

void MainWindow::closeEvent(QCloseEvent *)
{
    // Close event
    emit quitGame();
}

void MainWindow::tick()
{
    world->Step(1.0/60.0,6,2);
    scene->update();
}

void MainWindow::QUITSLOT()
{
    // For debug
    //std::cout << "Quit Game Signal receive !" << std::endl ;
}

void MainWindow::on_pushButton_clicked()
{

    //delete pigs
    delete pigList[0];
    delete pigList[1];
    delete pigList[2];
    delete pigList[3];
    pigList[0] = NULL;
    pigList[1] = NULL;
    pigList[2] = NULL;
    pigList[3] = NULL;
    pigList.clear();

    //delete obstacles
    delete obstacleList[0];
    delete obstacleList[1];
    obstacleList[0] = NULL;
    obstacleList[1] = NULL;
    obstacleList.clear();

    //delete birds
    delete birdList[0];
    delete birdList[1];
    delete birdList[2];
    delete birdList[3];
    birdList[0] = NULL;
    birdList[1] = NULL;
    birdList[2] = NULL;
    birdList[3] = NULL;
    birdList.clear();

    //delete eggs
    if(bird_num >= 2){
    delete eggList[0];
    delete eggList[1];
    delete eggList[2];
    delete eggList[3];
    delete eggList[4];
    eggList[0] = NULL;
    eggList[1] = NULL;
    eggList[2] = NULL;
    eggList[3] = NULL;
    eggList[4] = NULL;
    eggList.clear();
    }

    bird_num = 0;

    //stop the background music
    music->stop();

    //create the objects again
    Object();
}

void MainWindow::on_pushButton_2_clicked()
{
    emit quitGame();
    close();
}
