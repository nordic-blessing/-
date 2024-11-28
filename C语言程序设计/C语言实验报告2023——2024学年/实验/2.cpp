/************************************************/
/*程序名称：2.cpp								*/
/*主要功能：										*/
/*	计算											*/
/************************************************/
#include <iostream>                         // 包含输入输出接口文件
using namespace std;                        // 引用标准命名空间
int main()
{
	int n = 0;
	int i;
	int j, k;
	int sum = 0;
	cout << "please cin 'n':";
	cin >> n;
	for (i = 1;i <= n;i++)
	{
		k = 1;
		for (j = 1;j <= i;j++)
		{
			k = k * j;
		}
		sum = sum + k;
	}
	for (i = 1;i < n;i++)
	{
		cout << i << "!+";
	}
	cout << n << "!= " << sum;
}
