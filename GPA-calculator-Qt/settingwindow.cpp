#include "settingwindow.h"
#include "ui_settingwindow.h"

SettingWindow::SettingWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::SettingWindow)
{
    ui->setupUi(this);
    box.push_back(ui->doubleSpinBox);
    box.push_back(ui->doubleSpinBox_2);
    box.push_back(ui->doubleSpinBox_3);
    box.push_back(ui->doubleSpinBox_4);
    box.push_back(ui->doubleSpinBox_5);
    box.push_back(ui->doubleSpinBox_6);
    box.push_back(ui->doubleSpinBox_7);
    box.push_back(ui->doubleSpinBox_8);
    box.push_back(ui->doubleSpinBox_9);
    box.push_back(ui->doubleSpinBox_10);
    box.push_back(ui->doubleSpinBox_11);
    box.push_back(ui->doubleSpinBox_12);
    box.push_back(ui->doubleSpinBox_13);
    box.push_back(ui->doubleSpinBox_14);
    box.push_back(ui->doubleSpinBox_15);
    lable.push_back(ui->label);
    lable.push_back(ui->label_2);
    lable.push_back(ui->label_3);
    lable.push_back(ui->label_4);
    lable.push_back(ui->label_5);
    lable.push_back(ui->label_6);
    lable.push_back(ui->label_7);
    lable.push_back(ui->label_8);
    lable.push_back(ui->label_9);
    lable.push_back(ui->label_10);
    lable.push_back(ui->label_11);
    lable.push_back(ui->label_12);
    lable.push_back(ui->label_13);
    lable.push_back(ui->label_14);
    lable.push_back(ui->label_15);

    QFile file(QDir::currentPath()+"/settings.txt");
    if(!file.open(QIODevice::ReadWrite )){
        QMessageBox::about(NULL,  "Tips",  "Open txt Failed");
        return;
    }

    QTextStream in(&file);
    while (!in.atEnd()) {
        double a;QString b;
        in>>a;
        in>>b;
        r.push_back(QPair<double,QString>(a,b));
    }
    if(r.size()!=15)return;
    for(int i=0;i<15;i++){
        box[i]->setValue(r[i].first);
    }
    file.close();


}

SettingWindow::~SettingWindow()
{
    delete ui;
}

void SettingWindow::on_pushButton_clicked()
{
    QFile file(QDir::currentPath()+"/settings.txt");
    if(!file.open(QIODevice::ReadWrite )){
        QMessageBox::about(NULL,  "Tips",  "Open txt Failed");
        return;
    }
    QByteArray bt;
    for(int i=0;i<14;i++){
        bt.append(QString::number(box[i]->value()));
        bt.append(" ");
        bt.append(lable[i]->text());
        bt.append("\n");
    }
    bt.append(QString::number(box[14]->value()));
    bt.append(" ");
    bt.append(lable[14]->text());
    file.write(bt,bt.size());
    file.close();
}

