//***************************************************************
//*  程 序 名：4_6.cpp                                          *
//*  主要功能：                                                 * 
//*     密码文本加密                                            *
//*     使用移位加密法，密文序号为明文序号乘3                   *
//***************************************************************

#include <iostream>                 // 包含输入输出接口文件
#include <string.h>                 // 包含字符串相关函数定义的头文件
using namespace std;                // 引用标准命名空间 
int main()                          // 主函数
{
    char password[20] = "";         // 存储密码的字符数组
    char encodePass[20] = "";       // 加密后的密码
    char ch;                        // 当前字符
    int i;                          // 循环变量
    int n;                          // 密码字符串长度
    int num;                        // 字符

    cout<<"密  码：";
    cin>>password;

    n = strlen(password);           // 获取密码长度
    for(i = 0; i < n; i++)          // 计数循环，对密码字符依次进行处理
    {
        ch = password[i];
        if(ch >= 'a' && ch <= 'z')
        {                           // 小写字母
            num = ch - 'a' + 1;     // 计算字母序号
        }
        else if(ch >= 'A' && ch <= 'Z')
        {                           // 大字字母
            num = ch - 'A' + 27;    // 计算字母序号
        }
        else
        {
            encodePass[i] = ch;     // 其它字符，直接复制
            continue;               // 直接转向处理下一字符
        }

        num = num * 3 % 52;         // 密文字母序号
        if(num == 0)                // 处理字符Z
        {
            num = 52;
        }
        if(num <= 26)
        {
            ch = 'a' + num - 1;     // 将密文序号转为小写字母
        }
        else
        {
            ch = 'A' + num -27;     // 将密文序号转为大写字母
        }
        encodePass[i] = ch;         // 将密文字符存储到密文字符数组中
    }
    encodePass[i] = '\0';           // 为密文字符串加上结束标记

    cout<<"加密后的密码为："<<encodePass<<endl;

    return 0;
}
