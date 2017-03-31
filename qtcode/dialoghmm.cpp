#include "dialoghmm.h"
#include "ui_dialoghmm.h"
#include <QFile>
#include <QDir>
#include <QMessageBox>
#include <QFileDialog>
#include <QTextStream>

bool hmm_use_stopword;
int hmm_model_choose;
DialogHMM::DialogHMM(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::DialogHMM)
{
    ui->setupUi(this);
    hmm_use_stopword = true;
    hmm_model_choose = MODEL_FROM_DATA;
    load_stopword();
    setup_HMM_model_data();
    ui->hmm_strinput->setText("这是一个基于HMM的中文分词Demo.");
    QString get_str_qs = ui->hmm_strinput->toPlainText();
    wstring get_str_ws = get_str_qs.toStdWString();
    string get_str_s = wstr2str(get_str_ws);
    string get_res_s = HMM_teststr(get_str_s,hmm_use_stopword,hmm_model_choose);
    wstring get_res_ws = str2wstr(get_res_s);
    QString get_res_qs = QString::fromStdWString(get_res_ws);
    ui->hmm_strres->setText(get_res_qs);
    ui->hmm_strrun->hide();
}

DialogHMM::~DialogHMM()
{
    delete ui;
}
void DialogHMM::show_wait()
{
     ui->hmm_setupmodel_wait->show();
}

void DialogHMM::on_hmm_return_clicked()
{
    this->close();
}

void DialogHMM::on_hmm_strrun_clicked()
{
    QString get_str_qs = ui->hmm_strinput->toPlainText();
    wstring get_str_ws = get_str_qs.toStdWString();
    string get_str_s = wstr2str(get_str_ws);
    string get_res_s = HMM_teststr(get_str_s,hmm_use_stopword,hmm_model_choose);
    wstring get_res_ws = str2wstr(get_res_s);
    QString get_res_qs = QString::fromStdWString(get_res_ws);
    ui->hmm_strres->setText(get_res_qs);
    qDebug() << get_str_qs<< endl;

}

void DialogHMM::on_hmm_setup_trainfile_clicked()
{
    hmm_model_choose = MODEL_FROM_TRAINFILE;
    setup_HMM_model_train("", "pku_training.txt");
    ui->hmm_setupmodel_wait->clear();
    if(ui->hmm_strinput->toPlainText().toStdString().length() > 0){
        on_hmm_strrun_clicked();
    }
}

void DialogHMM::on_hmm_setup_data_clicked()
{
    hmm_model_choose = MODEL_FROM_DATA;
    setup_HMM_model_data();
    if(ui->hmm_strinput->toPlainText().toStdString().length() > 0){
        on_hmm_strrun_clicked();
    }
}

void DialogHMM::on_hmm_stopword_Y_clicked()
{
    hmm_use_stopword = !hmm_use_stopword;
    if(hmm_use_stopword == true){
        load_stopword();
    }
    if(ui->hmm_strinput->toPlainText().toStdString().length() > 0){
        on_hmm_strrun_clicked();
    }
}
void DialogHMM::train_start(){
    //ui->hmm_setupmodel_wait->show();
}


void DialogHMM::on_hmm_strinput_textChanged()
{
    if(ui->hmm_strinput->toPlainText().toStdString().length() > 0){
        on_hmm_strrun_clicked();
    }
    else{
        ui->hmm_strres->clear();
    }
}

void DialogHMM::on_hmm_fileopen_clicked()
{
    ui->hmm_filepath->clear();
    QString filepath = QFileDialog::getOpenFileName(NULL, tr("Open Txt"), QDir::currentPath(), tr("Text Files (*.txt)"), 0);
    if(!filepath.isEmpty()){
        ui->hmm_filepath->setText(filepath);
    }

    ui->hmm_fileres->clear();

}


void DialogHMM::loadfile(QString filename){
    QFile file(filename);
    if(file.open(QIODevice::ReadOnly | QIODevice::Text)){
        QTextStream textstream(&file);
        while(!textstream.atEnd()){
            printf("read line\n");
        }
    }
}


void DialogHMM::on_hmm_filetest_clicked()
{
    if(!ui->hmm_filepath->text().isEmpty()){
        wstring filepath_ws = ui->hmm_filepath->text().toStdWString();
        string filepath_s = wstr2str(filepath_ws);
        HMM_testfile("",filepath_s,hmm_use_stopword,hmm_model_choose);
        string filepath_s_new = filepath_s.substr(0,filepath_s.length()-4) + "_new.txt";
        wstring filepath_ws_new = str2wstr(filepath_s_new);
        QString filepath_new = QString::fromStdWString(filepath_ws_new);
        ui->hmm_fileres->setText(filepath_new);
    }
    else{
        ui->hmm_fileres->setText("file path empty");
    }
}
