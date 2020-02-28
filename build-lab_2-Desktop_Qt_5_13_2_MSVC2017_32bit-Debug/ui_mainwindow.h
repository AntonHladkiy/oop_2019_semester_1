/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.13.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtGui/QIcon>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QStackedWidget>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTimeEdit>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QListWidget *listWidget;
    QWidget *verticalLayoutWidget;
    QVBoxLayout *verticalLayout;
    QComboBox *comboBox;
    QStackedWidget *stackedWidget_timers;
    QWidget *page_3;
    QHBoxLayout *horizontalLayout_2;
    QGroupBox *groupBox;
    QVBoxLayout *verticalLayout_3;
    QTimeEdit *timeEdit_timer;
    QHBoxLayout *horizontalLayout;
    QRadioButton *sound_btn_1_1;
    QRadioButton *sound_btn_1_2;
    QPushButton *timer_add;
    QPushButton *timer_delete;
    QWidget *page_4;
    QVBoxLayout *verticalLayout_2;
    QGroupBox *groupBox_2;
    QVBoxLayout *verticalLayout_4;
    QTimeEdit *timeEdit_alarm;
    QHBoxLayout *horizontalLayout_4;
    QRadioButton *sound_btn_2_1;
    QRadioButton *sound_btn_2_2;
    QPushButton *alarm_add;
    QPushButton *alarm_delete;
    QStackedWidget *stackedWidget_buttons;
    QWidget *page;
    QPushButton *start_btn;
    QWidget *page_2;
    QPushButton *stop_btn;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(800, 600);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        listWidget = new QListWidget(centralwidget);
        listWidget->setObjectName(QString::fromUtf8("listWidget"));
        listWidget->setGeometry(QRect(30, 30, 311, 411));
        verticalLayoutWidget = new QWidget(centralwidget);
        verticalLayoutWidget->setObjectName(QString::fromUtf8("verticalLayoutWidget"));
        verticalLayoutWidget->setGeometry(QRect(360, 30, 388, 371));
        verticalLayout = new QVBoxLayout(verticalLayoutWidget);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        comboBox = new QComboBox(verticalLayoutWidget);
        comboBox->setObjectName(QString::fromUtf8("comboBox"));

        verticalLayout->addWidget(comboBox);

        stackedWidget_timers = new QStackedWidget(verticalLayoutWidget);
        stackedWidget_timers->setObjectName(QString::fromUtf8("stackedWidget_timers"));
        page_3 = new QWidget();
        page_3->setObjectName(QString::fromUtf8("page_3"));
        horizontalLayout_2 = new QHBoxLayout(page_3);
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        groupBox = new QGroupBox(page_3);
        groupBox->setObjectName(QString::fromUtf8("groupBox"));
        verticalLayout_3 = new QVBoxLayout(groupBox);
        verticalLayout_3->setObjectName(QString::fromUtf8("verticalLayout_3"));
        timeEdit_timer = new QTimeEdit(groupBox);
        timeEdit_timer->setObjectName(QString::fromUtf8("timeEdit_timer"));
        timeEdit_timer->setButtonSymbols(QAbstractSpinBox::NoButtons);

        verticalLayout_3->addWidget(timeEdit_timer);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        sound_btn_1_1 = new QRadioButton(groupBox);
        sound_btn_1_1->setObjectName(QString::fromUtf8("sound_btn_1_1"));
        sound_btn_1_1->setChecked(true);

        horizontalLayout->addWidget(sound_btn_1_1);

        sound_btn_1_2 = new QRadioButton(groupBox);
        sound_btn_1_2->setObjectName(QString::fromUtf8("sound_btn_1_2"));

        horizontalLayout->addWidget(sound_btn_1_2);


        verticalLayout_3->addLayout(horizontalLayout);

        timer_add = new QPushButton(groupBox);
        timer_add->setObjectName(QString::fromUtf8("timer_add"));

        verticalLayout_3->addWidget(timer_add);

        timer_delete = new QPushButton(groupBox);
        timer_delete->setObjectName(QString::fromUtf8("timer_delete"));

        verticalLayout_3->addWidget(timer_delete);


        horizontalLayout_2->addWidget(groupBox);

        stackedWidget_timers->addWidget(page_3);
        page_4 = new QWidget();
        page_4->setObjectName(QString::fromUtf8("page_4"));
        verticalLayout_2 = new QVBoxLayout(page_4);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        groupBox_2 = new QGroupBox(page_4);
        groupBox_2->setObjectName(QString::fromUtf8("groupBox_2"));
        verticalLayout_4 = new QVBoxLayout(groupBox_2);
        verticalLayout_4->setObjectName(QString::fromUtf8("verticalLayout_4"));
        timeEdit_alarm = new QTimeEdit(groupBox_2);
        timeEdit_alarm->setObjectName(QString::fromUtf8("timeEdit_alarm"));
        timeEdit_alarm->setButtonSymbols(QAbstractSpinBox::NoButtons);
        timeEdit_alarm->setTime(QTime(0, 0, 0));

        verticalLayout_4->addWidget(timeEdit_alarm);

        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setObjectName(QString::fromUtf8("horizontalLayout_4"));
        sound_btn_2_1 = new QRadioButton(groupBox_2);
        sound_btn_2_1->setObjectName(QString::fromUtf8("sound_btn_2_1"));
        sound_btn_2_1->setChecked(true);

        horizontalLayout_4->addWidget(sound_btn_2_1);

        sound_btn_2_2 = new QRadioButton(groupBox_2);
        sound_btn_2_2->setObjectName(QString::fromUtf8("sound_btn_2_2"));

        horizontalLayout_4->addWidget(sound_btn_2_2);


        verticalLayout_4->addLayout(horizontalLayout_4);

        alarm_add = new QPushButton(groupBox_2);
        alarm_add->setObjectName(QString::fromUtf8("alarm_add"));

        verticalLayout_4->addWidget(alarm_add);

        alarm_delete = new QPushButton(groupBox_2);
        alarm_delete->setObjectName(QString::fromUtf8("alarm_delete"));

        verticalLayout_4->addWidget(alarm_delete);


        verticalLayout_2->addWidget(groupBox_2);

        stackedWidget_timers->addWidget(page_4);

        verticalLayout->addWidget(stackedWidget_timers);

        stackedWidget_buttons = new QStackedWidget(centralwidget);
        stackedWidget_buttons->setObjectName(QString::fromUtf8("stackedWidget_buttons"));
        stackedWidget_buttons->setGeometry(QRect(260, 470, 80, 80));
        page = new QWidget();
        page->setObjectName(QString::fromUtf8("page"));
        start_btn = new QPushButton(page);
        start_btn->setObjectName(QString::fromUtf8("start_btn"));
        start_btn->setEnabled(true);
        start_btn->setGeometry(QRect(0, 0, 80, 80));
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/<qresource>/images/play.png"), QSize(), QIcon::Normal, QIcon::Off);
        start_btn->setIcon(icon);
        start_btn->setIconSize(QSize(80, 80));
        stackedWidget_buttons->addWidget(page);
        page_2 = new QWidget();
        page_2->setObjectName(QString::fromUtf8("page_2"));
        stop_btn = new QPushButton(page_2);
        stop_btn->setObjectName(QString::fromUtf8("stop_btn"));
        stop_btn->setEnabled(true);
        stop_btn->setGeometry(QRect(0, 0, 80, 80));
        QIcon icon1;
        icon1.addFile(QString::fromUtf8(":/<qresource>/images/stop.png"), QSize(), QIcon::Normal, QIcon::Off);
        stop_btn->setIcon(icon1);
        stop_btn->setIconSize(QSize(80, 80));
        stop_btn->setCheckable(false);
        stackedWidget_buttons->addWidget(page_2);
        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 800, 26));
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        MainWindow->setStatusBar(statusbar);

        retranslateUi(MainWindow);

        stackedWidget_timers->setCurrentIndex(0);
        stackedWidget_buttons->setCurrentIndex(1);


        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        groupBox->setTitle(QString());
        sound_btn_1_1->setText(QCoreApplication::translate("MainWindow", "Cuckoo bird", nullptr));
        sound_btn_1_2->setText(QCoreApplication::translate("MainWindow", "Twin bell", nullptr));
        timer_add->setText(QCoreApplication::translate("MainWindow", "Add timer", nullptr));
        timer_delete->setText(QCoreApplication::translate("MainWindow", "Delete timer", nullptr));
        groupBox_2->setTitle(QString());
        sound_btn_2_1->setText(QCoreApplication::translate("MainWindow", "Cuckoo bird", nullptr));
        sound_btn_2_2->setText(QCoreApplication::translate("MainWindow", "Twin bell", nullptr));
        alarm_add->setText(QCoreApplication::translate("MainWindow", "Add alarm", nullptr));
        alarm_delete->setText(QCoreApplication::translate("MainWindow", "Delete alarm", nullptr));
        start_btn->setText(QString());
        stop_btn->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
