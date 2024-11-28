//***************************************************************
//*  �� �� ����8_4.cpp                                          *
//*  ��Ҫ���ܣ�                                                 * 
//*     ���ȴ��ֽ��ļ��ж�ȡѧ����Ϣ��Ȼ�����֮                *
//***************************************************************

#include <iostream>                         // ������������ӿ��ļ�
#include <fstream>                          // �������ļ��������������ͷ�ļ�
#include "student.h"                        // ����ѧ����Ϣ����ͷ�ļ�
using namespace std;                        // ���ñ�׼�����ռ� 

int main()                                  // ������
{
    const int N = 100;                      // �������鳤��
    StudentInfo stuList[N+1] = {0};         // ���ڴ洢����ѧ����Ϣ�Ľṹ���飬
                                            // �±�0��ʹ�ã���iλѧ������Ϣ�洢���±�i��
    int i = 0;                              // ѭ������
    int n = 0;                              // ���ļ��ж�ȡ����ѧ������
    freadStudents(stuList,n,"student.dat"); // ���ú�����ȡѧ����Ϣ���ṹ����

    cout<<"���ļ������ѧ����Ϣ��"<<endl;
    for(i = 1; i <= n; i++)                 // �������ѧ����Ϣ
    {           
        cout<<"�� "<<i<<" λѧ����"<<endl; 
        writeStudent(stuList[i]);           // �����iλѧ������Ϣ
    }

    return 0;
}
/*  freadStudents�����Ѷ�����student.h��
void freadStudents(StudentInfo stuList[], int &nStudent, char fileName[])

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
*/