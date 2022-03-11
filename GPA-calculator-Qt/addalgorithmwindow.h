#ifndef ADDALGORITHMWINDOW_H
#define ADDALGORITHMWINDOW_H


#include <QMainWindow>
#include"algorithm.h"
#include "QStandardItemModel"


namespace Ui {
class AddAlgorithmWindow;
}

class AddAlgorithmWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit AddAlgorithmWindow(QWidget *parent = nullptr);
    ~AddAlgorithmWindow();

private slots:
    void on_AddRow_clicked();

    void on_pushButton_2_clicked();

    void on_pushButton_clicked();

private:
    Ui::AddAlgorithmWindow *ui;

    QStandardItemModel *model = new QStandardItemModel();




};

#endif // ADDALGORITHMWINDOW_H
