#include "dialogcrf.h"
#include "ui_dialogcrf.h"
#include <QFile>
#include <QDir>
#include <QMessageBox>
#include <QFileDialog>
#include <QTextStream>
#include <QDebug>

DialogCRF::DialogCRF(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::DialogCRF)
{
    ui->setupUi(this);

    ui->crf_strinput->setText("这是一个基于CRF的中文分词器.");
    QString get_str_qs = ui->crf_strinput->toPlainText();
    wstring get_str_ws = get_str_qs.toStdWString();
    string get_str_s = wstr2str_(get_str_ws);
    string get_res_s = teststr(get_str_s,"model_pku");
    wstring get_res_ws = str2wstr_(get_res_s);
    QString get_res_qs = QString::fromStdWString(get_res_ws);
    ui->crf_strres->setText(get_res_qs);
}

DialogCRF::~DialogCRF()
{
    delete ui;
}

void DialogCRF::on_crf_strrun_clicked()
{
    QString get_str_qs = ui->crf_strinput->toPlainText();
    wstring get_str_ws = get_str_qs.toStdWString();
    string get_str_s = wstr2str_(get_str_ws);
    string get_res_s = teststr(get_str_s,"model_pku");
    wstring get_res_ws = str2wstr_(get_res_s);
    QString get_res_qs = QString::fromStdWString(get_res_ws);
    ui->crf_strres->setText(get_res_qs);
    qDebug() << get_str_qs<< endl;
}

void DialogCRF::on_crf_return_clicked()
{
    this->close();
}

void DialogCRF::on_crf_strinput_textChanged()
{
   /* if(ui->crf_strinput->toPlainText().toStdString().length() > 0){
        on_crf_strrun_clicked();
    }
    else{
        ui->crf_strres->clear();
    }*/
}

void DialogCRF::on_crf_fileopen_clicked()
{
    ui->crf_filepath->clear();
    QString filepath = QFileDialog::getOpenFileName(NULL, tr("Open Txt"), QDir::currentPath(), tr("Text Files (*.txt)"), 0);
    if(!filepath.isEmpty()){
        ui->crf_filepath->setText(filepath);
    }

    ui->crf_fileres->clear();
}

void DialogCRF::on_crf_filetest_clicked()
{
    if(!ui->crf_filepath->text().isEmpty()){
        wstring filepath_ws = ui->crf_filepath->text().toStdWString();
        string filepath_s = wstr2str_(filepath_ws);
        ui_testfile("",filepath_s);
        string filepath_s_new = "testfile_res.txt in the same Dir";
        wstring filepath_ws_new = str2wstr_(filepath_s_new);
        QString filepath_new = QString::fromStdWString(filepath_ws_new);
        ui->crf_fileres->setText(filepath_new);
    }
    else{
        ui->crf_fileres->setText("file path empty");
    }
}
