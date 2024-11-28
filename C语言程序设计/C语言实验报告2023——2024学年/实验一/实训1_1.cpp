


#include <iostream>
using namespace std;
int main()
{
	char choice;
	int nChoice;
	system("cls");
	cout<<"\n\n\n\n\n";
	cout<<"\t\t|--------学生选课系统（学生版）--------|\n";
	cout<<"\t\t|\t 0. 返回                       |\n";
	cout<<"\t\t|\t 1. 学生信息管理               |\n";
	cout<<"\t\t|\t 2. 教师信息                   |\n";
	cout<<"\t\t|\t 3. 课程信息管理               |\n";
	cout<<"\t\t|\t 4. 学生选课信息               |\n";
	cout<<"\t\t|\t 5. 学生成绩管理               |\n";
	cout<<"\t\t|\t 6. 信息统计模                 |\n";
	cout<<"\t\t|--------------------------------------|\n\n";
	cout<<"\t\t\t请输入模块号（0-6）：";
	cin>>choice;
	if(choice<'0'||choice>'9')
	{
	cout<<"模块号应为数字！"<<endl;
	return 1;
	} 
	 nChoice = choice -'0';
	 switch(nChoice)
	 {
	 	case 0:
	 		cout <<"你输入的模块名称为：0. 返回";
			 break ; 
			 
		case 1:
	 		cout <<"你输入的模块名称为：1.";
			 break ; 	 
	 }
	 return 0;
}
