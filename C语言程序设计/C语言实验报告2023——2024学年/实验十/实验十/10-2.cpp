///**********************************************************
///  ��������ʵѵ10_2_2.cpp                                 *
///  ��Ҫ���ܣ�                                             *
///     ����ѧ����Ϣ��Ȼ�����                              *
///**********************************************************
#include <iostream>
using namespace std;
struct Date                                 // ������������
{
    int year;                               // ��
    int month;                              // ��
    int day;                                // ��
};
struct StudentInfo                          // ����ѧ����Ϣ�ṹ������
{
    char no[20];                            // ѧ��
    char name[20];                          // ����
    char password[20];                      // ����
    int sexy;                               // �Ա�1Ϊ�У�0ΪŮ��
    double height;                          // ���
    double weight;                          // ����
    char telephone[20];                     // �绰
    char e_mail[40];                        // E_mail
    char qq[20];                            // QQ��
    Date birthday;                          // ����
};
StudentInfo readStudent();                  // ��������ѧ����Ϣ��Ϣ
void writeStudent(StudentInfo& stu);        // �������ѧ����Ϣ����
int main()
{
    cout << "������ѧ����Ϣ��" << endl;
    StudentInfo stu = readStudent();
    cout << "�������ѧ����Ϣ���£�" << endl;
    writeStudent(stu);
    return 0;
}
///**********************************************************
///  ��������readStudent                                    *
///  ���������                                             *
///      ��                                                 *
///  ����ֵ                                                 *
///      ѧ����Ϣ                                           *
///  �������ܣ�                                             *
///      �Ӽ�������ѧ����Ϣ������                           *
///**********************************************************
StudentInfo readStudent()                   // ����ѧ����Ϣ
{
    StudentInfo stu;                        // ����ѧ�����ͱ���
    fflush(stdin);                          // ������뻺����
    cout << "  ������\t\t";
    gets_s(stu.name);
    cout << "  ѧ�ţ�\t\t";
    cin >> stu.no;
    cout << "  ���룺\t\t";
    cin >> stu.password;
    cout << "  �Ա�(0ΪŮ, 1Ϊ��)��\t";
    cin >> stu.sexy;
    cout << "  ���գ�" << endl;
    cout << "    �꣺\t\t";
    cin >> stu.birthday.year;
    cout << "    �£�\t\t";
    cin >> stu.birthday.month;
    cout << "    �գ�\t\t";
    cin >> stu.birthday.day;
    cout << "  ��ߣ�\t\t";
    cin >> stu.height;
    cout << "  ���أ�\t\t";
    cin >> stu.weight;
    fflush(stdin);                          // ������뻺����
    cout << "  �绰��\t\t";
    cin >> stu.telephone;
    fflush(stdin);                          // ������뻺����
    cout << "  E_mail��\t\t";
    cin >> stu.e_mail;
    fflush(stdin);                          // ������뻺����
    cout << "  QQ�ţ�\t\t";
    cin >> stu.qq;
    return stu;
}
void writeStudent(StudentInfo& stu)
{                                           // ���ѧ����Ϣ
    cout << "  ������\t\t" << stu.name << endl;
    cout << "  ѧ�ţ�\t\t" << stu.no << endl;
    cout << "  �Ա�\t\t" << (stu.sexy == 1 ? "��" : "Ů") << endl;
    cout << "  ���գ�\t\t" << stu.birthday.year << "��"
        << stu.birthday.month << "��" << stu.birthday.day << "��" << endl;
    cout << "  ��ߣ�\t\t" << stu.height << endl;
    cout << "  ���أ�\t\t" << stu.weight << endl;
    cout << "  �绰��\t\t" << stu.telephone << endl;
    cout << "  E_mail��\t\t" << stu.e_mail << endl;
    cout << "  QQ�ţ�\t\t" << stu.qq << endl;
}