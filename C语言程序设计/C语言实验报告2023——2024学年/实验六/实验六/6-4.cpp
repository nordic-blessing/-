//***************************************************************
//*  程 序 名：实训6_4.cpp                                      *
//*  主要功能：                                                 *
//*     输入字符，将大小写调换，逆序输出						*
//***************************************************************
#include <iostream>                         // 包含输入输出接口文件
#include <string.h>                         // 包含字符串相关函数定义的头文件
using namespace std;                        // 引用标准命名空间
int main()
{
	const int n = 80;						//定义数组长度不超过80
	char type[n];
	int i = 0;

	cout << "请输入字符串：";
	gets_s(type);							//获取输入内容，储存在数组中

	for (i = 0;i <= strlen(type);i++)
	{
		if (type[i] >= 'a' && type[i] <= 'z')		//字符为小写字母
			type[i] = type[i] - 32;					//将小写转换为大写
		else if (type[i] >= 'A' && type[i] <= 'Z')	//字符为大写字母
			type[i] = type[i] + 32;					//将大写转换为小写
	}

	cout << "转换后的字符为：";
	for (i = strlen(type);i >= 0;i--)				//倒序输出
		cout << type[i];
}
