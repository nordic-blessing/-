#ifndef COUNTER_H_INCLUDED    //ifndef的作用为防止重定义
#define COUNTER_H_INCLUDED
#include <iostream>
using namespace std;
//***************************************************************
//*  函 数 名：counter                                          *
//*  输入参数                                                   *
//*      score     学生成绩数组                                 *
//*      n         学生总数                                     *
//*  返回值                                                     *
//*      无                                                     *
//*  函数功能：                                                 *
//*      统计并输出score数组各分数段的人数                      *
//***************************************************************
void counter(int score[], int n)
{
    int i;                    // 用于存储数组下标
    int grade_1 = 0;          // 用于存储90~100分的人数
    int grade_2 = 0;          // 用于存储80~89分的人数
    int grade_3 = 0;          // 用于存储70~79分的人数
    int grade_4 = 0;          // 用于存储60~69分的人数
    int grade_5 = 0;          // 用于存储60分以下的人数
    for(i = 0; i < n; i++)
    {
        if(score[i] < 60)
        {	
            grade_5++;
        }
        else if(score[i] < 69)
        {
            grade_4++;
        }
        else if(score[i] < 79)
        {
            grade_3++;
        }
        else if(score[i] < 89)
        {
            grade_2++;
        }
        else
        {
            grade_1++;
        }
    }
    cout<<"90～100分的人数为 "<<grade_1<<endl;
    cout<<"80～89分的人数为 "<<grade_2<<endl;
    cout<<"70～79分的人数为 "<<grade_3<<endl;
    cout<<"60～69分的人数为 "<<grade_4<<endl;
    cout<<"60分以下的人数为 "<<grade_5<<endl;
}
#endif