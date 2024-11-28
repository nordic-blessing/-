//********************************************
//*程序名：实训-3.2.cp                       *
//*主要功能：								 * 
//*		输入一元二次方程的系数，求解方程的根 *
//********************************************
#include <iostream>
#include <math.h>
using namespace std;
int main()
{
	double a=0.0, b=0.0, c=0.0;			//一元二次方程的系数 
	double delta=0.0;					//判别式 
	double x1=0.0, x2=0.0;				//一元二次方程的根 
	cout<<"请输入一元二次方程的系数a b c: ";
	cin>>a>>b>>c;
	if(fabs(a)<1e-6)					//若a非常小，不是一元二次方程 
	{
		cout<<"你所输入的系数不构成一元二次方程！"<<endl;
		return 1; 
	}
	delta = b*b-4*a*c;					//计算判别式的值 
	if(delta>=0)
	{
		x1=(-b+sqrt(delta))/(2*a);
		x2=(-b-sqrt(delta))/(2*a);
		cout<<"方程的两实根为："<<x1<<"和"<<x2<<endl; 
	}
	else
	{
		x1=-b/(2*a);					//复根的实部 
		x2=sqrt(-delta)/(2*fabs(a));	//复根的虚部 
		cout<<"方程的两个复根为："<<x1<<"+"<<x2<<"i和"<<x1<<"-"<<x2<<"i"<<endl; 
	}
	return 0;
}
