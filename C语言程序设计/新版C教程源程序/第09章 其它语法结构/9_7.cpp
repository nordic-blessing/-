//***************************************************************
//*  �� �� ����9_7.cpp                                          *
//*  ��Ҫ���ܣ�                                                 * 
//*     ���ѧ����Ϣ��ʹ��ö�����ͱ�ʾ�Ա�                      *
//***************************************************************
#include  <iostream> 
using namespace std;
enum Sexy{female, male};                // �����Ա�ö�����ͣ�femaleΪŮ��maleΪ��
struct Date                             // ������������
{
    int year;                           // ��
    int month;                          // ��
    int day;                            // ��
};
struct StudentInfo                      // ����ѧ����Ϣ�ṹ����
{
    char no[20];                        // ѧ��
    char name[20];                      // ����
    char password[20];                  // ����
    Sexy sexy;                          // �Ա�ʹ��ö�����ͣ�
    double height;                      // ���
    double weight;                      // ����
    char telephone[20];                 // �绰
    char e_mail[40];                    // E_mail
    char qq[20];                        // QQ��
    Date birthday;                      // ����
};
void writeStudent(StudentInfo & stu)
// ���ѧ����Ϣ�����ô����õ���
{
    cout<<"  ������\t\t"<<stu.name<<endl;
    cout<<"  ѧ�ţ�\t\t"<<stu.no<<endl;
    cout<<"  �Ա�\t\t"<<(stu.sexy == male?"��":"Ů")<<endl;
    cout<<"  ���գ�\t\t"<<stu.birthday.year<<"��"<<stu.birthday.month<<"��"<<stu.birthday.day<<"��"<<endl;
    cout<<"  ��ߣ�\t\t"<<stu.height<<endl;
    cout<<"  ���أ�\t\t"<<stu.weight<<endl;
    cout<<"  �绰��\t\t"<<stu.telephone<<endl;
    cout<<"  E_mail��\t\t"<<stu.e_mail<<endl;
    cout<<"  QQ�ţ�\t\t"<<stu.qq<<endl;
}