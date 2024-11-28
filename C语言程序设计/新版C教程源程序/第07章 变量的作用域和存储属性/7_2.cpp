//***************************************************************
//*  程 序 名：7_2.cpp                                          *
//*  主要功能：                                                 *
//*     测试形参变量的作用域                                    *
//***************************************************************
#include <iostream>                         // 包含输入输出接口文件
using namespace std;                        // 引用标准命名空间
double average(int score[], int n);         // average函数功能：求平均值
int main()
{
    const int STU_NUM = 5;                  // 定义整型常量代表学生人数
    int sco[STU_NUM] = {0};                 // 存放学生成绩的数组
    int i = 0;                              // 数组下标变量i
    double aver = 0;                        // 存放平均值
    cout << "请输入" << STU_NUM << "个学生的有效成绩，回车结束。" << endl;
    for(i = 0; i < STU_NUM; i++)   cin >> sco[i];
    aver = average(sco, STU_NUM);           // 调用求平均成绩的函数average
    cout << "平均成绩为:" << aver << endl;
    return 0;	
}
double average(int score[], int n)
{                                           // average函数开始
    int i = 0;                              // 数组下标变量
    double ave = 0;                         // 平均成绩
    int sum = 0;                            // 成绩总和
    for(i = 0; i < n; i++)
    {
        sum = sum + score[i];               // 累加求和
    }
    ave = sum / (double)n;                  // 求平均
    return ave;                             // 将程序流程和平均值ave返回主调函数
}                                           // average函数结束