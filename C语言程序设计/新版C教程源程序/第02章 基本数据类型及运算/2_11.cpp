//***************************************************************
//*  程 序 名：2_11.cpp                                         *
//*  主要功能：                                                 *
//*     数据输入示例                                            *
//***************************************************************
#include <iostream>                         // 包含输入输出接口文件
using namespace std;                        // 引用标准命名空间 
int main()                                  // 定义主函数
{                                           // 主函数开始
    int studentID;                          // 学号
    double score;                           // 成绩
    int year, month, day;                   // 年、月、日
    scanf("%8d%lf\n", &studentID, &score);
    scanf("%4d%2d%2d",&year, &month, &day);
    printf("studentID = %d, score = %f\n", studentID, score);
    printf("year = %d, month = %d, day = %d\n", year, month, day);
    return 0;                               // 函数返回值为0
}                                           // 主函数结束
