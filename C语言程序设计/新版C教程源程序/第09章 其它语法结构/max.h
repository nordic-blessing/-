#ifndef MAX_H_INCLUDED
#define MAX_H_INCLUDED
//***************************************************************
//*  �� �� ����max                                              *
//*  �������                                                   *
//*      score     ѧ���ɼ�����                                 *
//*      n         ѧ������                                     *
//*  ����ֵ                                                     *
//*      ��߷�                                                 *
//*  �������ܣ�                                                 *
//*      ͳ�Ʋ�����score������߷�                              *
//***************************************************************
int max(int score[], int n)
{
    int i;                                  // �����±�
    int max = 0;                            // ���ķ�ֵ
    for(i = 0; i < 2; i++)
    {
        if(score[i] > max)
        {
            max = score[i];
        }
    }
    return max;
}
#endif // MAX_H_INCLUDED
