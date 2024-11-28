//********************************************
//*程序名：实训-3.4.cp                       *
//*主要功能：								 * 
//*		求运输公司的运费计费				 *
//********************************************
#include <iostream>				//包含输入输出接口文件 
#include <math.h>
using namespace std;			//引用标准命名空间 
int main()						//主函数 
{
	double distance=0.0;				//距离 
	double weight=0.0; 					//重量 
	double price=0.0;					//单价 
	double fcharge=0.0;					//未折扣价 
	double discount=0.0;				//折扣 
	cout<<"请输入单价、重量和路程：";
	cin>>price>>weight>>distance;
	fcharge= weight * price * distance;	//计算未折扣价 
	int idistance=0;					
	idistance= distance/250;
	switch(idistance)
	{
		case 0:
			discount=0.0;
			cout<<"总运费为："<<fcharge*(1.0-discount)<<endl;
			break;
		case 1:
			discount=0.02;
			cout<<"总运费为："<<fcharge*(1.0-discount)<<endl;
			break;
		case 2 :
		case 3 :
			discount=0.05;
			cout<<"总运费为："<<fcharge*(1.0-discount)<<endl;
			break;
		case 4 :
		case 5 :
		case 6 :
		case 7 :
			discount=0.08;
			cout<<"总运费为："<<fcharge*(1.0-discount)<<endl;
			break;
		case 8 :
		case 9 :
		case 10 :
		case 11 :
			discount=0.1;
			cout<<"总运费为："<<fcharge*(1.0-discount)<<endl;
			break;
		default:
			discount=0.15;
			cout<<"总运费为："<<fcharge*(1.0-discount)<<endl; 
			break;
	}
	return 0;
 } 
