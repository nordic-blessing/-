//***************************************************************
//*  �� �� ����7_3.cpp                                          *
//*  ��Ҫ���ܣ�                                                 *
//*     ����ȫ�ֱ�����������                                    *
//***************************************************************
#include <iostream>                         // ������������ӿ��ļ�
using namespace std;                        // ���ñ�׼�����ռ�
int sum = 0;                                // ����ȫ�ֱ���sum��ųɼ��ܺ�
double average(int score[], int n);         // ����average����������Ϊ��ƽ��ֵ
double average(int score[], int n)
{
    int i = 0;                              // �����±����
    double ave = 0;                         // ƽ���ɼ�
    sum = 0;                                // ���֮ǰ�ۼӱ�����0
    for(i = 0; i < n; i++)
    {
        sum = sum + score[i];               // �ۼ����
    }
    ave = sum / (double)n;                  // ��ƽ��
    return ave;                             // ���̺�ƽ��ֵ������������
}
int main()
{
    const int STU_NUM = 5;                  // �������ͳ�������ѧ������
    int sco[STU_NUM] = {0};                 // ���ѧ���ɼ�������
    int i = 0;                              // �����±����i
    double aver = 0;                        // ���ƽ��ֵ
    cout << "����" << STU_NUM << "��ѧ���ĳɼ���" << endl;
    for(i = 0; i < STU_NUM; i++)
    {
        cin >> sco[i];
    }
    aver = average(sco, STU_NUM);
    cout << endl << "ƽ���ɼ�Ϊ:" << aver << endl;
    cout << endl << "�ɼ��ܺ�Ϊ:" << sum << endl;
    return 0;	
}
