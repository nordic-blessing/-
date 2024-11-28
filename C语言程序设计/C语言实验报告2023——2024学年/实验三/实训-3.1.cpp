//********************************************
//*程序名：实训-3.1.cp                       *
//*主要功能：								 * 
//*		显示主菜单，并获取用户输入的模块编号 *
//********************************************
#include <iostream>		//包含输入输出接口文件 
using namespace std;	//引用标准命名空间 
int main()				//定义主函数 
{					   //主函数开始 
	char choice;
	int nChoice;
	system("cls");
    cout<<"\n\n\n\n\n";
     cout<<"\t\t|-----------------学生信息管理------------------|\n";
    cout<<"\t\t|\t 0. 返回                                |\n";
    cout<<"\t\t|\t 1. 修改本人信息                        |\n";
    cout<<"\t\t|\t 2. 查询学生信息                        |\n";
    cout<<"\t\t|\t 3. 学生信息排序                        |\n";
    cout<<"\t\t|\t 4. 浏览学生信息                        |\n";
    cout<<"\t\t|-----------------------------------------------|\n\n";
    while(nChoice!='0')
	{
	  
	cout<<"\t\t\t请输入模块编号(0-4):";
    cin>>choice;							//输入字符模块号 
    if (choice<'0' ||choice>'9')			//输入的模块号不是数字 
    {
		cout<<"模块号应为数字！"<<endl;
		return 1;								//模块号不正确，返回错误代码 
	}
    nChoice = choice-'0';					//将字符模块号转为数字 
    switch(nChoice)
    {
    	case 0:
    		cout<<"你输入的模块名称为：0.返回";
			break; 
		case 1:
    		cout<<"你输入的模块名称为：1.修改本人信息";
			break;
		case 2:
    		cout<<"你输入的模块名称为：2.查询学生信息";
			break; 
		case 3:
    		cout<<"你输入的模块名称为：3.学生信息排序";
			break; 
		case 4:
    		cout<<"你输入的模块名称为：4.浏览学生信息";
			break; 
		default:
			cout<<"你输入的模块不存在！"<<endl; 
	}
}
    	return 0;
}												//主函数结束 
