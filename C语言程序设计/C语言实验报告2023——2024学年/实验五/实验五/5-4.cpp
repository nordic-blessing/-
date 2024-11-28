//***********************************************
//*程序名：5-4.cpp								*
//*主要功能：									*
//*		简易的计算程序							*
//***********************************************
#include <iostream>		//包含输入输出接口文件
#include <math.h>
using namespace std;	//引用标准命名空间
int main()				//主函数
{
	double a = 0.0;
	double b = 0.0;
	char chara;			//字符型（运算符）
	cout << "请输入两个数a和b:";
	cin >> a >> b;
	cout << "*****************************************\n";
	cout << "*		*:乘法			*\n";
	cout << "*		/:除法			*\n";
	cout << "*		+:加法			*\n";
	cout << "*		-:减法			*\n";
	cout << "*****************************************\n";
	cout << "请输入运算符<* / + ->,退出程序输入0：";
	cin >> chara;			//输入运算符
	while (chara != '0')	//未结束程序
	{
		switch (chara)
		{					//执行运算
		case '*':
			cout << a * b << endl;	break;
		case '/':
			cout << a / b << endl;	break;
		case '+':
			cout << a + b << endl;	break;
		case '-':
			cout << a - b << endl;	break;
		}
		cout << "请输入运算符<* / + ->,退出程序输入0：";
		cin >> chara;			//输入运算符
	}
	return 0;
}