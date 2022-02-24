#include "transcript.h"

void transcript::Retake_Course(int number,int score){
    for(int i=0;i<cor.size();i++){
        if(cor[i].number==number){
            cor.insert(i,Course(cor[i].Get_Number(),cor[i].Get_Name(),score, cor[i].Get_Credit(alg_name::ECUST),cor[i].Is_politic,1));
            return;
        }
    }
}
void transcript::Print_Script(){
    qDebug()<<"Your script:";
    qDebug()<<"number  credit  score  point     grade   name"<<endl;
    for(int i=0;i<cor.size();i++){
        if(!cor[i].Is_retake) {

            qDebug()<<cor[i].number<<".     "<<cor[i].Get_Credit(type)<<"     "<<cor[i].Get_Score()<<"     "<<cor[i].Get_point(type)<<"     "<<cor[i].Get_grade(type)<<"     "<<cor[i].name<<endl;

        }else{
            int p=0;
            while(cor[i+p].Is_retake){
                p++;
            }
            qDebug()<<cor[i+p].number<<".     "<<cor[i+p].Get_Credit(type)<<"     "<<cor[i+p].Get_Score()<<"     "<<cor[i+p].Get_point(type)<<"     "<<cor[i+p].Get_grade(type)<<"     "<<cor[i+p].name<<endl;
            for(int k=0;k<p;k++)
                qDebug()<<"    R*  "<<cor[i+k].Get_Credit(type)<<"     "<<cor[i+k].Get_Score()<<"     "<<cor[i+k].Get_point(type)<<"     "<<cor[i+k].Get_grade(type)<<"     "<<cor[i+k].name<<endl;
            i+=p;
        }
    }

    qDebug()<<"InitialGPA = "<<Get_Initial_GPA()<<"      InitalScore= "<<Get_Inital_Score()<<endl;
    qDebug()<<"OverAllGPA = "<<Get_OverAll_GPA()<<"      OverAllScore="<<Get_OverAll_Score()<<endl;
}

double transcript::Get_OverAll_GPA(){
    double alls=0,allc=0;
    for(int i=0;i<cor.size();i++){
        if(!cor[i].Is_retake){
            alls+=cor[i].Get_point(type)*cor[i].credit;
            allc+=cor[i].credit;
        }else {
            double maxx = 0;
            int p = 0;
            while (cor[i + p].Is_retake) {
                p++;
            }
            for (int k = 0; k < p; k++)
                maxx = max(maxx, cor[k + i].Get_point(type));
            alls += maxx * cor[i].credit;
            allc += cor[i].credit;
            i += p;
        }
    }
    return alls/allc;
}

double transcript::Get_OverAll_Score(){
    double alls=0,allc=0;
    for(int i=0;i<cor.size();i++){
        if(!cor[i].Is_retake){
            alls+=cor[i].score*cor[i].Get_Credit(type);
            allc+=cor[i].Get_Credit(type);
        }else {
            double maxx = 0;
            int p = 0;
            while (cor[i + p].Is_retake) {
                p++;
            }
            for (int k = 0; k < p; k++)
                maxx = max(maxx, cor[k + i].score);
            alls += maxx * cor[i].Get_Credit(type);
            allc += cor[i].Get_Credit(type);
            i += p;
        }
    }
    return alls/allc;
}


double transcript::Get_Initial_GPA() {
    double alls = 0, allc = 0;
    for (int i = 0; i < cor.size(); i++) {
        if (!cor[i].Is_retake) {
            alls += cor[i].Get_point(type) * cor[i].Get_Credit(type);
            allc += cor[i].Get_Credit(type);
        } else {
            int p = 0;
            while (cor[i + p].Is_retake) {
                p++;
            }
            alls += cor[i + p].Get_point(type) * cor[i + p].Get_Credit(type);
            allc += cor[i + p].Get_Credit(type);
            i += p;
        }
    }
    return alls / allc;
}

double transcript::Get_Inital_Score(){
    double alls = 0, allc = 0;
    for (int i = 0; i < cor.size(); i++) {
        if (!cor[i].Is_retake) {
            alls += cor[i].score * cor[i].Get_Credit(type);
            allc += cor[i].Get_Credit(type);
        } else {
            int p = 0;
            while (cor[i + p].Is_retake) {
                p++;
            }
            alls += cor[i + p].score * cor[i + p].Get_Credit(type);
            allc += cor[i + p].Get_Credit(type);
            i += p;
        }
    }
    return alls / allc;
}
