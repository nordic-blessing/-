//***************************************************************
//*  程 序 名：9_3.cpp                                          *
//*  主要功能：                                                 * 
//*     联合变量的正确访问方法演示                              *
//***************************************************************
#include  <iostream> 
using namespace std;
union 
{
    char name;                              // 名字
    int age;                                // 年龄
    float score;                            // 分数
}student;                                   // 定义无类型的联合变量student

int main(){
    student.age = 18;
	cout<<"age  =  "<<student.age<<endl;    // 输出学生年龄，正确
    cout<<"score = "<<student.score<<endl;  // 希望输出学生成绩，数值有误
    
    student.score = 333.5;
    cout<<"score = "<<student.score<<endl;  // 输出学生成绩，正确
	cout<<"age  =  "<<student.age<<endl;    // 希望输出学生年龄，数值有误
    
    student.name = 'A';
	cout<<"name  =  "<<student.name<<endl;  // 输出学生名字，正确

    cout<<"学生变量大小为："<<sizeof(student)<<"字节"<<endl;

    return 0;
}
