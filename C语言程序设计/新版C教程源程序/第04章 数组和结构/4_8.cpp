//***************************************************************
//*  �� �� ����4_8.cpp                                          *
//*  ��Ҫ���ܣ�                                                 * 
//*     ѧ��������Ϣ�Ĵ洢�ͱ�ʾ                                *
//*     ���ȶ���ṹ���ͣ���ʹ�ô����Ͷ�������������������    *
//***************************************************************

#include <iostream>                 // ������������ӿ��ļ�
using namespace std;                // ���ñ�׼�����ռ� 
struct Date                         // ������������
{
    int year;                       // ��
    int month;                      // ��
    int day;                        // ��
};

struct StudentInfo                  // ����ѧ����Ϣ�ṹ������
{
    char no[20];                    // ѧ��
    char name[20];                  // ����
    char password[20];              // ����
    int sexy;                       // �Ա�1Ϊ�У�0ΪŮ��
    double height;                  // ���
    double weight;                  // ����
    char telephone[20];             // �绰
    char e_mail[40];                // E_mail
    char qq[20];                    // QQ��
    Date birthday;                  // ����
};
int main()                          // ������
{
    StudentInfo stu;                // ����ѧ�����ͱ���

    cout<<"������ѧ����Ϣ��"<<endl;
    cout<<"  ������\t\t";
    gets_s(stu.name);
    cout<<"  ѧ�ţ�\t\t";
    cin>>stu.no;
    cout<<"  ���룺\t\t";
    cin>>stu.password;
    cout<<"  �Ա�(0ΪŮ, 1Ϊ��)��\t";
    cin>>stu.sexy;
    cout<<"  ���գ�"<<endl;
    cout<<"    �꣺\t\t";
    cin>>stu.birthday.year;
    cout<<"    �£�\t\t";
    cin>>stu.birthday.month;
    cout<<"    �գ�\t\t";
    cin>>stu.birthday.day;
    cout<<"  ��ߣ�\t\t";
    cin>>stu.height;
    cout<<"  ���أ�\t\t";
    cin>>stu.weight;
    cout<<"  �绰��\t\t";
    cin>>stu.telephone;
    cout<<"  E_mail��\t\t";
    cin>>stu.e_mail;
    cout<<"  QQ�ţ�\t\t";
    cin>>stu.qq;

    cout<<"������ĸ�����Ϣ���£�"<<endl;
    cout<<"  ������\t\t"<<stu.name<<endl;
    cout<<"  ѧ�ţ�\t\t"<<stu.no<<endl;
    cout<<"  �Ա�\t\t"<<(stu.sexy==1?"��":"Ů")<<endl;
    cout<<"  ���գ�\t\t"<<stu.birthday.year<<"��"
        <<stu.birthday.month<<"��"<<stu.birthday.day<<"��"<<endl;
    cout<<"  ��ߣ�\t\t"<<stu.height<<endl;
    cout<<"  ���أ�\t\t"<<stu.weight<<endl;
    cout<<"  �绰��\t\t"<<stu.telephone<<endl;
    cout<<"  E_mail��\t\t"<<stu.e_mail<<endl;
    cout<<"  QQ�ţ�\t\t"<<stu.qq<<endl;

    return 0;
}
