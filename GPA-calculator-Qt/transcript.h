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
    void Add_Course(QString name,double score,double credit){
        cor.append(Course(name,score,credit));
    }
    void Retake_Course(int n,double score);
    void Delete_Course(int n);

    void Print_Script();// for test

    double Get_OverAll_GPA(algorithm &alg);
    double Get_OverAll_Score(algorithm &alg);
    double Get_Initial_GPA(algorithm &alg);
    double Get_Inital_Score(algorithm &alg);


};

#endif // TRANSCRIPT_H
