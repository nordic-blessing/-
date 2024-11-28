//***************************************************************
//*  程 序 名：9_7.cpp                                          *
//*  主要功能：                                                 * 
//*     输出学生信息，使用枚举类型表示性别                      *
//***************************************************************
#include  <iostream> 
using namespace std;
enum Sexy{female, male};                // 定义性别枚举类型，female为女，male为男
struct Date                             // 定义日期类型
{
    int year;                           // 年
    int month;                          // 月
    int day;                            // 日
};
struct StudentInfo                      // 定义学生信息结构类型
{
    char no[20];                        // 学号
    char name[20];                      // 姓名
    char password[20];                  // 密码
    Sexy sexy;                          // 性别（使用枚举类型）
    double height;                      // 身高
    double weight;                      // 体重
    char telephone[20];                 // 电话
    char e_mail[40];                    // E_mail
    char qq[20];                        // QQ号
    Date birthday;                      // 生日
};
void writeStudent(StudentInfo & stu)
// 输出学生信息，采用传引用调用
{
    cout<<"  姓名：\t\t"<<stu.name<<endl;
    cout<<"  学号：\t\t"<<stu.no<<endl;
    cout<<"  性别：\t\t"<<(stu.sexy == male?"男":"女")<<endl;
    cout<<"  生日：\t\t"<<stu.birthday.year<<"年"<<stu.birthday.month<<"月"<<stu.birthday.day<<"日"<<endl;
    cout<<"  身高：\t\t"<<stu.height<<endl;
    cout<<"  体重：\t\t"<<stu.weight<<endl;
    cout<<"  电话：\t\t"<<stu.telephone<<endl;
    cout<<"  E_mail：\t\t"<<stu.e_mail<<endl;
    cout<<"  QQ号：\t\t"<<stu.qq<<endl;
}