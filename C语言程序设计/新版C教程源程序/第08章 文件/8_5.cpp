//***************************************************************
//*  �� �� ����8_5.cpp                                          *
//*  ��Ҫ���ܣ�                                                 * 
//*     ���ȴ��ֽ��ļ��ж�ȡ������ŵ�ѧ����Ϣ��Ȼ�����֮      *
//***************************************************************

#include <iostream>                     // ������������ӿ��ļ�
#include <fstream>                      // �������ļ��������������ͷ�ļ�
#include "student.h"                    // ����ѧ����Ϣ����ͷ�ļ�
using namespace std;                    // ���ñ�׼�����ռ� 

int main()                              // ������
{
    const int N = 100;                  // �������鳤��
    StudentInfo stuList[N+1] = {0};     // ���ڴ洢����ѧ����Ϣ�Ľṹ���飬
                                        // �±�0��ʹ�ã���iλѧ������Ϣ�洢���±�i��
    int i = 0;                          // ѭ������
    int n = 0;                          // ���ļ��ж�ȡ����ѧ������
    ifstream fin("student.dat", ios::binary);    
                                        // ���ֽ�����ʽ���ļ�student.dat���ڶ�
    if(!fin)
    {
        cout<<"�ļ���ʧ�ܣ�"<<endl;
        system("pause");                // �ȴ����������ر����д���
        return -1;                      // ���ش������-1
    }

    while(!fin.eof())                   // ѭ����ȡ�ļ����������ļ�����Ϊֹ
    {
        n++;                            // ��ǰѧ�������1
        fin.read((char *)(stuList+n), sizeof(StudentInfo));
        if(!fin.eof())
        {                               // �ļ���δ���꣬���ļ�λ��ָ�����һ��ѧ����¼
            fin.seekg(sizeof(StudentInfo), ios::cur); 
        }
        if(strlen(stuList[n].name) < 1)
        {                               // ��������ѧ������Ϊ�գ������֮
            n--;
        }
    }
    fin.close();                        // �ر������ļ�

    cout<<"���ļ������ѧ����Ϣ��"<<endl;
    writeStudentInfoTitle();            // ���ѧ����Ϣ������
    for(i = 1; i <= n; i++)             // �������ѧ����Ϣ
    {           
         writelnStudent(stuList[i]);
    }
    writeStudentInfoTail();             // ���ѧ����Ϣβ����
    cout<<"\t\t���� "<<n<<" λѧ��"<<endl;

    return 0;
}
