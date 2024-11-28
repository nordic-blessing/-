///**********************************************************
///  程 序 名：6_1.cpp                                      *
///  主要功能：                                             *
///     显示根据选择显示不同的用户登录界面                  *
///**********************************************************
#include  <iostream>
using namespace std;                            // 引用标准命名空间
struct  StudentPick                     // 学生选课结构体类型
{
    int num;                            // 学生选课纪录编号
    char teacherNo[20];                 // 教师编号
    char courseNo[20];                  // 课程号
    int lessonNum;                      // 课序号
    char studentNo[20];                 // 学号
    double peacetimeScore;              // 平时成绩
    double experimentScore;             // 实验成绩
    double finalExamScore;              // 期终考试成绩
    double termScore;                   // 学期成绩
};
void  updateScore(struct  StudentPick *pick);   // 申明修改学生成绩函数
int main()
{
    return 0;
}

///**********************************************************
///  函 数 名：updateScore                                  *
///  输入参数：                                             *
///      pick：学生选课结构体                               *
///  返回值                                                 *
///      无                                                 *
///  函数功能：                                             *
///      修改该选课结构体中的学生成绩                       *
///**********************************************************
void  updateScore(StudentPick *pick)
{
    do
    {
        cout<<"平时成绩("<<pick->peacetimeScore<<")：\t";
        cin>>pick->peacetimeScore;
        if(pick->peacetimeScore < 0)
        {
            cout<<"平时成绩不能为负！"<<endl;
        }
    }while(pick->peacetimeScore < 0);
    do
    {
        cout<<"实验成绩("<<pick->experimentScore<<")：\t";
        cin>>pick->experimentScore;
        if(pick->experimentScore < 0)
        {
            cout<<"实验成绩不能为负！"<<endl;
        }
    }while(pick->experimentScore < 0);
    do
    {
        cout<<"期终成绩("<<pick->finalExamScore<<")：\t";
        cin>>pick->finalExamScore;
        if(pick->finalExamScore < 0)
        {
            cout<<"期终成绩不能为负！"<<endl;
        }
    }while(pick->finalExamScore < 0);
    do
    {
        cout<<"学期成绩("<<pick->termScore<<")：\t";
        cin>>pick->termScore;
        if(pick->termScore < 0)
        {
            cout<<"学期成绩不能为负！"<<endl;
        }
    }while(pick->termScore < 0);
}
