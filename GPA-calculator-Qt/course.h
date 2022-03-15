#ifndef COURSE_H
#define COURSE_H
#include<QString>
#include"algorithm.h"
class Course{
public:

    QString name;
    double score;
    double credit;

    bool Is_take=true;
    Course(){

    }
    Course(QString name,double score,double credit):
        name(name),score(score),credit(credit){

    }
    void Set_Course(QString name,double score,double credit){
        this->score=score;
        this->name=name;
        this->credit=credit;
    }
    //void
    double Get_Score(){return score;}
    QString Get_Name(){return name;}

};

#endif // COURSE_H
