//***************************************************************
//*  �� �� ����4_9.cpp                                          *
//*  ��Ҫ���ܣ�                                                 *
//*     ѧ����Ϣ�Ĵ洢�����롢��������                        *
//*     ʹ�ü���ѭ������ѧ����Ϣ��                            *
//*     ʹ��ð�����򷨰���ߴ�С��������                        *
//*     ����������ѧ����Ϣ                                    *
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
    const int n = 40;               // ����ѧ������
    StudentInfo stuList[n + 1] = {0};                
                                    // ���ڴ洢����ѧ����Ϣ�Ľṹ���飬ȫ����ʼ��Ϊ0���±�0��ʹ�ã���iλѧ������Ϣ�洢���±�i��
    int i = 0, j = 0;               // ѭ������
    int changed = 0;                // ð�������У���־һ��ɨ�����Ƿ�����˽���

    for(i = 1; i <= n; i++)         // ѭ������ÿλѧ������Ϣ
    {
        cout<<"������� "<<i<<" λѧ����Ϣ��"<<endl;
        cout<<"  ������\t\t";
        fflush(stdin);              // ������뻺������������ǰ���������gets_s������ȷ������
        gets_s(stuList[i].name);
        cout<<"  ѧ�ţ�\t\t";
        cin>>stuList[i].no;
        cout<<"  ���룺\t\t";
        cin>>stuList[i].password;
        cout<<"  �Ա�(0ΪŮ, 1Ϊ��)��\t";
        cin>>stuList[i].sexy;
        cout<<"  ���գ�"<<endl;
        cout<<"    �꣺\t\t";
        cin>>stuList[i].birthday.year;
        cout<<"    �£�\t\t";
        cin>>stuList[i].birthday.month;
        cout<<"    �գ�\t\t";
        cin>>stuList[i].birthday.day;
        cout<<"  ��ߣ�\t\t";
        cin>>stuList[i].height;
        cout<<"  ���أ�\t\t";
        cin>>stuList[i].weight;
        cout<<"  �绰��\t\t";
        cin>>stuList[i].telephone;
        cout<<"  E_mail��\t\t";
        cin>>stuList[i].e_mail;
        cout<<"  QQ�ţ�\t\t";
        cin>>stuList[i].qq;
    }

    for(i = 1; i < n; i++)          // ʹ��ð������ѧ����Ϣ����ߴӵ͵�������
    {
        changed = 0;
        for(j = 1; j <= n - i; j++)
        {
            if(stuList[j].height > stuList[j+1].height)
            {                       // �������ѧ�����������,����stuList[0]Ϊ��ʱ��������֮
                stuList[0] = stuList[j];
                stuList[j] = stuList[j + 1];
                stuList[j + 1] = stuList[0];
                changed = 1;
            }
        }
        if(!changed)                // ���һ��ɨ��δ�������������˳�����
        {
            break;
        }
    }

    cout<<"���\t����\t���"<<endl;
    for(i = 1; i <= n; i++)         // ˳�������λѧ�������������
    {
        cout<<i<<"\t";
        cout<<stuList[i].name<<"\t";
        cout<<stuList[i].height<<endl;
    }

    return 0;
}
