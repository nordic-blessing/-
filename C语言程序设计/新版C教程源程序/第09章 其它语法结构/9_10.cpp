//***************************************************************
//*  �� �� ����9_10.cpp                                         *
//*  ��Ҫ���ܣ�                                                 *
//*     ѧ���ɼ�ͳ��                                            *
//***************************************************************
#include  <iostream> 
#include "max.h"                                        // ����������max������ͷ�ļ�
#include "counter.h"                                    // ����������counter������ͷ�ļ�
#include "average.h"                                    // ����������average������ͷ�ļ�
using namespace std;

int main()
{
    const int n = 25;                                   // ѧ������
    int score[n] = {100, 96, 97, 95, 92, 88, 85, 83, 84, 86, 87, 79, 77, 78, 73, 68, 66, 68, 67, 65, 64, 63, 61, 58, 55};
    cout<<"��߷֣�"<<max(score, n)<<endl<<endl;
    counter(score, n);
    cout<<endl;
    cout<<"ƽ���ɼ���"<<average(score, n)<<endl;

    return 0;
}
