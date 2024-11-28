//***************************************************************
//*  程 序 名：7_1.cpp                                          *
//*  主要功能：                                                 *
//*     测试局部变量的作用域                                    *
//***************************************************************
#include <iostream>                         // 包含输入输出接口文件
using namespace std;                        // 引用标准命名空间
int main()
{
    char stuNo[50] = "";                    // 定义字符数组用来存放学号
    unsigned int i = 0 ;                    // 数组下标变量
    unsigned long number = 0;               // 存放转换后得到的整数
    cout << "请输入学生的学号:\t";
    cin >> stuNo;	                        // 从键盘输入整型字符串到字符数组中
    while(stuNo[i] != '\0' && stuNo[i] >= '0' && stuNo[i] <= '9')
    {// 定义局部变量k存放字符stuNo[i]的ASCII码和字符'0' 的ASCII码之差
        int k = stuNo[i] - 48;              // 字符'0' 的ASCII码是48
        number = 10 * number + k;
        i++;		
    }
    cout << "转换出的整数为：" << number <<endl;
    return 0;
}
