//***************************************************************
//*  �� �� ����3_11.cpp                                         *
//*  ��Ҫ���ܣ�                                                 *
//*     �Ӽ����������ɸ�������                                  *
//*     ȥ������һ�����ֵ��һ����Сֵ����ƽ��ֵ                *
//***************************************************************
#include <iostream>                         // ������������ӿ��ļ�
using namespace std;                        // ���ñ�׼�����ռ� 
int main()                                  // ����������
{
    float score = 0.0f;                     // ר�Ҵ��
    float minScore = 100.0f;                // ��ͷ�
    float maxScore = 0.0f;                  // ��߷�
    float sum = 0.0f;                       // �ܷ�
    int i = 0;                              // ר����
    cout << "����ר�����֣���-1������" << endl;
    cin >> score;                           // �����һ������
    minScore = minScore = score;            // ������һ������Ϊ��߷ֺ���ͷ�
    while(score != -1)
    {  
        i ++;                               // ר������1
        sum = sum + score;                  // �����ۼ�
        if(score > maxScore)                // �����ǰ����������߷�
        {
            maxScore = score;               // ����߷ָ���
        }
        if(score < minScore)                //�����ǰ����С����ͷ�
        {
            minScore = score;               //����ͷָ���
        }
        cin >> score;                       // ������һ������
    }
    sum = sum - maxScore - minScore;        // ȥ��һ����߷ֺ�һ����ͷ�
    cout << "���÷֣�" << sum / (i - 2) << endl;
    return 0;
}                                           // ����������
