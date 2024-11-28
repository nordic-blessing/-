//***************************************************************
//*  �� �� ����8_2.cpp                                          *
//*  ��Ҫ���ܣ�                                                 * 
//*     ���ȴ��ı��ļ��ж�ȡѧ����Ϣ��Ȼ�����֮                *
//***************************************************************

#include <iostream>                 // ������������ӿ��ļ�
#include <fstream>                  // �������ļ��������������ͷ�ļ�
#include "student.h"                // ����ѧ����Ϣ����ͷ�ļ�
using namespace std;                // ���ñ�׼�����ռ� 

int main()                          // ������
{
    const int N = 100;              // �������鳤��
    StudentInfo stuList[N + 1];     // ���ڴ洢����ѧ����Ϣ�Ľṹ���飬
                                    // �±�0��ʹ�ã���iλѧ������Ϣ�洢���±�i��
    int i = 0;                      // ѭ������
    int n = 0;                      // ���ļ��ж�ȡ����ѧ������
    ifstream fin("student.txt");    // ���ַ�����ʽ���ļ�student.txt���ڶ�

    if(!fin)
    {
        cout<<"�ļ���ʧ�ܣ�"<<endl;
        system("pause");            // �ȴ����������ر����д���
        return -1;                  // ���ش������-1
    }

    char propertyName[20] = "";     // ���ڶ�ȡ�ļ��е���������
    char propertyValue[20] = "";    // ���ڶ�ȡ�ļ������Ե�ֵ

    while(!fin.eof())               // ѭ����ȡ�ļ����������ļ�����Ϊֹ
    {
        fin>>propertyName;          // ���������е���������
        if(strcmp(propertyName, "����") != 0)
        {                           // δ����������ת�������һ������
            continue;
        }

        n++;                        // ��ʼ��ȡ��nλͬѧ����Ϣ
        fin.getline(stuList[n].name, 20);

        fin>>propertyName;          // ����ѧ���е���������
        fin.getline(stuList[n].no, 20);

        fin>>propertyName;          // �����Ա��е���������
        fin.getline(propertyValue, 20);
        if(strstr(propertyValue, "��") >= 0)
        {
            stuList[n].sexy = 1;
        }
        else
        {
            stuList[n].sexy = 0;
        }

        fin>>propertyName;          // ���������е���������
        fin.getline(propertyValue, 20);
        stuList[n].birthday = str2date(propertyValue);

        fin>>propertyName;          // ��������е���������
        fin>>stuList[n].height;     // ������ߣ�Ȼ����������
        fin.getline(propertyValue, 20);

        fin>>propertyName;          // ���������е���������
        fin>>stuList[n].weight;     // �������أ�Ȼ����������
        fin.getline(propertyValue, 20);

        fin>>propertyName;          // ����绰�е���������
        fin.getline(stuList[n].telephone, 20);

        fin>>propertyName;          // ����e_mail�е���������
        fin.getline(stuList[n].e_mail, 40);

        fin>>propertyName;          // ����QQ�е���������
        fin.getline(stuList[n].qq, 20);
    }
    fin.close();                    // �ر������ļ�

    cout<<"���ļ������ѧ����Ϣ��"<<endl;
    writeStudentInfoTitle();        // ���ѧ����Ϣ������
    for(i = 1; i <= n; i++)         // �������ѧ����Ϣ
    {           
         writelnStudent(stuList[i]);
    }
    writeStudentInfoTail();         // ���ѧ����Ϣβ����
    cout<<"\t\t���� "<<n<<" λѧ��"<<endl;

    return 0;
}
