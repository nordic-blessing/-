//***************************************************************
//*  �� �� ����7_2.cpp                                          *
//*  ��Ҫ���ܣ�                                                 *
//*     �����βα�����������                                    *
//***************************************************************
#include <iostream>                         // ������������ӿ��ļ�
using namespace std;                        // ���ñ�׼�����ռ�
double average(int score[], int n);         // average�������ܣ���ƽ��ֵ
int main()
{
    const int STU_NUM = 5;                  // �������ͳ�������ѧ������
    int sco[STU_NUM] = {0};                 // ���ѧ���ɼ�������
    int i = 0;                              // �����±����i
    double aver = 0;                        // ���ƽ��ֵ
    cout << "������" << STU_NUM << "��ѧ������Ч�ɼ����س�������" << endl;
    for(i = 0; i < STU_NUM; i++)   cin >> sco[i];
    aver = average(sco, STU_NUM);           // ������ƽ���ɼ��ĺ���average
    cout << "ƽ���ɼ�Ϊ:" << aver << endl;
    return 0;	
}
double average(int score[], int n)
{                                           // average������ʼ
    int i = 0;                              // �����±����
    double ave = 0;                         // ƽ���ɼ�
    int sum = 0;                            // �ɼ��ܺ�
    for(i = 0; i < n; i++)
    {
        sum = sum + score[i];               // �ۼ����
    }
    ave = sum / (double)n;                  // ��ƽ��
    return ave;                             // ���������̺�ƽ��ֵave������������
}                                           // average��������