//***************************************************************
//*  程 序 名：2_8.cpp                                          *
//*  主要功能：                                                 *
//*     浮点型数据的输出示例                                    *
//***************************************************************
#include <iostream>                         // 包含输入输出接口文件
using namespace std;                        // 引用标准命名空间 
int main()                                  // 定义主函数
{                                           // 主函数开始
    float x = 344.972;                      // 定义单精度变量x并初始化
    printf("%f**%10f**%10.2f**%.2f**%-10.2f\n", x, x, x, x, x);
    printf("%e",344.972);
    return 0;                               // 函数返回值为0
}                                           // 主函数结束
