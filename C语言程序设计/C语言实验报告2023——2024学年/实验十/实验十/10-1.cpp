///***************** *****************************************
///  ��������ʵѵ10_1.cpp                                    *
///  ����                                                    *
///      ����ѧ�Ų�ѯѧ����Ϣ                                *
///***********************************************************
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
struct StudentList                          // ѧ����Ϣ��ṹ������
{
    StudentInfo  data[100];                 // �洢ѧ����Ϣ������
    int length;                             // ѧ������
};
int searchStudentByNo(StudentList& stuList, char no[]);// ����searchStudentByNo����
void writeStudent(StudentInfo stu);         // ���ѧ����Ϣ
int main()
{
    const int nStudent = 5;
    StudentList stuList = { {{""},           // ����ѧ����Ϣ����ʼ��
                {"2013141442001", "��Сһ", "123456", 1, 1.70, 70.0,
                   "13612345678", "", "", {1995,1,1}},
                {"2013141442002", "ǮС��", "123456", 0, 1.60, 50.0,
                   "13623456781", "", "", {1995,2,2}},
                {"2013141442003", "��С��", "123456", 1, 1.72, 71.0,
                   "13634567812", "", "", {1995,3,3}},
                {"2013141442004", "��С��", "123456", 0, 1.64, 60.0,
                   "13645678123", "", "", {1995,4,4}},
                {"2013141442005", "��С��", "123456", 1, 1.78, 75.0,
                   "13656781234", "", "", {1995,5,5}}
    }, nStudent };
    char no[20] = "";                       // Ҫ���ҵ�ѧ��ѧ��
    int nIndex = 0;                         // ���ҵ���ѧ�����
    cout << "ѧ����Ϣ�б�" << endl;
    for (int i = 1; i <= stuList.length; i++)
        writeStudent(stuList.data[i]);
    cout << "������Ҫ���ҵ�ѧ��ѧ�ţ�";
    cin >> no;
    nIndex = searchStudentByNo(stuList, no);// ���ú�������ѧ��ѧ��
    if (nIndex < 1)
    {
        cout << "δ�ҵ��������ѧ��ѧ�ţ�" << endl;
    }
    else
    {
        cout << "���ҳɹ���ѧ����ϢΪ��" << endl;
        writeStudent(stuList.data[nIndex]); // ������ҵ���ѧ����Ϣ
    }
    return 0;
}
void writeStudent(StudentInfo stu)          // ���ѧ����Ϣ
{
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
///**********************************************************
///  ��������searchStudentByNo                              *
///  �������                                               *
///      stuList    ѧ����Ϣ��                              *
///      no         ����ѧ����ѧ��                          *
///  ����ֵ                                                 *
///      ����     Ϊ0��ʾ���Ҳ��ɹ�                         *
///               ����0Ϊ���ҵ���ѧ�����±�                 *
///  �������ܣ�                                             *
///      ����ѧ�Ų���ѧ����Ϣ                               *
///  �㷨                                                   *
///      ʹ��˳����ҷ����ң����±괦���ü�����             *
///**********************************************************
int  searchStudentByNo(StudentList& stuList, char no[])
{
    int n = stuList.length;                 // ��
    int i = 0;                              // �������±�
    strcpy(stuList.data[0].no, no);         // ���ü�����
    for (i = n; strcmp(stuList.data[i].no, no) != 0; i--); // ˳�����
    return i;                               // ���ز��ҽ��
}
