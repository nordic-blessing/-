//***************************************************************
//*  程 序 名：7_9.cpp                                          *
//*  主要功能：                                                 *
//*     使用静态全局变量求10个成绩的最大值和最小值              *
//***************************************************************
#include <iostream>                         // 包含输入输出接口文件
using namespace std;                        // 引用标准命名空间
static int score[10] = { 0 };               // 定义静态全局数组
static int maxScore = 0, minScore = 0;      // 定义静态全局变量
void find_Max_Min();                        // 函数声明
int main()
{
    int i = 0;                              // 数组下标变量
    cout << "Enter 10 scores:" << endl;
    for(i = 0; i < 10; i++)
    {
        cin >> score[i];
    }
    maxScore = minScore = score[0];
    find_Max_Min();                         // 调用函数find_Max_Min()
    cout << "The Max score: " << maxScore << endl;
    cout << "The Min score: " << minScore << endl;
    return 0;
}
void find_Max_Min()                         // 求最大值和最小值函数
{
    int i = 0;                              // 数组下标变量
    for(i = 0; i < 10; i++)
    { 
        if(score[i] > maxScore)
        {
            maxScore = score[i];
        }
        if(score[i] < minScore)
        {
            minScore = score[i];
        }
    }
    return;                                 // 将程序的执行流程带回到主调函数
}
