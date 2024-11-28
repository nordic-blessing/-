//***************************************************************
//*  程 序 名：4_11.cpp                                         *
//*  主要功能：                                                 *
//*     按学号对学生信息进行顺序查找                            *
//***************************************************************

#include <iostream>                 // 包含输入输出接口文件
#include "student.h"                // 包含学生信息定义头文件
using namespace std;                // 引用标准命名空间 

int main()                          // 主函数
{
    const int n = 40;               // 定义学生人数
    StudentInfo stuList[n + 1];     // 用于存储所有学生信息的结构数组，
                                    // 下标0不使用，第i位学生的信息存储在下标i处
    int i = 0;                      // 循环变量
    char no[20] = "";               // 学号

    for(i = 1; i <= n; i++)         // 循环输入每位学生的信息
    {
        cout<<"请输入第 "<<i<<" 位学生信息："<<endl;
        stuList[i] = readStudent();
    }
    
    cout<<"请输入待查找学号：";
    cin>>no;

    strcpy(stuList[0].no, no);      // 设置监视哨
    for(i = n; strcmp(stuList[i].no, no) != 0; i--);
                                    // 按学号顺序查找
    if(i > 0)
    {                               // 查找成功
        cout<<"查找成功！学生信息为："<<endl;
        writeStudent(stuList[i]);   // 输出查找到的学生信息
    }
    else
    {
        cout<<"未查找到您所输入的学号！"<<endl;
    }

    return 0;
}
