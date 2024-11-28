//***************************************************************
//*  程 序 名：2_5.cpp                                          *
//*  主要功能：                                                 *
//*     单个字符输出示例                                        *
//***************************************************************
#include <iostream>                         // 包含输入输出接口文件
using namespace std;                        // 引用标准命名空间 
int main()                                  // 定义主函数
{                                           // 主函数开始
    char c1='a' ;                           // 定义字符型变量c1，并赋初值为a
    putchar('a');                           // 输出一个字符常量a 
    putchar(c1);                            // 输出一个字符变量 
    putchar('\n');                          // 输出换行符，使光标下移到下一行的开头 
    putchar(65);                            // 输出ASCII码为65的字符，即A. 
    putchar(c1 - 32);                       // 输出ASCII码为65(97-32=65）的字符A 
    return 0;                               // 函数返回值为0
}                                           // 主函数结束
