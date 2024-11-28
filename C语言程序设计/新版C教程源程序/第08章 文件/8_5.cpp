//***************************************************************
//*  程 序 名：8_5.cpp                                          *
//*  主要功能：                                                 * 
//*     首先从字节文件中读取奇数序号的学生信息，然后输出之      *
//***************************************************************

#include <iostream>                     // 包含输入输出接口文件
#include <fstream>                      // 包含对文件进行输入输出的头文件
#include "student.h"                    // 包含学生信息定义头文件
using namespace std;                    // 引用标准命名空间 

int main()                              // 主函数
{
    const int N = 100;                  // 定义数组长度
    StudentInfo stuList[N+1] = {0};     // 用于存储所有学生信息的结构数组，
                                        // 下标0不使用，第i位学生的信息存储在下标i处
    int i = 0;                          // 循环变量
    int n = 0;                          // 从文件中读取到的学生人数
    ifstream fin("student.dat", ios::binary);    
                                        // 以字节流方式打开文件student.dat用于读
    if(!fin)
    {
        cout<<"文件打开失败！"<<endl;
        system("pause");                // 等待按任意键后关闭运行窗口
        return -1;                      // 返回错误代码-1
    }

    while(!fin.eof())                   // 循环读取文件，至读到文件结束为止
    {
        n++;                            // 当前学生序号增1
        fin.read((char *)(stuList+n), sizeof(StudentInfo));
        if(!fin.eof())
        {                               // 文件尚未读完，将文件位置指针后移一个学生记录
            fin.seekg(sizeof(StudentInfo), ios::cur); 
        }
        if(strlen(stuList[n].name) < 1)
        {                               // 如果读入的学生姓名为空，则忽略之
            n--;
        }
    }
    fin.close();                        // 关闭输入文件

    cout<<"从文件读入的学生信息："<<endl;
    writeStudentInfoTitle();            // 输出学生信息标题行
    for(i = 1; i <= n; i++)             // 逐行输出学生信息
    {           
         writelnStudent(stuList[i]);
    }
    writeStudentInfoTail();             // 输出学生信息尾部行
    cout<<"\t\t共有 "<<n<<" 位学生"<<endl;

    return 0;
}
