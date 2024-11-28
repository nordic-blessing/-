//***************************************************************
//*  �� �� ����course.h                                         *
//*  ��    �ߣ�zengxd                                           *
//*  ����ʱ�䣺2015�� 2��20��                                   *
//*  ��Ҫ���ܣ�                                                 *
//*     ����γ̽ṹ����                                        *
//*     ����γ���Ϣ�����롢�������                            *
//***************************************************************
#include <iostream>
#include <iomanip>
using namespace std;
struct CourseInfo                       // ����γ���Ϣ�ṹ������
{
    char no[20];                        // �γ̱��
    char name[100];                     // �γ�����
    double credit;                      // ѧ��
    double classHour;                   // ѧʱ
    double weekHour;                    // ��ѧʱ
    int term;                           // ѧ��
};

CourseInfo readCourse();                                                    // ����γ���Ϣ
void writeCourse(CourseInfo &course);                                       // ����γ���Ϣ
int fwriteCourses(CourseInfo courseArray[], int nCourse, char fileName[]);  // ���γ�����д���ļ�
//***************************************************************
//*  �� �� ����fwriteCourses                                    *
//*  ��    �ߣ�zengxd                                           *
//*  ����ʱ�䣺2015�� 3��11��                                   *
//*  ��Ҫ���ܣ�                                                 *
//*     ���γ���Ϣ�����ֽ����ļ�                                *
//*  ����������                                                 *
//*     courseArray:    �洢�γ���Ϣ�Ľṹ����                  *
//*     nCourse:        �γ�����                                *
//*     fileName:       �γ��ļ���                              *
//*  ����ֵ��                                                   *
//*     1����ȷд���ļ����������ļ�д������                     *
//***************************************************************

int freadCourses(CourseInfo courseArray[], int &nCourse, char fileName[]);  // ���ļ���ȡ�γ���Ϣ���뵽������
//***************************************************************
//*  �� �� ����freadCourses                                     *
//*  ��    �ߣ�zengxd                                           *
//*  ����ʱ�䣺2015�� 3��11��                                   *
//*  ��Ҫ���ܣ�                                                 *
//*     �����ֽ����ļ�����γ���Ϣ                              *
//*  ����������                                                 *
//*     courseArray:    �洢�γ���Ϣ�Ľṹ����                  *
//*     nCourse:        �γ�����                                *
//*     fileName:       �γ��ļ���                              *
//*  ����ֵ��                                                   *
//*     1����ȷ��ȡ�ļ����������ļ���ȡ����                     *
//***************************************************************

CourseInfo readCourse()                                                     // ����γ���Ϣ
{
    CourseInfo course = {0};
 
    fflush(stdin);                                                          // ������뻺����

    cout<<"  ���ƣ�\t\t";
    gets_s(course.name);

    cout<<"  �γ̺ţ�\t\t";
    cin>>course.no;

    cout<<"  ѧ�֣�\t\t";
    cin>>course.credit;

    cout<<"  ��ѧʱ��\t\t";
    cin>>course.classHour;

    cout<<"  ��ѧʱ��\t\t";
    cin>>course.weekHour;

    cout<<"  ѧ�ڣ�\t\t";
    cin>>course.term;

    return course;
}

void writeCourse(CourseInfo &course)                                        // ����γ���Ϣ
{
    cout<<"  �γ�����\t\t"<<course.name<<endl;
    cout<<"  �γ̺ţ�\t\t"<<course.no<<endl;
    cout<<"  ѧ�֣�\t\t"<<course.credit<<endl;
    cout<<"  ��ѧʱ��\t\t"<<course.classHour<<endl;
    cout<<"  ��ѧʱ��\t\t"<<course.weekHour<<endl;
    cout<<"  ѧ�ڣ�\t\t"<<course.term<<endl;
}

void writeCourseInfoTitle()                                                 // ����γ���Ϣ������
{
    cout<<"    |----�γ̺�----|-------�γ���-------|-ѧ��-|-��ѧʱ-|-��ѧʱ-|-ѧ��-|"<<endl;
}

void writeCourseInfoTail()                                                  // ����γ���Ϣβ����
{
    cout<<"    |--------------|--------------------|------|--------|--------|------|"<<endl;
}

void writelnCourse(CourseInfo &course)                                      // ��һ��������γ���Ϣ
{
    //cout<<setw(10)<<showpoint<<12.345678 <<endl ;
    //cout<<setiosflags(ios::showbase);
    //cout<<oct<<setw(10)<<202<<endl;
    //cout<<hex<<202<<endl;

    cout.setf(ios::left);
    cout.fill(' ');
    cout<<"    | ";
    cout<<setw(13)<<course.no<<setw(1)<<"| ";
    cout<<setw(19)<<course.name<<setw(1)<<"| ";
    cout<<setw(5)<<setiosflags(ios::showpoint)<<setprecision(2)<<course.credit<<setw(1)<<"| ";
    cout<<setw(7)<<setiosflags(ios::showpoint)<<setprecision(3)<<course.classHour<<setw(1)<<"|  ";
    cout<<setw(6)<<setiosflags(ios::showpoint)<<setprecision(2)<<course.weekHour<<setw(1)<<"|   ";
    cout<<setw(3)<<course.term<<setw(1)<<"|";
    cout<<endl;
}

void writeCourses(CourseInfo courseArray[], int nCourse)
{
    int i = 0;
    writeCourseInfoTitle();
    for(i = 1; i <= nCourse; i++)
    {
        writelnCourse(courseArray[i]);
    }
    writeCourseInfoTail();
    cout<<"\t\t�� "<<nCourse<<" �ſγ�"<<endl;
}