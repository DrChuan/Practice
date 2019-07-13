/********************************************************************************
** Form generated from reading UI file 'MagicalTower.ui'
**
** Created by: Qt User Interface Compiler version 5.13.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAGICALTOWER_H
#define UI_MAGICALTOWER_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MagicalTowerClass
{
public:
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QWidget *centralWidget;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MagicalTowerClass)
    {
        if (MagicalTowerClass->objectName().isEmpty())
            MagicalTowerClass->setObjectName(QString::fromUtf8("MagicalTowerClass"));
        MagicalTowerClass->resize(600, 400);
        menuBar = new QMenuBar(MagicalTowerClass);
        menuBar->setObjectName(QString::fromUtf8("menuBar"));
        MagicalTowerClass->setMenuBar(menuBar);
        mainToolBar = new QToolBar(MagicalTowerClass);
        mainToolBar->setObjectName(QString::fromUtf8("mainToolBar"));
        MagicalTowerClass->addToolBar(mainToolBar);
        centralWidget = new QWidget(MagicalTowerClass);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        MagicalTowerClass->setCentralWidget(centralWidget);
        statusBar = new QStatusBar(MagicalTowerClass);
        statusBar->setObjectName(QString::fromUtf8("statusBar"));
        MagicalTowerClass->setStatusBar(statusBar);

        retranslateUi(MagicalTowerClass);

        QMetaObject::connectSlotsByName(MagicalTowerClass);
    } // setupUi

    void retranslateUi(QMainWindow *MagicalTowerClass)
    {
        MagicalTowerClass->setWindowTitle(QCoreApplication::translate("MagicalTowerClass", "MagicalTower", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MagicalTowerClass: public Ui_MagicalTowerClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAGICALTOWER_H
