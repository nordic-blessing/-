#ifndef AVERAGE_H_INCLUDED
#define AVERAGE_H_INCLUDED
//***************************************************************
//*  函 数 名：average                                          *
//*  输入参数                                                   *
//*      score     学生成绩数组                                 *
//*      n         学生总数                                     *
//*  返回值                                                     *
//*      平均成绩                                               *
//*  函数功能：                                                 *
//*      统计并返回score数组平均值                              *
//***************************************************************
double average(int score[], int n)
{
    int sum = 0;                     // 学生的总分数
    int i;                           // 数组下标
    for(i = 0; i < n; i++)
    {
        sum = sum + score[i];
    }
    return sum / (double)n;
}

#endif // AVERAGE_H_INCLUDED
