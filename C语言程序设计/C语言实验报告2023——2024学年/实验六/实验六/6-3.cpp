//***************************************************************
//*  程 序 名：实训6_3.cpp                                      *
//*  主要功能：                                                 *
//*     从键盘输入10位学生的身高，然后按低到高的顺序进行排序    *
//***************************************************************
#include <iostream>                         // 包含输入输出接口文件
using namespace std;                        // 引用标准命名空间
int main()
{
	const int n = 10;						//定义学生人数
	double height[n + 1] = { 0 };				//用于存储学生身高，初始化为0
											//下标0不使用，第i位学生的身高储存在下标i处
	int min = 0;
	int i = 0;
	int j = 0;

	cout << "请输入各位学生的身高：" << endl;
	for (i = 1;i <= n;i++)					//输入学生的身高
	{
		cout << "第" << i << "位同学的身高：";
		cin >> height[i];
	}

	for (i = 1 ; i < n ; i++)
	{
		min = i;							//设第i位学生的身高最低
		for (j = i + 1;j <= n;j++)
		{
			if (height[j] < height[min])	//相邻元素逆序
				min = j;					//更改身高最低学生的序号
		}
		if (min != i)						//交换height[min]和height[i]
		{
			height[0] = height[i];
			height[i] = height[min];
			height[min] = height[0];
		}
	}

	cout << "排序后的身高：" << endl;
	for (i = 1;i <= n;i++)					//按从小到大的顺序输出身高值
		cout << " " << height[i];
	return 0;
}