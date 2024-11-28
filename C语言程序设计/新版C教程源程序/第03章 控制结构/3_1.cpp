//***************************************************************
//*  程 序 名：3_1.cpp                                          *
//*  主要功能：                                                 * 
//*     从键盘输入一个学生的学号、姓名和成绩，并输出            *
//***************************************************************
#include <iostream>                         // 包含输入输出接口文件
using namespace std;                        // 引用标准命名空间 
int main()                                  // 定义主函数
{                                           // 主函数开始
    int StudentNumber;                      // 定义学号变量
    char StudentName[20] = "";              // 定义姓名字符数组
    float score;                            // 定义成绩变量
    cout << "Student number:" ;	
    cin >> StudentNumber;
    cout << "Student name:" ;
    cin >> StudentName;
    cout << "Score:" ;
    cin >> score;
    cout << StudentNumber << "    "<< StudentName << "    "<< score << endl;
    return 0;                               // 函数返回值为0
}                                           // 主函数结束
