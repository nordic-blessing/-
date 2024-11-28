//***************************************************************
//*  程 序 名：student.h                                        *
//*  主要功能：                                                 *
//*     定义日期和学生结构类型                                  *
//*     定义学生信息的输入、输出函数                            *
//***************************************************************
#include <iostream>
using namespace std;
struct Date                         // 定义日期类型
{
    int year;                       // 年
    int month;                      // 月
    int day;                        // 日
};
struct StudentInfo                  // 定义学生信息结构体类型
{
    char no[20];                    // 学号
    char name[20];                  // 姓名
    char password[20];              // 密码
    int sexy;                       // 性别（1为男，0为女）
    double height;                  // 身高
    double weight;                  // 体重
    char telephone[20];             // 电话
    char e_mail[40];                // E_mail
    char qq[20];                    // QQ号
    Date birthday;                  // 生日
};
StudentInfo readStudent()           // 读入学生信息
{
    StudentInfo stu;                // 定义学生类型变量
    fflush(stdin);                  // 清空输入缓冲区
    cout<<"  姓名：\t\t";
    gets(stu.name);
    cout<<"  学号：\t\t";
    cin>>stu.no;
    cout<<"  密码：\t\t";
    cin>>stu.password;
    cout<<"  性别(0为女, 1为男)：\t";
    cin>>stu.sexy;
    cout<<"  生日："<<endl;
    cout<<"    年：\t\t";
    cin>>stu.birthday.year;
    cout<<"    月：\t\t";
    cin>>stu.birthday.month;
    cout<<"    日：\t\t";
    cin>>stu.birthday.day;
    cout<<"  身高：\t\t";
    cin>>stu.height;
    cout<<"  体重：\t\t";
    cin>>stu.weight;
    fflush(stdin);                  // 清空输入缓冲区
    cout<<"  电话：\t\t";
    cin>>stu.telephone;
    fflush(stdin);                  // 清空输入缓冲区
    cout<<"  E_mail：\t\t";
    cin>>stu.e_mail;
    fflush(stdin);                  // 清空输入缓冲区
    cout<<"  QQ号：\t\t";
    cin>>stu.qq;
    return stu;
}

StudentInfo readStudent();          // 读入学生信息
void writeStudent(StudentInfo &stu);// 输出学生信息
writeStudents(StudentInfo stuList[], int nStudent);
// 以表格方式输出stuList中存储的nStudent个学生的信息
void freadStudents(StudentInfo stuList[], int &nStudent, char fileName[]);
// 从文件fileName中读取学生信息到学生信息结构数组stuList，nStudent为读入的学生人数
int fwriteStudentList(StudentInfo stuList[], int nStudent, char fileName[]);
// 将学生信息结构数组stuList写入到文件fileName中，nStudent为写入的学生人数

