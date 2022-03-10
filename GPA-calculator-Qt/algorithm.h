#ifndef ALGORITHM_H
#define ALGORITHM_H
#include<QString>
#include<QVector>
#include<QPair>
/*enum alg_name{
    ECUST = 1,
    WES=2,
    PKU=3,
    S4=4,S4_New=5,Canada=6,USTC=7,SJTU=8,UCD=9

};
*/
struct Range{
    double begin;
    double end;
    double point;
    QString grade;
    Range(){}
    Range(double a,double b,double c,QString d){
        begin=a;
        end=b;
        point=c;
        grade=d;
    }
};

class algorithm
{
    QString Name;
    QVector<Range> range;
public:
    bool WES=false;
    algorithm(){}
    algorithm(bool WES):WES(WES){}
    void Add_Range(Range range);
    double Get_Point(double score);
    QString Get_Grade(double score);
    /*static double GetPoint(alg_name type,double score){
        if(type==alg_name::ECUST){
            if(score<=59)return 0;
            else if(score>=60 && score<=61)return 1.0;
            else if(score>=62 && score<=65)return 1.4;
            else if(score>=66 && score<=70)return 1.8;
            else if(score>=71 && score<=74)return 2.3;
            else if(score>=75 && score<=77)return 2.7;
            else if(score>=78 && score<=81)return 3.0;
            else if(score>=82 && score<=84)return 3.3;
            else if(score>=85 && score<=89)return 3.7;
            else if(score>=90 && score<=100)return 4.0;
            else return -1;
        }
        else if(type==alg_name::WES){
            if(score<=59)return 0;
            else if(score>=60 && score<=74)return 2.0;
            else if(score>=75 && score<=84)return 3.0;
            else if(score>=85)return 4.0;
            else return -1;
        }
        else if(type==alg_name::PKU){
            if(score<=59)return 0;
            else if(score>=60 && score<=63)return 1.0;
            else if(score>=64 && score<=67)return 1.5;
            else if(score>=68 && score<=71)return 2.0;
            else if(score>=72 && score<=74)return 2.3;
            else if(score>=75 && score<=77)return 2.7;
            else if(score>=78 && score<=81)return 3.0;
            else if(score>=82 && score<=84)return 3.3;
            else if(score>=85 && score<=89)return 3.7;
            else if(score>=90 && score<=100)return 4.0;
            else return -1;
        }
        else if(type==alg_name::S4){
            if(score<=59)return 0;
            else if(score>=60 && score<=69)return 1.0;
            else if(score>=70 && score<=79)return 2.0;
            else if(score>=80 && score<=89)return 3.0;
            else if(score>=90 && score<=100)return 4.0;
            else return -1;
        }
        else if(type==alg_name::S4_New){
            if(score<=59)return 0;
            else if(score>=60 && score<=69)return 2.0;
            else if(score>=70 && score<=84)return 3.0;
            else if(score>=85)return 4.0;
            else return -1;
        }
        else if(type==alg_name::USTC){
            if(score<=59)return 0;
            else if(score>=60 && score<=60)return 1.0;
            else if(score>=61 && score<=63)return 1.3;
            else if(score>=64 && score<=64)return 1.5;
            else if(score>=65 && score<=67)return 1.7;
            else if(score>=68 && score<=71)return 2.0;
            else if(score>=72 && score<=74)return 2.3;
            else if(score>=75 && score<=77)return 2.7;
            else if(score>=78 && score<=81)return 3.0;
            else if(score>=82 && score<=84)return 3.3;
            else if(score>=85 && score<=89)return 3.7;
            else if(score>=90 && score<=94)return 4.0;
            else if(score>=95 && score<=100)return 4.3;
            else return -1;
        }
        else if(type==alg_name::USTC){
            if(score<=59)return 0;
            else if(score>=60 && score<=60)return 1.0;
            else if(score>=61 && score<=63)return 1.3;
            else if(score>=64 && score<=64)return 1.5;
            else if(score>=65 && score<=67)return 1.7;
            else if(score>=68 && score<=71)return 2.0;
            else if(score>=72 && score<=74)return 2.3;
            else if(score>=75 && score<=77)return 2.7;
            else if(score>=78 && score<=81)return 3.0;
            else if(score>=82 && score<=84)return 3.3;
            else if(score>=85 && score<=89)return 3.7;
            else if(score>=90 && score<=94)return 4.0;
            else if(score>=95 && score<=100)return 4.3;
            else return -1;
        }
        else if(type==alg_name::Canada){
            if(score<=59)return 0;
            else if(score>=60 && score<=64)return 2.3;
            else if(score>=65 && score<=69)return 2.7;
            else if(score>=70 && score<=74)return 3.0;
            else if(score>=75 && score<=79)return 3.3;
            else if(score>=80 && score<=84)return 3.7;
            else if(score>=85 && score<=89)return 4.0;
            else if(score>=90)return 4.3;
            else return -1;
        }
        else if(type==alg_name::SJTU){
            if(score<=59)return 0;
            else if(score>=60 && score<=61)return 1.0;
            else if(score>=62 && score<=64)return 1.7;
            else if(score>=65 && score<=66)return 2.0;
            else if(score>=67 && score<=69)return 2.3;
            else if(score>=70 && score<=74)return 2.7;
            else if(score>=75 && score<=79)return 3.0;
            else if(score>=80 && score<=84)return 3.3;
            else if(score>=85 && score<=89)return 3.7;
            else if(score>=90 && score<=94)return 4.0;
            else if(score>=95)return 4.3;
            else return -1;
        }
        else if(type==alg_name::UCD){
            if(score<=39)return 0;
            else if(score>=40 && score<=43)return 2.0;
            else if(score>=44 && score<=46)return 2.2;
            else if(score>=47 && score<=49)return 2.4;
            else if(score>=50 && score<=53)return 2.6;
            else if(score>=54 && score<=56)return 2.8;
            else if(score>=57 && score<=59)return 3.0;
            else if(score>=60 && score<=63)return 3.2;
            else if(score>=64 && score<=66)return 3.4;
            else if(score>=67 && score<=69)return 3.6;
            else if(score>=70 && score<=79)return 3.8;
            else if(score>=80 && score<=89)return 4.0;
            else if(score>=90)return 4.2;
            else return -1;
        }
        return 0;
    }
    static QString GetGrade(alg_name type,double score){
        if(type==alg_name::ECUST){
            if(score<=59)return "F ";
            else if(score>=60 && score<=61)return "D ";
            else if(score>=62 && score<=65)return "C-";
            else if(score>=66 && score<=70)return "C ";
            else if(score>=71 && score<=74)return "C+";
            else if(score>=75 && score<=77)return "B-";
            else if(score>=78 && score<=81)return "B ";
            else if(score>=82 && score<=84)return "B+";
            else if(score>=85 && score<=89)return "A-";
            else if(score>=90 && score<=100)return "A ";
            else return "Null";
        }
        else if(type==alg_name::WES){
            if(score<=59)return "F";
            else if(score>=60 && score<=74)return "C";
            else if(score>=75 && score<=84)return "B";
            else if(score>=85)return "A";
            else return "Null";
        }
        else if(type==alg_name::PKU){
            if(score<=59)return "F";
            else if(score>=60 && score<=63)return "D ";
            else if(score>=64 && score<=67)return "C-";
            else if(score>=68 && score<=71)return "C ";
            else if(score>=72 && score<=74)return "C+";
            else if(score>=75 && score<=77)return "B-";
            else if(score>=78 && score<=81)return "B ";
            else if(score>=82 && score<=84)return "B+";
            else if(score>=85 && score<=89)return "A-";
            else if(score>=90 && score<=100)return "A ";
            else return "Null";
        }
        else if(type==alg_name::S4){
            if(score<=59)return "F ";
            else if(score>=60 && score<=69)return "D ";
            else if(score>=70 && score<=79)return "C ";
            else if(score>=80 && score<=89)return "B ";
            else if(score>=90 && score<=100)return "A ";
            else return "Null";
        }
        else if(type==alg_name::S4_New){
            if(score<=59)return "F ";
            else if(score>=60 && score<=69)return "C ";
            else if(score>=70 && score<=84)return "B ";
            else if(score>=85 && score<=100)return "A ";
            else return "Null";
        }
        else if(type==alg_name::USTC){
            if(score<=59)return "F";
            else if(score>=60 && score<=60)return "D-";
            else if(score>=61 && score<=63)return "D";
            else if(score>=64 && score<=64)return "D+";
            else if(score>=65 && score<=67)return "C-";
            else if(score>=68 && score<=71)return "C";
            else if(score>=72 && score<=74)return "C+";
            else if(score>=75 && score<=77)return "B-";
            else if(score>=78 && score<=81)return "B";
            else if(score>=82 && score<=84)return "B+";
            else if(score>=85 && score<=89)return "A-";
            else if(score>=90 && score<=94)return "A";
            else if(score>=95 && score<=100)return "A+";
            else return "Null";
        }
        else if(type==alg_name::UCD){
            if(score<=39)return "F";
            else if(score>=40 && score<=43)return "D-";
            else if(score>=44 && score<=46)return "D";
            else if(score>=47 && score<=49)return "D+";
            else if(score>=50 && score<=53)return "C-";
            else if(score>=54 && score<=56)return "C";
            else if(score>=57 && score<=59)return "C+";
            else if(score>=60 && score<=63)return "B-";
            else if(score>=64 && score<=66)return "B";
            else if(score>=67 && score<=69)return "B+";
            else if(score>=70 && score<=79)return "A-";
            else if(score>=80 && score<=89)return "A";
            else if(score>=90)return "A+";
            else return "F";
        }
        return "Null";
    }*/
    //static double GetCredit(alg_name type,double credit,bool Is_politic);
};

#endif // ALGORITHM_H
