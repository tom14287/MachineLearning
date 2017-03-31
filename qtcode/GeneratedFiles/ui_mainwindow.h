/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.7.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QFrame>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralWidget;
    QLabel *label_maintitle;
    QFrame *line_1;
    QFrame *line_2;
    QFrame *line_3;
    QLabel *label_NB;
    QLabel *label_EM;
    QPushButton *button_EM;
    QPushButton *button_NB;
    QLabel *label_orgnization;
    QLabel *label_creator;
    QLabel *label_NB_2;
    QLabel *label_NB_3;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(1124, 683);
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        label_maintitle = new QLabel(centralWidget);
        label_maintitle->setObjectName(QStringLiteral("label_maintitle"));
        label_maintitle->setGeometry(QRect(0, 0, 1124, 71));
        QFont font;
        font.setFamily(QStringLiteral("Agency FB"));
        font.setPointSize(48);
        font.setBold(true);
        font.setWeight(75);
        label_maintitle->setFont(font);
        label_maintitle->setMouseTracking(false);
        label_maintitle->setLayoutDirection(Qt::LeftToRight);
        label_maintitle->setAutoFillBackground(false);
        label_maintitle->setStyleSheet(QLatin1String("background-color: rgb(0, 0, 0);\n"
"color: rgb(255, 255, 255);"));
        label_maintitle->setFrameShadow(QFrame::Raised);
        label_maintitle->setAlignment(Qt::AlignBottom|Qt::AlignHCenter);
        line_1 = new QFrame(centralWidget);
        line_1->setObjectName(QStringLiteral("line_1"));
        line_1->setGeometry(QRect(0, 70, 1124, 31));
        line_1->setFrameShape(QFrame::HLine);
        line_1->setFrameShadow(QFrame::Sunken);
        line_2 = new QFrame(centralWidget);
        line_2->setObjectName(QStringLiteral("line_2"));
        line_2->setGeometry(QRect(0, 160, 1124, 31));
        line_2->setFrameShape(QFrame::HLine);
        line_2->setFrameShadow(QFrame::Sunken);
        line_3 = new QFrame(centralWidget);
        line_3->setObjectName(QStringLiteral("line_3"));
        line_3->setGeometry(QRect(0, 250, 1124, 31));
        line_3->setFrameShape(QFrame::HLine);
        line_3->setFrameShadow(QFrame::Sunken);
        label_NB = new QLabel(centralWidget);
        label_NB->setObjectName(QStringLiteral("label_NB"));
        label_NB->setGeometry(QRect(20, 90, 201, 41));
        QFont font1;
        font1.setFamily(QStringLiteral("Agency FB"));
        font1.setPointSize(28);
        font1.setBold(true);
        font1.setItalic(false);
        font1.setWeight(75);
        label_NB->setFont(font1);
        label_NB->setStyleSheet(QStringLiteral(""));
        label_EM = new QLabel(centralWidget);
        label_EM->setObjectName(QStringLiteral("label_EM"));
        label_EM->setGeometry(QRect(20, 180, 201, 51));
        QFont font2;
        font2.setFamily(QStringLiteral("Agency FB"));
        font2.setPointSize(28);
        font2.setBold(true);
        font2.setWeight(75);
        label_EM->setFont(font2);
        button_EM = new QPushButton(centralWidget);
        button_EM->setObjectName(QStringLiteral("button_EM"));
        button_EM->setGeometry(QRect(0, 177, 1124, 85));
        button_EM->setStyleSheet(QStringLiteral("color: rgb(255, 255, 255);"));
        button_NB = new QPushButton(centralWidget);
        button_NB->setObjectName(QStringLiteral("button_NB"));
        button_NB->setGeometry(QRect(0, 87, 1124, 85));
        button_NB->setStyleSheet(QStringLiteral("color: rgb(255, 255, 255);"));
        label_orgnization = new QLabel(centralWidget);
        label_orgnization->setObjectName(QStringLiteral("label_orgnization"));
        label_orgnization->setGeometry(QRect(1040, 20, 91, 41));
        QFont font3;
        font3.setFamily(QStringLiteral("Agency FB"));
        font3.setPointSize(12);
        font3.setBold(true);
        font3.setWeight(75);
        label_orgnization->setFont(font3);
        label_orgnization->setStyleSheet(QStringLiteral("color: rgb(255, 255, 255);"));
        label_orgnization->setFrameShadow(QFrame::Raised);
        label_orgnization->setLineWidth(2);
        label_orgnization->setTextFormat(Qt::RichText);
        label_orgnization->setAlignment(Qt::AlignCenter);
        label_creator = new QLabel(centralWidget);
        label_creator->setObjectName(QStringLiteral("label_creator"));
        label_creator->setGeometry(QRect(1050, 40, 81, 41));
        QFont font4;
        font4.setFamily(QString::fromUtf8("\345\256\213\344\275\223"));
        font4.setPointSize(11);
        font4.setBold(false);
        font4.setWeight(50);
        label_creator->setFont(font4);
        label_creator->setStyleSheet(QStringLiteral("color: rgb(255, 255, 255);"));
        label_creator->setFrameShadow(QFrame::Raised);
        label_creator->setLineWidth(2);
        label_creator->setTextFormat(Qt::RichText);
        label_creator->setAlignment(Qt::AlignCenter);
        label_NB_2 = new QLabel(centralWidget);
        label_NB_2->setObjectName(QStringLiteral("label_NB_2"));
        label_NB_2->setGeometry(QRect(20, 130, 201, 41));
        QFont font5;
        font5.setFamily(QStringLiteral("Arial"));
        font5.setPointSize(18);
        font5.setBold(false);
        font5.setItalic(false);
        font5.setWeight(50);
        label_NB_2->setFont(font5);
        label_NB_2->setStyleSheet(QStringLiteral(""));
        label_NB_3 = new QLabel(centralWidget);
        label_NB_3->setObjectName(QStringLiteral("label_NB_3"));
        label_NB_3->setGeometry(QRect(20, 220, 351, 41));
        label_NB_3->setFont(font5);
        label_NB_3->setStyleSheet(QStringLiteral(""));
        MainWindow->setCentralWidget(centralWidget);
        button_NB->raise();
        button_EM->raise();
        label_maintitle->raise();
        line_1->raise();
        line_2->raise();
        line_3->raise();
        label_NB->raise();
        label_EM->raise();
        label_orgnization->raise();
        label_creator->raise();
        label_NB_2->raise();
        label_NB_3->raise();

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "MainWindow", 0));
        label_maintitle->setText(QApplication::translate("MainWindow", "Machine Learning", 0));
        label_NB->setText(QApplication::translate("MainWindow", "Naive Bayes", 0));
        label_EM->setText(QApplication::translate("MainWindow", "E-M Algorithm", 0));
        button_EM->setText(QString());
        button_NB->setText(QString());
        label_orgnization->setText(QApplication::translate("MainWindow", "Fudan-14CS", 0));
        label_creator->setText(QApplication::translate("MainWindow", "\346\210\264\345\230\211\346\266\246", 0));
        label_NB_2->setText(QApplication::translate("MainWindow", "Spam Filtering", 0));
        label_NB_3->setText(QApplication::translate("MainWindow", "Multi-label classification ", 0));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
