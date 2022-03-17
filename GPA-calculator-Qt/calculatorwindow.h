#ifndef CALCULATORWINDOW_H
#define CALCULATORWINDOW_H

#include <QMainWindow>
#include<QStandardItemModel>
#include<QMessageBox>
#include<QFileDialog>
#include"transcript.h"
#include"algorithm.h"
#include"settingwindow.h"
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

    void on_actionChange__Mode_triggered();

    void on_tabWidget_currentChanged(int index);

    void on_actionCopy_triggered();

    void on_actionPaste_triggered();

    void on_actionRetake_Course_triggered();

    void on_actionDelete_Course_triggered();

    void on_pushButton_3_clicked();

    void on_pushButton_clicked();

    void on_actionSettings_triggered();

private:
    bool isDigitString(const QString& src);
    Ui::CalculatorWindow *ui;
    AddAlgorithmWindow *awindow;
    AboutWindow *about;
    SettingWindow *setting;
    QVector<QTableView*> Tables;
    QVector<QStandardItemModel*> model;
    QVector<transcript*> trans;
    transcript ctran;
    int cc=0;
    QVector<QPair<double,QString>> r;
    QVector<algorithm> alg;
    algorithm calg;
    QTranslator tran;
    QApplication *qApp;
    bool edit=false;
    void Update_Transcript();
    bool Update_Settings();
    bool Update_Algorithm();
};
#endif // CALCULATORWINDOW_H
