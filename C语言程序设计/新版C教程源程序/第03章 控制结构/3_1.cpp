//***************************************************************
//*  �� �� ����3_1.cpp                                          *
//*  ��Ҫ���ܣ�                                                 * 
//*     �Ӽ�������һ��ѧ����ѧ�š������ͳɼ��������            *
//***************************************************************
#include <iostream>                         // ������������ӿ��ļ�
using namespace std;                        // ���ñ�׼�����ռ� 
int main()                                  // ����������
{                                           // ��������ʼ
    int StudentNumber;                      // ����ѧ�ű���
    char StudentName[20] = "";              // ���������ַ�����
    float score;                            // ����ɼ�����
    cout << "Student number:" ;	
    cin >> StudentNumber;
    cout << "Student name:" ;
    cin >> StudentName;
    cout << "Score:" ;
    cin >> score;
    cout << StudentNumber << "    "<< StudentName << "    "<< score << endl;
    return 0;                               // ��������ֵΪ0
}                                           // ����������
