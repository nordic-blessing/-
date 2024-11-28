//***************************************************************
//*  程 序 名：7_7.cpp                                          *
//*  主要功能：                                                 *
//*     使用静态局部变量计算1～6的阶乘                          *
//***************************************************************
#include <iostream>                         // 包含输入输出接口文件
using namespace std;                        // 引用标准命名空间
int fact(int n)                             // 计算n的阶乘
{
	static int result = 1;                  // 定义静态变量result并初始化
	result = result * n;                    // 计算n的阶乘
	return result;                          // 将程序的执行流程和result的值带回到主调函数
}
int main()
{
	for(int i = 1; i <= 6; i++)
    {
        cout << i << "!= " << fact(i) <<endl;
    }
    return 0;
}
