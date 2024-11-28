/****************************************************/
/*程序名称：8-4.cpp									*/
/*主要功能：										*/
/*	输入多门课程信息，按课程号从小到大排序后输出	*/
/****************************************************/
#include <iostream>                         // 包含输入输出接口文件
using namespace std;                        // 引用标准命名空间
struct CourseInfo		//定义课程信息结构类型
{
	char no[20];		//课程编号
	char name[100];		//课程名称
	double credit;		//学分
	int classHour;		//学时
	double weekHour;	//周学时
	int term;			//学期
};

int main()                                  // 主函数
{
	const int maxNum = 100;
	CourseInfo courseList[maxNum + 1] = { 0 };	//定义课程数组
	//下标为零处不存放数据
	CourseInfo* p = 0;							//定义指向课程信息的指针
	int nCourse;								//定义课程数量
	int i = 0;									//定义循环变量
	p = courseList;								//指针指向数组
	cout << "请输入课程门数：";
	cin >> nCourse;
	if (nCourse > maxNum)						//判断是否越界
	{
		cout << "数组越界！" << endl;
		return -1;
	}
	for (i = 1;i <= nCourse;i++)				//输入课程信息
	{
		cout << "请输入第" << i << "门课程的信息：" << endl;
		rewind(stdin);							//清除缓存
		cout << "  课程名称:\t";
		gets_s(p[i].name);
		cout << "  课程编号：\t";
		cin >> p[i].no;
		cout << "  学分：\t";
		cin >> p[i].credit;
		cout << "  学时：\t";
		cin >> p[i].classHour;
		cout << "  周学时：\t";
		cin >> p[i].weekHour;
		cout << "  学期：\t";
		cin >> p[i].term;
	}
	for (i = 1;i < nCourse;i++)				//插入排序法
	{
		if (strcmp(p[i].no, p[i + 1].no) < 0)
		{
			p[0] = p[i];
			p[i] = p[i + 1];
			p[i + 1] = p[0];
		}
	}
	cout << "|----课程号----|----课程名称----|----学分----|----学时----|---周学时---|----学期----|" << endl;
	for (i = 1;i <= nCourse;i++)			//输出排序后的课程信息
	{
		cout << p[i].no << "\t\t";
		cout << p[i].name << "\t\t";
		cout << p[i].credit << "\t";
		cout << p[i].classHour << "\t\t";
		cout << p[i].weekHour << "\t\t";
		cout << p[i].term << endl;
	}
	return 0;
}