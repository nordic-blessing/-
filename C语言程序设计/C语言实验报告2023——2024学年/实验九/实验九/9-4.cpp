/****************************/
/*�������ƣ�9-4.cpp			*/
/*��Ҫ���ܣ�					*/
/*	����ɼ����������		*/
/****************************/
#include <iostream>
using namespace std;
int student_average_score(int n);
int main()
{
	int n = 0;
	cout << "������ѧ��������";
	cin >> n;
	cout << "������ѧ���ɼ���" << endl;
	cout << "ƽ����Ϊ��" << student_average_score(n);
}

int student_average_score(int n)
{
	int i;
	int score = 0;
	int sum = 0;
	for (i = 1;i <= n;i++)
	{
		cout << "arrScore[" << i << "]:";
		cin >> score;
		sum += score;
		score = 0;
	}
	return sum / n;
}