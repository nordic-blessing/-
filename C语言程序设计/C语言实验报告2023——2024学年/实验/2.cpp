/************************************************/
/*�������ƣ�2.cpp								*/
/*��Ҫ���ܣ�										*/
/*	����											*/
/************************************************/
#include <iostream>                         // ������������ӿ��ļ�
using namespace std;                        // ���ñ�׼�����ռ�
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
