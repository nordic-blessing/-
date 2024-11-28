/****************************/
/*程序名称：9-4.cpp			*/
/*主要功能：					*/
/*	输入成绩，输出均分		*/
/****************************/
#include <iostream>
using namespace std;
int student_average_score(int n);
int main()
{
	int n = 0;
	cout << "请输入学生人数：";
	cin >> n;
	cout << "请输入学生成绩：" << endl;
	cout << "平均分为：" << student_average_score(n);
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