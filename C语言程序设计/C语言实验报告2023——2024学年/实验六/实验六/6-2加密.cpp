//***************************************************************
//*  程 序 名：实训6_2.cpp                                      *
//*  主要功能：                                                 *
//*     将密码文本加密                                            *
//***************************************************************
#include <iostream>                         // 包含输入输出接口文件
#include <string.h>                         // 包含字符串相关函数定义的头文件
using namespace std;                        // 引用标准命名空间
int main()                                  // 主函数
{
    char password[20] = "";                 // 存储密码的字符数组
    char encodePass[20] = "";               // 加密后的密码
    char ch;                                // 当前字符
    int i;                                  // 循环变量
    int n;                                  //密码字符串长度
    int num;                                // 字符
    cout << "密码：" ;
    cin >> password;
    n = strlen(password);
    for (i = 0; i < n; i++)
    {                                       // 循环至遇到字符结束标记不止
        ch = password[i];
        if (ch >= 'a' && ch <= 'z')
        {                                   // 小写字母
            num = ch - 'a' + 1;             // 计算字母序号
        }
        else if (ch >= 'A' && ch <= 'Z')
        {                                   // 大字字母
            num = ch - 'A' + 27;            // 计算字母序号
        }
        else
        {
            encodePass[i] = ch;               // 其它字符，直接复制
            continue;                       // 直接转向处理下一字符
        }
        num = num * 3 % 52;
        if (num == 0)
            num = 52;
        if (num <= 26)
            ch = num + 'a' - 1;
        else
            ch = num - 27 + 'A';
        encodePass[i] = ch;
    }
    encodePass[i] = '\0';
    cout << "加密后的密码为：" << encodePass << endl;
    return 0;
}