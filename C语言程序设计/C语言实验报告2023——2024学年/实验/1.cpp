/************************/
/*程序名称：1.cpp		*/
/*程序功能：温度的转换	*/
/************************/
#include <iostream>
using namespace std;
int main()
{
	double C = 0;
	double F = 0;
	int t = 0;
	cout << "请输入华氏温度:";
	cin >> F;
	C = (F - 32) / 1.8;
	C = C * 100;
	t = (C + 5) / 10;
	C = (double)t / 10;
	cout << "摄氏温度为：" << C;
	return 0;
}