#ifndef DIALOGHMM_H
#define DIALOGHMM_H

#include <QDialog>
#include <QString>
#include <QDebug>
#include "HMM.h"

namespace Ui {
class DialogHMM;
}

class DialogHMM : public QDialog
{
    Q_OBJECT

public:
    explicit DialogHMM(QWidget *parent = 0);
    ~DialogHMM();
    void show_wait();
    void loadfile(QString filename);

private slots:
    void on_hmm_return_clicked();

    void on_hmm_strrun_clicked();

    void on_hmm_setup_trainfile_clicked();

    void on_hmm_setup_data_clicked();

    void on_hmm_stopword_Y_clicked();

    void train_start();


    void on_hmm_strinput_textChanged();

    void on_hmm_fileopen_clicked();

    void on_hmm_filetest_clicked();

private:
    Ui::DialogHMM *ui;
};

#endif // DIALOGHMM_H
