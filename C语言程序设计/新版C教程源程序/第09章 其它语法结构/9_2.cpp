//***************************************************************
//*  �� �� ����9_2.cpp                                          *
//*  ��Ҫ���ܣ�                                                 * 
//*     ����λ��ͳ��ѧ���ɼ��ĸ��ȼ�����                        *
//***************************************************************
#include  <iostream> 
using namespace std;
struct{
    unsigned excellent:5;               // ����ѧ������
    unsigned fine:5;                    // ����ѧ������
    unsigned pass:5;                    // ����ѧ������
    unsigned fail:5;                    // ������ѧ������
}score;

int main(){
    score.excellent  = 0;
    score.fine  = 0;
    score.pass  = 0;
    score.fail  = 0;
    int s[25] = {100,96 ,97 ,95 ,92 ,88 ,85 ,83 ,84 ,86 ,87 ,79 ,77 ,78 ,73 ,68 ,66 ,68 ,67 ,65 ,64 ,63 ,61 ,58 ,55}; // ѧ���ɼ�
    int i;                              //���ڱ�ʾ������±�
    for(i = 0; i < 25; i++)
    {
        if(s[i] < 60)                   // ������
        {
            score.fail ++;
        }
        else if(s[i] < 69)              // ����
        {
            score.pass ++;
        }
        else if(s[i] < 89)              // ��
        {
            score.fine ++;
        }
        else                            // ��
        {
            score.excellent ++;
        }
    }
    cout<<"�ɼ����������Ϊ"<<score.excellent<<endl;
    cout<<"�ɼ����õ�����Ϊ"<<score.fine<<endl;
    cout<<"�ɼ����������Ϊ"<<score.pass<<endl;
    cout<<"�ɼ������������Ϊ"<<score.fail<<endl;
    return 0;
}
