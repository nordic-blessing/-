//***************************************************************
//*  �� �� ����6_10.cpp                                         *
//*  ��Ҫ���ܣ�                                                 * 
//*     ��ʾ������������в���                                  *
//***************************************************************
#include <iostream>
using namespace std;
int main(int argc,char *argv[ ])
{
    int icount=0;
    while(icount < argc)
    {
        cout<<"arg"<<icount<<": "<<argv[icount]<<endl;
        icount++;
    }
    return 0;
 }
