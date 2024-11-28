//***************************************************************
//*  程 序 名：8_3.cpp                                          *
//*  主要功能：                                                 * 
//*     学生个人信息的输入和存储                                *
//*     首先输入学生信息，再将其存储以字节流方式存储到文件中    *
//***************************************************************

#include <iostream>                 // 包含输入输出接口文件
#include <fstream>                  // 包含对文件进行输入输出的头文件
#include "student.h"                // 包含学生信息定义头文件
using namespace std;                // 引用标准命名空间 

int main()                          // 主函数
{
    const int n = 40;               // 定义学生人数
    StudentInfo stuList[n + 1];     // 用于存储所有学生信息的结构数组，
                                    // 下标0不使用，第i位学生的信息存储在下标i处
    int i = 0;                      // 循环变量
    ofstream fout("student.dat", ios::binary);   
                                    // 以字节流方式打开文件student.data用于写
    if(!fout)
    {
        cout<<"文件打开失败！"<<endl;
        system("pause");            // 等待按任意键后关闭运行窗口
        return -1;                  // 返回错误代码-1
    }

    for(i = 1; i <= n; i++)         // 循环输入每位学生的信息
    {
        cout<<"请输入第 "<<i<<" 位学生信息："<<endl;
        stuList[i] = readStudent();
    }

    for(i = 1; i <= n; i++)         // 循环将学生信息写入文件
    {   
        fout.write((char *)(stuList+i), sizeof(StudentInfo));
    }
    fout.close();                   // 关闭文件
    cout<<"学生信息已成功存储到文件student.dat中"<<endl;

    return 0;
}
