//***************************************************************
//*  程 序 名：1_2.cpp                                          *
//*  主要功能：                                                 * 
//*     输入平时成绩和期终考试成绩，求学期成绩                  *
//***************************************************************
#include <iostream>                         // 包含输入输出接口文件
using namespace std;                        // 引用标准命名空间 
int main()                                  // 定义主函数
{                                           // 主函数开始
    double peacetimeScore = 0;              // 定义平时成绩并初始化为0
    double finalExamScore = 0;              // 定义期终考试成绩并初始化为0
    double termScore = 0;                   // 定义学期成绩并初始化为0    
    cout<<"请输入平时成绩：";               // 输入提示
    cin>>peacetimeScore;                    // 输入平时成绩 
    cout<<"期终考试成绩：";                 // 输入提示
    cin>>finalExamScore;                    // 输入期终考试成绩
    termScore = peacetimeScore * 0.3 + finalExamScore * 0.7;    // 计算学期成绩
    cout<<"学期成绩："<<termScore<<endl;    // 输出学期成绩
    return 0;                               // 函数返回值为0
}                                           // 主函数结束
