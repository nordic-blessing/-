//***************************************************************
//*  �� �� ����7_9.cpp                                          *
//*  ��Ҫ���ܣ�                                                 *
//*     ʹ�þ�̬ȫ�ֱ�����10���ɼ������ֵ����Сֵ              *
//***************************************************************
#include <iostream>                         // ������������ӿ��ļ�
using namespace std;                        // ���ñ�׼�����ռ�
static int score[10] = { 0 };               // ���徲̬ȫ������
static int maxScore = 0, minScore = 0;      // ���徲̬ȫ�ֱ���
void find_Max_Min();                        // ��������
int main()
{
    int i = 0;                              // �����±����
    cout << "Enter 10 scores:" << endl;
    for(i = 0; i < 10; i++)
    {
        cin >> score[i];
    }
    maxScore = minScore = score[0];
    find_Max_Min();                         // ���ú���find_Max_Min()
    cout << "The Max score: " << maxScore << endl;
    cout << "The Min score: " << minScore << endl;
    return 0;
}
void find_Max_Min()                         // �����ֵ����Сֵ����
{
    int i = 0;                              // �����±����
    for(i = 0; i < 10; i++)
    { 
        if(score[i] > maxScore)
        {
            maxScore = score[i];
        }
        if(score[i] < minScore)
        {
            minScore = score[i];
        }
    }
    return;                                 // �������ִ�����̴��ص���������
}
