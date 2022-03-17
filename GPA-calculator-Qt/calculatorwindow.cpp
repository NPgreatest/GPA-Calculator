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





    if(!Update_Algorithm() || !Update_Settings()){

    }

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
    Tables[cc]->horizontalHeader()->setSectionResizeMode(QHeaderView::ResizeToContents);
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

bool CalculatorWindow::Update_Settings()
{
    r.clear();
    QFile file(QDir::currentPath()+"/settings.txt");
    if(!file.open(QIODevice::ReadOnly)){
        setting = new SettingWindow();
        setting->show();
        return false;
    }

    QTextStream in(&file);
    while (!in.atEnd()) {
        double a;QString b;
        in>>a;
        in>>b;
        r.push_back(QPair<double,QString>(a,b));
        qDebug()<<a<<b;
    }
    file.close();
    return true;
}

bool CalculatorWindow::Update_Algorithm()
{
    if(!alg.isEmpty())return true;
    double a,b,c;
    QString d;
    QDir directory("Algorithm");
    QStringList list = directory.entryList(QStringList() << "*.txt" << "*.TXT",QDir::Files);
    if(list.empty()){
        awindow=new AddAlgorithmWindow();
        awindow->show();
        return false;
    }
    foreach(QString filename, list){
        QFile file(QDir::currentPath()+"/Algorithm/"+filename);
        if (!file.open(QIODevice::ReadOnly | QIODevice::Text)){
            awindow=new AddAlgorithmWindow();
            awindow->show();
            return false;
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
        file.close();
    }
    calg=alg[0];
    return true;
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
    if(!Update_Settings() || !Update_Algorithm()) return;
    if(trans[cc]->cor.size()){
        Update_Transcript();
        return;
    }



    QString Address = QFileDialog::getOpenFileName(this, tr("Choose Transcript"), nullptr, tr("Transcript Files (*.txt)"));
    QFile file(Address);
    if (!file.open(QIODevice::ReadOnly | QIODevice::Text)){
        QMessageBox::about(NULL,  "Oops",  "Can not open file");
          return;
    }
    QTextStream in(&file);
    while (!in.atEnd()) {
        QString name;
        QString f_score;
        double score;
        double credit;
        in>>name;
        in>>credit;
        in>>f_score;
        if(isDigitString(f_score))
            score=f_score.toDouble();
        else{
            bool f=false;
            for(int i=0;i<r.size();i++){
                if(f_score==r[i].second){
                    score=r[i].first;
                    f=1;break;
                }
            }
            if(!f)score=-1;
        }
        trans[cc]->Add_Course(name,score,credit);
    }
    Update_Transcript();
}
bool CalculatorWindow::isDigitString(const QString& src) {
    const char *s = src.toUtf8().data();
    while(*s && ((*s>='0' && *s<='9' )|| *s=='.'))s++;
    return !bool(*s);
}

void CalculatorWindow::on_action_4_triggered()
{
    awindow=new AddAlgorithmWindow();
    awindow->show();
}


void CalculatorWindow::on_actionAdd_a_3_Credit_95_Score_Course_triggered()
{
    trans[cc]->Add_Course("Unknown Course "+ QString::number(QRandomGenerator::global()->bounded(1000000)),95,3);
        Update_Transcript();
}


void CalculatorWindow::on_actionAdd_a_2_Credit_95_Score_Course_triggered()
{
    trans[cc]->Add_Course("Unknown Course "+ QString::number(QRandomGenerator::global()->bounded(1000000)),95,2);
        Update_Transcript();
}


void CalculatorWindow::on_actionAdd_a_2_Credit_89_Score_Course_triggered()
{
    trans[cc]->Add_Course("Unknown Course "+ QString::number(QRandomGenerator::global()->bounded(1000000)),89,2);
        Update_Transcript();
}


void CalculatorWindow::on_actionAdd_a_3_Credit_89_Score_Course_triggered()
{
    trans[cc]->Add_Course("Unknown Course "+ QString::number(QRandomGenerator::global()->bounded(1000000)),89,3);
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
    QString name=ui->plainTextEdit->toPlainText().trimmed().isEmpty()?"Unkown Course":ui->plainTextEdit->toPlainText();
    if(model[cc]->rowCount() && name==model[cc]->item(model[cc]->rowCount()-1)->text())
        trans[cc]->Add_Course(name+ QString::number(QRandomGenerator::global()->bounded(1000000)),ui->ScoreBox->value(),ui->CreditBox->value());
    else
        trans[cc]->Add_Course(name,ui->ScoreBox->value(),ui->CreditBox->value());
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


void CalculatorWindow::on_pushButton_3_clicked()
{
    QModelIndex index=Tables[cc]->selectionModel()->currentIndex();
    if(index.row()<0) return;
    trans[cc]->cor[index.row()].credit=ui->Change_Credit->value();
    Update_Transcript();
}


void CalculatorWindow::on_pushButton_clicked()
{
    QModelIndex index=Tables[cc]->selectionModel()->currentIndex();
    if(index.row()<0) return;
    trans[cc]->cor[index.row()].score=ui->Change_Score->value();
    Update_Transcript();
}


void CalculatorWindow::on_actionSettings_triggered()
{
    setting = new SettingWindow();
    setting->show();
}

