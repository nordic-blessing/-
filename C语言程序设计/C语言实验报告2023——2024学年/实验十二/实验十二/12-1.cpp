//***************************************************************
//*  ��������ʵѵ12_1.cpp                                       *
//*  ��Ҫ���ܣ�                                                 *
//*     ���ȴ��ֽ��ļ��ж�ȡѧ����Ϣ��Ȼ�����֮                *
//***************************************************************

#include <iostream>                         // ������������ӿ��ļ�
#include <fstream>                          // �������ļ��������������ͷ�ļ�
using namespace std;                        // ���ñ�׼�����ռ�
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
void writeStudent(StudentInfo& stu);       // �������ѧ����Ϣ�ĺ���
void freadStudents(StudentInfo stuList[], int& nStudent, char fileName[]);
// �������ֽ����ļ�����ѧ����Ϣ�ĺ���
int main()                                  // ������
{
    const int N = 100;                      // �������鳤��
    StudentInfo stuList[N + 1] = { 0 };         // ���ڴ洢����ѧ����Ϣ�Ľṹ���飬
    // �±�0��ʹ�ã���iλѧ������Ϣ�洢���±�i��
    int i = 0;                              // ѭ������
    int n = 0;                              // ���ļ��ж�ȡ����ѧ������
    freadStudents(stuList, n, "student.dat"); // ���ú�����ȡѧ����Ϣ���ṹ����
    cout << "���ļ������ѧ����Ϣ��" << endl;
    for (i = 1; i <= n; i++)                 // �������ѧ����Ϣ
    {
        cout << "��" << i << " λѧ����" << endl;
        writeStudent(stuList[i]);           // �����iλѧ������Ϣ
    }
    return 0;
}
///**********************************************************
///  ��������freadStudents                                  *
///  ���������                                             *
///      stuList�� ���ڴ洢ѧ����Ϣ�Ľṹ����               *
///      nStudent:  ѧ������                                *
///      fileName:  �ļ���                                  *
///  ����ֵ                                                 *
///      ��                                                 *
///  �������ܣ�                                             *
///      ���ļ�����ѧ����Ϣ�洢��������Ȼ�󷵻�             *
///**********************************************************
void freadStudents(StudentInfo stuList[], int& nStudent, char fileName[])
{
    ifstream fin(fileName, ios::binary);    // ���ֽ����ļ�fileName���ڶ�
    nStudent = 0;                           // ѧ������ʼ��Ϊ��
    if (!fin)
    {
        cout << "�ļ���ʧ�ܣ�" << endl;
        system("pause");                    // �ȴ����������ر����д���
        return;                             // ����
    }
    while (!fin.eof())                       // ѭ����ȡ�ļ����������ļ�����Ϊֹ
    {
        nStudent++;                         // ��ǰѧ�������
        fin.read((char*)(stuList + nStudent), sizeof(StudentInfo));
        if (strlen(stuList[nStudent].name) < 1)
        {                                   // ��������ѧ������Ϊ�գ������֮
            nStudent--;
        }
    }
    fin.close();                            // �ر������ļ�
}
void writeStudent(StudentInfo& stu)
{                                   // ���ѧ����Ϣ
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
