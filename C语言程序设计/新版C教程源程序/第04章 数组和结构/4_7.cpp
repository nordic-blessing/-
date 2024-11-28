//***************************************************************
//*  程 序 名：4_7.cpp                                          *
//*  主要功能：                                                 * 
//*     密码文本解密                                            *
//*     使用移位加密法，明文序号为密文序号除以3                 *
//***************************************************************

#include <iostream>                 // 包含输入输出接口文件
#include <string.h>                 // 包含字符串相关函数定义的头文件
using namespace std;                // 引用标准命名空间 
int main()                          // 主函数
{
    char password[20] = "";         // 存储密码的字符数组
    char encodePass[20] = "clMAPAehbchSb";      // 加密后的密码 
                                    
    char ch;                        // 当前字符
    int i;                          // 循环变量
    int num;                        // 当前字符字符对应的序号

    for(i = 0; encodePass[i] != '\0' ; i++)          
    {                               // 循环处理密文字符至遇到字符结束标记不止
        ch = encodePass[i];
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
            password[i] = ch;       // 其它字符，直接复制
            continue;               // 直接转向处理下一字符
        }

        if(num % 3 != 0)         // 密文序号=（明文序号*3）% 52
        {
            num = num + 52;
        }
        num = num / 3;              // 得到明文字母序号
        if(num == 0)                // 处理字符Z
        {
            num = 52;
        }
        if(num <= 26)
        {
            ch = 'a' + num - 1;     // 将明文序号转为小写字母
        }
        else
        {
            ch = 'A' + num -27;     // 将明文序号转为大写字母
        }
        password[i] = ch;           // 将明文字符存储到明文字符数组中
    }
    password[i] = '\0';             // 为明文字符串加上结束标记

    cout<<"密码密文："<<encodePass<<endl;
    cout<<"密码明文："<<password<<endl;

    return 0;
}
