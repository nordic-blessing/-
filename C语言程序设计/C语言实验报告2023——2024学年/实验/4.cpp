#include <iostream>
using namespace std;
int main()
{
	int M, N;
	int a, b, c;
	int i;
	int count = 0;
	cin >> M >> N;
	for (i = M;i <= N;i++)
	{
		a = i % 10;		//��λ
		b = i / 100;	//��λ
		c = (i - b * 100) / 10;		//ʮλ
		if ((a + b + c) == 5)
		{
			cout << i << " ";
			count += 1;
		}
	}
	cout<<ecdl<<"count="<<count; 
}
