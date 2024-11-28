//***************************************************************
//*  程 序 名：4_5.cpp                                          *
//*  主要功能：                                                 * 
//*     用户登录示例                                            *
//*     输入用户名和密码，验证信息是否正确                      *
//*     正确显示登录成功，否则显示登录失败                      *
//***************************************************************

#include <iostream>                 // 包含输入输出接口文件
#include <string.h>                 // 包含字符串相关函数定义的头文件
using namespace std;                // 引用标准命名空间 
int main()                          // 主函数
{
    char mUserName[20] = "admin";   // 预存用户名
    char mPassword[20] = "123456";  // 预存密码
    char userName[20] = "";         // 存储用户名的字符数组
    char password[20] = "";         // 存储密码的字符数组

    cout<<"用户名：";
    cin>>userName;
    cout<<"密  码：";
    cin>>password;

    if(strcmp(userName, mUserName) == 0 && strcmp(password, mPassword) == 0)
    {                               // 将输入的用户名、密码与预存的用户名、密码进行比较
        cout<<"登录成功！"<<endl;
    }
    else
    {
        cout<<"用户名或密码错误，登录失败！"<<endl;
    }

    return 0;
}
