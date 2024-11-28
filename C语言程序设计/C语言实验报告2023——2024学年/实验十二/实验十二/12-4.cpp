#include<iostream>
#include<fstream>
#include <iomanip>
using namespace std;
const int True = 1;
const int False = 0;
struct Date
{
	int year;
	int month;
	int day;
};
struct TeacherInfo
{
	char no[20];
	char name[20];
	char password[20];
	int right;
	Date birthday;
	int sexy;
	char education[20];
	char academicTitle[20];
	char telephone[20];
	char e_mail[40];
	char qq[20];
};
int freadTeacherList(TeacherInfo arrTeacher[],
	int& nTeacher, char fileName[])
{
	int i = 0;
	nTeacher = 0;
	ifstream fin(fileName,ios::binary);
	if (!fin)
	{
		cout << "�ļ���ʧ��!" << endl;
		return -1;
	}
	while (!fin.eof())
	{
		nTeacher++;
		fin.read((char*)(arrTeacher + nTeacher), sizeof(TeacherInfo));
		if (strlen(arrTeacher[nTeacher].name) < 1)
		{
			nTeacher--;
		}
	}
	fin.close();
}
void writeTeacherList(TeacherInfo arrTeacher[], int nTeacher)
{
	cout << "    |----���ʺ�----|-------����-------|-----����------|---Ȩ��---|-�Ա�-|---ѧ��---|----ְ��----|" << endl;
	int i = 0;
	for (i = 1; i <= nTeacher; i++)
	{
		cout.setf(ios::left);               // �������������
		cout.fill(' ');                     // λ������ʱ���Կո����
		cout << showpoint;                    // ���������ʱ��ʾС����
		cout << setprecision(3);              // ���������ʱ����Ϊλ��Ч����
		cout << "    | ";
		cout << setw(13) << arrTeacher[i].no << "| ";
		cout << setw(17) << arrTeacher[i].name << "| ";
		cout.setf(ios::right);                 // ���������Ҷ���
		cout << setw(4) << arrTeacher[i].birthday.year << "��"
			<< setw(2) << arrTeacher[i].birthday.month << "��"
			<< setw(2) << arrTeacher[i].birthday.day << "��|";
		cout<<setw(9)<<(arrTeacher[i].right == 1 ? "����Ա " : "��ͨ��ʦ") << " | ";
		cout <<setw(3)<< (arrTeacher[i].sexy == 1 ? "��" : "Ů") << "  " << "| ";
		cout << setw(8) << arrTeacher[i].education << " | ";
		cout << setw(10) << arrTeacher[i].academicTitle << " |";
		cout.unsetf(ios::right);            // ȡ�����������Ҷ���
		cout << endl;
	}
		cout << "    |--------------|------------------|---------------|----------|------|----------|------------|" << endl;
	cout << "��" << nTeacher << " λ��ʦ" << endl;
}
int main()
{
	const int MAX_SIZE = 50;
	TeacherInfo arrTeacher[MAX_SIZE] = { 0 };
	int nTeacher = 0;
	int i = 0;
	freadTeacherList(arrTeacher, nTeacher, "teacher.dat");
	cout << "�����Ľ�ʦ��Ϣ:" << endl;
	writeTeacherList(arrTeacher, nTeacher);
	return 0;
}
