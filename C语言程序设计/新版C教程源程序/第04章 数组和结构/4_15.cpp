//***************************************************************
//*  程 序 名：4_15.cpp                                         *
//*  主要功能：                                                 *
//*     按姓名对学生信息进行模糊查找                            *
//***************************************************************

#include <iostream>                 // 包含输入输出接口文件
#include <string.h>                 // 包含字符串处理头文件
#include "student.h"                // 包含学生信息定义头文件
using namespace std;                // 引用标准命名空间 

int main()                          // 主函数
{
    const int n = 40;               // 定义学生人数
    StudentInfo stuList[n + 1];     // 用于存储所有学生信息的结构数组，
                                    // 下标0不使用，第i位学生的信息存储在下标i处
    int i = 0;                      // 循环变量
    int count = 0;                  // 查找到的学生人数
    char name[20] = "";             // 姓名

    for(i = 1; i <= n; i++)         // 循环输入每位学生的信息
    {
        cout<<"请输入第 "<<i<<" 位学生信息："<<endl;
        stuList[i] = readStudent();
    }
    
    fflush(stdin);                  // 清空输入缓冲区
    cout<<"请输入待查找姓名：";
    gets_s(name);

    cout<<"查找结果："<<endl;
    writeStudentInfoTitle();        // 输出学生信息标题行
    for(i = 1; i <= n; i++)         // 依次查找各位学生的姓名是否符合条件
    {
        if(strstr(stuList[i].name, name))
        {                           // 查找成功，则输出当前学生信息
            writelnStudent(stuList[i]);
            count++;                // 查找到的学生数增1
        }
    }
    writeStudentInfoTail();         // 输出学生信息尾部行
    cout<<"共计找到 "<<count<<" 位学生"<<endl;

    return 0;
}
