//***************************************************************
//*  程 序 名：9_1.cpp                                          *
//*  主要功能：                                                 * 
//*     显示字符的奇偶校验码和ASCII码                           *
//***************************************************************
#include  <iostream> 
using namespace std;
struct Bit
{
    unsigned b0:1, b1:1, b2:1, b3:1, b4:1, b5:1, b6:1, b7:1;
}*sp;
char data[] = "abcdef";                         // 待显示的字符
int main()
{
    int bit_sum;                                // 字符各位之和，即为1的位数
    int parity;                                 // 字符奇偶检验码
    char *dp = data;                            // 指向字符数组的指针
    while(*dp != '\0')                          // 循环处理字符串中的每个字符
    {
        sp = (struct Bit*) dp;                  // 将字符强制转换为位域
        bit_sum = sp->b0 + sp->b1 + sp->b2 + sp->b3 + sp->b4 + sp->b5 + sp->b6;
        parity = bit_sum%2;                     // 得到奇偶校验码
        cout<<*dp<<parity<<sp->b6<<sp->b5<<sp->b4<<sp->b3<<sp->b2<<sp->b1<<sp->b0<<endl;
        dp++;
    }
	return 0;
}
