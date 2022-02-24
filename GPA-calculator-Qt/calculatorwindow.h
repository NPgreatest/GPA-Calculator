#ifndef CALCULATORWINDOW_H
#define CALCULATORWINDOW_H

#include <QMainWindow>
#include<QStandardItemModel>
#include<QFileDialog>
#include"transcript.h"
#include"algorithm.h"
#include"course.h"
#include<QFile>
#include"QTableView"
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
    void on_P_transcript_clicked();

    void on_comboBox_currentIndexChanged(int index);

    void on_Add1_clicked();

    void on_Add2_clicked();

    void on_Add3_clicked();

    void on_Retake_clicked();

    void on_Delete_clicked();


private:
    Ui::CalculatorWindow *ui;
    transcript trans;
    QStandardItemModel *model = new QStandardItemModel();
    alg_name type;

    void Update_Transcript();
};
#endif // CALCULATORWINDOW_H
