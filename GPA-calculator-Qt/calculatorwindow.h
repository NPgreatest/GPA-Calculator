#ifndef CALCULATORWINDOW_H
#define CALCULATORWINDOW_H

#include <QMainWindow>
#include<QStandardItemModel>
#include<QMessageBox>
#include<QFileDialog>
#include"transcript.h"
#include"algorithm.h"
#include"course.h"
#include<QFile>
#include<QTranslator>
#include"QTableView"
#include"addalgorithmwindow.h"
#include"aboutwindow.h"
QT_BEGIN_NAMESPACE
namespace Ui { class CalculatorWindow; }
QT_END_NAMESPACE

class CalculatorWindow : public QMainWindow
{
    Q_OBJECT

public:
    CalculatorWindow(QWidget *parent = nullptr);
    ~CalculatorWindow();

private slots:

    void on_comboBox_currentIndexChanged(int index);

    void on_Retake_clicked();

    void on_action_zh_triggered();

    void on_action_English_triggered();

    void on_action_3_triggered();

    void on_action_4_triggered();

    void on_actionAdd_a_3_Credit_95_Score_Course_triggered();

    void on_actionAdd_a_2_Credit_95_Score_Course_triggered();

    void on_actionAdd_a_2_Credit_89_Score_Course_triggered();

    void on_actionAdd_a_3_Credit_89_Score_Course_triggered();

    void on_actionDelete_Transcript_triggered();

    void on_Add3_clicked();

    void on_action_6_triggered();

private:
    Ui::CalculatorWindow *ui;
    AddAlgorithmWindow *awindow;
    AboutWindow *about;
    transcript trans;
    QStandardItemModel *model = new QStandardItemModel();

    QVector<algorithm> alg;
    algorithm calg;
    QTranslator tran;
    QApplication *qApp;
    void Update_Transcript();
};
#endif // CALCULATORWINDOW_H
