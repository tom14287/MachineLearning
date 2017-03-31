#include "dialogem.h"
#include "ui_dialogem.h"

DialogEM::DialogEM(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::DialogEM)
{
    ui->setupUi(this);
}

DialogEM::~DialogEM()
{
    delete ui;
}

void DialogEM::on_em_return_clicked()
{
    this->close();
}
