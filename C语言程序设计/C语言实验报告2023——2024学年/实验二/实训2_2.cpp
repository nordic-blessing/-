//********************************************
//*程序名：实训2_2.cp                        *
//*主要功能：
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
    cout<<"\t\t|-----------------学生信息管理-----------------|\n";
    cout<<"\t\t|\t 0. 返回                               |\n";
    cout<<"\t\t|\t 1. 修改本人信息                       |\n";
    cout<<"\t\t|\t 2. 查询学生信息                       |\n";
    cout<<"\t\t|\t 3. 学生信息排序                       |\n";
    cout<<"\t\t|\t 4. 浏览学生信息                       |\n";
    cout<<"\t\t|----------------------------------------------|\n\n";
    while(nChoice!='0')
	{
	  
	cout<<"\t\t\t请输入模块编号(0-4):";
     cin>>choice;
    if (choice<'0' ||choice>'4')
    {
	cout<<"请输入正确的模块编号！"<<endl;
	return 1;
	}
    nChoice = choice-'0';
    switch(nChoice)
    {
    	case 0:
    		cout<<"你输入的模块编号为：0.返回";
			break; 
			
		case 1:
    		cout<<"你输入的模块编号为：1.修改本人信息";
			break;
			
		case 2:
    		cout<<"你输入的模块编号为：2.查询学生信息";
			break; 
			
		case 3:
    		cout<<"你输入的模块编号为：3.学生信息排序";
			break; 
			
		case 4:
    		cout<<"你输入的模块编号为：4.浏览学生信息";
			break; 
	}
}
    	return 0;
}
