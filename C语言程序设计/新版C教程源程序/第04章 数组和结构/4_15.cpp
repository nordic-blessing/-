//***************************************************************
//*  �� �� ����4_15.cpp                                         *
//*  ��Ҫ���ܣ�                                                 *
//*     ��������ѧ����Ϣ����ģ������                            *
//***************************************************************

#include <iostream>                 // ������������ӿ��ļ�
#include <string.h>                 // �����ַ�������ͷ�ļ�
#include "student.h"                // ����ѧ����Ϣ����ͷ�ļ�
using namespace std;                // ���ñ�׼�����ռ� 

int main()                          // ������
{
    const int n = 40;               // ����ѧ������
    StudentInfo stuList[n + 1];     // ���ڴ洢����ѧ����Ϣ�Ľṹ���飬
                                    // �±�0��ʹ�ã���iλѧ������Ϣ�洢���±�i��
    int i = 0;                      // ѭ������
    int count = 0;                  // ���ҵ���ѧ������
    char name[20] = "";             // ����

    for(i = 1; i <= n; i++)         // ѭ������ÿλѧ������Ϣ
    {
        cout<<"������� "<<i<<" λѧ����Ϣ��"<<endl;
        stuList[i] = readStudent();
    }
    
    fflush(stdin);                  // ������뻺����
    cout<<"�����������������";
    gets_s(name);

    cout<<"���ҽ����"<<endl;
    writeStudentInfoTitle();        // ���ѧ����Ϣ������
    for(i = 1; i <= n; i++)         // ���β��Ҹ�λѧ���������Ƿ��������
    {
        if(strstr(stuList[i].name, name))
        {                           // ���ҳɹ����������ǰѧ����Ϣ
            writelnStudent(stuList[i]);
            count++;                // ���ҵ���ѧ������1
        }
    }
    writeStudentInfoTail();         // ���ѧ����Ϣβ����
    cout<<"�����ҵ� "<<count<<" λѧ��"<<endl;

    return 0;
}
