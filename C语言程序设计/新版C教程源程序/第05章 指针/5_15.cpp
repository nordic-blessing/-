//***************************************************************
//*  程 序 名：5_15.cpp                                         *
//*  主要功能：                                                 *
//*     查询给定实习日的任务安排                                *
//***************************************************************
#include <iostream>                         // 包含输入输出接口文件
using namespace std;                        // 引用标准命名空间
struct Date                                 // 定义结构类型Date，表示日期
{
	int year;                               // 年
	int month;                              // 月
	int day;                                // 日
};

int main()
{
    Date today;                             // 定义today为Date类型的结构
    Date *p_today = 0;                      // 定义p_today用来指向结构变量today
    //二维数组的第2维下标代表实习月份（1～7月），二维数组元素的值代表某月的天数
    int day_tab[2][7] = {{0,31,28,31,30,31,30},{0,31,29,31,30,31,30}};  
    int i = 0;                              // 循环变量
    int flag = 0;                           // 标志，0为平年，非0为闰年	
    unsigned int day=0;                     //表示：从本年1月1日开始至指定日期一共有多少天；
    p_today = &today;                       //p_today指向today
    cout << "注意：实习时间从每年的01月01日开始到06月30号结束。" << endl;
    cout << "请输入待查询的日期：" << endl;
    cout << "年: ";
    cin >> p_today->year;
    cout << "月: ";
    cin >> p_today->month;
    cout << "日: ";
    cin >> p_today->day;
    //检测输入的查询月份是否为实习期
    while(!(p_today->month > 0 && p_today->month < 7))
    {
        cout << "输入的查询月份不在实习期！" << endl;
        cout << "请重新输入待查询的日期：" << endl;
        cout << "年: ";
        cin >> p_today->year;
        cout << "月: ";
        cin >> p_today->month;
        cout << "日: ";
        cin >> p_today->day;
    }
    //检测输入的年份是否为闰年
    flag = (p_today->year % 4 == 0 && p_today->year % 100 != 0 || p_today->year % 400 == 0);	
    //计算从本年1月1日开始至指定日期一共有多少天
    for(i = 1; i < p_today->month; i++)
    {
        day=day+day_tab[flag][i];
    }
    day = day + p_today->day;
    if(day % 5 > 0 && day % 5 < 4 )	
    {
        cout << "今天听讲座." << endl;
    }
    else
    {
        cout << "今天上生产线." << endl;
    }
    return 0;
}
