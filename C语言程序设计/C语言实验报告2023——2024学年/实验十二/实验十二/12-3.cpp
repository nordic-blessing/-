#include <iostream>
#include <fstream>
using namespace std;
struct Date
{
    int year=0;
    int month=0;
    int day=0;
};
struct Teacher
{
    char teacherID[21];
    char teacherName[50];
    char password[20];
    int userType;
    Date birthday;
    int gender;
    char education[50];
    char title[50];
    char phone[20];
    char email[50];
    char qq[20];
};

int fwriteTeacherListToTxtfile(Teacher arrTeacher[], int nTeacher, const char* fileName) 
{
    ofstream fout(fileName,ios::binary);
    if (!fout)
    {
        cout << "无法打开文件\n";
        system("pause");
        return 0;
    }
    int i;
    for (int i = 0; i < nTeacher; i++)
    {
        cout<<"请输入第"<<i+1<<"位教师的信息：\n";
        cout<<"教师编号：";
        cin>>arrTeacher[i].teacherID;
        cout<<"教师姓名：";
        cin>>arrTeacher[i].teacherName;
        cout<<"密码：";
        cin>> arrTeacher[i].password;
        cout<<"用户权限（0为普通教师，1为教务员）：";
        cin>> arrTeacher[i].userType;
        cout<<"生日\n";
        cout<<" 年：";
        cin >>arrTeacher[i].birthday.year;
        cout<<" 月：";
        cin>> arrTeacher[i].birthday.month;
        cout<<" 日：";
        cin>> arrTeacher[i].birthday.day;
        cout<<"性别（0为女，1为男）：";
        cin>> arrTeacher[i].gender;
        cout<<"学历：";
        cin>> arrTeacher[i].education;
        cout<<"职称：";
        cin>> arrTeacher[i].title;
        cout<<"电话：";
        cin>> arrTeacher[i].phone;
        cout<<"E-mail：";
        cin>> arrTeacher[i].email;
        cout<<"QQ：";
        cin>>arrTeacher[i].qq;
    }
    for (i = 0;i < nTeacher;i++)
    {
        fout << "教师编号：" << arrTeacher[i].teacherID << endl;
        fout<<"教师姓名："<< arrTeacher[i].teacherName << endl;
        fout<<"密码："<< arrTeacher[i].password << endl;
        fout<<"用户权限："<< (arrTeacher[i].userType==1?"教务员":"普通老师") << endl;
        fout<<"生日："<< arrTeacher[i].birthday.year<<"-"<<arrTeacher[i].birthday.month << "-" << arrTeacher[i].birthday.day << endl;
        fout<<"性别："<< (arrTeacher[i].gender==1?"男":"女") << endl;
        fout<<"学历："<< arrTeacher[i].education << endl;
        fout<<"职称："<< arrTeacher[i].title << endl;
        fout<<"电话："<< arrTeacher[i].phone << endl;
        fout<<"E-mail："<< arrTeacher[i].email << endl;
        fout<<"QQ：" << arrTeacher[i].qq << endl;
    }
    fout.close();
    return 1;
}

int main()
{
    int nTeacher;
    cout << "请输入人数：";
    cin >> nTeacher;
    Teacher* teachers = (Teacher*)malloc(nTeacher * sizeof(Teacher));
    fwriteTeacherListToTxtfile(teachers, nTeacher, "teacher.txt");
}
