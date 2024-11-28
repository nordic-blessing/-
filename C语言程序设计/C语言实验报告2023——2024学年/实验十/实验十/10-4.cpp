//***************************************************************
//*  �� �� ��													*
//*  ��Ҫ���ܣ�  ʵѵ4											* 
//*     �������ѧ����Ϣ��������									*
//***************************************************************
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
void sortArrStudentByAge(StudentInfo arrStudent[], int n);
void outputStudents(StudentInfo arrStudent[], int n);
int main()
{
    const int n = 5;                    // ѧ������
    StudentInfo arrStudent[n + 1] = { {0},   // ѧ����Ϣ���飬�±�0���洢����Ԫ��
        {"2013141442001", "��һ", "123456", 1, 1.70, 70, "13600010001", "zhaoyi@scu.edu.cn", "12345678", {1995, 1, 1}},
        {"2013141442002", "Ǯ��", "123456", 2, 1.60, 56, "13600020002", "qianer@scu.edu.cn", "23456789", {1995, 2, 2}},
        {"2013141442003", "����", "123456", 1, 1.75, 76, "13600030003", "sunsan@scu.edu.cn", "34567890", {1994, 3, 3}},
        {"2013141442004", "����", "123456", 2, 1.65, 66, "13600040004", "lisi@scu.edu.cn", "45678901", {1996, 4, 4}},
        {"2013141442005", "����", "123456", 1, 1.80, 96, "13600050005", "zhouwu@scu.edu.cn", "56789012", {1995, 2, 5}} };
    cout << "����ǰѧ����Ϣ��" << endl;	//��Ϣ�������
    outputStudents(arrStudent, n);       //�������ǰ��Ϣ
    sortArrStudentByAge(arrStudent, n);	//������
    cout << "\n\n�����ѧ����Ϣ��" << endl;   //����������Ϣ
    outputStudents(arrStudent, n);		//��Ϣ�������
 }
//***************************************************************
//*  ��������outputStudents                                  
//*  ��  ����  StudentInFo�����飬����                        
//*  ����ֵ��                                          
//*        ��                                            
//*  ��  �ܣ����ѧ����Ϣ
//***************************************************************
void outputStudents(StudentInfo arrStudent[], int n)
{
    for (int i = 0; i < n; i++)
    {
        cout << "  ѧ�ţ�\t\t" << arrStudent[i + 1].no << endl;
        cout << "  ������\t\t" << arrStudent[i + 1].name << endl;
        cout << "  �Ա�\t\t" << (arrStudent[i + 1].sexy == 1 ? "��" : "Ů") << endl;
        cout << "  ��ߣ�\t\t" << arrStudent[i + 1].height << endl;
        cout << "  ���أ�\t\t" << arrStudent[i + 1].weight << endl;
        cout << "  �绰��\t\t" << arrStudent[i + 1].telephone << endl;
        cout << "  E_mail��\t\t" << arrStudent[i + 1].e_mail << endl;
        cout << "  QQ�ţ�\t\t" << arrStudent[i + 1].qq << endl;
        cout << "  ���գ�\t\t" << arrStudent[i + 1].birthday.year << "��"
            << arrStudent[i + 1].birthday.month << "��" << arrStudent[i + 1].birthday.day << "��" << endl << endl;
    }
}
//***************************************************************
//*  ��������sortArrStudentByAge
//*  ��  ����  StudentInFo�����飬����                        
//*  ����ֵ��                                          
//*        ��                                            
//*  ��  �ܣ���ѧ����Ϣ�������������
//***************************************************************
void sortArrStudentByAge(StudentInfo arrStudent[], int n)
{
    for (int i = 2;i <= n;i++)
    {
        for (int j = 1;j < i;j++)
        {
            bool isYearSame(arrStudent[i].birthday.year == arrStudent[j].birthday.year);
            bool isMonthSame(arrStudent[i].birthday.month == arrStudent[j].birthday.month);
            if (arrStudent[i].birthday.year > arrStudent[j].birthday.year)
            {
                arrStudent[0] = arrStudent[i];
                arrStudent[i] = arrStudent[j];
                arrStudent[j] = arrStudent[i];
            }
            if (isYearSame)
            {
                if(arrStudent[i].birthday.month > arrStudent[j].birthday.month)
                {
                    arrStudent[0] = arrStudent[i];
                    arrStudent[i] = arrStudent[j];
                    arrStudent[j] = arrStudent[i];
                }
                if (isMonthSame)
                {
                    if (arrStudent[i].birthday.day > arrStudent[j].birthday.day)
                    {
                        arrStudent[0] = arrStudent[i];
                        arrStudent[i] = arrStudent[j];
                        arrStudent[j] = arrStudent[i];
                    }
                }
            }
        }
    }
}