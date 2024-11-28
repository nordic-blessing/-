//********************************************************* 
//*程序名：实训2_3 										  *
//*主要功能： 											  *
//*		输入三角形的两直角边，计算斜边边长和三角形面积 	  *
//*********************************************************
#include <iostream>	//包含输入输出接口文件
#include <math.h>
using namespace std; //引用标准命名空间 
int main()   		//定义主函数 
{					//主函数开始 
	double a=0.0, b=0.0;
	double c=0.0, S=0.0;
	cout<<"请输入直角三角形的两直角边(如：a b)：";
	cin>>a>>b;
	c=sqrt(a*a+b*b);
	S=a*b/2;
	cout<<"三角形的斜边："<<c<<endl;
	cout<<"三角形的面积："<<S<<endl; 
	return 0;
 } 
