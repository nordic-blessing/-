//***********************************************
//程序名称：实训4-3								*
//主要功能：									*
//  输入每位同学的成绩，计算并输出加权平均分	*
// **********************************************
#include <iostream>
#include <math.h>
using namespace std;
int main()
{
	double score1 = 0.0;
	double score2 = 0.0;
	double score3 = 0.0;
	int credit1 = 4;
	int credit2 = 3;
	int credit3 = 2;
	double aveScore = 0.0;
	cout << "请输入学生成绩，以空格分隔：";
	cin >> score1 >> score2 >> score3;
	while (score1 >= 0 && score2 >= 0 && score3 >= 0)
	{
		aveScore = (score1 * credit1 + score2 * credit2 + score3 * credit3) / (credit1 + credit2 + credit3);
		cout << "加权平均分：" << aveScore << endl;
		cout << "请输入学生成绩，以空格分隔：";
		cin >> score1 >> score2 >> score3;
	}
	return 0;
}
