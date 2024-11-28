//***************************************************************
//*  程 序 名：4_5_2.cpp                                        *
//*  主要功能：                                                 * 
//*     字符数组输入输出示例                                    *
//***************************************************************

#include <iostream>                 // 包含输入输出接口文件
#include <string.h>                 // 包含字符串相关函数定义的头文件
using namespace std;                // 引用标准命名空间 
int main()                          // 主函数
{
    char userName[10] = "";         // 存储用户名的字符数组，实际数组长度为10
    char userName1[4] = {'t','r','e','e'};
    char password[10] = "";         // 存储密码的字符数组，实际数组长度为10

    cout<<"用户名：";
    gets(userName);                 // 不能输入超过9个字符，超过了，执行后会出现数组越界错误，userName中可以包含空格
    cout<<"密  码：";
    cin>>password;                  // 不能输入超过9个字符，超过了，执行后会出现数组越界错误，password中不能包含空格

    cout<<"您的输入：\n";
    cout<<"用户名：";
    puts(userName);                 // 输出用户名，自动加回车 
    cout<<"密  码："<<password<<endl; 
    cout<<"userName1="<<userName1<<endl;
    cout<<"userName1=";
    puts(userName1);                // 会输出不确定的奇怪字符

    return 0;
}
