//********************************************
//*��������ʵѵ-3.3.cp                       *
//*��Ҫ���ܣ�								 * 
//*		�����ĵ��						 *
//********************************************
#include <iostream>				//������������ӿ��ļ� 
#include <math.h>
using namespace std;			//���ñ�׼�����ռ� 
int main()						//������ 
{
	double electricity = 0.0;	//�õ��� 
	double low = 180.0;			//�͵����� 
	double mid = 280.0;			//�е����� 
	double lowPrice = 0.5224;	//�͵���� 
	double midPrice = 0.6224;	//�е���� 
	double highPrice = 0.8224;	//�ߵ���� 
	double charge = 0.0;		//��� 
	cout<<"�������õ�����"; 
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
	 cout<<"���Ϊ��"<<charge<<endl;
	 return 0; 
}
