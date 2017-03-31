#include "dialognb.h"
#include "ui_dialognb.h"
#include "nb.h"
#include <qstring.h>
#include <QFile>
#include <QTextCodec>
#include <QTextStream>
#include <QDebug>
#include <QPalette>

QVector<double> fossilData, correctData, errorData;

 int file_type = 0;
 int get_fileno = 1;
 bool dataset = false;
 bool banstopword = false;
 bool stem = false;
 bool legend_created = false;

 int hamfile_size = N/2;
 int spamfile_size = N/2;

DialogNB::DialogNB(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::DialogNB)
{
    ui->setupUi(this);
    ui->nb_type_ham->setChecked(true);
    ui->nb_type_spam->setChecked(false);
    int datasize = N;
    string s_datasize;
    IntToString(s_datasize, datasize);
    QString qs_datasize = QString::fromStdString(s_datasize);

    ui->nb_dataset_show->setText(qs_datasize);

    int trainfilenum = CHOOSE_N;
    string s_trainfilenum;
    IntToString(s_trainfilenum, trainfilenum);
    QString qs_trainfilenum = QString::fromStdString(s_trainfilenum);

    ui->nb_trainfilenum_show->setText("Random " + qs_trainfilenum);

    file_type = 0;

    ui->nb_stemmed_show->setText("N");

    ui->nb_fileno_range->setText("<= " + QString::number(setSpinBox(dataset, file_type), 10));

    legend_created = false;

    ui->nb_hamac_show->clear();
    ui->nb_spamac_show->clear();
    ui->nb_totalac_show->clear();
    ui->customPlot->clearItems();
    ui->customPlot->rescaleAxes();
    ui->customPlot->clearPlottables();
    ui->customPlot->replot();

    ui->customPlot->removePlottable(0);
    ui->customPlot->removePlottable(1);

    setupDemo(0,0,0,0,0,0);

    on_nb_getfile_clicked();



}

DialogNB::~DialogNB()
{
    delete ui;
}

int DialogNB::setSpinBox(bool dataset, int file_type){
    int max;
    if(dataset == false){
        ui->nb_fileno->setRange(1, N/2);
        max = N/2;
    }
    else if(dataset == true && file_type == 0){
        ui->nb_fileno->setRange(1, L_N_HAM);
        max = L_N_HAM;
    }
    else{
        ui->nb_fileno->setRange(1, L_N_SPAM);
        max = L_N_SPAM;
    }
    return max;
}


void DialogNB::on_nb_return_clicked()
{
    this->close();
}


void DialogNB::on_nb_type_spam_clicked()
{
    file_type = 1;
    ui->nb_fileno_range->setText("<= " + QString::number(setSpinBox(dataset, file_type), 10));
    ui->nb_classification_res_show->clear();
    ui->nb_classification_res_show2->clear();
    ui->nb_filecontext->clear();
    on_nb_getfile_clicked();
}
void DialogNB::on_nb_type_ham_clicked()
{
    file_type = 0;
     ui->nb_fileno_range->setText("<= " + QString::number(setSpinBox(dataset, file_type), 10));

    ui->nb_classification_res_show->clear();
    ui->nb_classification_res_show2->clear();
    ui->nb_filecontext->clear();
    on_nb_getfile_clicked();
}
void DialogNB::on_nb_getfile_clicked()
{
    get_fileno = ui->nb_fileno->text().toInt();
    dataset = ui->nb_dataset->checkState();
    stem = ui->nb_stem->checkState();
    string res = get_ui_testfile(file_type,stem,dataset,get_fileno);
    QString res_ = QString::fromStdString(res);
    //ui->nb_filecontext->setText(res_);
    QFile file(res_);
     QTextCodec * code = QTextCodec::codecForName("utf8");
    if(!file.open(QIODevice::ReadOnly)){
        qDebug() << "cant open" << endl;
        ui->nb_filecontext->setText("unable to open file :" + res_);
    }
    ui->nb_filecontext->setText("file not exist");
    QTextStream stream(&file);
    stream.setCodec(code);
    while (stream.atEnd() == 0) {
            ui->nb_filecontext->setText(stream.readAll());
     }



}

