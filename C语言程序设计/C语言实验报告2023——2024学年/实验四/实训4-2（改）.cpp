//***************************************************************
//*  程序名：实训4_1.cpp                                        *
//***************************************************************
#include <iostream>                         // 包含输入输出接口文件
using namespace std;                        // 引用标准命名空间
int main()                                  // 定义主函数
{
    int a = 1, b = 1, counter = 0;        // 定义短整型变量
    for (counter = 0; (counter < 6); counter++)
    {                                       // 计数循环
        a = a * a + b;
        b = a + b * b;
        if(a<0||b<0)
        {
        	break;
		}
    }
    if (a < 0)
    {
        cout << "变量a的值溢出，现在其值为" << a << endl;
    }
    else
    {
        cout << "a的值为" << a << endl;
    }
    return 0;
}                                           // 主函数结束
