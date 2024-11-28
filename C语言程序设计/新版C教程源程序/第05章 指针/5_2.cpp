//***************************************************************
//*  程 序 名：5_2.cpp                                          *
//*  主要功能：                                                 *
//*     测试交换两个指针变量的指向                              *
//***************************************************************
#include <iostream>                         // 宏包含预编译命令
using namespace std;                        // 引用标准命名空间
int main()                                
{
    int *p_max = 0, *p_min = 0, *p = 0;     // 定义指向整型的指针变量并初始化为0
    int C_score = 0, math_score = 0;        // 定义变量用来存放C成绩和数学成绩
    cin>>C_score>>math_score;               // 从键盘输入C成绩和数学成绩放入对应的变量中
    p_max = &C_score;                       // 首先, p_max 指向 C_score
    p_min = &math_score;                    // p_min指向math_score 
    if(math_score > C_score)                // 如果数学成绩较高	
    {
        p = p_max, p_max = p_min, p_min = p;//交换p_max和p_min的内容
    }   
    cout << "C_score=" << C_score << ",";
    cout << "math_score=" << math_score << endl;
    cout << "Highscore=" << *p_max << "," << "Lowscore=" << *p_min << endl;	   
    return 0;
}
