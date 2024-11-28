#include<iostream>
using namespace std;
void count(int m, int n, int& gb, int& gy) // 修改函数参数，使用引用传递得到最小公倍数和最大公约数
{
	if (m > n)                        // 如果第一个数大于第二个数
	{
		for (gb = m; gb % n != 0; gb += m); // 计算最小公倍数
		gy = m * n / gb;                    // 计算最大公约数
	}
	else                                 // 如果第二个数大于等于第一个数
	{
		for (gb = n; gb % m != 0; gb += n); // 计算最小公倍数
		gy = m * n / gb; // 计算最大公约数
	}
	cout << "最小公倍数为：" << gb << endl; // 输出最小公倍数
	cout << "最大公约数为：" << gy << endl; // 输出最大公约数
}

int main()
{
	int m, n, gb, gy; // 定义变量用于存储输入的两个数、最小公倍数和最大公约数
	cout << "请输入第一个数：";
	cin >> m; // 输入第一个数
	cout << "请输入第二个数：";
	cin >> n; // 输入第二个数
	count(m, n, gb, gy); // 调用函数并传入参数m、n，得到最小公倍数和最大公约数
	return 0;
}