//***************************************************************
//*  程 序 名：实训5_1.cpp                                      *
//*  主要功能：                                                 *
//*     从键盘输入某一课程成绩，并进行统计                      *
//***************************************************************
#include <iostream>                         // 包含输入输出接口文件
using namespace std;                        // 引用标准命名空间
int main()                                  // 定义主函数
{
    int count = 0;                          // 选课总人数
    int examScore = 0;                      // 学生成绩
    int maxExamScore = 0;                   // 最高分
    int minExamScore = 0;                   // 最低分
    int totalExamScore = 0;                 // 总分
    int averageExamScore = 0;               // 平均分
    int score_100 = 0;                      // 100分人数
    int score_90_99 = 0;                    // 90～分人数
    int score_80_89 = 0;                    // 80～分人数
    int score_70_79 = 0;                    // 70～分人数
    int score_60_69 = 0;                    // 60～分人数
    int score_0 = 0;                        // 不及格人数
    cout << "请输入学生成绩（0～100）：" << endl;
    cin >> examScore;
    maxExamScore = minExamScore = examScore;
    while (examScore >= 0 && examScore <= 100)
    {                                       // 对符合条件的分值进行统计和计算
        count++;                          // 人数累增
        if (examScore > maxExamScore)        // 记录最高分
        {
            maxExamScore = examScore;
        }
        if (examScore < minExamScore)        // 记录最低分
        {
            minExamScore = examScore;
        }
        switch (examScore / 10)                // 按分数段统计人数
        {
                  case 10: score_100++;   break;
                  case 9:  score_90_99++; break;
                  case 8:  score_80_89++; break;
                  case 7:  score_70_79++; break;
                  case 6:  score_60_69++; break;
                  default: score_0++;
        
}
        totalExamScore += examScore;        // 总分累增
        cin >> examScore;                   // 输入下一个学生的成绩
    }
    averageExamScore = totalExamScore / count;  // 计算平均分
    cout << endl;                           // 以下显示统计信息
    cout << "选课总人数：" << count << endl;
    cout << "最高分：" << maxExamScore << endl;
    cout << "最低分：" << minExamScore << endl;
    cout << "平均分：" << averageExamScore << endl;
    cout << "100分人数：  " << score_100 << endl;
    cout << "90~99分人数：" << score_90_99 << endl;
    cout << "80~89分人数：" << score_80_89 << endl;
    cout << "70~79分人数：" << score_70_79 << endl;
    cout << "60~69分人数：" << score_60_69 << endl;
    cout << "不及格人数： " << score_0 << endl;
    cout << endl;
    system("pause ");
    return 0;
}                                           // 主函数结束
