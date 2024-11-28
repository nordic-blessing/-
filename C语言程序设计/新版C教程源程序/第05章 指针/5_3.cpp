//***************************************************************
//*  程 序 名：5_3.cpp                                          *
//*  主要功能：                                                 *
//*     显示内存中数组元素的地址分配情况                        *
//***************************************************************

#include <iostream>
using namespace std;                // 引用标准命名空间
int main()
{
	short arr_short[3] = {0};
	float arr_float[3] = {0};
	double arr_double[3] = {0};
	int i =0 ;

	cout << "\t\tshort类型数组\tfloat类型数组\tdouble类型数组" << endl;
	cout << "＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝" << endl;
	for(i = 0; i < 3; i++) 
	{
	/*	cout << "元素" << i << "的地址" << "\t" << &arr_short[i] <<
			"\t" << &arr_float[i] << "\t" << &arr_double[i] << endl;*/
		cout << "元素" << i << "的地址" << "\t" << arr_short+i <<
            "\t" << arr_float+i << "\t" << arr_double+i << endl;	
	}	
	return 1;
}
