#include "transcript.h"

void transcript::Retake_Course(int n,double score){
   cor.insert(n,Course(cor[n].Get_Name(),score, cor[n].credit));
}

void transcript::Delete_Course(int n)
{
    cor.removeAt(n);
}
void transcript::Print_Script(){
  /*  qDebug()<<"Your script:";
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
    qDebug()<<"OverAllGPA = "<<Get_OverAll_GPA()<<"      OverAllScore="<<Get_OverAll_Score()<<endl;*/
}



double transcript::Get_OverAll_GPA(algorithm &alg){
    double alls=0,allc=0;
    for(int i=0;i<cor.size();i++){
        if(i==cor.size()-1 ||cor[i+1].Get_Name()!=cor[i].Get_Name()){
            alls+=alg.Get_Point(cor[i].Get_Score())* cor[i].credit;
            allc+=cor[i].credit;
        }else {
            double maxx = 0;
            int p = 0;
            while (i+p+1<cor.size() && cor[i + p + 1].Get_Name()==cor[i].Get_Name()) {
                p++;
            }
            for (int k = 0; k < p; k++)
                maxx = max(maxx, alg.Get_Point(cor[k + i].Get_Score()));
            alls += maxx * cor[i].credit;
            allc += cor[i].credit;
            i += p;
        }
    }
    return alls/allc;
}

double transcript::Get_OverAll_Score(algorithm &alg){
    double alls=0,allc=0;
    for(int i=0;i<cor.size();i++){
        if(i==cor.size()-1 ||cor[i+1].Get_Name()!=cor[i].Get_Name()){
            alls+= cor[i].score * cor[i].credit;
            allc+=cor[i].credit;
        }else {
            double maxx = 0;
            int p = 0;
            while (i+p+1<cor.size() && cor[i + p + 1].Get_Name()==cor[i].Get_Name()) {
                p++;
            }
            for (int k = 0; k < p; k++)
                maxx = max(maxx, cor[k + i].score);
            alls += maxx * cor[i].credit;
            allc += cor[i].credit;
            i += p;
        }
    }
    return alls/allc;
}


double transcript::Get_Initial_GPA(algorithm &alg) {
    double alls = 0, allc = 0;
    for (int i = 0; i < cor.size(); i++) {
        if (i==cor.size()-1 || cor[i+1].Get_Name()!=cor[i].Get_Name()) {
            alls += alg.Get_Point(cor[i].Get_Score()) * cor[i].credit;
            allc += cor[i].credit;
        } else {
            int p = 1;
            while (i+p+1<cor.size() && cor[i + p + 1].Get_Name()==cor[i].Get_Name()) {
                p++;
            }
            alls += alg.Get_Point(cor[i + p].Get_Score()) * cor[i].credit;
            allc += cor[i].credit;
            i += p;
        }
    }
    return alls / allc;
}

double transcript::Get_Inital_Score(algorithm &alg){
    double alls = 0, allc = 0;
    for (int i = 0; i < cor.size(); i++) {
        if (i==cor.size()-1 ||cor[i+1].Get_Name()!=cor[i].Get_Name()) {
            alls += cor[i].score * cor[i].credit;
            allc += cor[i].credit;
        } else {
            int p = 0;
            while (i+p+1<cor.size() && cor[i + p + 1].Get_Name()==cor[i].Get_Name()) {
                p++;
            }
            alls += cor[i + p].score *cor[i].credit;
            allc += cor[i].credit;
            i += p;
        }
    }
    return alls / allc;
}
