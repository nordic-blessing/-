//*******************************************************
//*程序名：5-2.cp										*
//*主要功能：											* 
//*		显示主菜单，重复获取用户输入的模块编号并输出	*
//*******************************************************
#include <iostream>		//包含输入输出接口文件 
using namespace std;	//引用标准命名空间 
int main()				//定义主函数 
{					   //主函数开始 
	char choice;		//定义字符模块变量
	int nChoice;		//定义数字模块变量
	system("cls");				//清除屏幕
    cout<<"\n\n\n\n\n";
    cout<<"\t\t|---------------学生选课系统(学生版)------------|\n";
    cout<<"\t\t|\t 0. 返回                                |\n";
    cout<<"\t\t|\t 1. 学生信息管理                        |\n";
    cout<<"\t\t|\t 2. 教师信息信息                        |\n";
    cout<<"\t\t|\t 3. 课程信息管理                        |\n";
    cout<<"\t\t|\t 4. 学生选课信息                        |\n";
    cout<<"\t\t|\t 5. 学生成绩管理                        |\n";
    cout<<"\t\t|\t 6. 信息统计模块                        |\n";
    cout<<"\t\t|-----------------------------------------------|\n\n";
    cout<<"\t\t\t请输入模块编号(0-6):";
    cin>>choice;							//输入字符模块号 
	nChoice = choice - '0';					//将字符模块转化为数字模块
	while (nChoice != 0)					//设置循环条件，输入值不为0
	{
		if (choice < '0' || choice> '9')			//输入的模块号不是数字 
		{
			cout << "模块号应为数字！" << endl;
			goto again;								//转向输入语句
		}

		switch (nChoice)
		{
			case 1:
				cout << "你输入的模块名称为：1.学生信息管理" << endl;
				break;
			case 2:
				cout << "你输入的模块名称为：2.教师信息信息" << endl;
				break;
			case 3:
				cout << "你输入的模块名称为：3.课程信息管理" << endl;
				break;
			case 4:
				cout << "你输入的模块名称为：4.学生选课信息" << endl;
				break;
			case 5:
				cout << "你输入的模块名称为：5.学生成绩管理" << endl;
				break;
			case 6:
				cout << "你输入的模块名称为：6.信息统计模块"<< endl;
				break;
			default:
				cout << "你输入的模块不存在！" << endl;
		}
		again:									//输入语句
		cout << "\t\t\t请输入模块编号(0-6):";
		cin >> choice;							//输入字符模块号
		nChoice = choice - '0';					//将字符模块号转换为数字模块号
	}
	return 0;
}												//主函数结束 
