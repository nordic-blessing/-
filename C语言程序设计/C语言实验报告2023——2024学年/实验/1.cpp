/************************/
/*�������ƣ�1.cpp		*/
/*�����ܣ��¶ȵ�ת��	*/
/************************/
#include <iostream>
using namespace std;
int main()
{
	double C = 0;
	double F = 0;
	int t = 0;
	cout << "�����뻪���¶�:";
	cin >> F;
	C = (F - 32) / 1.8;
	C = C * 100;
	t = (C + 5) / 10;
	C = (double)t / 10;
	cout << "�����¶�Ϊ��" << C;
	return 0;
}