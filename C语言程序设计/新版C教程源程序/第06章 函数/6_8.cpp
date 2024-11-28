
#include <iostream>                 // 包含输入输出接口文件
using namespace std;                // 引用标准命名空间
double fact(int n);                 // 申明阶乘函数
int main()
{
    int n = 8;
    cout << n << "!=" << fact(n) << endl;
	return 0;
}

//***********************************************************
//*  函 数 名：fact                                         *
//*  主要功能：                                             *
//*     使用递归函数，利用n!=n*(n-1)!，求n! 的值            *
//***********************************************************
double fact(int n)
{
    if(n == 0)                      // 递归的边界
    {
        return 1;                   // 返回0!的值1
    }
    else
    {
        return n * fact(n - 1);     // 使用递归公式，返回n!的值
    }
}