void DialogNB::setupDemo(int ham_correct, int ham_error, int spam_correct, int spam_error, int all_correct, int all_error)
{
  setupBarChartDemo(ui->customPlot,ham_correct,ham_error,spam_correct,spam_error,all_correct,all_error);
  setWindowTitle("QCustomPlot: "+demoName);
  ui->customPlot->replot();
}


void DialogNB::setupPlayground(QCustomPlot *customPlot)
{
  Q_UNUSED(customPlot)
}
void DialogNB::setupBarChartDemo(QCustomPlot *customPlot,int ham_correct, int ham_error, int spam_correct, int spam_error, int all_correct, int all_error)
{

  demoName = "Bar Chart Demo";
  QLinearGradient gradient(0, 0, 0, 400);
  gradient.setColorAt(0, QColor(90, 90, 90));
  gradient.setColorAt(0.38, QColor(105, 105, 105));
  gradient.setColorAt(1, QColor(70, 70, 70));
  customPlot->setBackground(QBrush(gradient));


  // create empty bar chart objects:
  QCPBars *error = new QCPBars(customPlot->xAxis, customPlot->yAxis);
  QCPBars *correct = new QCPBars(customPlot->xAxis, customPlot->yAxis);


  error->setAntialiased(false); // gives more crisp, pixel aligned bar borders
  correct->setAntialiased(false);

  error->setStackingGap(1);
  correct->setStackingGap(1);
  // set names and colors:
  correct->setName("correct");
  correct->setPen(QPen(QColor(0, 168, 140).lighter(130)));
  correct->setBrush(QColor(0, 168, 140));


  error->setName("error");
  error->setPen(QPen(QColor(250, 170, 20).lighter(150)));
  error->setBrush(QColor(250, 170, 20));

  // stack bars on top of each other:
  error->moveAbove(correct);

  // prepare x axis with country labels:
  QVector<double> ticks;
  QVector<QString> labels;
  ticks << 1 << 2 << 3;
  labels << "Ham" << "Spam" << "All";
  QSharedPointer<QCPAxisTickerText> textTicker(new QCPAxisTickerText);
  textTicker->addTicks(ticks, labels);
  customPlot->xAxis->setTicker(textTicker);
  customPlot->xAxis->setTickLabelRotation(60);
  customPlot->xAxis->setSubTicks(false);
  customPlot->xAxis->setTickLength(0, 4);
  customPlot->xAxis->setRange(0, 4);
  customPlot->xAxis->setBasePen(QPen(Qt::white));
  customPlot->xAxis->setTickPen(QPen(Qt::white));
  customPlot->xAxis->grid()->setVisible(true);
  customPlot->xAxis->grid()->setPen(QPen(QColor(130, 130, 130), 0, Qt::DotLine));
  customPlot->xAxis->setTickLabelColor(Qt::white);
  customPlot->xAxis->setLabelColor(Qt::white);

  // prepare y axis:
  if(dataset==false){
  customPlot->yAxis->setRange(0, 50);
  }
  else{
      customPlot->yAxis->setRange(0, 1200);
  }
  customPlot->yAxis->setPadding(5); // a bit more space to the left border
  customPlot->yAxis->setLabel("Test File Num");
  customPlot->yAxis->setBasePen(QPen(Qt::white));
  customPlot->yAxis->setTickPen(QPen(Qt::white));
  customPlot->yAxis->setSubTickPen(QPen(Qt::white));
  customPlot->yAxis->grid()->setSubGridVisible(true);
  customPlot->yAxis->setTickLabelColor(Qt::white);
  customPlot->yAxis->setLabelColor(Qt::white);
  customPlot->yAxis->grid()->setPen(QPen(QColor(130, 130, 130), 0, Qt::SolidLine));
  customPlot->yAxis->grid()->setSubGridPen(QPen(QColor(130, 130, 130), 0, Qt::DotLine));

  // Add data:
  correctData.clear();
  errorData.clear();
  correctData << ham_correct << spam_correct << all_correct;
  errorData   << ham_error << spam_error << all_error;
  correct->setData(ticks, correctData);
  error->setData(ticks, errorData);

  // setup legend:
  // if(legend_created == false){
    customPlot->legend->setVisible(true);
    customPlot->axisRect()->insetLayout()->setInsetAlignment(0, Qt::AlignTop | Qt::AlignRight);
    customPlot->legend->setBrush(QColor(255, 255, 255, 100));
    customPlot->legend->setBorderPen(Qt::NoPen);
    QFont legendFont = font();
    legendFont.setPointSize(10);
    customPlot->legend->setFont(legendFont);
    customPlot->setInteractions(QCP::iRangeDrag | QCP::iRangeZoom);



}

