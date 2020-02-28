#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QMessageBox>
#include <vector>
#include "timers.h"
QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private:
    Ui::MainWindow *ui;
    QTimer *tmr;
    QTime *time;
    std::vector<Timers*> timers;
private slots:
        void updateTime();
        void on_comboBox_currentIndexChanged(int index);
        void on_stop_btn_clicked();
        void on_start_btn_clicked();
        void on_alarm_add_clicked();
        void on_timer_add_clicked();
};
#endif // MAINWINDOW_H
