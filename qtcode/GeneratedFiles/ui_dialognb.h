/********************************************************************************
** Form generated from reading UI file 'dialognb.ui'
**
** Created by: Qt User Interface Compiler version 5.7.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DIALOGNB_H
#define UI_DIALOGNB_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QScrollBar>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QTextBrowser>

QT_BEGIN_NAMESPACE

class Ui_DialogNB
{
public:
    QLabel *label_NB;
    QPushButton *nb_return;
    QTextBrowser *textBrowser;
    QScrollBar *verticalScrollBar;
    QLabel *label;
    QLabel *label_2;
    QPushButton *pushButton;
    QLabel *label_3;
    QCheckBox *nb_stem;
    QCheckBox *nb_largedataset;
    QLabel *label_4;
    QRadioButton *radioButton;
    QRadioButton *radioButton_2;
    QSpinBox *spinBox;

    void setupUi(QDialog *DialogNB)
    {
        if (DialogNB->objectName().isEmpty())
            DialogNB->setObjectName(QStringLiteral("DialogNB"));
        DialogNB->resize(1124, 683);
        QFont font;
        font.setFamily(QStringLiteral("Agency FB"));
        font.setPointSize(16);
        font.setBold(true);
        font.setWeight(75);
        DialogNB->setFont(font);
        label_NB = new QLabel(DialogNB);
        label_NB->setObjectName(QStringLiteral("label_NB"));
        label_NB->setGeometry(QRect(0, 0, 1124, 71));
        QFont font1;
        font1.setFamily(QStringLiteral("Agency FB"));
        font1.setPointSize(48);
        font1.setBold(true);
        font1.setWeight(75);
        label_NB->setFont(font1);
        label_NB->setMouseTracking(false);
        label_NB->setLayoutDirection(Qt::LeftToRight);
        label_NB->setAutoFillBackground(false);
        label_NB->setStyleSheet(QLatin1String("background-color: rgb(0, 0, 0);\n"
"color: rgb(255, 255, 255);"));
        label_NB->setFrameShadow(QFrame::Raised);
        label_NB->setAlignment(Qt::AlignBottom|Qt::AlignHCenter);
        nb_return = new QPushButton(DialogNB);
        nb_return->setObjectName(QStringLiteral("nb_return"));
        nb_return->setGeometry(QRect(1030, 630, 91, 51));
        QFont font2;
        font2.setFamily(QStringLiteral("Arial"));
        font2.setPointSize(14);
        nb_return->setFont(font2);
        textBrowser = new QTextBrowser(DialogNB);
        textBrowser->setObjectName(QStringLiteral("textBrowser"));
        textBrowser->setGeometry(QRect(40, 170, 601, 411));
        verticalScrollBar = new QScrollBar(DialogNB);
        verticalScrollBar->setObjectName(QStringLiteral("verticalScrollBar"));
        verticalScrollBar->setGeometry(QRect(620, 170, 20, 411));
        verticalScrollBar->setOrientation(Qt::Vertical);
        label = new QLabel(DialogNB);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(40, 135, 81, 21));
        label->setFont(font);
        label_2 = new QLabel(DialogNB);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setGeometry(QRect(200, 135, 41, 21));
        label_2->setFont(font);
        pushButton = new QPushButton(DialogNB);
        pushButton->setObjectName(QStringLiteral("pushButton"));
        pushButton->setGeometry(QRect(550, 135, 75, 23));
        label_3 = new QLabel(DialogNB);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setGeometry(QRect(270, 130, 91, 31));
        label_3->setFont(font);
        nb_stem = new QCheckBox(DialogNB);
        nb_stem->setObjectName(QStringLiteral("nb_stem"));
        nb_stem->setGeometry(QRect(240, 140, 21, 16));
        nb_largedataset = new QCheckBox(DialogNB);
        nb_largedataset->setObjectName(QStringLiteral("nb_largedataset"));
        nb_largedataset->setGeometry(QRect(360, 140, 21, 16));
        label_4 = new QLabel(DialogNB);
        label_4->setObjectName(QStringLiteral("label_4"));
        label_4->setGeometry(QRect(390, 130, 41, 31));
        label_4->setFont(font);
        radioButton = new QRadioButton(DialogNB);
        radioButton->setObjectName(QStringLiteral("radioButton"));
        radioButton->setGeometry(QRect(430, 130, 61, 31));
        radioButton_2 = new QRadioButton(DialogNB);
        radioButton_2->setObjectName(QStringLiteral("radioButton_2"));
        radioButton_2->setGeometry(QRect(490, 130, 61, 31));
        spinBox = new QSpinBox(DialogNB);
        spinBox->setObjectName(QStringLiteral("spinBox"));
        spinBox->setGeometry(QRect(120, 131, 61, 31));
        label_3->raise();
        label->raise();
        label_2->raise();
        label_NB->raise();
        nb_return->raise();
        textBrowser->raise();
        verticalScrollBar->raise();
        pushButton->raise();
        nb_stem->raise();
        nb_largedataset->raise();
        label_4->raise();
        radioButton->raise();
        radioButton_2->raise();
        spinBox->raise();

        retranslateUi(DialogNB);

        QMetaObject::connectSlotsByName(DialogNB);
    } // setupUi

    void retranslateUi(QDialog *DialogNB)
    {
        DialogNB->setWindowTitle(QApplication::translate("DialogNB", "Dialog", 0));
        label_NB->setText(QApplication::translate("DialogNB", "Naive Bayes", 0));
        nb_return->setText(QApplication::translate("DialogNB", "Return", 0));
        label->setText(QApplication::translate("DialogNB", "Test File No:", 0));
        label_2->setText(QApplication::translate("DialogNB", "Stem:", 0));
        pushButton->setText(QApplication::translate("DialogNB", "Get", 0));
        label_3->setText(QApplication::translate("DialogNB", "LargeDataSet:", 0));
        nb_stem->setText(QString());
        nb_largedataset->setText(QString());
        label_4->setText(QApplication::translate("DialogNB", "Type:", 0));
        radioButton->setText(QApplication::translate("DialogNB", "Spam", 0));
        radioButton_2->setText(QApplication::translate("DialogNB", "Ham", 0));
    } // retranslateUi

};

namespace Ui {
    class DialogNB: public Ui_DialogNB {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DIALOGNB_H
