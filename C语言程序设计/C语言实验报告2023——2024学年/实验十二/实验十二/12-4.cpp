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
		cout << "文件打开失败!" << endl;
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
	cout << "    |----工资号----|-------姓名-------|-----生日------|---权限---|-性别-|---学历---|----职称----|" << endl;
	int i = 0;
	for (i = 1; i <= nTeacher; i++)
	{
		cout.setf(ios::left);               // 设置内容左对齐
		cout.fill(' ');                     // 位数不足时，以空格填充
		cout << showpoint;                    // 输出浮点数时显示小数点
		cout << setprecision(3);              // 输出浮点数时精度为位有效数字
		cout << "    | ";
		cout << setw(13) << arrTeacher[i].no << "| ";
		cout << setw(17) << arrTeacher[i].name << "| ";
		cout.setf(ios::right);                 // 设置内容右对齐
		cout << setw(4) << arrTeacher[i].birthday.year << "年"
			<< setw(2) << arrTeacher[i].birthday.month << "月"
			<< setw(2) << arrTeacher[i].birthday.day << "日|";
		cout<<setw(9)<<(arrTeacher[i].right == 1 ? "教务员 " : "普通老师") << " | ";
		cout <<setw(3)<< (arrTeacher[i].sexy == 1 ? "男" : "女") << "  " << "| ";
		cout << setw(8) << arrTeacher[i].education << " | ";
		cout << setw(10) << arrTeacher[i].academicTitle << " |";
		cout.unsetf(ios::right);            // 取消设置内容右对齐
		cout << endl;
	}
		cout << "    |--------------|------------------|---------------|----------|------|----------|------------|" << endl;
	cout << "共" << nTeacher << " 位老师" << endl;
}
int main()
{
	const int MAX_SIZE = 50;
	TeacherInfo arrTeacher[MAX_SIZE] = { 0 };
	int nTeacher = 0;
	int i = 0;
	freadTeacherList(arrTeacher, nTeacher, "teacher.dat");
	cout << "读到的教师信息:" << endl;
	writeTeacherList(arrTeacher, nTeacher);
	return 0;
}
