#ifndef AVERAGE_H_INCLUDED
#define AVERAGE_H_INCLUDED
//***************************************************************
//*  �� �� ����average                                          *
//*  �������                                                   *
//*      score     ѧ���ɼ�����                                 *
//*      n         ѧ������                                     *
//*  ����ֵ                                                     *
//*      ƽ���ɼ�                                               *
//*  �������ܣ�                                                 *
//*      ͳ�Ʋ�����score����ƽ��ֵ                              *
//***************************************************************
double average(int score[], int n)
{
    int sum = 0;                     // ѧ�����ܷ���
    int i;                           // �����±�
    for(i = 0; i < n; i++)
    {
        sum = sum + score[i];
    }
    return sum / (double)n;
}

#endif // AVERAGE_H_INCLUDED
