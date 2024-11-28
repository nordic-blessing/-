//***************************************************************
//*  程 序 名：8_2.cpp                                          *
//*  主要功能：                                                 * 
//*     首先从文本文件中读取学生信息，然后输出之                *
//***************************************************************

#include <iostream>                 // 包含输入输出接口文件
#include <fstream>                  // 包含对文件进行输入输出的头文件
#include "student.h"                // 包含学生信息定义头文件
using namespace std;                // 引用标准命名空间 

int main()                          // 主函数
{
    const int N = 100;              // 定义数组长度
    StudentInfo stuList[N + 1];     // 用于存储所有学生信息的结构数组，
                                    // 下标0不使用，第i位学生的信息存储在下标i处
    int i = 0;                      // 循环变量
    int n = 0;                      // 从文件中读取到的学生人数
    ifstream fin("student.txt");    // 以字符流方式打开文件student.txt用于读

    if(!fin)
    {
        cout<<"文件打开失败！"<<endl;
        system("pause");            // 等待按任意键后关闭运行窗口
        return -1;                  // 返回错误代码-1
    }

    char propertyName[20] = "";     // 用于读取文件中的属性名称
    char propertyValue[20] = "";    // 用于读取文件中属性的值

    while(!fin.eof())               // 循环读取文件，至读到文件结束为止
    {
        fin>>propertyName;          // 读入姓名行的属性名称
        if(strcmp(propertyName, "姓名") != 0)
        {                           // 未读到姓名，转向读入下一行内容
            continue;
        }

        n++;                        // 开始读取第n位同学的信息
        fin.getline(stuList[n].name, 20);

        fin>>propertyName;          // 读入学号行的属性名称
        fin.getline(stuList[n].no, 20);

        fin>>propertyName;          // 读入性别行的属性名称
        fin.getline(propertyValue, 20);
        if(strstr(propertyValue, "男") >= 0)
        {
            stuList[n].sexy = 1;
        }
        else
        {
            stuList[n].sexy = 0;
        }

        fin>>propertyName;          // 读入生日行的属性名称
        fin.getline(propertyValue, 20);
        stuList[n].birthday = str2date(propertyValue);

        fin>>propertyName;          // 读入身高行的属性名称
        fin>>stuList[n].height;     // 读入身高，然后跳过本行
        fin.getline(propertyValue, 20);

        fin>>propertyName;          // 读入体重行的属性名称
        fin>>stuList[n].weight;     // 读入体重，然后跳过本行
        fin.getline(propertyValue, 20);

        fin>>propertyName;          // 读入电话行的属性名称
        fin.getline(stuList[n].telephone, 20);

        fin>>propertyName;          // 读入e_mail行的属性名称
        fin.getline(stuList[n].e_mail, 40);

        fin>>propertyName;          // 读入QQ行的属性名称
        fin.getline(stuList[n].qq, 20);
    }
    fin.close();                    // 关闭输入文件

    cout<<"从文件读入的学生信息："<<endl;
    writeStudentInfoTitle();        // 输出学生信息标题行
    for(i = 1; i <= n; i++)         // 逐行输出学生信息
    {           
         writelnStudent(stuList[i]);
    }
    writeStudentInfoTail();         // 输出学生信息尾部行
    cout<<"\t\t共有 "<<n<<" 位学生"<<endl;

    return 0;
}
