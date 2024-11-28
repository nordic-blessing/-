//***************************************************************
//*  程 序 名：4_5_3.cpp                                        *
//*  主要功能：                                                 * 
//*     字符串相关函数示例                                      *
//***************************************************************

#include <iostream>                 // 包含输入输出接口文件
#include <string.h>                 // 包含字符串相关函数定义的头文件
using namespace std;                // 引用标准命名空间 
int main()                          // 主函数
{
    char userName[20] = "Chengdu";  // 存储用户名的字符数组，实际数组长度为20
    char userName1[10] = "Sichuan";
    char password[20] = " Chengdu"; // 存储密码的字符数组，实际数组长度为20
    
    cout<<"userName原为："<<userName<<endl;
    cout<<"其中的字符数："<<strlen(userName)<<endl;
    
    strcpy(userName, userName1);    // userName1复制到userName中
    cout<<"将userName1复制到userName后，userName为："<<userName<<endl;
    
    strncpy(userName, password, 3); // 将password的前三个字符复制到userName中
    cout<<"将password前三个字符复制到userName后，userName为："<<userName<<endl;

    //strcat(userName, "1234567890123");    // 字符串拼接，但拼接后的字符串长度超过了userName的数组长度，执行后出现数组越界错误
    strcat(userName, password);     // 将password中的字符拼接到userName后
    cout<<"将password拼接到userName后，userName为："<<userName<<endl;

    strcpy(userName, "Chengdu");
    strcpy(userName1, "Sichuan");   // 恢复userName和userName1的原值
    cout<<"userName<userName1="<<(userName>userName1)<<endl;
    cout<<"strcmp(userName, userName1)="<<strcmp(userName, userName1)<<endl;

    return 0;
}