void DialogNB::on_nb_stem_clicked()
{
    stem = ui->nb_stem->checkState();
    if(stem == true){
        ui->nb_stemmed_show->setText("Y");
    }
    else{
        ui->nb_stemmed_show->setText("N");
    }

    ui->nb_hamac_show->clear();
    ui->nb_spamac_show->clear();
    ui->nb_totalac_show->clear();

    ui->nb_classification_res_show->clear();
    ui->nb_classification_res_show2->clear();
    ui->nb_filecontext->clear();
    on_nb_getfile_clicked();
    ui->customPlot->clearItems();
    ui->customPlot->rescaleAxes();
    ui->customPlot->clearPlottables();
    ui->customPlot->replot();

    ui->customPlot->removePlottable(0);
    ui->customPlot->removePlottable(1);
    setupDemo(0,0,0,0,0,0);
}

void DialogNB::on_nb_dataset_clicked()
{
    dataset = ui->nb_dataset->checkState();
    qDebug()  << dataset << endl;
    int datasize;
    string s_datasize;
    QString qs_datasize;

    int trainfilenum;
    string s_trainfilenum;
    QString qs_trainfilenum;
    if(dataset == true){
        datasize = L_N_HAM + L_N_SPAM;
        IntToString(s_datasize, datasize);
        qs_datasize = QString::fromStdString(s_datasize);

        ui->nb_dataset_show->setText(qs_datasize);

        trainfilenum = L_CHOOSE_N;
        IntToString(s_trainfilenum, trainfilenum);
        qs_trainfilenum = QString::fromStdString(s_trainfilenum);

        ui->nb_trainfilenum_show->setText("Random " + qs_trainfilenum);

        hamfile_size = L_N_HAM;
        spamfile_size = L_N_SPAM;


    }
    else{
        datasize = N;
        IntToString(s_datasize, datasize);
        qs_datasize = QString::fromStdString(s_datasize);

        ui->nb_dataset_show->setText(qs_datasize);

        trainfilenum = CHOOSE_N;
        IntToString(s_trainfilenum, trainfilenum);
        qs_trainfilenum = QString::fromStdString(s_trainfilenum);

        ui->nb_trainfilenum_show->setText("Random " + qs_trainfilenum);

        hamfile_size = N/2;
        spamfile_size = N/2;


    }

    ui->nb_hamac_show->clear();
    ui->nb_spamac_show->clear();
    ui->nb_totalac_show->clear();

    ui->nb_classification_res_show->clear();
    ui->nb_classification_res_show2->clear();
    ui->nb_filecontext->clear();
    on_nb_getfile_clicked();
    ui->nb_fileno_range->setText("<= " + QString::number(setSpinBox(dataset, file_type), 10));

    ui->customPlot->clearItems();
    ui->customPlot->rescaleAxes();
    ui->customPlot->clearPlottables();
    ui->customPlot->replot();

    ui->customPlot->removePlottable(0);
    ui->customPlot->removePlottable(1);
    setupDemo(0,0,0,0,0,0);
}

void DialogNB::on_nb_stopword_clicked()
{
    ui->nb_hamac_show->clear();
    ui->nb_spamac_show->clear();
    ui->nb_totalac_show->clear();
    banstopword = ui->nb_stopword->checkState();
    ui->customPlot->clearItems();
    ui->customPlot->rescaleAxes();
    ui->customPlot->clearPlottables();
    ui->customPlot->replot();

    ui->customPlot->removePlottable(0);
    ui->customPlot->removePlottable(1);
    setupDemo(0,0,0,0,0,0);
}

