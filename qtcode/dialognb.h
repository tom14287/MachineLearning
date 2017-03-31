#ifndef DIALOGNB_H
#define DIALOGNB_H

#include <qcustomplot.h>
#include <QDialog>

namespace Ui {
class DialogNB;
}

class DialogNB : public QDialog
{
    Q_OBJECT

public:
    explicit DialogNB(QWidget *parent = 0);
    ~DialogNB();
    int setSpinBox(bool dataset, int file_type);
    void setupDemo(int ham_correct, int ham_error, int spam_correct, int spam_error, int all_correct, int all_error);
    void setupPlayground(QCustomPlot *customPlot);
    void setupBarChartDemo(QCustomPlot *customPlot,int ham_correct, int ham_error, int spam_correct, int spam_error, int all_correct, int all_error);
//    void on_nb_getfile_clicked();

private slots:
    void on_nb_return_clicked();

    void on_nb_type_spam_clicked();

    void on_nb_getfile_clicked();

    void on_nb_type_ham_clicked();

    void on_nb_stem_clicked();

    void on_nb_dataset_clicked();

    void on_nb_stopword_clicked();

    void on_nb_run_clicked();

    void on_nb_fileno_valueChanged(const QString &arg1);

private:
    Ui::DialogNB *ui;
    QString demoName;
    QTimer dataTimer;
    QCPItemTracer *itemDemoPhaseTracer;


};

#endif // DIALOGNB_H
