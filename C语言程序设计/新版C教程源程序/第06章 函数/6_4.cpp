///**********************************************************
///  �� �� ����writeStudent                                 *
///  �������                                               *
///      stu    ѧ����Ϣ�ṹ��                              *
///  ����ֵ                                                 *
///      ��                                                 *
///  �������ܣ�                                             *
///      ��ӡ���ĳͬѧ������Ϣ                             *
///**********************************************************
#include "student.h"                            // �����Զ����ѧ����Ϣͷ�ļ�
void writeStudent(struct  StudentInfo  stu)
{
    cout<<"  ������\t\t"<<stu.name<<endl;
    cout<<"  ѧ�ţ�\t\t"<<stu.no<<endl;
    cout<<"  �Ա�\t\t"<<(stu.sexy==1?"��":"Ů")<<endl;
    cout<<"  ���գ�\t\t"<<stu.birthday.year<<"��"<<stu.birthday.month<<"��"<<stu.birthday.day<<"��"<<endl;
    cout<<"  ��ߣ�\t\t"<<stu.height<<endl;
    cout<<"  ���أ�\t\t"<<stu.weight<<endl;
    cout<<"  �绰��\t\t"<<stu.telephone<<endl;
    cout<<"  E_mail��\t\t"<<stu.e_mail<<endl;
    cout<<"  QQ�ţ�\t\t"<<stu.qq<<endl;
} 
