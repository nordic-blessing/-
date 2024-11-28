//***************************************************************
//*  程 序 名：4_9.cpp                                          *
//*  主要功能：                                                 *
//*     学生信息的存储、输入、排序和输出                        *
//*     使用计数循环输入学生信息后，                            *
//*     使用冒泡排序法按身高从小到大排序                        *
//*     最后依次输出学生信息                                    *
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
    const int n = 40;               // 定义学生人数
    StudentInfo stuList[n + 1] = {0};                
                                    // 用于存储所有学生信息的结构数组，全部初始化为0，下标0不使用，第i位学生的信息存储在下标i处
    int i = 0, j = 0;               // 循环变量
    int changed = 0;                // 冒泡排序中，标志一趟扫描中是否进行了交换

    for(i = 1; i <= n; i++)         // 循环输入每位学生的信息
    {
        cout<<"请输入第 "<<i<<" 位学生信息："<<endl;
        cout<<"  姓名：\t\t";
        fflush(stdin);              // 清空输入缓冲区，避免以前的输入干扰gets_s输入正确的姓名
        gets_s(stuList[i].name);
        cout<<"  学号：\t\t";
        cin>>stuList[i].no;
        cout<<"  密码：\t\t";
        cin>>stuList[i].password;
        cout<<"  性别(0为女, 1为男)：\t";
        cin>>stuList[i].sexy;
        cout<<"  生日："<<endl;
        cout<<"    年：\t\t";
        cin>>stuList[i].birthday.year;
        cout<<"    月：\t\t";
        cin>>stuList[i].birthday.month;
        cout<<"    日：\t\t";
        cin>>stuList[i].birthday.day;
        cout<<"  身高：\t\t";
        cin>>stuList[i].height;
        cout<<"  体重：\t\t";
        cin>>stuList[i].weight;
        cout<<"  电话：\t\t";
        cin>>stuList[i].telephone;
        cout<<"  E_mail：\t\t";
        cin>>stuList[i].e_mail;
        cout<<"  QQ号：\t\t";
        cin>>stuList[i].qq;
    }

    for(i = 1; i < n; i++)          // 使用冒泡排序将学生信息按身高从低到高排序
    {
        changed = 0;
        for(j = 1; j <= n - i; j++)
        {
            if(stuList[j].height > stuList[j+1].height)
            {                       // 如果相邻学生的身高逆序,则以stuList[0]为临时变量交换之
                stuList[0] = stuList[j];
                stuList[j] = stuList[j + 1];
                stuList[j + 1] = stuList[0];
                changed = 1;
            }
        }
        if(!changed)                // 如果一趟扫描未发生交换，则退出排序
        {
            break;
        }
    }

    cout<<"序号\t姓名\t身高"<<endl;
    for(i = 1; i <= n; i++)         // 顺序输出各位学生的姓名和身高
    {
        cout<<i<<"\t";
        cout<<stuList[i].name<<"\t";
        cout<<stuList[i].height<<endl;
    }

    return 0;
}
