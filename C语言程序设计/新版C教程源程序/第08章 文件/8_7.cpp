//***************************************************************
//*  函 数 名：fwriteCourses                                    *
//*  主要功能：                                                 *
//*     将课程信息存入字节流文件                                *
//*  函数参数：                                                 *
//*     courseArray:    存储课程信息的结构数组                  *
//*     nCourse:        课程门数                                *
//*     fileName:       课程文件名                              *
//*  返回值：                                                   *
//*     1：正确写入文件；其它：文件写入有误                     *
//***************************************************************

#include <iostream>                 // 包含输入输出接口文件
#include <fstream>                  // 包含对文件进行输入输出的头文件
#include "course.h"                 // 包含课程信息定义头文件
using namespace std;                // 引用标准命名空间 

int main()                          // 主函数
{
    const int n = 40;               // 定义课程门数
    CourseInfo courseList[n + 1];   // 用于存储所有课程信息的结构数组，
                                    // 下标0不使用，第i门课程的信息存储在下标i处
    int i = 0;                      // 循环变量
    for(i = 1; i <= n; i++)
    {
        cout<<"输入第 "<<i<<" 门课程的信息："<<endl;
        courseList[i] = readCourse();
    }

    if(fwriteCourses(courseList, n, "course.dat"))
    {
        cout<<"课程信息写入成功！"<<endl;
    }

    return 0;
}

int fwriteCourses(CourseInfo courseArray[], int nCourse, char fileName[])
{
    int i = 0;                      // 循环变量
    ofstream fout(fileName, ios::binary);   
                                    // 以字节流方式打开文件fileName用于写
    if(!fout)
    {
        return -1;                  // 文件打开出错
    }

    for(i = 1; i <= nCourse; i++)   // 循环将课程信息写入文件
    {   
        fout.write((char *)(courseArray+i), sizeof(CourseInfo));
    }
    fout.close();                   // 关闭文件
    
    return 1;
}