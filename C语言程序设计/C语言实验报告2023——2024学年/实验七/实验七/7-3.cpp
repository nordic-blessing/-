//***************************************************************
//*  �� �� ����ʵѵ7_3.cpp                                      *
//*  ��Ҫ���ܣ�                                                 *
//*     ������ſγ̵���Ϣ,���γ̺Ŵ�С������������           *
//***************************************************************
#include <iostream>							// ������������ӿ��ļ�
#include <string.h>
using namespace std;                        // ���ñ�׼�����ռ�
struct CourseInfo							//����γ���Ϣ�ṹ������
{
	char no[20];		//�γ����
	char name[100];		//�γ�����
	double credit;		//ѧ��
	int studyHour;		//ѧʱ
	double weekHour;	//��ѧʱ
	int term;			//ѧ��
};	

int main()                                  // ������
{
	const int maxNum = 100;					//����γ��������
	CourseInfo course[maxNum+1] = { 0 };	//���ڴ洢���пγ���Ϣ�Ľṹ���飬ȫ����ʼ��Ϊ0��
											// �±�0��ʹ�ã���i�ſγ̵���Ϣ�洢���±�i��
	int nCourse;
	int i, j;
	int changed = 0;
	cout << "������γ�������";
	cin >> nCourse;
	if (nCourse <= maxNum)				//�ж������Ƿ�Խ��
	{
		for (i = 1;i<=nCourse;i++)		//����γ���Ϣ
			{
				cout << "�������" << i << "�ſγ���Ϣ��" << endl;
				rewind(stdin);
				cout << "�γ����ƣ�\t";
				gets_s(course[i].name);		
				cout << "�γ̺ţ�\t";
				cin >> course[i].no;
				cout << "ѧ�֣�\t";
				cin >> course[i].credit;
				cout << "ѧʱ��\t";
				cin >> course[i].studyHour;
				cout << "��ѧʱ��\t";
				cin >> course[i].weekHour;
				cout << "ѧ�ڣ�\t";
				cin >> course[i].term;
			}
		for (i = 2; i <= nCourse; i++)
		{
			course[0] = course[i];
			for (j = i - 1; strcmp(course[0].no, course[j].no) < 0; j--)
			{
				course[j + 1] = course[j];
			}
			course[j + 1] = course[0];
		}
		cout << "|----�γ̺�----|----�γ�����----|----ѧ��----|----ѧʱ----|---��ѧʱ---|----ѧ��----|" << endl;
	for (i = 1;i <= nCourse;i++)			//��������Ŀγ���Ϣ
		{
			cout << course[i].no << "\t\t";
			cout << course[i].name << "\t\t";
			cout << course[i].credit << "\t";
			cout << course[i].studyHour << "\t\t";
			cout << course[i].weekHour << "\t\t";
			cout << course[i].term << endl;
		}
								
	}
	else
	{
		cout << "����Խ�磡";
		system("pause");            // �ȴ����������ر����д���
		return -1 / -2 / -3;
	}
	return 0;
}