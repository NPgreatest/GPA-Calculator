#ifndef SETTINGWINDOW_H
#define SETTINGWINDOW_H

#include <QMainWindow>
#include<QFile>
#include<QDir>
#include<QMessageBox>
#include<QByteArray>
#include<QTextStream>
#include<QPair>
#include<QDoubleSpinBox>
#include<QLabel>
namespace Ui {
class SettingWindow;
}

class SettingWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit SettingWindow(QWidget *parent = nullptr);
    ~SettingWindow();

private slots:
    void on_pushButton_clicked();

private:
    Ui::SettingWindow *ui;
    QVector<QPair<double,QString>> r;
    QVector<QDoubleSpinBox*> box;
    QVector<QLabel*> lable;
};

#endif // SETTINGWINDOW_H
