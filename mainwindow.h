#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "sceneseats.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    void resizeEvent(QResizeEvent* event);
    SceneSeats *currentSeats;
private slots:
    void on_bookTime_userTimeChanged(const QTime &time);

    void on_bookCalendar_selectionChanged();

private:
    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H
