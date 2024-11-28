//***************************************************************
//*  程 序 名：8_6.cpp                                          *
//*  主要功能：                                                 * 
//*     首先从字节文件中读取学生信息，然后以表格形式输出之      *
//***************************************************************

#include <iostream>                 // 包含输入输出接口文件
#include <fstream>                  // 包含对文件进行输入输出的头文件
#include "student.h"                // 包含学生信息定义头文件
using namespace std;                // 引用标准命名空间 

int main()                          // 主函数
{
    const int N = 100;              // 定义数组长度
    StudentInfo stuList[N+1] = {0}; // 用于存储所有学生信息的结构数组，
                                    // 下标0不使用，第i位学生的信息存储在下标i处
    int i = 0;                      // 循环变量
    int n = 0;                      // 从文件中读取到的学生人数
    freadStudents(stuList, n, "student.dat");

    cout<<"从文件读入的学生信息："<<endl;
    writeStudents(stuList, n);

    return 0;
}
