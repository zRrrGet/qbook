#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "ClickableQPixmap.h"
#include "authdialog.h"
#include "RecordScene.h"
#include <QGraphicsPixmapItem>
#include <QDebug>
#include <QResizeEvent>

#define occupiedpm ":\\assets\\freeSeat.jpg" // дефайны путей для картинок со свободным и занятым местами
#define freepm ":\\assets\\occupiedSeat.jpg"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);


    AuthDialog *auth = new AuthDialog;  // авторизация пользователя
    auth->setWindowTitle("Авторизация");
    auth->exec();

    QString username = auth->gotUserName;  // получение имени авторизованного пользователя
    auth->deleteLater();

    if (auth->gotUserName == "") exit(0); // если логин не успешный - закрываем программу

    // Устанавливаем сцену(RecordScene - наследник QGraphicsScene с модицифорованными полями, определение в RecordScene.h)
    ui->bookView->setScene(new RecordScene(new QGraphicsScene(), username));
    ui->bookView->scene()->addPixmap(QPixmap(":\\assets\\emptyScene.jpg")); // ставим задний фон


    setWindowTitle("Добро пожаловать, "+username);

    // создаем объект, который работает с местами на сцене
    currentSeats = new SceneSeats(ui->bookView, ui->bookCalendar, ui->bookTime);
    // downcast и добавление только что созданного объекта в сцену
    ((RecordScene *)(ui->bookView->scene()))->setSceneSeats(currentSeats);

    // показываем главное окно и сцену
    show();
    ui->bookView->show();
    ui->bookView->viewport()->update();

    // задаем размеры сцены в соответствии с view(чтобы убрать привязанное соотношение сторон можно поставить Qt::IgnoreAspectRatio)
    ui->bookView->fitInView(ui->bookView->scene()->sceneRect(), Qt::KeepAspectRatio);

    ui->bookTime->setTime(QTime(QTime::currentTime().hour()+1,0));

}



MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::resizeEvent(QResizeEvent *event)
{
    // Данная функция вызывается каждый раз, когда меняется размер окна. Подгоняет размер сцены под view
    ui->bookView->fitInView(ui->bookView->scene()->sceneRect(), Qt::KeepAspectRatio);
    delete event;
}

void MainWindow::on_bookTime_userTimeChanged(const QTime &time)
{
    // меняется установленное в поле время - обновляем места на сцене
    currentSeats->updateSeats();
}

void MainWindow::on_bookCalendar_selectionChanged()
{
    // то же с датой на календаре
    currentSeats->updateSeats();
}
