//***************************************************************
//*  程 序 名：实训7_4.cpp                                      *
//*  主要功能：                                                 *
//*     输入多门课程的信息,按课程号从小到大排序后输出           *
//***************************************************************
#include <iostream>							// 包含输入输出接口文件
#include <string.h>						// 包含数组函数文件
using namespace std;                        // 引用标准命名空间
struct StudentScore                 // 定义学生成绩结构体类型
{
	int num;                        // 学生成绩纪录编号
	char teacherNo[20];             // 教师编号
	char courseNo[20];              // 课程号
	int lessonNum;                  // 课序号
	char studentNo[20];             // 学号
	double peacetimeScore;          // 平时成绩
	double experimentScore;         // 实验成绩
	double finalExamScore;          // 期末考试成绩
	double termScore;               // 学期成绩
};
int main()							//主函数
{
	const int maxNum = 100;
	StudentScore scoreList[maxNum + 1] = { 0 };	//定义学生数组
	int nScore = 0;
	int i = 0;
	double maxpeacetimeScore = 0;			//最高平时成绩
	double minpeacetimeScore = 100;			//最低平时成绩
	double avgpeacetimeScore = 0;			//平均平时成绩
	double maxexrimentScore = 0;			//最高实验成绩
	double minexrimentScore = 100;			//最低实验成绩
	double avgexrimentScore = 0;			//平均实验成绩
	double maxfinalExamScore = 0;			//最高期末成绩
	double minfinalExamScore = 100;			//最低期末成绩
	double avgfinalExamScore = 0;			//平均期末成绩
	cout << "请输入选课门数：";
	cin >> nScore;
	if (nScore > maxNum)
	{
		cout << "数组越界！" << endl;
		system("pause");            // 等待按任意键后关闭运行窗口
		return -1 / -2 / -3;
	}
	for (i = 1;i <= nScore;i++)
	{
		cout << "请输入第" << i << "门课程成绩：" << endl;
		cout << " 平时成绩：\t\t";
		cin >> scoreList[i].peacetimeScore;
		if (scoreList[i].peacetimeScore < minpeacetimeScore)		//计算最低
			minpeacetimeScore = scoreList[i].peacetimeScore;
		if (scoreList[i].peacetimeScore > maxpeacetimeScore)		//计算最高
			maxpeacetimeScore = scoreList[i].peacetimeScore;
		avgpeacetimeScore += scoreList[i].peacetimeScore;			//求成绩总和
		cout << " 实验成绩：\t\t";
		cin >> scoreList[i].experimentScore;
		if (scoreList[i].experimentScore < minexrimentScore)		//计算最低
			minexrimentScore = scoreList[i].experimentScore;
		if (scoreList[i].experimentScore > maxexrimentScore)		//计算最高
			maxexrimentScore = scoreList[i].experimentScore;
		avgexrimentScore += scoreList[i].experimentScore;			//求成绩总和
		cout << " 期末成绩：\t\t";
		cin >> scoreList[i].finalExamScore;		
		if (scoreList[i].finalExamScore < minfinalExamScore)		//计算最低
			minfinalExamScore = scoreList[i].finalExamScore;
		if (scoreList[i].finalExamScore > maxfinalExamScore)		//计算最高
			maxfinalExamScore = scoreList[i].finalExamScore;
		avgfinalExamScore += scoreList[i].finalExamScore;			//求成绩总和
	}
	avgexrimentScore = avgexrimentScore / nScore;
	avgfinalExamScore = avgfinalExamScore / nScore;
	avgpeacetimeScore = avgpeacetimeScore / nScore;					//计算平均成绩
	cout << "成绩统计信息为：" << endl;								//输出成绩单
	cout << "平时成绩：" << endl;
	cout << " 最低分：\t\t" << minpeacetimeScore << endl;
	cout << " 最高分：\t\t" << maxpeacetimeScore << endl;
	cout << " 平均分：\t\t" << avgpeacetimeScore << endl;
	cout << "实验成绩：" << endl;
	cout << " 最低分：\t\t" << minexrimentScore << endl;
	cout << " 最高分：\t\t" << maxexrimentScore << endl;
	cout << " 平均分：\t\t" << avgexrimentScore << endl;
	cout << "期末成绩：" << endl;
	cout << " 最低分：\t\t" << minfinalExamScore << endl;
	cout << " 最高分：\t\t" << maxfinalExamScore << endl;
	cout << " 平均分：\t\t" << avgfinalExamScore << endl;
	return 0;
}