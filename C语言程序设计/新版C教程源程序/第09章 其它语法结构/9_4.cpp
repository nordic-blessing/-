//***************************************************************
//*  �� �� ����9_4.cpp                                          *
//*  ��Ҫ���ܣ�                                                 * 
//*     �������Ͻ���һ�������ĵ�8�ֽں͸�8�ֽ�                  *
//***************************************************************
#include  <iostream> 
using namespace std;
struct BYTE                                         // �ֽڽṹ����
{
    unsigned char l;                                // ���ֽ�
    unsigned char h;                                // ���ֽ�
};
union Body                                          // �ֽ���������
{
    BYTE byte;                                      // �ֽڱ�ʾ
    unsigned short word;                            // ���ͱ�ʾ
}a, b;

int main(){
    cout<<"������һ��������";
    cin>>hex>>a.word;                               // ��16������ʽ������������ŵ����ϵ�������Ա��
    b.byte.h = a.byte.l;                            // ������a�ĵ��ֽڸ���b�ĸ��ֽ� 
    b.byte.l = a.byte.h;                            // ������a�ĸ��ֽڸ���b�ĵ��ֽ�
    cout<<hex<<a.word<<"-->"<<hex<<b.word<<endl;    // ���ת�����
    return 0;
}
