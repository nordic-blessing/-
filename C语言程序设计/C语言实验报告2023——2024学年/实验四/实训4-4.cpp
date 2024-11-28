//***********************************************
//程序名称：实训4-3								*
//主要功能：									*
//  计算从1累加到100的结果						*
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
