//***************************************************
//*��������5-3.cpp									*
//*��Ҫ���ܣ�										*
//*		���ַ��󷽳̵ĸ�							*
//***************************************************
#include <iostream>
#include <math.h>
using namespace std;
int main()
{
	double low = 0.0;		//����½�
	double high = 0.0;		//����Ͻ�
	double mid = 0.0;		//�м��
	double yLow = 0.0;		//�½�㴦����ֵ
	double yHigh = 0.0;		//�Ͻ�㴦����ֵ
	double yMid = 0.0;		//�м�㴦����ֵ

	cout << "�����������Ͻ磺";
	cin >> high ;				//�����Ͻ�
	cout << "�����������½磺";
	cin >> low ;				//�����½�
	mid = (low + high) / 2.0;	//�м��

	yLow = low * low * low - 2.0 * low * low - low + 2;
	yHigh = high * high * high - 2.0 * high * high - high + 2;

	if (yLow * yHigh > 0)
	{
		cout << "���ܱ�֤���������и����������������䣡" << endl;		//�������޸�
		return 1;
	}
	
	cout << "���̵ĸ�Ϊ��";

	while (high - low >= 1e-4)		//�ж��Ͻ��Ƿ���½��
	{
		mid = (low + high) / 2.0;
		yMid = mid * mid * mid - 2.0 * mid * mid - mid + 2;

		if (fabs(yMid)<1e-6)			
		{								//��Ϊmid
			break;
		}
		else
			if (yLow * yMid < 0)
			{							//���ڣ�low��mid)֮��
				yHigh = yMid;
				high = mid;
			}
			else
			{							//���ڣ�mid,high)֮��
				yLow = yMid;
				low = mid;
			}	
	}
	cout << mid;
}