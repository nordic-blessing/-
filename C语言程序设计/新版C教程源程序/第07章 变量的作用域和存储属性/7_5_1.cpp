//***************************************************************
//*  �� �� ����7_5_1.cpp                                        *
//*  ��Ҫ���ܣ�                                                 *
//*     �����ⲿ���������������쵽Դ�ļ�7_6_2.cpp               *
//***************************************************************
#include <iostream>                         // ������������ӿ��ļ�
using namespace std;                        // ���ñ�׼�����ռ���
static int score[10] = { 0 };                      // �����ⲿ����
static int maxScore = 0, minScore = 0;             // �����ⲿ����
void find_Max_Min();
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
