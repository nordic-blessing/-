//***********************************************
//�������ƣ�ʵѵ4-3								*
//��Ҫ���ܣ�									*
//  ����ÿλͬѧ�ĳɼ������㲢�����Ȩƽ����	*
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
	cout << "������ѧ���ɼ����Կո�ָ���";
	cin >> score1 >> score2 >> score3;
	while (score1 >= 0 && score2 >= 0 && score3 >= 0)
	{
		aveScore = (score1 * credit1 + score2 * credit2 + score3 * credit3) / (credit1 + credit2 + credit3);
		cout << "��Ȩƽ���֣�" << aveScore << endl;
		cout << "������ѧ���ɼ����Կո�ָ���";
		cin >> score1 >> score2 >> score3;
	}
	return 0;
}
