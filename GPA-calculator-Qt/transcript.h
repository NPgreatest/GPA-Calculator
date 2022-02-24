#ifndef TRANSCRIPT_H
#define TRANSCRIPT_H
#include"course.h"
#include"algorithm.h"
#include<QVector>
#include<QDebug>
using namespace std;
class transcript
{
private:


public:
    QVector<Course> cor;
    alg_name type;
    void Add_Course(int number,QString name,double score,double credit,bool Is_politic,bool Is_retake){
        cor.append(Course(number,name,score,credit,Is_politic,Is_retake));
    }
    void Retake_Course(int number,int score);

    void Change_Mod(alg_name type){
        this->type=type;
    }
    void Print_Script();// for test


    double Get_OverAll_GPA();
    double Get_OverAll_Score();
    double Get_Initial_GPA();
    double Get_Inital_Score();


};

#endif // TRANSCRIPT_H
