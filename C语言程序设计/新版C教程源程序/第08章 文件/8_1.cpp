//***************************************************************
//*  �� �� ����8_1.cpp                                          *
//*  ��Ҫ���ܣ�                                                 * 
//*     ѧ��������Ϣ������ʹ洢                                *
//*     ��������ѧ����Ϣ���ٽ���洢���ַ�����ʽ�洢���ļ���    *
//***************************************************************

#include <iostream>                 // ������������ӿ��ļ�
#include <fstream>                  // �������ļ��������������ͷ�ļ�
#include "student.h"                // ����ѧ����Ϣ����ͷ�ļ�
using namespace std;                // ���ñ�׼�����ռ� 

int main()                          // ������
{
    const int n = 4;               // ����ѧ������
    StudentInfo stuList[n + 1];     // ���ڴ洢����ѧ����Ϣ�Ľṹ���飬
                                    // �±�0��ʹ�ã���iλѧ������Ϣ�洢���±�i��
    int i = 0;                      // ѭ������
    ofstream fout("student.txt");   // ���ַ�����ʽ���ļ�student.txt����д
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
        fout<<"���� "<<stuList[i].name<<endl;
        fout<<"ѧ�� "<<stuList[i].no<<endl;
        fout<<"�Ա� "<<(stuList[i].sexy==1?"��":"Ů")<<endl;
        fout<<"���� "<<stuList[i].birthday.year<<"-"
            <<stuList[i].birthday.month<<"-"<<stuList[i].birthday.day<<endl;
        fout<<"��� "<<stuList[i].height<<endl;
        fout<<"���� "<<stuList[i].weight<<endl;
        fout<<"�绰 "<<stuList[i].telephone<<endl;
        fout<<"E_mail "<<stuList[i].e_mail<<endl;
        fout<<"QQ�� "<<stuList[i].qq<<endl;
    }
    fout.close();                   // �ر��ļ�
    cout<<"ѧ����Ϣ�ѳɹ��洢���ļ�student.txt��"<<endl;

    return 0;
}
