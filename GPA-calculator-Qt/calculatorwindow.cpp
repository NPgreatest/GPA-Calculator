#include "calculatorwindow.h"
#include "ui_calculatorwindow.h"
#include <QCoreApplication>
#include <QRandomGenerator>
CalculatorWindow::CalculatorWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::CalculatorWindow)
{
    ui->setupUi(this);

    Tables.push_back(ui->TranscriptView);
    Tables.push_back(ui->TranscriptView_2);
    Tables.push_back(ui->TranscriptView_3);

    for(int i=0;i<3;i++){
        transcript *tt=new transcript();
        QStandardItemModel *m=new QStandardItemModel();
        model.push_back(m);
        trans.push_back(tt);
    }

    QActionGroup *Language_Group;
    Language_Group=new QActionGroup(this);
    Language_Group->addAction(ui->action_zh);
    Language_Group->addAction(ui->action_English);
    Language_Group->setExclusive(1);
    on_action_zh_triggered();

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
    model[cc]->clear();
    model[cc]->setHorizontalHeaderItem(0, new QStandardItem(QObject::tr("Name")));
    model[cc]->setHorizontalHeaderItem(1, new QStandardItem(QObject::tr("Credit")));
    model[cc]->setHorizontalHeaderItem(2, new QStandardItem(QObject::tr("Score")));
    model[cc]->setHorizontalHeaderItem(3, new QStandardItem(QObject::tr("Point")));
    model[cc]->setHorizontalHeaderItem(4, new QStandardItem(QObject::tr("Grade")));
    Tables[cc]->setModel(model[cc]);
    for(int i=0;i<trans[cc]->cor.size();i++){
        model[cc]->setItem(i,0,new QStandardItem(trans[cc]->cor[i].Get_Name()));
        model[cc]->setItem(i,1,new QStandardItem(QString::number(trans[cc]->cor[i].credit)));
        model[cc]->setItem(i,2,new QStandardItem(QString::number(trans[cc]->cor[i].Get_Score())));
        model[cc]->setItem(i,3,new QStandardItem(QString::number(calg.Get_Point(trans[cc]->cor[i].Get_Score()))));
        model[cc]->setItem(i,4,new QStandardItem(calg.Get_Grade(trans[cc]->cor[i].Get_Score())));
        if(i!=trans[cc]->cor.size()-1 && trans[cc]->cor[i+1].Get_Name()==trans[cc]->cor[i].Get_Name()){
            model[cc]->setItem(i,0,new QStandardItem(trans[cc]->cor[i].Get_Name()+"R*"));
            for(int k=0;k<5;k++){
                model[cc]->item(i,k)->setForeground(QBrush(QColor(255, 0, 0)));
                model[cc]->item(i,k)->setBackground(QBrush(QColor(Qt::yellow)));
            }
        }
    }

    ui->IGPA->setText(QString::number( trans[cc]->Get_Initial_GPA(calg)));
    ui->OGPA->setText(QString::number( trans[cc]->Get_OverAll_GPA(calg)));
    ui->IScore->setText(QString::number( trans[cc]->Get_Inital_Score(calg)));
    ui->OScore->setText(QString::number( trans[cc]->Get_OverAll_Score(calg)));

}

void CalculatorWindow::on_Retake_clicked()
{
    QModelIndex index=Tables[cc]->selectionModel()->currentIndex();
    if(index.row()<0) return;
    trans[cc]->Retake_Course(index.row(),ui->ScoreBox2->value());
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
    if(trans[cc]->cor.size()){
        Update_Transcript();
        return;
    }
    QString name;
    double score;
    double credit;


    QString Address = QFileDialog::getOpenFileName(this, tr("Choose Transcript"), nullptr, tr("Transcript Files (*.txt)"));
    QFile file(Address);
    if (!file.open(QIODevice::ReadOnly | QIODevice::Text)){
        QMessageBox::about(NULL,  "Oops",  "Can not open file");
          return;
    }
    QTextStream in(&file);
    while (!in.atEnd()) {
        in>>name;
        in>>credit;
        in>>score;
        trans[cc]->Add_Course(name,score,credit);
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
    trans[cc]->Add_Course("Future Course "+ QString::number(QRandomGenerator::global()->bounded(1000000)),95,3);
        Update_Transcript();
}


void CalculatorWindow::on_actionAdd_a_2_Credit_95_Score_Course_triggered()
{
    trans[cc]->Add_Course("Future Course "+ QString::number(QRandomGenerator::global()->bounded(1000000)),95,2);
        Update_Transcript();
}


void CalculatorWindow::on_actionAdd_a_2_Credit_89_Score_Course_triggered()
{
    trans[cc]->Add_Course("Future Course "+ QString::number(QRandomGenerator::global()->bounded(1000000)),89,2);
        Update_Transcript();
}


void CalculatorWindow::on_actionAdd_a_3_Credit_89_Score_Course_triggered()
{
    trans[cc]->Add_Course("Future Course "+ QString::number(QRandomGenerator::global()->bounded(1000000)),89,3);
        Update_Transcript();
}


void CalculatorWindow::on_actionDelete_Transcript_triggered()
{
    QVector<Course> n;
    trans[cc]->cor.swap(n);
    Update_Transcript();
}


void CalculatorWindow::on_Add3_clicked()
{
    trans[cc]->Add_Course("Future Course "+ QString::number(QRandomGenerator::global()->bounded(1000000)),ui->ScoreBox->value(),ui->CreditBox->value());
        Update_Transcript();
}


void CalculatorWindow::on_action_6_triggered()
{
    about = new AboutWindow();
    about->show();
}



void CalculatorWindow::on_actionChange__Mode_triggered()
{
    edit=!edit;
    if(edit){
        ui->actionChange__Mode->setText("Change to View Mode");
        ui->TranscriptView->setEditTriggers(QAbstractItemView::DoubleClicked);

    }else{
        ui->actionChange__Mode->setText("Change to Edit Mode");
        ui->TranscriptView->setEditTriggers(QAbstractItemView::NoEditTriggers);
    }
}


void CalculatorWindow::on_tabWidget_currentChanged(int index)
{
    cc=index;
    Update_Transcript();
}


void CalculatorWindow::on_actionCopy_triggered()
{
    ctran=*trans[cc];
}


void CalculatorWindow::on_actionPaste_triggered()
{

    trans[cc]->cor=ctran.cor;
    Update_Transcript();
}



void CalculatorWindow::on_actionRetake_Course_triggered()
{
    on_Retake_clicked();
}


void CalculatorWindow::on_actionDelete_Course_triggered()
{
    QModelIndex index=Tables[cc]->selectionModel()->currentIndex();
    if(index.row()<0) return;
    trans[cc]->Delete_Course(index.row());
    Update_Transcript();
}

