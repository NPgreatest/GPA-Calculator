#include "algorithm.h"

algorithm::algorithm()
{

}
double algorithm::GetCredit(alg_name type,double credit,bool Is_politic){
    if(type==alg_name::WES){
        if(Is_politic){
            return 0;
        }
    }
    return credit;
}
