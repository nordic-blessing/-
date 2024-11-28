//***************************************************************
//*  �� �� ����4_16.cpp                                         *
//*  ��Ҫ���ܣ�                                                 *
//*     ʹ��ֱ�Ӳ��뷨��ѧ����Ϣ������������±�0Ϊ������     *
//***************************************************************

#include <iostream>                 // ������������ӿ��ļ�
#include "student.h"                // ����ѧ����Ϣ����ͷ�ļ�
using namespace std;                // ���ñ�׼�����ռ� 

int main()                          // ������
{
    const int n = 40;               // ����ѧ������
    StudentInfo stuList[n + 1];     // ���ڴ洢����ѧ����Ϣ�Ľṹ���飬
                                    // �±�0��ʹ�ã���iλѧ������Ϣ�洢���±�i��
    int i = 0, j = 0;               // ѭ������

    for(i = 1; i <= n; i++)         // ѭ������ÿλѧ������Ϣ
    {
        cout<<"������� "<<i<<" λѧ����Ϣ��"<<endl;
        stuList[i] = readStudent();
    }
    
    for(i = 2; i <= n; i++)
    {
        stuList[0] = stuList[i];    // ���ü�����
        for(j = i - 1; stuList[0].height < stuList[j].height; j--)
        {                           // �����jλѧ������߽ϴ������
            stuList[j+1]  = stuList[j];
        }
        stuList[j+1] = stuList[0];  // ��iλѧ������Ϣ��λ
    }


    cout<<"������ѧ����Ϣ��"<<endl;
    writeStudentInfoTitle();        // ���ѧ����Ϣ������
    for(i = 1; i <= n; i++)         // ���β��Ҹ�λѧ���������Ƿ��������
    {
        writelnStudent(stuList[i]);
    }
    writeStudentInfoTail();         // ���ѧ����Ϣβ����
    cout<<"�ܹ� "<<n<<" λѧ��"<<endl;

    return 0;
}
