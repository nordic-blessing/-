//***************************************************************
//*  �� �� ����ʵѵ5_1.cpp                                      *
//*  ��Ҫ���ܣ�                                                 *
//*     �Ӽ�������ĳһ�γ̳ɼ���������ͳ��                      *
//***************************************************************
#include <iostream>                         // ������������ӿ��ļ�
using namespace std;                        // ���ñ�׼�����ռ�
int main()                                  // ����������
{
    int count = 0;                          // ѡ��������
    int examScore = 0;                      // ѧ���ɼ�
    int maxExamScore = 0;                   // ��߷�
    int minExamScore = 0;                   // ��ͷ�
    int totalExamScore = 0;                 // �ܷ�
    int averageExamScore = 0;               // ƽ����
    int score_100 = 0;                      // 100������
    int score_90_99 = 0;                    // 90��������
    int score_80_89 = 0;                    // 80��������
    int score_70_79 = 0;                    // 70��������
    int score_60_69 = 0;                    // 60��������
    int score_0 = 0;                        // ����������
    cout << "������ѧ���ɼ���0��100����" << endl;
    cin >> examScore;
    maxExamScore = minExamScore = examScore;
    while (examScore >= 0 && examScore <= 100)
    {                                       // �Է��������ķ�ֵ����ͳ�ƺͼ���
        count++;                          // ��������
        if (examScore > maxExamScore)        // ��¼��߷�
        {
            maxExamScore = examScore;
        }
        if (examScore < minExamScore)        // ��¼��ͷ�
        {
            minExamScore = examScore;
        }
        switch (examScore / 10)                // ��������ͳ������
        {
                  case 10: score_100++;   break;
                  case 9:  score_90_99++; break;
                  case 8:  score_80_89++; break;
                  case 7:  score_70_79++; break;
                  case 6:  score_60_69++; break;
                  default: score_0++;
        
}
        totalExamScore += examScore;        // �ܷ�����
        cin >> examScore;                   // ������һ��ѧ���ĳɼ�
    }
    averageExamScore = totalExamScore / count;  // ����ƽ����
    cout << endl;                           // ������ʾͳ����Ϣ
    cout << "ѡ����������" << count << endl;
    cout << "��߷֣�" << maxExamScore << endl;
    cout << "��ͷ֣�" << minExamScore << endl;
    cout << "ƽ���֣�" << averageExamScore << endl;
    cout << "100��������  " << score_100 << endl;
    cout << "90~99��������" << score_90_99 << endl;
    cout << "80~89��������" << score_80_89 << endl;
    cout << "70~79��������" << score_70_79 << endl;
    cout << "60~69��������" << score_60_69 << endl;
    cout << "������������ " << score_0 << endl;
    cout << endl;
    system("pause ");
    return 0;
}                                           // ����������
