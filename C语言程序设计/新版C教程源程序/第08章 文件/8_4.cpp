//***************************************************************
//*  程 序 名：8_4.cpp                                          *
//*  主要功能：                                                 * 
//*     首先从字节文件中读取学生信息，然后输出之                *
//***************************************************************

#include <iostream>                         // 包含输入输出接口文件
#include <fstream>                          // 包含对文件进行输入输出的头文件
#include "student.h"                        // 包含学生信息定义头文件
using namespace std;                        // 引用标准命名空间 

int main()                                  // 主函数
{
    const int N = 100;                      // 定义数组长度
    StudentInfo stuList[N+1] = {0};         // 用于存储所有学生信息的结构数组，
                                            // 下标0不使用，第i位学生的信息存储在下标i处
    int i = 0;                              // 循环变量
    int n = 0;                              // 从文件中读取到的学生人数
    freadStudents(stuList,n,"student.dat"); // 调用函数读取学生信息到结构数组

    cout<<"从文件读入的学生信息："<<endl;
    for(i = 1; i <= n; i++)                 // 逐行输出学生信息
    {           
        cout<<"第 "<<i<<" 位学生："<<endl; 
        writeStudent(stuList[i]);           // 输出第i位学生的信息
    }

    return 0;
}
/*  freadStudents函数已定义在student.h中
void freadStudents(StudentInfo stuList[], int &nStudent, char fileName[])

    ifstream fin(fileName, ios::binary);    // 打开字节流文件fileName用于读
    nStudent = 0;                           // 学生数初始化为零

    if(!fin)
    {
        cout<<"文件打开失败！"<<endl;
        system("pause");                    // 等待按任意键后关闭运行窗口
        return;                             // 返回
    }
    while(!fin.eof())                       // 循环读取文件，至读到文件结束为止
    {
        nStudent++;                         // 当前学生序号增1
        fin.read((char *)(stuList+nStudent), sizeof(StudentInfo));
        if(strlen(stuList[nStudent].name) < 1)
        {                                   // 如果读入的学生姓名为空，则忽略之
            nStudent--;
        }
    }
    fin.close();                            // 关闭输入文件
}
*/