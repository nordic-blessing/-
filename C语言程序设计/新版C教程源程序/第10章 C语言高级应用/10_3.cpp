//***************************************************************
//*  程 序 名：10_3.cpp                                         *
//*  主要功能：                                                 *
//*     建立一个含n个结点的教师信息表                           *
//*     首先输入每个教工信息，再将以链表方式存储                *
//***************************************************************
#include <iostream>                         // 包含输入输出接口文件
using namespace std;                        // 引用标准命名空间
struct TeacherInfo                          // 定义教师信息结构体类型
{
    char no[20];                            // 教师编号
    char name[20];                          // 姓名
    int sexy;                               // 性别    
};
// 教师信息表使用带头结点的单向链表存储
struct TeacherNode                          // 教师链表结点类型                                                       
{
    TeacherInfo data;                       // 教师信息
    TeacherNode *next;                      // 指向下一结点的指针
};
typedef TeacherNode* TeacherList; 

TeacherInfo readTeacher();                  // 读入教师信息
TeacherList initTeacherList();              // 初始化教师信息表
int appendTeacherInfo(TeacherList teacherList, TeacherInfo teacher); 
TeacherList createList(int n);              // 建立一个含n个结点的教师信息表

int main()
{
    const int TEACHER_NUM = 3;              // 定义教师结点数
    if(createList(TEACHER_NUM) != NULL)     // 建立一个含3个结点的教师信息表
    {
        return 0;                           // 成功，返回0
    }
    else 
    {
        return 1;                           // 失败，返回1
    }
}

TeacherList createList(int n)               // 建立一个含n个结点的教师信息表
{
    TeacherInfo teacher;                    // 定义教师类型变量
    TeacherList teacher_list = NULL;    
    teacher_list = initTeacherList();       // 建立一个空的教师信息表
    for(int i = 0; i < n; i++)
    {
        cout<<"\n请输入第" << i+1 << "个教师信息："<<endl;
        teacher = readTeacher();            // 读入教师信息
        if(appendTeacherInfo(teacher_list, teacher))
        {                                   // 将结点（教师信息）添加到教师信息表中
            cout<<"教师信息新增成功！"<<endl;
        }
        else
        {
            cout<<"教师信息新增失败！"<<endl;
        }
    }
    return teacher_list;
}

TeacherInfo readTeacher()                   // 读入教师信息函数
{
    TeacherInfo teacher = {0};
    fflush(stdin);                          // 清空输入缓冲区
    cout<<"  姓名：\t\t";
    gets(teacher.name);
    cout<<"  工资号：\t\t";
    cin>>teacher.no;    
    cout<<"  性别(0为女, 1为男)：\t";
    cin>>teacher.sexy;    
    return teacher;
}
// 初始化教师信息表：建立一个只含头结点的教师信息表
TeacherList initTeacherList()               // 初始化教师信息表
{
    TeacherList teacherList = NULL;
    teacherList = new TeacherNode;          // 生成头结点
    teacherList->next = NULL;               // 头结点后继结点指向空
    return teacherList;
}

// 将教师信息teacher插入到教师信息表teacherList的最后
int appendTeacherInfo(TeacherList teacherList, TeacherInfo teacher)
{
    if(!teacherList)                        // 教师信息表头结点为空，返回错误
    {
        return false;
    }
    TeacherNode *p = teacherList;           // 指向当前教师结点的指针
    TeacherNode *s = NULL;                  // 指向新生成结点的指针    
    while(p->next != NULL)                  // 循环后移指针，至p指向教师表的最后一个结点为止
    {
        p = p->next;
    }
    s = new TeacherNode;                    // 生成新结点
    s->data = teacher;
    s->next = NULL;
    p->next = s;
    return true;
}