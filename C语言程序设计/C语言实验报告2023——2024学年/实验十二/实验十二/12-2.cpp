//***************************************************************
//*  ��������ʵѵ12_2.cpp                                       *
//*  ��Ҫ���ܣ�                                                 *
//*     �Ա��ʽ��ʾѧ����Ϣ                                  *
//***************************************************************
#include <iostream>                         // ������������ӿ��ļ�
#include <iomanip>                          // ������ʽ����ͷ�ļ�
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
void writeStudents(StudentInfo stuList[], int nStudent);
// �������ѧ����Ϣ�ĺ���
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
    writeStudents(stuList, n);
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
//***************************************************************
//*  ��������writeStudents                                      *
//*  ��Ҫ���ܣ�                                                 *
//*     �Ա��ʽ���ѧ����Ϣ                                  *
//*  ����������                                                 *
//*     stuList:    �洢ѧ����Ϣ�Ľṹ����                      *
//*     nStudent:   ѧ������                                    *
//***************************************************************
void writeStudents(StudentInfo stuList[], int nStudent)
{
    int i = 0;
    cout << "    |-----ѧ��-----|-------����-------|"
        << "-----����------|-�Ա�-|-���-|-����-|" << endl;
    for (i = 1; i <= nStudent; i++)
    {
        cout.setf(ios::left);               // �������������
        cout.fill(' ');                     // λ������ʱ���Կո����
        cout << showpoint;                    // ���������ʱ��ʾС����
        cout << setprecision(3);              // ���������ʱ����Ϊλ��Ч����
        cout << "    | ";
        cout << setw(13) << stuList[i].no << "| ";
        cout << setw(17) << stuList[i].name << "| ";
        cout.setf(ios::right);                 // ���������Ҷ���
        cout << setw(4) << stuList[i].birthday.year << "��"
            << setw(2) << stuList[i].birthday.month << "��"
            << setw(2) << stuList[i].birthday.day << "��|";
        cout << "  " << (stuList[i].sexy == 1 ? "��" : "Ů") << "  " << "| ";
        cout << setw(4) << stuList[i].height << " | ";
        cout << setw(4) << stuList[i].weight << " |";
        cout.unsetf(ios::right);            // ȡ�����������Ҷ���
        cout << endl;
    }
    cout << "    |--------------|------------------|"
        << "---------------|------|------|------|" << endl;
    cout << "\t\t����" << nStudent << " λѧ��" << endl;
}
