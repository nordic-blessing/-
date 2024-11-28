//***************************************************************
//*  程 序 名：4_16.cpp                                         *
//*  主要功能：                                                 *
//*     使用直接插入法对学生信息按身高排序，以下标0为监视哨     *
//***************************************************************

#include <iostream>                 // 包含输入输出接口文件
#include "student.h"                // 包含学生信息定义头文件
using namespace std;                // 引用标准命名空间 

int main()                          // 主函数
{
    const int n = 40;               // 定义学生人数
    StudentInfo stuList[n + 1];     // 用于存储所有学生信息的结构数组，
                                    // 下标0不使用，第i位学生的信息存储在下标i处
    int i = 0, j = 0;               // 循环变量

    for(i = 1; i <= n; i++)         // 循环输入每位学生的信息
    {
        cout<<"请输入第 "<<i<<" 位学生信息："<<endl;
        stuList[i] = readStudent();
    }
    
    for(i = 2; i <= n; i++)
    {
        stuList[0] = stuList[i];    // 设置监视哨
        for(j = i - 1; stuList[0].height < stuList[j].height; j--)
        {                           // 如果第j位学生的身高较大，则后移
            stuList[j+1]  = stuList[j];
        }
        stuList[j+1] = stuList[0];  // 第i位学生的信息就位
    }


    cout<<"排序后的学生信息："<<endl;
    writeStudentInfoTitle();        // 输出学生信息标题行
    for(i = 1; i <= n; i++)         // 依次查找各位学生的姓名是否符合条件
    {
        writelnStudent(stuList[i]);
    }
    writeStudentInfoTail();         // 输出学生信息尾部行
    cout<<"总共 "<<n<<" 位学生"<<endl;

    return 0;
}
