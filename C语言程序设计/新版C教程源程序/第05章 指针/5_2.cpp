//***************************************************************
//*  �� �� ����5_2.cpp                                          *
//*  ��Ҫ���ܣ�                                                 *
//*     ���Խ�������ָ�������ָ��                              *
//***************************************************************
#include <iostream>                         // �����Ԥ��������
using namespace std;                        // ���ñ�׼�����ռ�
int main()                                
{
    int *p_max = 0, *p_min = 0, *p = 0;     // ����ָ�����͵�ָ���������ʼ��Ϊ0
    int C_score = 0, math_score = 0;        // ��������������C�ɼ�����ѧ�ɼ�
    cin>>C_score>>math_score;               // �Ӽ�������C�ɼ�����ѧ�ɼ������Ӧ�ı�����
    p_max = &C_score;                       // ����, p_max ָ�� C_score
    p_min = &math_score;                    // p_minָ��math_score 
    if(math_score > C_score)                // �����ѧ�ɼ��ϸ�	
    {
        p = p_max, p_max = p_min, p_min = p;//����p_max��p_min������
    }   
    cout << "C_score=" << C_score << ",";
    cout << "math_score=" << math_score << endl;
    cout << "Highscore=" << *p_max << "," << "Lowscore=" << *p_min << endl;	   
    return 0;
}