void writeStudent(StudentInfo & stu) 
{                                   // 输出学生信息
    cout<<"  姓名：\t\t"<<stu.name<<endl;
    cout<<"  学号：\t\t"<<stu.no<<endl;
    cout<<"  性别：\t\t"<<(stu.sexy==1?"男":"女")<<endl;
    cout<<"  生日：\t\t"<<stu.birthday.year<<"年"
        <<stu.birthday.month<<"月"<<stu.birthday.day<<"日"<<endl;
    cout<<"  身高：\t\t"<<stu.height<<endl;
    cout<<"  体重：\t\t"<<stu.weight<<endl;
    cout<<"  电话：\t\t"<<stu.telephone<<endl;
    cout<<"  E_mail：\t\t"<<stu.e_mail<<endl;
    cout<<"  QQ号：\t\t"<<stu.qq<<endl;
}
void writeStudentInfoTitle()        // 输出学生信息标题行
{
    cout<<"    |-----学号-----|-------姓名-------|-----生日------|"
        <<"-性别-|-身高-|-体重-|"<<endl;
}
void writeStudentInfoTail()         // 输出学生信息尾部行
{
    cout<<"    |--------------|------------------|---------------|"
        <<"------|------|------|"<<endl;
}
void writelnStudent(StudentInfo & stu)  
{                                   // 在一行中输出学生信息
        cout.setf(ios::left);       // 设置内容左对齐
        cout.fill(' ');             // 位数不足时，以空格填充
        cout<<showpoint;            // 输出浮点数时显示小数点
        cout<<setprecision(3);      // 输出浮点数时精度为3位有效数字
        cout<<"    | ";
        cout<<setw(13)<< stu.no<<"| ";
        cout<<setw(17)<< stu.name<<"| ";
        cout.setf(ios::right);      // 设置内容右对齐
        cout<<setw(4)<< stu.birthday.year<<"年"<<setw(2)
            << stu.birthday.month<<"月"<<setw(2)<< stu.birthday.day<<"日|";
        cout<<"  "<<( stu.sexy==1?"男":"女")<<"  "<<"| ";
        cout<<setw(4)<< stu.height<<" | ";
        cout<<setw(4)<< stu.weight<<" |";
        cout.unsetf(ios::right);    // 取消设置内容右对齐
        cout<<endl;
}
void writeStudents(StudentInfo stuList[], int nStudent)
// 以表格方式输出stuList中存储的nStudent个学生的信息
{
    int i = 0;
    writeStudentInfoTitle()         // 输出学生信息标题行
    for(i = 1; i <= nStudent; i++)
    {
        writelnStudent(stuList[i]); // 在一行中输出当前学生信息
    }
    writeStudentInfoTail()          // 输出学生信息尾部行
    cout<<"\t\t共有 "<<nStudent<<" 位学生"<<endl;
}
Date str2date(char str[])
// 将格式为yyyy-mm-dd的字符串转换为日期类型
{
    Date date;
    char year[10] = "";
    char month[10] = "";
    char day[10] = "";
    char *p = NULL;
    char *q = NULL;
    for(p  = str, q = year; *p != '\0' && *p != '-'; p++, q++)
    {
        *q = *p;
    }
    *q = '\0';
    for(p++, q = month; *p != '\0' && *p != '-'; p++, q++)
    {
        *q = *p;
    }
    *q = '\0';
    for(p++, q = day; *p != '\0'; p++, q++)
    {
        *q = *p;
    }
    *q = '\0';
    date.year = atoi(year);
    date.month = atoi(month);
    date.day = atoi(day);
    return date;
}
void freadStudents(StudentInfo stuList[], int &nStudent, char fileName[])
// 从文件fileName中读取学生信息到学生信息结构数组stuList，nStudent为读入的学生人数
{
    ifstream fin(fileName, ios::binary);    // 打开字节流文件fileName用于读
    nStudent = 0;                           // 学生数初始化为零
    if(!fin)
    {
        cout<<"文件打开失败！"<<endl;
        system("pause");                    // 等待按任意键后关闭运行窗口
        return;                             // 返回
    }
    while(!fin.eof())                       // 循环读取文件，至读到文件结束为止
    {
        nStudent++;                         // 当前学生序号增1
        fin.read((char *)(stuList+nStudent), sizeof(StudentInfo));
        if(strlen(stuList[nStudent].name) < 1)
        {                                   // 如果读入的学生姓名为空，则忽略之
            nStudent--;
        }
    }
    fin.close();                            // 关闭输入文件
}
int fwriteStudentList(StudentInfo stuList[], int nStudent, char fileName[])
// 将学生信息结构数组stuList写入到文件fileName中，nStudent为写入的学生人数
{
    ofstream out(fileName, ios::binary);    // 以二进制文件方式打开输出文件
    if(!out)
    {
        return false;
    }
    for(int i = 1; i <= nStudent; i++)      // 依次将数组中的学生信息写入文件
    {
        out.write((char *)(stuList + i), sizeof(StudentInfo));
    }
    out.close();                            // 关闭输出文件  
    return true;
}
