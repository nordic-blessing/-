//****************************************************
//*程序名：实训2_4.cp								 *
//*主要功能：										 *
//*		输入工作小时数，输出税后收入				 *
//****************************************************
# include <iostream>		//包含输入输出接口文件 
using namespace std ;		//引用标准命名空间 
int main()					//定义主函数 
{							//主函数开始 
	double hourPrice = 25.0;
	double taxRate = 0.15;
	double workingHour = 0.0;
	double income = 0.0;
	cout<<"请输入工作小时数：";
	cin>>workingHour;
	income = workingHour*hourPrice*(1-taxRate);
	cout<<"实际收入为："<<income<<"元"<<endl;
	return 0; 
}
