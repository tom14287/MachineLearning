#ifndef DIALOGEM_H
#define DIALOGEM_H

#include <QDialog>

namespace Ui {
class DialogEM;
}

class DialogEM : public QDialog
{
    Q_OBJECT

public:
    explicit DialogEM(QWidget *parent = 0);
    ~DialogEM();

private slots:
    void on_em_return_clicked();

private:
    Ui::DialogEM *ui;
};

#endif // DIALOGEM_H
