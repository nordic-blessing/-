//***********************************************
//�������ƣ�ʵѵ4-3								*
//��Ҫ���ܣ�									*
//  �����1�ۼӵ�100�Ľ��						*
// **********************************************
#include<iostream>
#include<stdio.h>
using namespace std;
int main()
{
	int iSum = 0;
	int iNumber = 1;
	while (iNumber <= 100)
	{
		iSum = iSum + iNumber;
		iNumber++;
	}
	cout << "the result is :" << iSum << endl;
	return 0;
}
