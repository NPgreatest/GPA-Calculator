#include "algorithm.h"



void algorithm::Add_Range(Range range)
{
    this->range.push_back(range);
}

double algorithm::Get_Point(double score)
{
    for(int i=0;i<range.size();i++)
        if(score>=range[i].begin && score<range[i].end)
            return range[i].point;
    return -1;
}

QString algorithm::Get_Grade(double score)
{
    for(int i=0;i<range.size();i++)
        if(score>=range[i].begin && score<range[i].end)
            return range[i].grade;
    return "Null";
}
//double algorithm::GetCredit(alg_name type,double credit,bool Is_politic){
 //   if(type==alg_name::WES){
 //       if(Is_politic){
 //           return 0;
 //       }
//    }
//    return credit;
//}
