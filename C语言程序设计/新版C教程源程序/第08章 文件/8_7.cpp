//***************************************************************
//*  �� �� ����fwriteCourses                                    *
//*  ��Ҫ���ܣ�                                                 *
//*     ���γ���Ϣ�����ֽ����ļ�                                *
//*  ����������                                                 *
//*     courseArray:    �洢�γ���Ϣ�Ľṹ����                  *
//*     nCourse:        �γ�����                                *
//*     fileName:       �γ��ļ���                              *
//*  ����ֵ��                                                   *
//*     1����ȷд���ļ����������ļ�д������                     *
//***************************************************************

#include <iostream>                 // ������������ӿ��ļ�
#include <fstream>                  // �������ļ��������������ͷ�ļ�
#include "course.h"                 // �����γ���Ϣ����ͷ�ļ�
using namespace std;                // ���ñ�׼�����ռ� 

int main()                          // ������
{
    const int n = 40;               // ����γ�����
    CourseInfo courseList[n + 1];   // ���ڴ洢���пγ���Ϣ�Ľṹ���飬
                                    // �±�0��ʹ�ã���i�ſγ̵���Ϣ�洢���±�i��
    int i = 0;                      // ѭ������
    for(i = 1; i <= n; i++)
    {
        cout<<"����� "<<i<<" �ſγ̵���Ϣ��"<<endl;
        courseList[i] = readCourse();
    }

    if(fwriteCourses(courseList, n, "course.dat"))
    {
        cout<<"�γ���Ϣд��ɹ���"<<endl;
    }

    return 0;
}

int fwriteCourses(CourseInfo courseArray[], int nCourse, char fileName[])
{
    int i = 0;                      // ѭ������
    ofstream fout(fileName, ios::binary);   
                                    // ���ֽ�����ʽ���ļ�fileName����д
    if(!fout)
    {
        return -1;                  // �ļ��򿪳���
    }

    for(i = 1; i <= nCourse; i++)   // ѭ�����γ���Ϣд���ļ�
    {   
        fout.write((char *)(courseArray+i), sizeof(CourseInfo));
    }
    fout.close();                   // �ر��ļ�
    
    return 1;
}