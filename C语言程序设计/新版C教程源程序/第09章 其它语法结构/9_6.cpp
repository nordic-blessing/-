//***************************************************************
//*  �� �� ����9_6.cpp                                          *
//*  ��Ҫ���ܣ�                                                 * 
//*     ʹ��ö���������һ�ܵ�ѧϰ���                          *
//***************************************************************
#include  <iostream> 
using namespace std;
enum Day{mon, tue, wed, thu, fri};                  // ����ѧϰ��ö������
void studyDay(Day stDay);                           // ����ѧϰ�պ�����������ʾĳ���ѧϰ���
void studyDay(Day stDay)                            // ѧϰ�պ�����������ʾĳ���ѧϰ���
{
    switch(stDay)
    {
        case mon:
            cout<<"��һ C����"<<endl;
            break;
        case tue:
            cout<<"�ܶ� ΢����"<<endl;
        case wed:
            cout<<"���� ���ݽṹ"<<endl;
            break;
        case thu:
            cout<<"���� ����ϵͳ"<<endl;
            break;
        case fri:
            cout<<"���� �����ͼ��ѧ"<<endl;
    }
}

int main(){
    Day a;                                          // ����ѧϰ�ձ���
    for(a = mon; a <= fri; a = (Day)(a+1))          // ѭ���������ѧϰ�յ�ѧϰ���
    {                                               // ��ע������һö��ֵ�ķ���
	    studyDay(a);
    }

    return 0;
}
