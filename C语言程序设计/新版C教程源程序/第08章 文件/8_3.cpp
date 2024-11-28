//***************************************************************
//*  �� �� ����8_3.cpp                                          *
//*  ��Ҫ���ܣ�                                                 * 
//*     ѧ��������Ϣ������ʹ洢                                *
//*     ��������ѧ����Ϣ���ٽ���洢���ֽ�����ʽ�洢���ļ���    *
//***************************************************************

#include <iostream>                 // ������������ӿ��ļ�
#include <fstream>                  // �������ļ��������������ͷ�ļ�
#include "student.h"                // ����ѧ����Ϣ����ͷ�ļ�
using namespace std;                // ���ñ�׼�����ռ� 

int main()                          // ������
{
    const int n = 40;               // ����ѧ������
    StudentInfo stuList[n + 1];     // ���ڴ洢����ѧ����Ϣ�Ľṹ���飬
                                    // �±�0��ʹ�ã���iλѧ������Ϣ�洢���±�i��
    int i = 0;                      // ѭ������
    ofstream fout("student.dat", ios::binary);   
                                    // ���ֽ�����ʽ���ļ�student.data����д
    if(!fout)
    {
        cout<<"�ļ���ʧ�ܣ�"<<endl;
        system("pause");            // �ȴ����������ر����д���
        return -1;                  // ���ش������-1
    }

    for(i = 1; i <= n; i++)         // ѭ������ÿλѧ������Ϣ
    {
        cout<<"������� "<<i<<" λѧ����Ϣ��"<<endl;
        stuList[i] = readStudent();
    }

    for(i = 1; i <= n; i++)         // ѭ����ѧ����Ϣд���ļ�
    {   
        fout.write((char *)(stuList+i), sizeof(StudentInfo));
    }
    fout.close();                   // �ر��ļ�
    cout<<"ѧ����Ϣ�ѳɹ��洢���ļ�student.dat��"<<endl;

    return 0;
}
