//***************************************************************
//*  程 序 名													*
//*  主要功能：  实训4											* 
//*     按年龄对学生信息进行排列									*
//***************************************************************
#include <iostream>
using namespace std;
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
void sortArrStudentByAge(StudentInfo arrStudent[], int n);
void outputStudents(StudentInfo arrStudent[], int n);
int main()
{
    const int n = 5;                    // 学生人数
    StudentInfo arrStudent[n + 1] = { {0},   // 学生信息数组，下标0不存储数据元素
        {"2013141442001", "赵一", "123456", 1, 1.70, 70, "13600010001", "zhaoyi@scu.edu.cn", "12345678", {1995, 1, 1}},
        {"2013141442002", "钱二", "123456", 2, 1.60, 56, "13600020002", "qianer@scu.edu.cn", "23456789", {1995, 2, 2}},
        {"2013141442003", "孙三", "123456", 1, 1.75, 76, "13600030003", "sunsan@scu.edu.cn", "34567890", {1994, 3, 3}},
        {"2013141442004", "李四", "123456", 2, 1.65, 66, "13600040004", "lisi@scu.edu.cn", "45678901", {1996, 4, 4}},
        {"2013141442005", "周五", "123456", 1, 1.80, 96, "13600050005", "zhouwu@scu.edu.cn", "56789012", {1995, 2, 5}} };
    cout << "排序前学生信息：" << endl;	//信息输出函数
    outputStudents(arrStudent, n);       //输出排序前信息
    sortArrStudentByAge(arrStudent, n);	//排序函数
    cout << "\n\n排序后学生信息：" << endl;   //输出排序后信息
    outputStudents(arrStudent, n);		//信息输出函数
 }
//***************************************************************
//*  函数名：outputStudents                                  
//*  参  数：  StudentInFo型数组，整数                        
//*  返回值：                                          
//*        无                                            
//*  功  能：输出学生信息
//***************************************************************
void outputStudents(StudentInfo arrStudent[], int n)
{
    for (int i = 0; i < n; i++)
    {
        cout << "  学号：\t\t" << arrStudent[i + 1].no << endl;
        cout << "  姓名：\t\t" << arrStudent[i + 1].name << endl;
        cout << "  性别：\t\t" << (arrStudent[i + 1].sexy == 1 ? "男" : "女") << endl;
        cout << "  身高：\t\t" << arrStudent[i + 1].height << endl;
        cout << "  体重：\t\t" << arrStudent[i + 1].weight << endl;
        cout << "  电话：\t\t" << arrStudent[i + 1].telephone << endl;
        cout << "  E_mail：\t\t" << arrStudent[i + 1].e_mail << endl;
        cout << "  QQ号：\t\t" << arrStudent[i + 1].qq << endl;
        cout << "  生日：\t\t" << arrStudent[i + 1].birthday.year << "年"
            << arrStudent[i + 1].birthday.month << "月" << arrStudent[i + 1].birthday.day << "日" << endl << endl;
    }
}
//***************************************************************
//*  函数名：sortArrStudentByAge
//*  参  数：  StudentInFo型数组，整数                        
//*  返回值：                                          
//*        无                                            
//*  功  能：对学生信息按年龄进行排序
//***************************************************************
void sortArrStudentByAge(StudentInfo arrStudent[], int n)
{
    for (int i = 2;i <= n;i++)
    {
        for (int j = 1;j < i;j++)
        {
            bool isYearSame(arrStudent[i].birthday.year == arrStudent[j].birthday.year);
            bool isMonthSame(arrStudent[i].birthday.month == arrStudent[j].birthday.month);
            if (arrStudent[i].birthday.year > arrStudent[j].birthday.year)
            {
                arrStudent[0] = arrStudent[i];
                arrStudent[i] = arrStudent[j];
                arrStudent[j] = arrStudent[i];
            }
            if (isYearSame)
            {
                if(arrStudent[i].birthday.month > arrStudent[j].birthday.month)
                {
                    arrStudent[0] = arrStudent[i];
                    arrStudent[i] = arrStudent[j];
                    arrStudent[j] = arrStudent[i];
                }
                if (isMonthSame)
                {
                    if (arrStudent[i].birthday.day > arrStudent[j].birthday.day)
                    {
                        arrStudent[0] = arrStudent[i];
                        arrStudent[i] = arrStudent[j];
                        arrStudent[j] = arrStudent[i];
                    }
                }
            }
        }
    }
}