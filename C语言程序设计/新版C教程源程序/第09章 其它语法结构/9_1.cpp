//***************************************************************
//*  �� �� ����9_1.cpp                                          *
//*  ��Ҫ���ܣ�                                                 * 
//*     ��ʾ�ַ�����żУ�����ASCII��                           *
//***************************************************************
#include  <iostream> 
using namespace std;
struct Bit
{
    unsigned b0:1, b1:1, b2:1, b3:1, b4:1, b5:1, b6:1, b7:1;
}*sp;
char data[] = "abcdef";                         // ����ʾ���ַ�
int main()
{
    int bit_sum;                                // �ַ���λ֮�ͣ���Ϊ1��λ��
    int parity;                                 // �ַ���ż������
    char *dp = data;                            // ָ���ַ������ָ��
    while(*dp != '\0')                          // ѭ�������ַ����е�ÿ���ַ�
    {
        sp = (struct Bit*) dp;                  // ���ַ�ǿ��ת��Ϊλ��
        bit_sum = sp->b0 + sp->b1 + sp->b2 + sp->b3 + sp->b4 + sp->b5 + sp->b6;
        parity = bit_sum%2;                     // �õ���żУ����
        cout<<*dp<<parity<<sp->b6<<sp->b5<<sp->b4<<sp->b3<<sp->b2<<sp->b1<<sp->b0<<endl;
        dp++;
    }
	return 0;
}
