/********************************/
/*程序名称：9-3.cpp				*/
/*主要功能：						*/
/*	输出判断结果					*/
/********************************/
#include <iostream>
using namespace std;
int is_narcissistic_number(int n);
int main()
{
	int n ;
	int i = 0;
	for ( ;i == 0; )
	{
		cout << "Please enter the number:";
		cin >> n;
		if (n < 0 || n>1000)
		{
			cout << "The number you entered is smaller than 0 or larger than 1000."
				<< endl << "Please enter again.\n" << endl;
			i = 0;
		}
		else
		{
			if (is_narcissistic_number(n))
			{
				cout << "The number is a narcissistic number.";
				i = 1;
			}
			else
			{
				cout << "The number is not a narcissistic number.";
				i =	1;
			}
		}
	}
	return 0;
}
/************************************************/
/*程序名称：is_narcissistic_number				*/
/*主要功能：										*/
/*	输出判断结果									*/
/************************************************/
int is_narcissistic_number(int n)
{
	int sum = 0;
	int m = n;
	while (m != 0)
	{
		sum += pow(m % 10, 3.0);
		m = m / 10;
	}
	return sum == n;
}
