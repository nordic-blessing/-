


#include <iostream>
using namespace std;
int main()
{
	char choice;
	int nChoice;
	system("cls");
	cout<<"\n\n\n\n\n";
	cout<<"\t\t|--------ѧ��ѡ��ϵͳ��ѧ���棩--------|\n";
	cout<<"\t\t|\t 0. ����                       |\n";
	cout<<"\t\t|\t 1. ѧ����Ϣ����               |\n";
	cout<<"\t\t|\t 2. ��ʦ��Ϣ                   |\n";
	cout<<"\t\t|\t 3. �γ���Ϣ����               |\n";
	cout<<"\t\t|\t 4. ѧ��ѡ����Ϣ               |\n";
	cout<<"\t\t|\t 5. ѧ���ɼ�����               |\n";
	cout<<"\t\t|\t 6. ��Ϣͳ��ģ                 |\n";
	cout<<"\t\t|--------------------------------------|\n\n";
	cout<<"\t\t\t������ģ��ţ�0-6����";
	cin>>choice;
	if(choice<'0'||choice>'9')
	{
	cout<<"ģ���ӦΪ���֣�"<<endl;
	return 1;
	} 
	 nChoice = choice -'0';
	 switch(nChoice)
	 {
	 	case 0:
	 		cout <<"�������ģ������Ϊ��0. ����";
			 break ; 
			 
		case 1:
	 		cout <<"�������ģ������Ϊ��1.";
			 break ; 	 
	 }
	 return 0;
}
