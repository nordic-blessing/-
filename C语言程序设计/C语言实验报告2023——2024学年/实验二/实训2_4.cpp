//****************************************************
//*��������ʵѵ2_4.cp								 *
//*��Ҫ���ܣ�										 *
//*		���빤��Сʱ�������˰������				 *
//****************************************************
# include <iostream>		//������������ӿ��ļ� 
using namespace std ;		//���ñ�׼�����ռ� 
int main()					//���������� 
{							//��������ʼ 
	double hourPrice = 25.0;
	double taxRate = 0.15;
	double workingHour = 0.0;
	double income = 0.0;
	cout<<"�����빤��Сʱ����";
	cin>>workingHour;
	income = workingHour*hourPrice*(1-taxRate);
	cout<<"ʵ������Ϊ��"<<income<<"Ԫ"<<endl;
	return 0; 
}
