//***************************************************************
//*  程 序 名：9_6.cpp                                          *
//*  主要功能：                                                 * 
//*     使用枚举类型输出一周的学习情况                          *
//***************************************************************
#include  <iostream> 
using namespace std;
enum Day{mon, tue, wed, thu, fri};                  // 定义学习日枚举类型
void studyDay(Day stDay);                           // 申明学习日函数，用于显示某天的学习情况
void studyDay(Day stDay)                            // 学习日函数，用于显示某天的学习情况
{
    switch(stDay)
    {
        case mon:
            cout<<"周一 C语言"<<endl;
            break;
        case tue:
            cout<<"周二 微积分"<<endl;
        case wed:
            cout<<"周三 数据结构"<<endl;
            break;
        case thu:
            cout<<"周四 操作系统"<<endl;
            break;
        case fri:
            cout<<"周五 计算机图形学"<<endl;
    }
}

int main(){
    Day a;                                          // 定义学习日变量
    for(a = mon; a <= fri; a = (Day)(a+1))          // 循环输出各个学习日的学习情况
    {                                               // 需注意获得下一枚举值的方法
	    studyDay(a);
    }

    return 0;
}
