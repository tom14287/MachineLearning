/********************************************************************************
** Form generated from reading UI file 'dialogem.ui'
**
** Created by: Qt User Interface Compiler version 5.7.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DIALOGEM_H
#define UI_DIALOGEM_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>

QT_BEGIN_NAMESPACE

class Ui_DialogEM
{
public:
    QLabel *label_EM;
    QPushButton *em_return;

    void setupUi(QDialog *DialogEM)
    {
        if (DialogEM->objectName().isEmpty())
            DialogEM->setObjectName(QStringLiteral("DialogEM"));
        DialogEM->resize(1124, 683);
        QFont font;
        font.setFamily(QStringLiteral("Arial"));
        font.setPointSize(14);
        font.setBold(false);
        font.setWeight(50);
        DialogEM->setFont(font);
        label_EM = new QLabel(DialogEM);
        label_EM->setObjectName(QStringLiteral("label_EM"));
        label_EM->setGeometry(QRect(0, 0, 1124, 71));
        QFont font1;
        font1.setFamily(QStringLiteral("Agency FB"));
        font1.setPointSize(48);
        font1.setBold(true);
        font1.setWeight(75);
        label_EM->setFont(font1);
        label_EM->setMouseTracking(false);
        label_EM->setLayoutDirection(Qt::LeftToRight);
        label_EM->setAutoFillBackground(false);
        label_EM->setStyleSheet(QLatin1String("background-color: rgb(0, 0, 0);\n"
"color: rgb(255, 255, 255);"));
        label_EM->setFrameShadow(QFrame::Raised);
        label_EM->setAlignment(Qt::AlignBottom|Qt::AlignHCenter);
        em_return = new QPushButton(DialogEM);
        em_return->setObjectName(QStringLiteral("em_return"));
        em_return->setGeometry(QRect(1030, 630, 91, 51));

        retranslateUi(DialogEM);

        QMetaObject::connectSlotsByName(DialogEM);
    } // setupUi

    void retranslateUi(QDialog *DialogEM)
    {
        DialogEM->setWindowTitle(QApplication::translate("DialogEM", "Dialog", 0));
        label_EM->setText(QApplication::translate("DialogEM", "E-M Algorithm", 0));
        em_return->setText(QApplication::translate("DialogEM", "Return", 0));
    } // retranslateUi

};

namespace Ui {
    class DialogEM: public Ui_DialogEM {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DIALOGEM_H
