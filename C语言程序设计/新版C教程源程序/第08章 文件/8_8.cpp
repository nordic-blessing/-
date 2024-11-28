//***************************************************************
//*  �� �� ����freadCourses                                     *
//*  ��Ҫ���ܣ�                                                 *
//*     �����ֽ����ļ�����γ���Ϣ                              *
//*  ����������                                                 *
//*     courseArray:    �洢�γ���Ϣ�Ľṹ����                  *
//*     nCourse:        �γ�����                                *
//*     fileName:       �γ��ļ���                              *
//*  ����ֵ��                                                   *
//*     1����ȷ��ȡ�ļ����������ļ���ȡ����                     *
//***************************************************************

#include <iostream>                 // ������������ӿ��ļ�
#include <fstream>                  // �������ļ��������������ͷ�ļ�
#include "course.h"                 // �����γ���Ϣ����ͷ�ļ�
using namespace std;                // ���ñ�׼�����ռ� 

int main()                          // ������
{
    const int n = 40;               // �������鳤��
    CourseInfo courseList[n+1]={0}; // ���ڴ洢���пγ���Ϣ�Ľṹ���飬
                                    // �±�0��ʹ�ã���i�ſγ̵���Ϣ�洢���±�i��
    int nCourse = 0;                // �γ�����
    if(freadCourses(courseList, nCourse, "course.dat"))
    {
        cout<<"�γ���Ϣ����ɹ���"<<endl;
        writeCourses(courseList, nCourse);
    }

    return 0;
}

int freadCourses(CourseInfo courseArray[], int &nCourse, char fileName[])
{
    ifstream fin(fileName, ios::binary);   
                                    // ���ֽ�����ʽ���ļ�fileName���ڶ�
    if(!fin)
    {
        return -1;                  // �ļ��򿪳���
    }

    nCourse = 0;                    // ��ʼ���γ�����Ϊ0
    while(!fin.eof())               // ѭ�����ļ�����γ���Ϣ
    {  
        nCourse++;                  // �γ�������1
        fin.read((char *)(courseArray + nCourse), sizeof(CourseInfo));
        if(strlen(courseArray[nCourse].name) < 1)
        {                           // ����γ���Ϊ�գ�����Ե�ǰ�γ�
            nCourse--;      
        }
    }
    fin.close();                   // �ر��ļ�
    
    return 1;
}