/****************************************************/
/*�������ƣ�8-4.cpp									*/
/*��Ҫ���ܣ�										*/
/*	������ſγ���Ϣ�����γ̺Ŵ�С������������	*/
/****************************************************/
#include <iostream>                         // ������������ӿ��ļ�
using namespace std;                        // ���ñ�׼�����ռ�
struct CourseInfo		//����γ���Ϣ�ṹ����
{
	char no[20];		//�γ̱��
	char name[100];		//�γ�����
	double credit;		//ѧ��
	int classHour;		//ѧʱ
	double weekHour;	//��ѧʱ
	int term;			//ѧ��
};

int main()                                  // ������
{
	const int maxNum = 100;
	CourseInfo courseList[maxNum + 1] = { 0 };	//����γ�����
	//�±�Ϊ�㴦���������
	CourseInfo* p = 0;							//����ָ��γ���Ϣ��ָ��
	int nCourse;								//����γ�����
	int i = 0;									//����ѭ������
	p = courseList;								//ָ��ָ������
	cout << "������γ�������";
	cin >> nCourse;
	if (nCourse > maxNum)						//�ж��Ƿ�Խ��
	{
		cout << "����Խ�磡" << endl;
		return -1;
	}
	for (i = 1;i <= nCourse;i++)				//����γ���Ϣ
	{
		cout << "�������" << i << "�ſγ̵���Ϣ��" << endl;
		rewind(stdin);							//�������
		cout << "  �γ�����:\t";
		gets_s(p[i].name);
		cout << "  �γ̱�ţ�\t";
		cin >> p[i].no;
		cout << "  ѧ�֣�\t";
		cin >> p[i].credit;
		cout << "  ѧʱ��\t";
		cin >> p[i].classHour;
		cout << "  ��ѧʱ��\t";
		cin >> p[i].weekHour;
		cout << "  ѧ�ڣ�\t";
		cin >> p[i].term;
	}
	for (i = 1;i < nCourse;i++)				//��������
	{
		if (strcmp(p[i].no, p[i + 1].no) < 0)
		{
			p[0] = p[i];
			p[i] = p[i + 1];
			p[i + 1] = p[0];
		}
	}
	cout << "|----�γ̺�----|----�γ�����----|----ѧ��----|----ѧʱ----|---��ѧʱ---|----ѧ��----|" << endl;
	for (i = 1;i <= nCourse;i++)			//��������Ŀγ���Ϣ
	{
		cout << p[i].no << "\t\t";
		cout << p[i].name << "\t\t";
		cout << p[i].credit << "\t";
		cout << p[i].classHour << "\t\t";
		cout << p[i].weekHour << "\t\t";
		cout << p[i].term << endl;
	}
	return 0;
}