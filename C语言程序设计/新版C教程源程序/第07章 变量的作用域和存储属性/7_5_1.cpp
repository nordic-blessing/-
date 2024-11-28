//***************************************************************
//*  程 序 名：7_5_1.cpp                                        *
//*  主要功能：                                                 *
//*     测试外部变量的作用域延伸到源文件7_6_2.cpp               *
//***************************************************************
#include <iostream>                         // 包含输入输出接口文件
using namespace std;                        // 引用标准命名空间令
static int score[10] = { 0 };                      // 定义外部数组
static int maxScore = 0, minScore = 0;             // 定义外部变量
void find_Max_Min();
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
