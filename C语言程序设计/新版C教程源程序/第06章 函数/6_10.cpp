//***************************************************************
//*  程 序 名：6_10.cpp                                         *
//*  主要功能：                                                 * 
//*     显示程序的所有运行参数                                  *
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
