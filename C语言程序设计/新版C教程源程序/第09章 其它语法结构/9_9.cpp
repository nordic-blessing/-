//***************************************************************
//*  �� �� ����9_9.cpp                                          *
//*  ��Ҫ���ܣ�                                                 *
//*     ���κ��滻ʾ��                                          *
//***************************************************************
#include  <iostream> 
#define MAX(a,b) ((a > b)?a:b)
#define Cal(a,b) (a + b - a * b)
using namespace std;

int main()
{
    int x = 10, y = 20;
    cout<<"���ֵΪ"<<MAX(x+y,y-x)<<endl;
    cout<<"Cal(2,3)="<<Cal(2,3)<<endl;
    cout<<"Cal(1+1,1+2)="<<Cal(1+1,1+2)<<endl;
    return 01;
}
