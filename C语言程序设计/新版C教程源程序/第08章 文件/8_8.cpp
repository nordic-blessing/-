//***************************************************************
//*  函 数 名：freadCourses                                     *
//*  主要功能：                                                 *
//*     将从字节流文件读入课程信息                              *
//*  函数参数：                                                 *
//*     courseArray:    存储课程信息的结构数组                  *
//*     nCourse:        课程门数                                *
//*     fileName:       课程文件名                              *
//*  返回值：                                                   *
//*     1：正确读取文件；其它：文件读取有误                     *
//***************************************************************

#include <iostream>                 // 包含输入输出接口文件
#include <fstream>                  // 包含对文件进行输入输出的头文件
#include "course.h"                 // 包含课程信息定义头文件
using namespace std;                // 引用标准命名空间 

int main()                          // 主函数
{
    const int n = 40;               // 定义数组长度
    CourseInfo courseList[n+1]={0}; // 用于存储所有课程信息的结构数组，
                                    // 下标0不使用，第i门课程的信息存储在下标i处
    int nCourse = 0;                // 课程门数
    if(freadCourses(courseList, nCourse, "course.dat"))
    {
        cout<<"课程信息读入成功！"<<endl;
        writeCourses(courseList, nCourse);
    }

    return 0;
}

int freadCourses(CourseInfo courseArray[], int &nCourse, char fileName[])
{
    ifstream fin(fileName, ios::binary);   
                                    // 以字节流方式打开文件fileName用于读
    if(!fin)
    {
        return -1;                  // 文件打开出错
    }

    nCourse = 0;                    // 初始化课程门数为0
    while(!fin.eof())               // 循环从文件读入课程信息
    {  
        nCourse++;                  // 课程门数增1
        fin.read((char *)(courseArray + nCourse), sizeof(CourseInfo));
        if(strlen(courseArray[nCourse].name) < 1)
        {                           // 如果课程名为空，则忽略当前课程
            nCourse--;      
        }
    }
    fin.close();                   // 关闭文件
    
    return 1;
}