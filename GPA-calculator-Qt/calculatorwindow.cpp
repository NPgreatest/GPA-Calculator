#include "calculatorwindow.h"
#include "ui_calculatorwindow.h"
#include <QCoreApplication>
CalculatorWindow::CalculatorWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::CalculatorWindow)
{
    ui->setupUi(this);

    QActionGroup *Language_Group;
    Language_Group=new QActionGroup(this);
    Language_Group->addAction(ui->action_zh);
    Language_Group->addAction(ui->action_English);
    Language_Group->setExclusive(1);

    ui->splitter_2->setStretchFactor(0,4);
    ui->splitter_2->setStretchFactor(1,1);
    ui->splitter->setStretchFactor(0,4);
    ui->splitter->setStretchFactor(1,1);
    ui->splitter->show();
    ui->splitter_2->show();

    double a,b,c;
    QString d;
    QDir directory("Algorithm");
    QStringList list = directory.entryList(QStringList() << "*.txt" << "*.TXT",QDir::Files);
    foreach(QString filename, list) {

        QFile file(QDir::currentPath()+"/Algorithm/"+filename);
        if (!file.open(QIODevice::ReadOnly | QIODevice::Text)){
            QMessageBox::about(NULL,  "Oops",  "Can not open file");
              return;
        }
        QTextStream in(&file);
        alg.push_back(0);
        while (!in.atEnd()) {
            in>>a;
            in>>b;
            in>>c;
            in>>d;


            Range t(a,b,c,d);

            (alg.end()-1)->Add_Range(t);

        }
        ui->comboBox->addItem(filename.left(filename.size()-4));
        if(filename.left(filename.size()-4)=="WES") (alg.end()-1)->WES=1;
        file.close();
    }
    calg=alg[0];

}

CalculatorWindow::~CalculatorWindow()
{
    delete ui;
}





void CalculatorWindow::on_comboBox_currentIndexChanged(int index)
{

    calg=alg[index];

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
        model->setItem(i,2,new QStandardItem(QString::number((calg.WES? trans.cor[i].Is_politic?0:trans.cor[i].credit:trans.cor[i].credit))));
        model->setItem(i,3,new QStandardItem(QString::number(trans.cor[i].Get_Score())));
        model->setItem(i,4,new QStandardItem(QString::number(calg.Get_Point(trans.cor[i].Get_Score()))));
        model->setItem(i,5,new QStandardItem(calg.Get_Grade(trans.cor[i].Get_Score())));
        if(trans.cor[i].Is_retake){
            model->setItem(i,0,new QStandardItem("R*"));
            for(int k=0;k<6;k++){
                model->item(i,k)->setForeground(QBrush(QColor(255, 0, 0)));
                model->item(i,k)->setBackground(QBrush(QColor(Qt::yellow)));
            }
        }
    }
    ui->IGPA->setText(QString::number( trans.Get_Initial_GPA(calg)));
    ui->OGPA->setText(QString::number( trans.Get_OverAll_GPA(calg)));
    ui->IScore->setText(QString::number( trans.Get_Inital_Score(calg)));
    ui->OScore->setText(QString::number( trans.Get_OverAll_Score(calg)));

}

void CalculatorWindow::on_Retake_clicked()
{

    QModelIndex index=ui->TranscriptView->selectionModel()->currentIndex();
    trans.Retake_Course(model->item(index.row(),0)->text().toInt(),ui->ScoreBox2->value());
    Update_Transcript();
}







void CalculatorWindow::on_action_zh_triggered()
{
    tran.load(":/tr_zh.qm");
    qApp->installTranslator(&tran);
    ui->retranslateUi(this);
    Update_Transcript();
}


void CalculatorWindow::on_action_English_triggered()
{
    tran.load(":/tr_en.qm");
    qApp->installTranslator(&tran);
    ui->retranslateUi(this);
    Update_Transcript();
}


void CalculatorWindow::on_action_3_triggered()
{
    if(trans.cor.size()){
        Update_Transcript();
        return;
    }
    QString name;
    double score;
    double credit;
    int Is_politic;
    int Is_retake;

    QString Address = QFileDialog::getOpenFileName(this, tr("Choose Transcript"), nullptr, tr("Transcript Files (*.txt)"));
    QFile file(Address);
    if (!file.open(QIODevice::ReadOnly | QIODevice::Text)){
        QMessageBox::about(NULL,  "Oops",  "Can not open file");
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


void CalculatorWindow::on_action_4_triggered()
{
    awindow=new AddAlgorithmWindow();
    awindow->show();
}


void CalculatorWindow::on_actionAdd_a_3_Credit_95_Score_Course_triggered()
{
    trans.Add_Course((trans.cor.end()-1)->Get_Number()+1,"Future Course",95,3,0,0);
        Update_Transcript();
}


void CalculatorWindow::on_actionAdd_a_2_Credit_95_Score_Course_triggered()
{
    trans.Add_Course((trans.cor.end()-1)->Get_Number()+1,"Future Course",95,2,0,0);
        Update_Transcript();
}


void CalculatorWindow::on_actionAdd_a_2_Credit_89_Score_Course_triggered()
{
    trans.Add_Course((trans.cor.end()-1)->Get_Number()+1,"Future Course",89,2,0,0);
        Update_Transcript();
}


void CalculatorWindow::on_actionAdd_a_3_Credit_89_Score_Course_triggered()
{
    trans.Add_Course((trans.cor.end()-1)->Get_Number()+1,"Future Course",89,3,0,0);
        Update_Transcript();
}


void CalculatorWindow::on_actionDelete_Transcript_triggered()
{
    QVector<Course> n;
    trans.cor.swap(n);
    Update_Transcript();
}


void CalculatorWindow::on_Add3_clicked()
{
    trans.Add_Course((trans.cor.end()-1)->Get_Number()+1,"Future Course",ui->ScoreBox->value(),ui->CreditBox->value(),0,0);
        Update_Transcript();
}


void CalculatorWindow::on_action_6_triggered()
{
    about = new AboutWindow();
    about->show();
}

