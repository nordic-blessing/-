//***************************************************************
//*  �� �� ����9_3.cpp                                          *
//*  ��Ҫ���ܣ�                                                 * 
//*     ���ϱ�������ȷ���ʷ�����ʾ                              *
//***************************************************************
#include  <iostream> 
using namespace std;
union 
{
    char name;                              // ����
    int age;                                // ����
    float score;                            // ����
}student;                                   // ���������͵����ϱ���student

int main(){
    student.age = 18;
	cout<<"age  =  "<<student.age<<endl;    // ���ѧ�����䣬��ȷ
    cout<<"score = "<<student.score<<endl;  // ϣ�����ѧ���ɼ�����ֵ����
    
    student.score = 333.5;
    cout<<"score = "<<student.score<<endl;  // ���ѧ���ɼ�����ȷ
	cout<<"age  =  "<<student.age<<endl;    // ϣ�����ѧ�����䣬��ֵ����
    
    student.name = 'A';
	cout<<"name  =  "<<student.name<<endl;  // ���ѧ�����֣���ȷ

    cout<<"ѧ��������СΪ��"<<sizeof(student)<<"�ֽ�"<<endl;

    return 0;
}
