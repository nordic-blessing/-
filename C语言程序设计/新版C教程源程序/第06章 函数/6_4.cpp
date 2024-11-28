///**********************************************************
///  函 数 名：writeStudent                                 *
///  输入参数                                               *
///      stu    学生信息结构体                              *
///  返回值                                                 *
///      无                                                 *
///  函数功能：                                             *
///      打印输出某同学所有信息                             *
///**********************************************************
#include "student.h"                            // 包含自定义的学生信息头文件
void writeStudent(struct  StudentInfo  stu)
{
    cout<<"  姓名：\t\t"<<stu.name<<endl;
    cout<<"  学号：\t\t"<<stu.no<<endl;
    cout<<"  性别：\t\t"<<(stu.sexy==1?"男":"女")<<endl;
    cout<<"  生日：\t\t"<<stu.birthday.year<<"年"<<stu.birthday.month<<"月"<<stu.birthday.day<<"日"<<endl;
    cout<<"  身高：\t\t"<<stu.height<<endl;
    cout<<"  体重：\t\t"<<stu.weight<<endl;
    cout<<"  电话：\t\t"<<stu.telephone<<endl;
    cout<<"  E_mail：\t\t"<<stu.e_mail<<endl;
    cout<<"  QQ号：\t\t"<<stu.qq<<endl;
} 
