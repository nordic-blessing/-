//***************************************************************
//*  程序名：实训12_1.cpp                                       *
//*  主要功能：                                                 *
//*     首先从字节文件中读取学生信息，然后输出之                *
//***************************************************************

#include <iostream>                         // 包含输入输出接口文件
#include <fstream>                          // 包含对文件进行输入输出的头文件
using namespace std;                        // 引用标准命名空间
struct Date                                 // 定义日期类型
{
    int year;                               // 年
    int month;                              // 月
    int day;                                // 日
};
struct StudentInfo                          // 定义学生信息结构体类型
{
    char no[20];                            // 学号
    char name[20];                          // 姓名
    char password[20];                      // 密码
    int sexy;                               // 性别（1为男，0为女）
    double height;                          // 身高
    double weight;                          // 体重
    char telephone[20];                     // 电话
    char e_mail[40];                        // E_mail
    char qq[20];                            // QQ号
    Date birthday;                          // 生日
};
void writeStudent(StudentInfo& stu);       // 申明输出学生信息的函数
void freadStudents(StudentInfo stuList[], int& nStudent, char fileName[]);
// 申明从字节流文件读入学生信息的函数
int main()                                  // 主函数
{
    const int N = 100;                      // 定义数组长度
    StudentInfo stuList[N + 1] = { 0 };         // 用于存储所有学生信息的结构数组，
    // 下标0不使用，第i位学生的信息存储在下标i处
    int i = 0;                              // 循环变量
    int n = 0;                              // 从文件中读取到的学生人数
    freadStudents(stuList, n, "student.dat"); // 调用函数读取学生信息到结构数组
    cout << "从文件读入的学生信息：" << endl;
    for (i = 1; i <= n; i++)                 // 逐行输出学生信息
    {
        cout << "第" << i << " 位学生：" << endl;
        writeStudent(stuList[i]);           // 输出第i位学生的信息
    }
    return 0;
}
///**********************************************************
///  函数名：freadStudents                                  *
///  输入参数：                                             *
///      stuList： 用于存储学生信息的结构数组               *
///      nStudent:  学生人数                                *
///      fileName:  文件名                                  *
///  返回值                                                 *
///      无                                                 *
///  函数功能：                                             *
///      从文件读入学生信息存储到数组中然后返回             *
///**********************************************************
void freadStudents(StudentInfo stuList[], int& nStudent, char fileName[])
{
    ifstream fin(fileName, ios::binary);    // 打开字节流文件fileName用于读
    nStudent = 0;                           // 学生数初始化为零
    if (!fin)
    {
        cout << "文件打开失败！" << endl;
        system("pause");                    // 等待按任意键后关闭运行窗口
        return;                             // 返回
    }
    while (!fin.eof())                       // 循环读取文件，至读到文件结束为止
    {
        nStudent++;                         // 当前学生序号增
        fin.read((char*)(stuList + nStudent), sizeof(StudentInfo));
        if (strlen(stuList[nStudent].name) < 1)
        {                                   // 如果读入的学生姓名为空，则忽略之
            nStudent--;
        }
    }
    fin.close();                            // 关闭输入文件
}
void writeStudent(StudentInfo& stu)
{                                   // 输出学生信息
    cout << "  姓名：\t\t" << stu.name << endl;
    cout << "  学号：\t\t" << stu.no << endl;
    cout << "  性别：\t\t" << (stu.sexy == 1 ? "男" : "女") << endl;
    cout << "  生日：\t\t" << stu.birthday.year << "年"
        << stu.birthday.month << "月" << stu.birthday.day << "日" << endl;
    cout << "  身高：\t\t" << stu.height << endl;
    cout << "  体重：\t\t" << stu.weight << endl;
    cout << "  电话：\t\t" << stu.telephone << endl;
    cout << "  E_mail：\t\t" << stu.e_mail << endl;
    cout << "  QQ号：\t\t" << stu.qq << endl;
}
