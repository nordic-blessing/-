//***************************************************************
//*  �� �� ����5_3.cpp                                          *
//*  ��Ҫ���ܣ�                                                 *
//*     ��ʾ�ڴ�������Ԫ�صĵ�ַ�������                        *
//***************************************************************

#include <iostream>
using namespace std;                // ���ñ�׼�����ռ�
int main()
{
	short arr_short[3] = {0};
	float arr_float[3] = {0};
	double arr_double[3] = {0};
	int i =0 ;

	cout << "\t\tshort��������\tfloat��������\tdouble��������" << endl;
	cout << "����������������������������������������������������" << endl;
	for(i = 0; i < 3; i++) 
	{
	/*	cout << "Ԫ��" << i << "�ĵ�ַ" << "\t" << &arr_short[i] <<
			"\t" << &arr_float[i] << "\t" << &arr_double[i] << endl;*/
		cout << "Ԫ��" << i << "�ĵ�ַ" << "\t" << arr_short+i <<
            "\t" << arr_float+i << "\t" << arr_double+i << endl;	
	}	
	return 1;
}
