//***************************************************************
//*  程 序 名：5_14.cpp                                         *
//*  主要功能：                                                 *
//*     统计一篇英文文章中的单词数                              *
//***************************************************************
#include <iostream>                         // 包含输入输出接口文件
using namespace std;                        // 引用标准命名空间
int main()
{
    const int MAXSTRING = 50;               // 能处理的字符串的最大长度
    char text[MAXSTRING+1]="";              // 存储文本的数组
    char *p = 0;                            // 指向文本的指针
    unsigned int count = 0;                 // 单词计数器清0
    gets(text);                             // 输入文本
    p = text;                               // 字符指针指向文本的开头
    while(*p != '\0')
    {
        while(isspace(*p))                  // 跳过空格
        {
            p++;
        }
        if(*p != '\0')
        {
            count++;                        // 计单词数
            while(!isspace(*p) && *p!='\0')
            {
                p++;                        // 跳过单词其它字符
            }
        }
    }
    cout << "文本中单词的个数为：" << count << endl;
    return 0;
}
