//***************************************************************
//*  程 序 名：course.h                                         *
//*  作    者：zengxd                                           *
//*  编制时间：2015年 2月20日                                   *
//*  主要功能：                                                 *
//*     定义课程结构类型                                        *
//*     定义课程信息的输入、输出函数                            *
//***************************************************************
#include <iostream>
#include <iomanip>
using namespace std;
struct CourseInfo                       // 定义课程信息结构体类型
{
    char no[20];                        // 课程编号
    char name[100];                     // 课程名称
    double credit;                      // 学分
    double classHour;                   // 学时
    double weekHour;                    // 周学时
    int term;                           // 学期
};

CourseInfo readCourse();                                                    // 读入课程信息
void writeCourse(CourseInfo &course);                                       // 输出课程信息
int fwriteCourses(CourseInfo courseArray[], int nCourse, char fileName[]);  // 将课程数组写入文件
//***************************************************************
//*  函 数 名：fwriteCourses                                    *
//*  作    者：zengxd                                           *
//*  编制时间：2015年 3月11日                                   *
//*  主要功能：                                                 *
//*     将课程信息存入字节流文件                                *
//*  函数参数：                                                 *
//*     courseArray:    存储课程信息的结构数组                  *
//*     nCourse:        课程门数                                *
//*     fileName:       课程文件名                              *
//*  返回值：                                                   *
//*     1：正确写入文件；其它：文件写入有误                     *
//***************************************************************

int freadCourses(CourseInfo courseArray[], int &nCourse, char fileName[]);  // 从文件读取课程信息存入到数组中
//***************************************************************
//*  函 数 名：freadCourses                                     *
//*  作    者：zengxd                                           *
//*  编制时间：2015年 3月11日                                   *
//*  主要功能：                                                 *
//*     将从字节流文件读入课程信息                              *
//*  函数参数：                                                 *
//*     courseArray:    存储课程信息的结构数组                  *
//*     nCourse:        课程门数                                *
//*     fileName:       课程文件名                              *
//*  返回值：                                                   *
//*     1：正确读取文件；其它：文件读取有误                     *
//***************************************************************

CourseInfo readCourse()                                                     // 读入课程信息
{
    CourseInfo course = {0};
 
    fflush(stdin);                                                          // 清空输入缓冲区

    cout<<"  名称：\t\t";
    gets_s(course.name);

    cout<<"  课程号：\t\t";
    cin>>course.no;

    cout<<"  学分：\t\t";
    cin>>course.credit;

    cout<<"  总学时：\t\t";
    cin>>course.classHour;

    cout<<"  周学时：\t\t";
    cin>>course.weekHour;

    cout<<"  学期：\t\t";
    cin>>course.term;

    return course;
}

void writeCourse(CourseInfo &course)                                        // 输出课程信息
{
    cout<<"  课程名：\t\t"<<course.name<<endl;
    cout<<"  课程号：\t\t"<<course.no<<endl;
    cout<<"  学分：\t\t"<<course.credit<<endl;
    cout<<"  总学时：\t\t"<<course.classHour<<endl;
    cout<<"  周学时：\t\t"<<course.weekHour<<endl;
    cout<<"  学期：\t\t"<<course.term<<endl;
}

void writeCourseInfoTitle()                                                 // 输出课程信息标题行
{
    cout<<"    |----课程号----|-------课程名-------|-学分-|-总学时-|-周学时-|-学期-|"<<endl;
}

void writeCourseInfoTail()                                                  // 输出课程信息尾部行
{
    cout<<"    |--------------|--------------------|------|--------|--------|------|"<<endl;
}

void writelnCourse(CourseInfo &course)                                      // 在一行中输出课程信息
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
    cout<<"\t\t共 "<<nCourse<<" 门课程"<<endl;
}