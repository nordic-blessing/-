#ifndef COUNTER_H_INCLUDED    //ifndef������Ϊ��ֹ�ض���
#define COUNTER_H_INCLUDED
#include <iostream>
using namespace std;
//***************************************************************
//*  �� �� ����counter                                          *
//*  �������                                                   *
//*      score     ѧ���ɼ�����                                 *
//*      n         ѧ������                                     *
//*  ����ֵ                                                     *
//*      ��                                                     *
//*  �������ܣ�                                                 *
//*      ͳ�Ʋ����score����������ε�����                      *
//***************************************************************
void counter(int score[], int n)
{
    int i;                    // ���ڴ洢�����±�
    int grade_1 = 0;          // ���ڴ洢90~100�ֵ�����
    int grade_2 = 0;          // ���ڴ洢80~89�ֵ�����
    int grade_3 = 0;          // ���ڴ洢70~79�ֵ�����
    int grade_4 = 0;          // ���ڴ洢60~69�ֵ�����
    int grade_5 = 0;          // ���ڴ洢60�����µ�����
    for(i = 0; i < n; i++)
    {
        if(score[i] < 60)
        {	
            grade_5++;
        }
        else if(score[i] < 69)
        {
            grade_4++;
        }
        else if(score[i] < 79)
        {
            grade_3++;
        }
        else if(score[i] < 89)
        {
            grade_2++;
        }
        else
        {
            grade_1++;
        }
    }
    cout<<"90��100�ֵ�����Ϊ "<<grade_1<<endl;
    cout<<"80��89�ֵ�����Ϊ "<<grade_2<<endl;
    cout<<"70��79�ֵ�����Ϊ "<<grade_3<<endl;
    cout<<"60��69�ֵ�����Ϊ "<<grade_4<<endl;
    cout<<"60�����µ�����Ϊ "<<grade_5<<endl;
}
#endif