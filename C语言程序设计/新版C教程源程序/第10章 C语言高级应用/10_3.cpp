//***************************************************************
//*  �� �� ����10_3.cpp                                         *
//*  ��Ҫ���ܣ�                                                 *
//*     ����һ����n�����Ľ�ʦ��Ϣ��                           *
//*     ��������ÿ���̹���Ϣ���ٽ�������ʽ�洢                *
//***************************************************************
#include <iostream>                         // ������������ӿ��ļ�
using namespace std;                        // ���ñ�׼�����ռ�
struct TeacherInfo                          // �����ʦ��Ϣ�ṹ������
{
    char no[20];                            // ��ʦ���
    char name[20];                          // ����
    int sexy;                               // �Ա�    
};
// ��ʦ��Ϣ��ʹ�ô�ͷ���ĵ�������洢
struct TeacherNode                          // ��ʦ����������                                                       
{
    TeacherInfo data;                       // ��ʦ��Ϣ
    TeacherNode *next;                      // ָ����һ����ָ��
};
typedef TeacherNode* TeacherList; 

TeacherInfo readTeacher();                  // �����ʦ��Ϣ
TeacherList initTeacherList();              // ��ʼ����ʦ��Ϣ��
int appendTeacherInfo(TeacherList teacherList, TeacherInfo teacher); 
TeacherList createList(int n);              // ����һ����n�����Ľ�ʦ��Ϣ��

int main()
{
    const int TEACHER_NUM = 3;              // �����ʦ�����
    if(createList(TEACHER_NUM) != NULL)     // ����һ����3�����Ľ�ʦ��Ϣ��
    {
        return 0;                           // �ɹ�������0
    }
    else 
    {
        return 1;                           // ʧ�ܣ�����1
    }
}

TeacherList createList(int n)               // ����һ����n�����Ľ�ʦ��Ϣ��
{
    TeacherInfo teacher;                    // �����ʦ���ͱ���
    TeacherList teacher_list = NULL;    
    teacher_list = initTeacherList();       // ����һ���յĽ�ʦ��Ϣ��
    for(int i = 0; i < n; i++)
    {
        cout<<"\n�������" << i+1 << "����ʦ��Ϣ��"<<endl;
        teacher = readTeacher();            // �����ʦ��Ϣ
        if(appendTeacherInfo(teacher_list, teacher))
        {                                   // ����㣨��ʦ��Ϣ����ӵ���ʦ��Ϣ����
            cout<<"��ʦ��Ϣ�����ɹ���"<<endl;
        }
        else
        {
            cout<<"��ʦ��Ϣ����ʧ�ܣ�"<<endl;
        }
    }
    return teacher_list;
}

TeacherInfo readTeacher()                   // �����ʦ��Ϣ����
{
    TeacherInfo teacher = {0};
    fflush(stdin);                          // ������뻺����
    cout<<"  ������\t\t";
    gets(teacher.name);
    cout<<"  ���ʺţ�\t\t";
    cin>>teacher.no;    
    cout<<"  �Ա�(0ΪŮ, 1Ϊ��)��\t";
    cin>>teacher.sexy;    
    return teacher;
}
// ��ʼ����ʦ��Ϣ������һ��ֻ��ͷ���Ľ�ʦ��Ϣ��
TeacherList initTeacherList()               // ��ʼ����ʦ��Ϣ��
{
    TeacherList teacherList = NULL;
    teacherList = new TeacherNode;          // ����ͷ���
    teacherList->next = NULL;               // ͷ����̽��ָ���
    return teacherList;
}

// ����ʦ��Ϣteacher���뵽��ʦ��Ϣ��teacherList�����
int appendTeacherInfo(TeacherList teacherList, TeacherInfo teacher)
{
    if(!teacherList)                        // ��ʦ��Ϣ��ͷ���Ϊ�գ����ش���
    {
        return false;
    }
    TeacherNode *p = teacherList;           // ָ��ǰ��ʦ����ָ��
    TeacherNode *s = NULL;                  // ָ�������ɽ���ָ��    
    while(p->next != NULL)                  // ѭ������ָ�룬��pָ���ʦ������һ�����Ϊֹ
    {
        p = p->next;
    }
    s = new TeacherNode;                    // �����½��
    s->data = teacher;
    s->next = NULL;
    p->next = s;
    return true;
}