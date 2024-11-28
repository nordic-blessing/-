//********************************************
//*程序名：实训-3.3.cp                       *
//*主要功能：								 * 
//*		求居民的电费						 *
//********************************************
#include <iostream>				//包含输入输出接口文件 
#include <math.h>
using namespace std;			//引用标准命名空间 
int main()						//主函数 
{
	double electricity = 0.0;	//用电量 
	double low = 180.0;			//低档电量 
	double mid = 280.0;			//中档电量 
	double lowPrice = 0.5224;	//低档电价 
	double midPrice = 0.6224;	//中档电价 
	double highPrice = 0.8224;	//高档电价 
	double charge = 0.0;		//电费 
	cout<<"请输入用电量："; 
	cin>>electricity;
	if(electricity<=low)
	{
		charge = electricity * lowPrice;
	 } 
	 else if(electricity<=mid)
	 {
	 	charge = low * lowPrice + (electricity-low) * midPrice;
	 }
	 else
	 {
	 	charge = low * lowPrice + (mid - low) * midPrice + (electricity - mid) * highPrice;
	 }
	 cout<<"电费为："<<charge<<endl;
	 return 0; 
}
