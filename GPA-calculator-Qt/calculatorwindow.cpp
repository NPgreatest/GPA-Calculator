#include "calculatorwindow.h"
#include "ui_calculatorwindow.h"

CalculatorWindow::CalculatorWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::CalculatorWindow)
{
    ui->setupUi(this);


    trans.Change_Mod(alg_name::ECUST);









}

CalculatorWindow::~CalculatorWindow()
{
    delete ui;
}


void CalculatorWindow::on_P_transcript_clicked()
{
    if(trans.cor.size()){
        Update_Transcript();
        return;
    }
    int number;
    QString name;
    double score;
    double credit;
    int Is_politic;
    int Is_retake;
    QString Address = QFileDialog::getOpenFileName(this, tr("Choose Transcript"), nullptr, tr("Transcript Files (*.txt)"));
    QFile file(Address);
    if (!file.open(QIODevice::ReadOnly | QIODevice::Text)){
        qDebug()<<"Open File filed";
          return;
    }
    QTextStream in(&file);
    int i=1;
    while (!in.atEnd()) {
        in>>name;
        in>>credit;
        in>>score;
        in>>Is_politic;
        in>>Is_retake;
        if(Is_retake){
            trans.Add_Course(i,name,score,credit,Is_politic,Is_retake);
            continue;
        }
        trans.Add_Course(i,name,score,credit,Is_politic,Is_retake);
        i++;
    }


    Update_Transcript();
}


void CalculatorWindow::on_comboBox_currentIndexChanged(int index)
{

    switch (index) {
    case 0:type=alg_name::ECUST;break;
    case 1:type=alg_name::WES;break;
    case 2:type=alg_name::PKU;break;
    case 3:type=alg_name::S4;break;
    case 4:type=alg_name::S4_New;break;
    case 5:type=alg_name::USTC;break;
    case 6:type=alg_name::SJTU;break;
    case 7:type=alg_name::Canada;break;
    }
    trans.Change_Mod(type);

    Update_Transcript();
}





void CalculatorWindow::on_Add1_clicked()
{
       trans.Add_Course((trans.cor.end()-1)->Get_Number()+1,"Future Course",90,3,0,0);
           Update_Transcript();
}


void CalculatorWindow::on_Add2_clicked()
{
       trans.Add_Course((trans.cor.end()-1)->Get_Number()+1,"Future Course",90,2,0,0);
           Update_Transcript();
}


void CalculatorWindow::on_Add3_clicked()
{
       trans.Add_Course((trans.cor.end()-1)->Get_Number()+1,"Future Course",ui->ScoreBox->value(),ui->CreditBox->value(),0,0);
           Update_Transcript();
}

void CalculatorWindow::Update_Transcript(){
    model->clear();
    model->setHorizontalHeaderItem(0, new QStandardItem(QObject::tr("Number")));
    model->setHorizontalHeaderItem(1, new QStandardItem(QObject::tr("Name")));
    model->setHorizontalHeaderItem(2, new QStandardItem(QObject::tr("Credit")));
    model->setHorizontalHeaderItem(3, new QStandardItem(QObject::tr("Score")));
    model->setHorizontalHeaderItem(4, new QStandardItem(QObject::tr("Point")));
    model->setHorizontalHeaderItem(5, new QStandardItem(QObject::tr("Grade")));
    ui->TranscriptView->setModel(model);
    for(int i=0;i<trans.cor.size();i++){
        model->setItem(i,0,new QStandardItem(QString::number(trans.cor[i].Get_Number())));
        model->setItem(i,1,new QStandardItem(trans.cor[i].Get_Name()));
        model->setItem(i,2,new QStandardItem(QString::number(trans.cor[i].Get_Credit(trans.type))));
        model->setItem(i,3,new QStandardItem(QString::number(trans.cor[i].Get_Score())));
        model->setItem(i,4,new QStandardItem(QString::number(trans.cor[i].Get_point(trans.type))));
        model->setItem(i,5,new QStandardItem(trans.cor[i].Get_grade(trans.type)));
        if(trans.cor[i].Is_retake){
            model->setItem(i,0,new QStandardItem("R*"));
            for(int k=0;k<6;k++){
                model->item(i,k)->setForeground(QBrush(QColor(255, 0, 0)));
                model->item(i,k)->setBackground(QBrush(QColor(Qt::yellow)));
            }
        }
    }
    ui->IGPA->setText(QString::number( trans.Get_Initial_GPA()));
    ui->OGPA->setText(QString::number( trans.Get_OverAll_GPA()));
    ui->IScore->setText(QString::number( trans.Get_Inital_Score()));
    ui->OScore->setText(QString::number( trans.Get_OverAll_Score()));

}

void CalculatorWindow::on_Retake_clicked()
{

    QModelIndex index=ui->TranscriptView->selectionModel()->currentIndex();
    trans.Retake_Course(model->item(index.row(),0)->text().toInt(),ui->ScoreBox2->value());
    Update_Transcript();
}


void CalculatorWindow::on_Delete_clicked()
{
    QVector<Course> n;
    trans.cor.swap(n);
    Update_Transcript();
}


