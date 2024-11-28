//***************************************************************
//*  程 序 名：实训7_3.cpp                                      *
//*  主要功能：                                                 *
//*     输入多门课程的信息,按课程号从小到大排序后输出           *
//***************************************************************
#include <iostream>							// 包含输入输出接口文件
#include <string.h>
using namespace std;                        // 引用标准命名空间
struct CourseInfo							//定义课程信息结构体类型
{
	char no[20];		//课程序号
	char name[100];		//课程名称
	double credit;		//学分
	int studyHour;		//学时
	double weekHour;	//周学时
	int term;			//学期
};	

int main()                                  // 主函数
{
	const int maxNum = 100;					//定义课程最大数量
	CourseInfo course[maxNum+1] = { 0 };	//用于存储所有课程信息的结构数组，全部初始化为0，
											// 下标0不使用，第i门课程的信息存储在下标i处
	int nCourse;
	int i, j;
	int changed = 0;
	cout << "请输入课程门数：";
	cin >> nCourse;
	if (nCourse <= maxNum)				//判断数组是否越界
	{
		for (i = 1;i<=nCourse;i++)		//输入课程信息
			{
				cout << "请输入第" << i << "门课程信息：" << endl;
				rewind(stdin);
				cout << "课程名称：\t";
				gets_s(course[i].name);		
				cout << "课程号：\t";
				cin >> course[i].no;
				cout << "学分：\t";
				cin >> course[i].credit;
				cout << "学时：\t";
				cin >> course[i].studyHour;
				cout << "周学时：\t";
				cin >> course[i].weekHour;
				cout << "学期：\t";
				cin >> course[i].term;
			}
		for (i = 2; i <= nCourse; i++)
		{
			course[0] = course[i];
			for (j = i - 1; strcmp(course[0].no, course[j].no) < 0; j--)
			{
				course[j + 1] = course[j];
			}
			course[j + 1] = course[0];
		}
		cout << "|----课程号----|----课程名称----|----学分----|----学时----|---周学时---|----学期----|" << endl;
	for (i = 1;i <= nCourse;i++)			//输出排序后的课程信息
		{
			cout << course[i].no << "\t\t";
			cout << course[i].name << "\t\t";
			cout << course[i].credit << "\t";
			cout << course[i].studyHour << "\t\t";
			cout << course[i].weekHour << "\t\t";
			cout << course[i].term << endl;
		}
								
	}
	else
	{
		cout << "数组越界！";
		system("pause");            // 等待按任意键后关闭运行窗口
		return -1 / -2 / -3;
	}
	return 0;
}