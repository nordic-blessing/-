//***************************************************************
//*  程 序 名：4_14.cpp                                         *
//*  主要功能：                                                 *
//*     求最大元音数的单词， 以'#'结束输入                      *
//***************************************************************

#include <iostream>                 // 包含输入输出接口文件
#include <string.h>
using namespace std;                // 引用标准命名空间 

int main()                          // 主函数
{
    const int MaxChar = 80;         // 单词最大长度
    int index = 0;                  // 当前单词的当前字符所在的数组下标
    int num = 0;                    // 当前单词元音数
    int maxNum = 0;                 // 最大元音数
    char ch;                        // 当前字符
    char word[MaxChar] = "";        // 当前单词
    char maxWord[MaxChar] = "";     // 最大元音数单词

    cout<<"请输入文本，以#结束："<<endl;
    do
    {
        ch = getchar();             // 注意不要使用cin，否则会忽略单词间的空格
        if(ch == ' ' || ch == '\t' || ch == '\n' || ch == '#')
        {                           // 读到单词间的分隔符或结束符
            word[index] = '\0';     // 为当前单词加上结束符

            if(num > maxNum)
            {                       // 当前单词元音数大于原最大元音数，则保存之
                maxNum = num;
                strcpy(maxWord, word);
            }
            num = 0;                // 当前单词元音数置为0
            index = 0;              // 当前单词的当前字符所在下标置为0
        }
        else
        {                           // 读到普通字符
            word[index] = ch;       // 将当前字符写入到当前单词
            index ++;               // 数组下标增1，为写入下一字符作准备
            if(ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u'||
                ch == 'A' || ch == 'E' || ch == 'I' || ch == 'O' || ch == 'U')
            {                       // 如果当前字符是元音字母
                num++;              // 则元音数增1
            }
        }
    }while(ch != '#');

    cout<<"最大元音数单词："<<maxWord<<endl;
    cout<<"最大元音数："<<maxNum<<endl;

    return 0;
}
