#ifndef COURSE_H
#define COURSE_H
#include<QString>
#include"algorithm.h"
class Course{
public:
    int number;
    QString name;
    double score;
    double credit;
    bool Is_politic;
    bool Is_retake;
    Course(){

    }
    Course(int number,QString name,double score,double credit,bool Is_politic,bool Is_retake):
        number(number),name(name),score(score),credit(credit),Is_politic(Is_politic),Is_retake(Is_retake){

    }
    void Set_Course(int number,QString name,double score,double credit,bool Is_politic,bool Is_retake){
        this->score=score;
        this->name=name;
        this->number=number;
        this->credit=credit;
        this->Is_politic=Is_politic;
        this->Is_retake=Is_retake;
    }
    double Get_Score(){return score;}
    int Get_Number(){return number;}
    QString Get_Name(){return name;}
    double Get_point(alg_name type){
        return algorithm::GetPoint(type,this->score);
    }
    QString Get_grade(alg_name type){
        return algorithm::GetGrade(type,this->score);
    }
    double Get_Credit(alg_name type){
        return algorithm::GetCredit(type,this->credit,this->Is_politic);
    }
};

#endif // COURSE_H
