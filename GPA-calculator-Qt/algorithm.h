#ifndef ALGORITHM_H
#define ALGORITHM_H
#include<QString>
enum alg_name{
    ECUST = 1,
    WES=2,
    PKU=3,
    S4=4,S4_New=5,Canada=6,USTC=7,SJTU=8

};



class algorithm
{
public:
    algorithm();
    static double GetPoint(alg_name type,double score){
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
        return "Null";
    }
    static double GetCredit(alg_name type,double credit,bool Is_politic);
};

#endif // ALGORITHM_H
