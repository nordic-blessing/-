//***************************************************************
//*  �� �� ����ʵѵ7_4.cpp                                      *
//*  ��Ҫ���ܣ�                                                 *
//*     ������ſγ̵���Ϣ,���γ̺Ŵ�С������������           *
//***************************************************************
#include <iostream>							// ������������ӿ��ļ�
#include <string.h>						// �������麯���ļ�
using namespace std;                        // ���ñ�׼�����ռ�
struct StudentScore                 // ����ѧ���ɼ��ṹ������
{
	int num;                        // ѧ���ɼ���¼���
	char teacherNo[20];             // ��ʦ���
	char courseNo[20];              // �γ̺�
	int lessonNum;                  // �����
	char studentNo[20];             // ѧ��
	double peacetimeScore;          // ƽʱ�ɼ�
	double experimentScore;         // ʵ��ɼ�
	double finalExamScore;          // ��ĩ���Գɼ�
	double termScore;               // ѧ�ڳɼ�
};
int main()							//������
{
	const int maxNum = 100;
	StudentScore scoreList[maxNum + 1] = { 0 };	//����ѧ������
	int nScore = 0;
	int i = 0;
	double maxpeacetimeScore = 0;			//���ƽʱ�ɼ�
	double minpeacetimeScore = 100;			//���ƽʱ�ɼ�
	double avgpeacetimeScore = 0;			//ƽ��ƽʱ�ɼ�
	double maxexrimentScore = 0;			//���ʵ��ɼ�
	double minexrimentScore = 100;			//���ʵ��ɼ�
	double avgexrimentScore = 0;			//ƽ��ʵ��ɼ�
	double maxfinalExamScore = 0;			//�����ĩ�ɼ�
	double minfinalExamScore = 100;			//�����ĩ�ɼ�
	double avgfinalExamScore = 0;			//ƽ����ĩ�ɼ�
	cout << "������ѡ��������";
	cin >> nScore;
	if (nScore > maxNum)
	{
		cout << "����Խ�磡" << endl;
		system("pause");            // �ȴ����������ر����д���
		return -1 / -2 / -3;
	}
	for (i = 1;i <= nScore;i++)
	{
		cout << "�������" << i << "�ſγ̳ɼ���" << endl;
		cout << " ƽʱ�ɼ���\t\t";
		cin >> scoreList[i].peacetimeScore;
		if (scoreList[i].peacetimeScore < minpeacetimeScore)		//�������
			minpeacetimeScore = scoreList[i].peacetimeScore;
		if (scoreList[i].peacetimeScore > maxpeacetimeScore)		//�������
			maxpeacetimeScore = scoreList[i].peacetimeScore;
		avgpeacetimeScore += scoreList[i].peacetimeScore;			//��ɼ��ܺ�
		cout << " ʵ��ɼ���\t\t";
		cin >> scoreList[i].experimentScore;
		if (scoreList[i].experimentScore < minexrimentScore)		//�������
			minexrimentScore = scoreList[i].experimentScore;
		if (scoreList[i].experimentScore > maxexrimentScore)		//�������
			maxexrimentScore = scoreList[i].experimentScore;
		avgexrimentScore += scoreList[i].experimentScore;			//��ɼ��ܺ�
		cout << " ��ĩ�ɼ���\t\t";
		cin >> scoreList[i].finalExamScore;		
		if (scoreList[i].finalExamScore < minfinalExamScore)		//�������
			minfinalExamScore = scoreList[i].finalExamScore;
		if (scoreList[i].finalExamScore > maxfinalExamScore)		//�������
			maxfinalExamScore = scoreList[i].finalExamScore;
		avgfinalExamScore += scoreList[i].finalExamScore;			//��ɼ��ܺ�
	}
	avgexrimentScore = avgexrimentScore / nScore;
	avgfinalExamScore = avgfinalExamScore / nScore;
	avgpeacetimeScore = avgpeacetimeScore / nScore;					//����ƽ���ɼ�
	cout << "�ɼ�ͳ����ϢΪ��" << endl;								//����ɼ���
	cout << "ƽʱ�ɼ���" << endl;
	cout << " ��ͷ֣�\t\t" << minpeacetimeScore << endl;
	cout << " ��߷֣�\t\t" << maxpeacetimeScore << endl;
	cout << " ƽ���֣�\t\t" << avgpeacetimeScore << endl;
	cout << "ʵ��ɼ���" << endl;
	cout << " ��ͷ֣�\t\t" << minexrimentScore << endl;
	cout << " ��߷֣�\t\t" << maxexrimentScore << endl;
	cout << " ƽ���֣�\t\t" << avgexrimentScore << endl;
	cout << "��ĩ�ɼ���" << endl;
	cout << " ��ͷ֣�\t\t" << minfinalExamScore << endl;
	cout << " ��߷֣�\t\t" << maxfinalExamScore << endl;
	cout << " ƽ���֣�\t\t" << avgfinalExamScore << endl;
	return 0;
}