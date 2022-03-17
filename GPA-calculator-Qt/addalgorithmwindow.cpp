#include "addalgorithmwindow.h"
#include "ui_addalgorithmwindow.h"
#include<QFileDialog>
#include<QMessageBox>
AddAlgorithmWindow::AddAlgorithmWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::AddAlgorithmWindow)
{
    ui->setupUi(this);

    model->clear();
    ui->Table->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
    model->setHorizontalHeaderItem(0, new QStandardItem(QObject::tr("ScoreMin")));
    model->setHorizontalHeaderItem(1, new QStandardItem(QObject::tr("ScoreMax")));
    model->setHorizontalHeaderItem(2, new QStandardItem(QObject::tr("Point")));
    model->setHorizontalHeaderItem(3, new QStandardItem(QObject::tr("Grade")));
    ui->splitter_2->setStretchFactor(0,4);
    ui->splitter_2->setStretchFactor(1,1);

}



AddAlgorithmWindow::~AddAlgorithmWindow()
{
    delete ui;
}

void AddAlgorithmWindow::on_AddRow_clicked()
{
    int t=model->rowCount();
    model->setHorizontalHeaderItem(0, new QStandardItem(QObject::tr("ScoreMin")));
    model->setHorizontalHeaderItem(1, new QStandardItem(QObject::tr("ScoreMax")));
    model->setHorizontalHeaderItem(2, new QStandardItem(QObject::tr("Point")));
    model->setHorizontalHeaderItem(3, new QStandardItem(QObject::tr("Grade")));
    model->setItem(t,0,new QStandardItem(QString::number(ui->min->value())));
    model->setItem(t,1,new QStandardItem(QString::number(ui->max->value())));
    model->setItem(t,2,new QStandardItem(QString::number(ui->point->value())));
    model->setItem(t,3,new QStandardItem(ui->grade->currentText()));
    ui->Table->setModel(model);
}


void AddAlgorithmWindow::on_pushButton_2_clicked()
{
    model->removeRow(ui->Table->selectionModel()->currentIndex().row());
}


void AddAlgorithmWindow::on_pushButton_clicked()
{
    QString Address = QFileDialog::getSaveFileName(this, tr("Choose Output Position"), nullptr, tr("Transcript Files (*.txt)"));
    QFile file(Address);
    if(!file.open(QIODevice::WriteOnly | QIODevice::Text)){
        QMessageBox::about(NULL,  "Tips",  "Output Failed");
        return;
    }
    QByteArray bt;
    for(int i=0;i<model->rowCount();i++){
        bt.append(model->item(i,0)->text());
        bt.append(" ");
        bt.append(model->item(i,1)->text());
        bt.append(" ");
        bt.append(model->item(i,2)->text());
        bt.append(" ");
        bt.append(model->item(i,3)->text());
        bt.append("\n");
    }
    file.write(bt,bt.size());
    file.close();
}

