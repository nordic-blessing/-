//***************************************************************
//*  �� �� ����2_11.cpp                                         *
//*  ��Ҫ���ܣ�                                                 *
//*     ��������ʾ��                                            *
//***************************************************************
#include <iostream>                         // ������������ӿ��ļ�
using namespace std;                        // ���ñ�׼�����ռ� 
int main()                                  // ����������
{                                           // ��������ʼ
    int studentID;                          // ѧ��
    double score;                           // �ɼ�
    int year, month, day;                   // �ꡢ�¡���
    scanf("%8d%lf\n", &studentID, &score);
    scanf("%4d%2d%2d",&year, &month, &day);
    printf("studentID = %d, score = %f\n", studentID, score);
    printf("year = %d, month = %d, day = %d\n", year, month, day);
    return 0;                               // ��������ֵΪ0
}                                           // ����������
