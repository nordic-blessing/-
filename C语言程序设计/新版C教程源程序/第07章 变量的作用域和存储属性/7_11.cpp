//***************************************************************
//*  程 序 名：7_11.cpp                                         *
//*  主要功能：                                                 *
//*     实现数的不同进制间的转换                                *
//***************************************************************
#include <iostream>                         // 包含输入输出接口文件
using namespace std;                        // 引用标准命名空间
int b;                                      // 全局变量，数制基数
int i = 0;                                  // 全局变量，循环变量
int c[50];                                  // 全局变量，转换后各数位
int n;                                      // 全局变量，待转换的数
void convert();                             // 申明进制转换函数
int main()
{  
	char base[] = "0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZ"; 
	int j, m;
  
	cout << "输入一个十进制整数：";
	cin >> n;
	cout << "输入数制基数：";
	cin >> b;
	
	m = n;
	convert();                              // 调用函数进行进制转换
	cout << m <<"转换成" << b <<"进制数为:";
	for(i--; i >= 0; i--)                   // 依次输出转换后的各数位
    { 
		j = c[i];
		cout << base[j] ;
    }
	cout << endl;
	return 0;
}

void convert()                              // 进制转换函数，使用长除法
{
	while(n != 0)
	{
		c[i] = n % b;                       // 取得当前数位
		n = n / b ;
		i++;                                // 转换后的数的位数增1
	}
	return;
}
