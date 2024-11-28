//***************************************************************
//*  程 序 名：10_1.cpp                                         *
//*  主要功能：                                                 *
//*     首先给输入的字符串动态分配存储空间                      *
//*     然后，将字符串变为大写显示                              *
//***************************************************************
#include <iostream>                         // 包含输入输出接口文件
#include <malloc.h>                         // 包含动态内存分配接口文件
using namespace std;                        // 引用标准命名空间
int main( )
{
    int *q = new int[3];
    delete[] q;
    //cout << *q <<endl;
    const int MAXSTRING = 49;               // 定义能处理的字符串的最大长度
    char *ptr = 0, *p = 0;
    ptr = (char*)malloc(MAXSTRING + 1);
    if(ptr == NULL)                         // 内存分配出错检测
    {
        cout << "内存分配出错！" << endl;
        return 1;
    }
    cout << "请输入一个不包含空格的字符串: ";
    cin >> ptr;
    cout << "输入的字符串大写为: " ;
    for(p = ptr; *p != '\0'; p++)
    {
        if('a' <= *p && *p <= 'z')
        {
            *p = *p - 32;
        }
        cout << *p;
    }
    cout << endl;
    free(ptr);                              // 释放动态分配的内存
    return 0;
}