void DialogNB::on_nb_run_clicked()
{
    int get_choose_ham;
    int get_choose_spam;
    int get_error_ham;
    int get_error_spam;
    qDebug() << "run  " << dataset << endl;
    NaiveBayes(dataset,stem,banstopword,get_choose_ham,get_choose_spam,get_error_ham,get_error_spam);
    qDebug() << "get_choose_ham" << get_choose_ham << endl;
    qDebug() << "get_choose_spam" << get_choose_spam << endl;
    qDebug() << "get_error_ham" << get_error_ham << endl;
    qDebug() << "get_error_spam" << get_error_spam << endl;
    ui->customPlot->clearItems();
    ui->customPlot->rescaleAxes();
    ui->customPlot->clearPlottables();
    ui->customPlot->replot();

    ui->customPlot->removePlottable(0);
    ui->customPlot->removePlottable(1);
    setupDemo(hamfile_size - get_choose_ham-get_error_ham,get_error_ham,spamfile_size - get_choose_spam-get_error_spam,get_error_spam,hamfile_size + spamfile_size -get_choose_ham-get_error_ham - get_choose_spam-get_error_spam,get_error_ham+get_error_spam);

    bool classify_res = classify_single_file(dataset,get_fileno,file_type);

    double ham_accuracy = ((hamfile_size - get_choose_ham - get_error_ham) * 1.0  / (hamfile_size-get_choose_ham)) * 100;
    double spam_accuracy = ((spamfile_size - get_choose_spam - get_error_spam) * 1.0 / (spamfile_size-get_choose_spam)) * 100;
    double total_accuracy = ((hamfile_size + spamfile_size- get_choose_ham - get_choose_spam - get_error_ham - get_error_spam) * 1.0 / (hamfile_size + spamfile_size - get_choose_ham - get_choose_spam)) * 100;
    QString ham_accuracy_qs = QString::number(ham_accuracy,'g',3);
    QString Mole_ham = QString::number(hamfile_size - get_choose_ham - get_error_ham, 10);
    QString Deno_ham = QString::number(hamfile_size - get_choose_ham, 10);
    QString spam_accuracy_qs = QString::number(spam_accuracy,'g',3);
    QString Mole_spam = QString::number(spamfile_size - get_choose_spam - get_error_spam, 10);
    QString Deno_spam = QString::number(spamfile_size - get_choose_spam, 10);
    QString total_accuracy_qs = QString::number(total_accuracy,'g',3);
    QString Mole_total = QString::number(hamfile_size + spamfile_size - get_choose_ham - get_error_ham - get_choose_spam - get_error_spam, 10);
    QString Deno_total = QString::number(hamfile_size + spamfile_size - get_choose_ham - get_choose_spam, 10);

    ui->nb_hamac_show->setText(Mole_ham + "/" + Deno_ham + "(" + ham_accuracy_qs + "%)");
    ui->nb_spamac_show->setText(Mole_spam + "/" + Deno_spam + "(" + spam_accuracy_qs + "%)");
    ui->nb_totalac_show->setText(Mole_total + "/" + Deno_total + "(" + total_accuracy_qs + "%)");

    if(classify_res == false){
        if(file_type == 0){
            ui->nb_classification_res_show->setText("Spam");
        }
        else{
            ui->nb_classification_res_show->setText("Ham");
        }
        ui->nb_classification_res_show2->setText("Wrong");
        QPalette palette = ui->nb_classification_res_show2->palette();
        palette.setColor(QPalette::WindowText, QColor(Qt::red));
        ui->nb_classification_res_show2->setPalette(palette);
    }
    else{
        if(file_type == 0){
            ui->nb_classification_res_show->setText("Ham");
        }
        else{
            ui->nb_classification_res_show->setText("Spam");
        }
        ui->nb_classification_res_show2->setText("Correct");
        QPalette palette = ui->nb_classification_res_show2->palette();
        palette.setColor(QPalette::WindowText, QColor(Qt::green));
        ui->nb_classification_res_show2->setPalette(palette);
    }
    qDebug() << QString::number(get_fileno) << endl;
    qDebug() << "single file " << classify_res << endl;

}

void DialogNB::on_nb_fileno_valueChanged(const QString &arg1)
{
    get_fileno = ui->nb_fileno->text().toInt();
    ui->nb_classification_res_show->clear();
    ui->nb_classification_res_show2->clear();
    ui->nb_filecontext->clear();

    on_nb_getfile_clicked();

}
