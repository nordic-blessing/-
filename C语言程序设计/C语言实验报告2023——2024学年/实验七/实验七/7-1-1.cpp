//***************************************************************
//*  程 序 名：实训7-1-1.cpp                                      *
//*  主要功能：                                                 *
//*     学生信息的存储、输入、排序和输出                        *
//*     使用计数循环输入学生信息后，                            *
//*     使用冒泡排序法按身高从小到大排序                        *
//*     最后依次输出学生信息                                    *
//***************************************************************
#include <iostream>                         // 包含输入输出接口文件
#include "student.h"
using namespace std;                        // 引用标准命名空间

int main()                                  // 主函数
{
    const int n = 2;                       // 定义学生人数
    StudentInfo stuList[n + 1] = { 0 };
    // 用于存储所有学生信息的结构数组，全部初始化为0，
    // 下标0不使用，第i位学生的信息存储在下标i处
    int i = 0, j = 0;                       // 循环变量
    int changed = 0;                        // 标志一趟扫描中是否进行了交换
    for (i = 1; i <= n; i++)                 // 循环输入每位学生的信息
    {
        cout << "请输入第" << i << "位学生信息：" << endl;
        stuList[i] = readStudent();
    }
    for (i = 1; i < n; i++)                  // 将学生信息按身高从低到高排序
    {
        changed = 0;
        for (j = 1; j <= n - i; j++)
        {
            if (stuList[j].height > stuList[j + 1].height)
            {       // 如果相邻学生的身高逆序,则以stuList[0]为临时变量交换之
                stuList[0] = stuList[j];
                stuList[j] = stuList[j + 1];
                stuList[j + 1] = stuList[0];
                changed = 1;
            }
        }
        if (!changed)                        // 如果一趟扫描未发生交换，则退出排序
        {
            break;
        }
    }
    cout << "序号\t姓名\t身高" << endl;
    for (i = 1; i <= n; i++)                 // 顺序输出各位学生的姓名和身高
    {
        cout << i << "\t";
        cout << stuList[i].name << "\t";
        cout << stuList[i].height << endl;
    }
    return 0;
}