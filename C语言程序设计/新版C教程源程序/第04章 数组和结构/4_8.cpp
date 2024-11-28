//***************************************************************
//*  程 序 名：4_8.cpp                                          *
//*  主要功能：                                                 * 
//*     学生个人信息的存储和表示                                *
//*     首先定义结构类型，再使用此类型定义变量，于输入输出它    *
//***************************************************************

#include <iostream>                 // 包含输入输出接口文件
using namespace std;                // 引用标准命名空间 
struct Date                         // 定义日期类型
{
    int year;                       // 年
    int month;                      // 月
    int day;                        // 日
};

struct StudentInfo                  // 定义学生信息结构体类型
{
    char no[20];                    // 学号
    char name[20];                  // 姓名
    char password[20];              // 密码
    int sexy;                       // 性别（1为男，0为女）
    double height;                  // 身高
    double weight;                  // 体重
    char telephone[20];             // 电话
    char e_mail[40];                // E_mail
    char qq[20];                    // QQ号
    Date birthday;                  // 生日
};
int main()                          // 主函数
{
    StudentInfo stu;                // 定义学生类型变量

    cout<<"请输入学生信息："<<endl;
    cout<<"  姓名：\t\t";
    gets_s(stu.name);
    cout<<"  学号：\t\t";
    cin>>stu.no;
    cout<<"  密码：\t\t";
    cin>>stu.password;
    cout<<"  性别(0为女, 1为男)：\t";
    cin>>stu.sexy;
    cout<<"  生日："<<endl;
    cout<<"    年：\t\t";
    cin>>stu.birthday.year;
    cout<<"    月：\t\t";
    cin>>stu.birthday.month;
    cout<<"    日：\t\t";
    cin>>stu.birthday.day;
    cout<<"  身高：\t\t";
    cin>>stu.height;
    cout<<"  体重：\t\t";
    cin>>stu.weight;
    cout<<"  电话：\t\t";
    cin>>stu.telephone;
    cout<<"  E_mail：\t\t";
    cin>>stu.e_mail;
    cout<<"  QQ号：\t\t";
    cin>>stu.qq;

    cout<<"您输入的个人信息如下："<<endl;
    cout<<"  姓名：\t\t"<<stu.name<<endl;
    cout<<"  学号：\t\t"<<stu.no<<endl;
    cout<<"  性别：\t\t"<<(stu.sexy==1?"男":"女")<<endl;
    cout<<"  生日：\t\t"<<stu.birthday.year<<"年"
        <<stu.birthday.month<<"月"<<stu.birthday.day<<"日"<<endl;
    cout<<"  身高：\t\t"<<stu.height<<endl;
    cout<<"  体重：\t\t"<<stu.weight<<endl;
    cout<<"  电话：\t\t"<<stu.telephone<<endl;
    cout<<"  E_mail：\t\t"<<stu.e_mail<<endl;
    cout<<"  QQ号：\t\t"<<stu.qq<<endl;

    return 0;
}
