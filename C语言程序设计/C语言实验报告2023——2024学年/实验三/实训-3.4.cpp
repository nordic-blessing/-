//********************************************
//*��������ʵѵ-3.4.cp                       *
//*��Ҫ���ܣ�								 * 
//*		�����乫˾���˷ѼƷ�				 *
//********************************************
#include <iostream>				//������������ӿ��ļ� 
#include <math.h>
using namespace std;			//���ñ�׼�����ռ� 
int main()						//������ 
{
	double distance=0.0;				//���� 
	double weight=0.0; 					//���� 
	double price=0.0;					//���� 
	double fcharge=0.0;					//δ�ۿۼ� 
	double discount=0.0;				//�ۿ� 
	cout<<"�����뵥�ۡ�������·�̣�";
	cin>>price>>weight>>distance;
	fcharge= weight * price * distance;	//����δ�ۿۼ� 
	int idistance=0;					
	idistance= distance/250;
	switch(idistance)
	{
		case 0:
			discount=0.0;
			cout<<"���˷�Ϊ��"<<fcharge*(1.0-discount)<<endl;
			break;
		case 1:
			discount=0.02;
			cout<<"���˷�Ϊ��"<<fcharge*(1.0-discount)<<endl;
			break;
		case 2 :
		case 3 :
			discount=0.05;
			cout<<"���˷�Ϊ��"<<fcharge*(1.0-discount)<<endl;
			break;
		case 4 :
		case 5 :
		case 6 :
		case 7 :
			discount=0.08;
			cout<<"���˷�Ϊ��"<<fcharge*(1.0-discount)<<endl;
			break;
		case 8 :
		case 9 :
		case 10 :
		case 11 :
			discount=0.1;
			cout<<"���˷�Ϊ��"<<fcharge*(1.0-discount)<<endl;
			break;
		default:
			discount=0.15;
			cout<<"���˷�Ϊ��"<<fcharge*(1.0-discount)<<endl; 
			break;
	}
	return 0;
 } 
