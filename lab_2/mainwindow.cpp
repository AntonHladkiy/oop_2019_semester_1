#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "iostream"
#include <QTimer>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    tmr = new QTimer(this);
    connect(tmr, SIGNAL(timeout()), this, SLOT(updateTime()));
    tmr->start(1000);
    ui->comboBox->addItem(QString("Timers"));
    ui->comboBox->addItem(QString("Alarms"));
    ui->stackedWidget_buttons->setCurrentIndex(0);
    ui->start_btn->setDisabled(true);
    ui->stop_btn->setDisabled(true);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::updateTime()
{
    for(size_t i=0;i<timers.size();i++){
        if(timers[i]->is_active){
            //*timers[i]->time=timers[i]->time->addSecs(-1);
            ui->listWidget->item(i)->setText(timers[i]->time->toString());
            if(*timers[i]->time == QTime(0,0,0))
            QMessageBox::information(this,tr("Time is out"),tr("Wake up"));
        }
    }
}


void MainWindow::on_comboBox_currentIndexChanged(int index)
{
ui->stackedWidget_timers->setCurrentIndex(index);
}

void MainWindow::on_stop_btn_clicked()
{
    ui->stackedWidget_buttons->setCurrentIndex(0);
}

void MainWindow::on_start_btn_clicked()
{
     ui->stackedWidget_buttons->setCurrentIndex(1);
}

void MainWindow::on_alarm_add_clicked()
{
    QMediaPlayer* music=new QMediaPlayer();
    if(ui->sound_btn_2_1->isChecked()){
        music->setMedia(QUrl("qrc:/qresource/sounds/Cuckoo-bird-sound.mp3"));
    } else{
        music->setMedia(QUrl("qrc:/qresource/sounds/Twin-bell-alarm.mp3"));
    }
    QTime temp=ui->timeEdit_alarm->time();
 Timers* tmr=new Timers(&temp,false,music);
  timers.push_back(tmr);
}

void MainWindow::on_timer_add_clicked()
{
    QMediaPlayer* music=new QMediaPlayer();
    if(ui->sound_btn_1_1->isChecked()){
        music->setMedia(QUrl("qrc:/qresource/sounds/Cuckoo-bird-sound.mp3"));
    } else{
        music->setMedia(QUrl("qrc:/qresource/sounds/Twin-bell-alarm.mp3"));
    }
    QTime temp=ui->timeEdit_timer->time();
 Timers* timer=new Timers(&temp,true,music);
 timers.push_back(timer);
ui->listWidget->addItem(timer->time->toString());
}
