//***************************************************************
//*  程 序 名													*
//*  主要功能：  实训3											* 
//*     求Fibonacci 数列											*
//***************************************************************
#include <iostream>
using namespace std;
int fibonacci(int n);
int main()
{
	int n = 0;
	cout << "请输入整数：";
	cin >> n;
	cout << "Fibonacci 数列的第 " << n << " 项为：" << fibonacci(n) << endl;
}
//***************************************************************
//*  函数名：fibonacci                                           *
//*  参  数：  整数                                            *
//*  返回值：？？？                                             *
//*         整数                                                *
//*  功  能：返回Fibonacci 数列的第n项                          *
//***************************************************************
int fibonacci(int n)
{
	if (n == 1 || n == 2)
	{
		return 1;
	}
	else
	{
		return fibonacci(n - 1) + fibonacci(n - 2);
	}
}