//***************************************************************
//*  程 序 名：9_2.cpp                                          *
//*  主要功能：                                                 * 
//*     利用位域统计学生成绩的各等级人数                        *
//***************************************************************
#include  <iostream> 
using namespace std;
struct{
    unsigned excellent:5;               // 优秀学生人数
    unsigned fine:5;                    // 良好学生人数
    unsigned pass:5;                    // 及格学生人数
    unsigned fail:5;                    // 不及格学生人数
}score;

int main(){
    score.excellent  = 0;
    score.fine  = 0;
    score.pass  = 0;
    score.fail  = 0;
    int s[25] = {100,96 ,97 ,95 ,92 ,88 ,85 ,83 ,84 ,86 ,87 ,79 ,77 ,78 ,73 ,68 ,66 ,68 ,67 ,65 ,64 ,63 ,61 ,58 ,55}; // 学生成绩
    int i;                              //用于表示数组的下标
    for(i = 0; i < 25; i++)
    {
        if(s[i] < 60)                   // 不及格
        {
            score.fail ++;
        }
        else if(s[i] < 69)              // 及格
        {
            score.pass ++;
        }
        else if(s[i] < 89)              // 良
        {
            score.fine ++;
        }
        else                            // 优
        {
            score.excellent ++;
        }
    }
    cout<<"成绩优秀的人数为"<<score.excellent<<endl;
    cout<<"成绩良好的人数为"<<score.fine<<endl;
    cout<<"成绩及格的人数为"<<score.pass<<endl;
    cout<<"成绩不及格的人数为"<<score.fail<<endl;
    return 0;
}
