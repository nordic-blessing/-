#ifndef MAX_H_INCLUDED
#define MAX_H_INCLUDED
//***************************************************************
//*  函 数 名：max                                              *
//*  输入参数                                                   *
//*      score     学生成绩数组                                 *
//*      n         学生总数                                     *
//*  返回值                                                     *
//*      最高分                                                 *
//*  函数功能：                                                 *
//*      统计并返回score数组最高分                              *
//***************************************************************
int max(int score[], int n)
{
    int i;                                  // 数组下标
    int max = 0;                            // 最大的分值
    for(i = 0; i < 2; i++)
    {
        if(score[i] > max)
        {
            max = score[i];
        }
    }
    return max;
}
#endif // MAX_H_INCLUDED
