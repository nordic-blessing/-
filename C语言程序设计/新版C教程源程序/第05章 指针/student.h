//***************************************************************
//*  �� �� ����student.h                                        *
//*  ��Ҫ���ܣ�                                                 *
//*     �������ں�ѧ���ṹ����                                  *
//*     ����ѧ����Ϣ�����롢�������                            *
//***************************************************************
#include <iostream>
using namespace std;
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
StudentInfo readStudent()           // ����ѧ����Ϣ
{
    StudentInfo stu;                // ����ѧ�����ͱ���
    fflush(stdin);                  // ������뻺����
    cout<<"  ������\t\t";
    gets(stu.name);
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
    fflush(stdin);                  // ������뻺����
    cout<<"  �绰��\t\t";
    cin>>stu.telephone;
    fflush(stdin);                  // ������뻺����
    cout<<"  E_mail��\t\t";
    cin>>stu.e_mail;
    fflush(stdin);                  // ������뻺����
    cout<<"  QQ�ţ�\t\t";
    cin>>stu.qq;
    return stu;
}

StudentInfo readStudent();          // ����ѧ����Ϣ
void writeStudent(StudentInfo &stu);// ���ѧ����Ϣ
writeStudents(StudentInfo stuList[], int nStudent);
// �Ա��ʽ���stuList�д洢��nStudent��ѧ������Ϣ
void freadStudents(StudentInfo stuList[], int &nStudent, char fileName[]);
// ���ļ�fileName�ж�ȡѧ����Ϣ��ѧ����Ϣ�ṹ����stuList��nStudentΪ�����ѧ������
int fwriteStudentList(StudentInfo stuList[], int nStudent, char fileName[]);
// ��ѧ����Ϣ�ṹ����stuListд�뵽�ļ�fileName�У�nStudentΪд���ѧ������

void writeStudent(StudentInfo & stu) 
{                                   // ���ѧ����Ϣ
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
}
void writeStudentInfoTitle()        // ���ѧ����Ϣ������
{
    cout<<"    |-----ѧ��-----|-------����-------|-----����------|"
        <<"-�Ա�-|-���-|-����-|"<<endl;
}
void writeStudentInfoTail()         // ���ѧ����Ϣβ����
{
    cout<<"    |--------------|------------------|---------------|"
        <<"------|------|------|"<<endl;
}
void writelnStudent(StudentInfo & stu)  
{                                   // ��һ�������ѧ����Ϣ
        cout.setf(ios::left);       // �������������
        cout.fill(' ');             // λ������ʱ���Կո����
        cout<<showpoint;            // ���������ʱ��ʾС����
        cout<<setprecision(3);      // ���������ʱ����Ϊ3λ��Ч����
        cout<<"    | ";
        cout<<setw(13)<< stu.no<<"| ";
        cout<<setw(17)<< stu.name<<"| ";
        cout.setf(ios::right);      // ���������Ҷ���
        cout<<setw(4)<< stu.birthday.year<<"��"<<setw(2)
            << stu.birthday.month<<"��"<<setw(2)<< stu.birthday.day<<"��|";
        cout<<"  "<<( stu.sexy==1?"��":"Ů")<<"  "<<"| ";
        cout<<setw(4)<< stu.height<<" | ";
        cout<<setw(4)<< stu.weight<<" |";
        cout.unsetf(ios::right);    // ȡ�����������Ҷ���
        cout<<endl;
}
void writeStudents(StudentInfo stuList[], int nStudent)
// �Ա��ʽ���stuList�д洢��nStudent��ѧ������Ϣ
{
    int i = 0;
    writeStudentInfoTitle()         // ���ѧ����Ϣ������
    for(i = 1; i <= nStudent; i++)
    {
        writelnStudent(stuList[i]); // ��һ���������ǰѧ����Ϣ
    }
    writeStudentInfoTail()          // ���ѧ����Ϣβ����
    cout<<"\t\t���� "<<nStudent<<" λѧ��"<<endl;
}
Date str2date(char str[])
// ����ʽΪyyyy-mm-dd���ַ���ת��Ϊ��������
{
    Date date;
    char year[10] = "";
    char month[10] = "";
    char day[10] = "";
    char *p = NULL;
    char *q = NULL;
    for(p  = str, q = year; *p != '\0' && *p != '-'; p++, q++)
    {
        *q = *p;
    }
    *q = '\0';
    for(p++, q = month; *p != '\0' && *p != '-'; p++, q++)
    {
        *q = *p;
    }
    *q = '\0';
    for(p++, q = day; *p != '\0'; p++, q++)
    {
        *q = *p;
    }
    *q = '\0';
    date.year = atoi(year);
    date.month = atoi(month);
    date.day = atoi(day);
    return date;
}
void freadStudents(StudentInfo stuList[], int &nStudent, char fileName[])
// ���ļ�fileName�ж�ȡѧ����Ϣ��ѧ����Ϣ�ṹ����stuList��nStudentΪ�����ѧ������
{
    ifstream fin(fileName, ios::binary);    // ���ֽ����ļ�fileName���ڶ�
    nStudent = 0;                           // ѧ������ʼ��Ϊ��
    if(!fin)
    {
        cout<<"�ļ���ʧ�ܣ�"<<endl;
        system("pause");                    // �ȴ����������ر����д���
        return;                             // ����
    }
    while(!fin.eof())                       // ѭ����ȡ�ļ����������ļ�����Ϊֹ
    {
        nStudent++;                         // ��ǰѧ�������1
        fin.read((char *)(stuList+nStudent), sizeof(StudentInfo));
        if(strlen(stuList[nStudent].name) < 1)
        {                                   // ��������ѧ������Ϊ�գ������֮
            nStudent--;
        }
    }
    fin.close();                            // �ر������ļ�
}
int fwriteStudentList(StudentInfo stuList[], int nStudent, char fileName[])
// ��ѧ����Ϣ�ṹ����stuListд�뵽�ļ�fileName�У�nStudentΪд���ѧ������
{
    ofstream out(fileName, ios::binary);    // �Զ������ļ���ʽ������ļ�
    if(!out)
    {
        return false;
    }
    for(int i = 1; i <= nStudent; i++)      // ���ν������е�ѧ����Ϣд���ļ�
    {
        out.write((char *)(stuList + i), sizeof(StudentInfo));
    }
    out.close();                            // �ر�����ļ�  
    return true;
}
