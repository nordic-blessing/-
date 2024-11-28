//***************************************************************
//*  程 序 名：9_5.cpp                                          *
//*  主要功能：                                                 * 
//*     使用联合存储学生信息和教师信息                          *
//***************************************************************
#include  <iostream> 
using namespace std;
union ClassPost                                     // 由班级和职务组成的联合类型
{
    int studentClass;                               // 学生班级
    char teacherPost[20];                           // 教师职务
};
struct PersonInfo                                   // 人员信息结构类型
{
    int num;                                        // 编号
    char name[20];                                  // 姓名
    char sexy[20];                                  // 性别
    char job[20];                                   // 职业        
    ClassPost classPost;                            // 学生班级或教师职务
};

int main(){
    PersonInfo personList[] = {{101, "Li", "Female", "Student"},{102, "Wang", "Male", "Teacher"}};
    int i = 0;                                                  // 循环变量
    personList[0].classPost.studentClass = 501;                 // 输入学生班级
    strcpy(personList[1].classPost.teacherPost, "professor");   // 输入教师职务
    
    for(i = 0; i < 2; i++)                                      // 依次输出各人员信息
    {
        cout<<personList[i].num<<"\t"<<personList[i].name<<"\t"<<personList[i].sexy<<"\t"<<personList[i].job<<"\t";
        if(strcmp(personList[i].job, "Student") == 0)           // 如果当前人员的职业为学生
        {
            cout<<personList[i].classPost.studentClass<<endl;   // 输出学生班级
        }
        else                                                    // 如果当前人员的职业为教师
        {
            cout<<personList[i].classPost.teacherPost<<endl;    // 输出教师职务
        }
    }

    return 0;
}
