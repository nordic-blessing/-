//***************************************************************
//*  程 序 名：9_4.cpp                                          *
//*  主要功能：                                                 * 
//*     利用联合交换一个整数的低8字节和高8字节                  *
//***************************************************************
#include  <iostream> 
using namespace std;
struct BYTE                                         // 字节结构类型
{
    unsigned char l;                                // 低字节
    unsigned char h;                                // 高字节
};
union Body                                          // 字节联合类型
{
    BYTE byte;                                      // 字节表示
    unsigned short word;                            // 整型表示
}a, b;

int main(){
    cout<<"请输入一个整数：";
    cin>>hex>>a.word;                               // 以16进制形式输入整数，存放到联合的整数成员中
    b.byte.h = a.byte.l;                            // 将整数a的低字节赋给b的高字节 
    b.byte.l = a.byte.h;                            // 将整数a的高字节赋给b的低字节
    cout<<hex<<a.word<<"-->"<<hex<<b.word<<endl;    // 输出转换结果
    return 0;
}
