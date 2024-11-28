//***************************************************
//*程序名：5-3.cpp									*
//*主要功能：										*
//*		二分法求方程的根							*
//***************************************************
#include <iostream>
#include <math.h>
using namespace std;
int main()
{
	double low = 0.0;		//求根下界
	double high = 0.0;		//求根上界
	double mid = 0.0;		//中间点
	double yLow = 0.0;		//下界点处函数值
	double yHigh = 0.0;		//上界点处函数值
	double yMid = 0.0;		//中间点处函数值

	cout << "请输入区间上界：";
	cin >> high ;				//输入上界
	cout << "请输入区间下界：";
	cin >> low ;				//输入下界
	mid = (low + high) / 2.0;	//中间点

	yLow = low * low * low - 2.0 * low * low - low + 2;
	yHigh = high * high * high - 2.0 * high * high - high + 2;

	if (yLow * yHigh > 0)
	{
		cout << "不能保证此区间内有根，请重新输入区间！" << endl;		//区间内无根
		return 1;
	}
	
	cout << "方程的根为：";

	while (high - low >= 1e-4)		//判断上界是否比下界大
	{
		mid = (low + high) / 2.0;
		yMid = mid * mid * mid - 2.0 * mid * mid - mid + 2;

		if (fabs(yMid)<1e-6)			
		{								//根为mid
			break;
		}
		else
			if (yLow * yMid < 0)
			{							//根在（low，mid)之间
				yHigh = yMid;
				high = mid;
			}
			else
			{							//根在（mid,high)之间
				yLow = yMid;
				low = mid;
			}	
	}
	cout << mid;
}