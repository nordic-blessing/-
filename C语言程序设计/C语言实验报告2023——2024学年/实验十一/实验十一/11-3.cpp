#include<iostream>
using namespace std;
struct Result {
	double ave;  // 平均值
	int max;     // 最大值
	int min;     // 最小值
};

// 统计函数，输入二十个数，找出最大值、最小值以及它们的平均值
Result count()
{
	int num[21];  // 存储输入的二十个数
	int i, j, max = 0, min = 0;  // max用于保存最大值，min用于保存最小值
	double sum = 0, ave = 0;    // sum用于保存累加和，ave用于保存平均值
	for (i = 1; i <= 20; i++)
	{
		cout << "请输入第" << i << "个数：";
		cin >> num[i];
	}
	max = num[1], min = num[1], sum = num[1];  // 初始化max、min和sum为第一个数
	for (j = 2; j <= 20; j++)
	{
		if (num[j] > max)   // 如果当前数大于max，则更新max
		{
			max = num[j];
		}
		else if (num[j] < min)  // 如果当前数小于min，则更新min
		{
			min = num[j];
		}
		else
		{
			continue;
		}
		sum = sum + num[j];  // 累加每个数到sum中
	}
	ave = sum / 19;  // 计算平均值，注意要除以19而不是20，因为第一个数已经被加入sum中
	Result res = { ave, max, min };  // 创建结果结构体并赋值
	return res;  // 返回结果结构体
}

int main()
{
	Result res = count();  // 调用统计函数获取结果
	cout << "最大值为：" << res.max << endl;  // 输出最大值
	cout << "最小值为：" << res.min << endl;  // 输出最小值
	cout << "平均值为：" << res.ave << endl;  // 输出平均值
	return 0;
}