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
		a = i % 10;		//个位
		b = i / 100;	//百位
		c = (i - b * 100) / 10;		//十位
		if ((a + b + c) == 5)
		{
			cout << i << " ";
			count += 1;
		}
	}
	cout<<ecdl<<"count="<<count; 
}
