//***************************************************************
//*  程 序 名：7_3.cpp                                          *
//*  主要功能：                                                 *
//*     测试全局变量的作用域                                    *
//***************************************************************
#include <iostream>                         // 包含输入输出接口文件
using namespace std;                        // 引用标准命名空间
int sum = 0;                                // 定义全局变量sum存放成绩总和
double average(int score[], int n);         // 申明average函数，功能为求平均值
double average(int score[], int n)
{
    int i = 0;                              // 数组下标变量
    double ave = 0;                         // 平均成绩
    sum = 0;                                // 求和之前累加变量清0
    for(i = 0; i < n; i++)
    {
        sum = sum + score[i];               // 累加求和
    }
    ave = sum / (double)n;                  // 求平均
    return ave;                             // 流程和平均值返回主调函数
}
int main()
{
    const int STU_NUM = 5;                  // 定义整型常量代表学生人数
    int sco[STU_NUM] = {0};                 // 存放学生成绩的数组
    int i = 0;                              // 数组下标变量i
    double aver = 0;                        // 存放平均值
    cout << "输入" << STU_NUM << "个学生的成绩。" << endl;
    for(i = 0; i < STU_NUM; i++)
    {
        cin >> sco[i];
    }
    aver = average(sco, STU_NUM);
    cout << endl << "平均成绩为:" << aver << endl;
    cout << endl << "成绩总和为:" << sum << endl;
    return 0;	
}
