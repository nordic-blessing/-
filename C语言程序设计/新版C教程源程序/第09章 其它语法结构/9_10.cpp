//***************************************************************
//*  程 序 名：9_10.cpp                                         *
//*  主要功能：                                                 *
//*     学生成绩统计                                            *
//***************************************************************
#include  <iostream> 
#include "max.h"                                        // 包含定义了max函数的头文件
#include "counter.h"                                    // 包含定义了counter函数的头文件
#include "average.h"                                    // 包含定义了average函数的头文件
using namespace std;

int main()
{
    const int n = 25;                                   // 学生人数
    int score[n] = {100, 96, 97, 95, 92, 88, 85, 83, 84, 86, 87, 79, 77, 78, 73, 68, 66, 68, 67, 65, 64, 63, 61, 58, 55};
    cout<<"最高分："<<max(score, n)<<endl<<endl;
    counter(score, n);
    cout<<endl;
    cout<<"平均成绩："<<average(score, n)<<endl;

    return 0;
}
