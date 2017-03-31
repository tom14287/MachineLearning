#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QTimer>
#include "dialogem.h"
#include "dialognb.h"
#include "dialoghmm.h"
#include "dialogcrf.h"
#include "common.h"
#include "stopword.h"
#include "nb.h"


namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();


private slots:
    void on_button_NB_clicked();

    void on_button_EM_clicked();

    void on_button_NB_2_clicked();

    void on_button_CRF_clicked();

private:
    Ui::MainWindow *ui;

    DialogEM dialogem;
    DialogNB dialognb;
    DialogHMM dialoghmm;
    DialogCRF dialogcrf;


};

#endif // MAINWINDOW_H
