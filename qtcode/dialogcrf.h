#ifndef DIALOGCRF_H
#define DIALOGCRF_H

#include <QDialog>
#include "crf.h"

namespace Ui {
class DialogCRF;
}

class DialogCRF : public QDialog
{
    Q_OBJECT

public:
    explicit DialogCRF(QWidget *parent = 0);
    ~DialogCRF();

private slots:
    void on_crf_strrun_clicked();

    void on_crf_return_clicked();

    void on_crf_strinput_textChanged();

    void on_crf_fileopen_clicked();

    void on_crf_filetest_clicked();

private:
    Ui::DialogCRF *ui;
};

#endif // DIALOGCRF_H
