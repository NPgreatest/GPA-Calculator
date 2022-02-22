#include <iostream>
#include<fstream>
#include <iomanip>
using namespace std;
class Course{
public:
    string name;
    double score;
    double credit;
    bool Is_politic;
    bool Is_retake;
    int number;
    Course(){
        this->score=0;
        this->name="";
        this->number=-1;
        this->credit=0;
        this->Is_politic=0;
        this->Is_retake=0;
    }
    void Set_Course(int number,string name,double score,double credit,bool Is_politic,bool Is_retake){
        this->score=score;
        this->name=name;
        this->number=number;
        this->credit=credit;
        this->Is_politic=Is_politic;
        this->Is_retake=Is_retake;
    }

    double Get_point(int method = 1){
        if(method==1){
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
        else if(method==2){
            if(score<=59)return 0;
            else if(score>=60 && score<=74)return 2.0;
            else if(score>=75 && score<=84)return 3.0;
            else if(score>=85)return 4.0;
            else return -1;
        }
        if(method==3){
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
    }
    string Get_grade(int method = 1){
        if(method==1){
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
        else if(method==2){
            if(score<=59)return "F";
            else if(score>=60 && score<=74)return "C";
            else if(score>=75 && score<=84)return "B";
            else if(score>=85)return "A";
            else return "Null";
        }
        else if(method==3){
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
            else return "?";
        }
    }
};



class transcript{
private:
    double GPA;
    int C_number;
    Course cor[999];
    int mode=1;
public:
    void Add_Course(int number,string name,double score,double credit,bool Is_politic,bool Is_retake){
        cor[C_number].Set_Course(number,name,score,credit,Is_politic,Is_retake);
        C_number++;
    }
    void Retake_Course(int number,int score){
        for(int i=0;i<C_number;i++){
            if(cor[i].number==number){
                cor[i].score=score;
                return;
            }
        }
    }
    void Change_Mod(int mode){
        this->mode=mode;
        if(mode==2){
            for(int i=0;i<C_number;i++){
                if(cor[i].Is_politic){
                    cor[i].credit=0;
                }
            }
        }
    }
    void Print_Script(){
        cout<<"Your script:"<<endl;
        cout<<"number  credit  score  point     grade   name"<<endl;
        cout<<fixed<<setprecision(1);
        for(int i=0;i<C_number;i++){
            if(cor[i].number<10)cout<<"0";
            if(!cor[i].Is_retake) {

                cout<<cor[i].number<<".     "<<cor[i].credit<<"     "<<cor[i].score<<"     "<<cor[i].Get_point(mode)<<"     "<<cor[i].Get_grade(mode)<<"     "<<cor[i].name<<endl;

            }else{
                int p=0;
                while(cor[i+p].Is_retake){
                    p++;
                }
                cout<<cor[i+p].number<<".     "<<cor[i+p].credit<<"     "<<cor[i+p].score<<"     "<<cor[i+p].Get_point(mode)<<"     "<<cor[i+p].Get_grade(mode)<<"     "<<cor[i+p].name<<endl;
                for(int k=0;k<p;k++)
                    cout<<"    R*  "<<cor[i+k].credit<<"     "<<cor[i+k].score<<"     "<<cor[i+k].Get_point(mode)<<"     "<<cor[i+k].Get_grade(mode)<<"     "<<cor[i+k].name<<endl;
                i+=p;
            }
        }
        cout<<fixed<<setprecision(4);
        cout<<"InitialGPA = "<<Get_Initial_GPA()<<"      InitalScore= "<<Get_Inital_Score()<<endl;
        cout<<"OverAllGPA = "<<Get_OverAll_GPA()<<"      OverAllScore="<<Get_OverAll_Score()<<endl;
    }
    double Get_OverAll_GPA(){
        double alls=0,allc=0;
        for(int i=0;i<C_number;i++){
            if(!cor[i].Is_retake){
                alls+=cor[i].Get_point(mode)*cor[i].credit;
                allc+=cor[i].credit;
            }else {
                double maxx = 0;
                int p = 0;
                while (cor[i + p].Is_retake) {
                    p++;
                }
                for (int k = 0; k < p; k++)
                    maxx = max(maxx, cor[k + i].Get_point(mode));
                alls += maxx * cor[i].credit;
                allc += cor[i].credit;
                i += p;
            }
        }
        return alls/allc;
    }
    double Get_OverAll_Score(){
        double alls=0,allc=0;
        for(int i=0;i<C_number;i++){
            if(!cor[i].Is_retake){
                alls+=cor[i].score*cor[i].credit;
                allc+=cor[i].credit;
            }else {
                double maxx = 0;
                int p = 0;
                while (cor[i + p].Is_retake) {
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
    double Get_Initial_GPA() {
        double alls = 0, allc = 0;
        for (int i = 0; i < C_number; i++) {
            if (!cor[i].Is_retake) {
                alls += cor[i].Get_point(mode) * cor[i].credit;
                allc += cor[i].credit;
            } else {
                int p = 0;
                while (cor[i + p].Is_retake) {
                    p++;
                }
                alls += cor[i + p].Get_point(mode) * cor[i + p].credit;
                allc += cor[i + p].credit;
                i += p;
            }
        }
        return alls / allc;
    }
    double Get_Inital_Score(){
        double alls = 0, allc = 0;
        for (int i = 0; i < C_number; i++) {
            if (!cor[i].Is_retake) {
                alls += cor[i].score * cor[i].credit;
                allc += cor[i].credit;
            } else {
                int p = 0;
                while (cor[i + p].Is_retake) {
                    p++;
                }
                alls += cor[i + p].score * cor[i + p].credit;
                allc += cor[i + p].credit;
                i += p;
            }
        }
        return alls / allc;
    }
};

int main() {
    int n,c;
    int number,mod=1;
    string name;
    double score;
    double credit;
    bool Is_politic;
    bool Is_retake;
    transcript trans;
    ifstream in("D:\\transcript.txt");
    if (! in.is_open())
    { cout << "Error opening file"<<endl;
        cout<<"please put transcript.txt in D:\\ and restart"<<endl;exit (1); }
    in>>n;
    for(int i=0;i<n;i++) {
        in>>number;
        in>>name;
        in>>credit;
        in>>score;
        in>>Is_politic;
        in>>Is_retake;
        trans.Add_Course(number,name,score,credit,Is_politic,Is_retake);
    }
    cout<<"operation:"<<endl<<"1.check transcript"<<endl<<"2.change algorithm"<<endl<<"3.plan"<<endl<<endl<<"current algorithm: ";
    switch (mod) {
        case 1:cout<<"ECUST";break;
        case 2:cout<<"WES";break;
    }
    cout<<endl<<"input number:";
    while(cin>>c){

        switch (c) {
            case 0:return 0;
            case 1:trans.Print_Script();break;
            case 2:
                cout<<"algorithm:"<<endl<<"1.ECUST"<<"2.WES"<<"3.BeiDa"<<endl;
                cin>>c;
                mod=c;
                trans.Change_Mod(c);
                break;
            case 3:
                cout<<"add or retake course:"<<endl<<"1.Add Course"<<endl<<"2.Retake Course"<<endl;
                cin>>c;
                if(c==1){
                    cout<<"Input name,score,credit,Is_politic,Is_retake :"<<endl;
                    cin>>name;
                    cin>>score;
                    cin>>credit;
                    cin>>Is_politic;
                    cin>>Is_retake;
                    trans.Add_Course(++number,name,score,credit,Is_politic,Is_retake);
                }
                else{
                    cout<<"Input Course Number And the Score"<<endl;
                    cin>>number;
                    cin>>score;
                    trans.Retake_Course(number,score);
                    trans.Print_Script();
                }
                break;
        }
        cout<<endl<<endl<<endl;
        cout<<"operation:"<<endl<<"1.check transcript"<<endl<<"2.change algorithm"<<endl<<"3.plan"<<endl<<endl<<"current algorithm: ";
        switch (mod) {
            case 1:cout<<"ECUST";break;
            case 2:cout<<"WES";break;
            case 3:cout<<"BeiDa";break;
        }
        cout<<endl<<"input number:";
    }
    return 0;
}
