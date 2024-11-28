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
        cout << "�޷����ļ�\n";
        system("pause");
        return 0;
    }
    int i;
    for (int i = 0; i < nTeacher; i++)
    {
        cout<<"�������"<<i+1<<"λ��ʦ����Ϣ��\n";
        cout<<"��ʦ��ţ�";
        cin>>arrTeacher[i].teacherID;
        cout<<"��ʦ������";
        cin>>arrTeacher[i].teacherName;
        cout<<"���룺";
        cin>> arrTeacher[i].password;
        cout<<"�û�Ȩ�ޣ�0Ϊ��ͨ��ʦ��1Ϊ����Ա����";
        cin>> arrTeacher[i].userType;
        cout<<"����\n";
        cout<<" �꣺";
        cin >>arrTeacher[i].birthday.year;
        cout<<" �£�";
        cin>> arrTeacher[i].birthday.month;
        cout<<" �գ�";
        cin>> arrTeacher[i].birthday.day;
        cout<<"�Ա�0ΪŮ��1Ϊ�У���";
        cin>> arrTeacher[i].gender;
        cout<<"ѧ����";
        cin>> arrTeacher[i].education;
        cout<<"ְ�ƣ�";
        cin>> arrTeacher[i].title;
        cout<<"�绰��";
        cin>> arrTeacher[i].phone;
        cout<<"E-mail��";
        cin>> arrTeacher[i].email;
        cout<<"QQ��";
        cin>>arrTeacher[i].qq;
    }
    for (i = 0;i < nTeacher;i++)
    {
        fout << "��ʦ��ţ�" << arrTeacher[i].teacherID << endl;
        fout<<"��ʦ������"<< arrTeacher[i].teacherName << endl;
        fout<<"���룺"<< arrTeacher[i].password << endl;
        fout<<"�û�Ȩ�ޣ�"<< (arrTeacher[i].userType==1?"����Ա":"��ͨ��ʦ") << endl;
        fout<<"���գ�"<< arrTeacher[i].birthday.year<<"-"<<arrTeacher[i].birthday.month << "-" << arrTeacher[i].birthday.day << endl;
        fout<<"�Ա�"<< (arrTeacher[i].gender==1?"��":"Ů") << endl;
        fout<<"ѧ����"<< arrTeacher[i].education << endl;
        fout<<"ְ�ƣ�"<< arrTeacher[i].title << endl;
        fout<<"�绰��"<< arrTeacher[i].phone << endl;
        fout<<"E-mail��"<< arrTeacher[i].email << endl;
        fout<<"QQ��" << arrTeacher[i].qq << endl;
    }
    fout.close();
    return 1;
}

int main()
{
    int nTeacher;
    cout << "������������";
    cin >> nTeacher;
    Teacher* teachers = (Teacher*)malloc(nTeacher * sizeof(Teacher));
    fwriteTeacherListToTxtfile(teachers, nTeacher, "teacher.txt");
}
