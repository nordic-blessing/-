//***************************************************************
//*  程 序 名：3_11.cpp                                         *
//*  主要功能：                                                 *
//*     从键盘输入若干个整数，                                  *
//*     去掉其中一个最大值和一个最小值，求平均值                *
//***************************************************************
#include <iostream>                         // 包含输入输出接口文件
using namespace std;                        // 引用标准命名空间 
int main()                                  // 定义主函数
{
    float score = 0.0f;                     // 专家打分
    float minScore = 100.0f;                // 最低分
    float maxScore = 0.0f;                  // 最高分
    float sum = 0.0f;                       // 总分
    int i = 0;                              // 专家数
    cout << "输入专家评分，以-1结束：" << endl;
    cin >> score;                           // 输入第一个分数
    minScore = minScore = score;            // 设读入第一个分数为最高分和最低分
    while(score != -1)
    {  
        i ++;                               // 专家数增1
        sum = sum + score;                  // 分数累加
        if(score > maxScore)                // 如果当前分数大于最高分
        {
            maxScore = score;               // 则将最高分更新
        }
        if(score < minScore)                //如果当前分数小于最低分
        {
            minScore = score;               //则将最低分更新
        }
        cin >> score;                       // 输入下一个分数
    }
    sum = sum - maxScore - minScore;        // 去掉一个最高分和一个最低分
    cout << "最后得分：" << sum / (i - 2) << endl;
    return 0;
}                                           // 主函数结束
