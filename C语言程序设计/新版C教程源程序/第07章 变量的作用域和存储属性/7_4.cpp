//***************************************************************
//*  程 序 名：7_4.cpp                                          *
//*  主要功能：                                                 *
//*     测试同名变量的屏蔽规则                                  *
//***************************************************************
#include <iostream>                         // 包含输入输出接口文件
using namespace std;                        // 引用标准命名空间
int var = 100;                              // 定义全局变量var，具有文件作用域
void varScope()                             // 测试变量作用域的函数
{
    int var = 200;                          // 定义局部变量var，具有函数作用域
    {  
        int var = 300;                      // 定义局部变量var，具有块作用域
        cout << var <<endl;                 // 输出的是具有块作用域的var的值
        cout << ::var <<endl;               // 输出的是具有文件作用域的var的值
    }
    cout << var <<endl;                     // 输出的是具有函数作用域的var的值
    return;                                 // 流程返回主调函数
}
int main()
{
    varScope();                             // 调用varScope函数
    cout << var <<endl;                     // 输出的是具有文件作用域的var的值
    return 0;
}
