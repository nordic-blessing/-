//***************************************************************
//*  �� �� ����5_15.cpp                                         *
//*  ��Ҫ���ܣ�                                                 *
//*     ��ѯ����ʵϰ�յ�������                                *
//***************************************************************
#include <iostream>                         // ������������ӿ��ļ�
using namespace std;                        // ���ñ�׼�����ռ�
struct Date                                 // ����ṹ����Date����ʾ����
{
	int year;                               // ��
	int month;                              // ��
	int day;                                // ��
};

int main()
{
    Date today;                             // ����todayΪDate���͵Ľṹ
    Date *p_today = 0;                      // ����p_today����ָ��ṹ����today
    //��ά����ĵ�2ά�±����ʵϰ�·ݣ�1��7�£�����ά����Ԫ�ص�ֵ����ĳ�µ�����
    int day_tab[2][7] = {{0,31,28,31,30,31,30},{0,31,29,31,30,31,30}};  
    int i = 0;                              // ѭ������
    int flag = 0;                           // ��־��0Ϊƽ�꣬��0Ϊ����	
    unsigned int day=0;                     //��ʾ���ӱ���1��1�տ�ʼ��ָ������һ���ж����죻
    p_today = &today;                       //p_todayָ��today
    cout << "ע�⣺ʵϰʱ���ÿ���01��01�տ�ʼ��06��30�Ž�����" << endl;
    cout << "���������ѯ�����ڣ�" << endl;
    cout << "��: ";
    cin >> p_today->year;
    cout << "��: ";
    cin >> p_today->month;
    cout << "��: ";
    cin >> p_today->day;
    //�������Ĳ�ѯ�·��Ƿ�Ϊʵϰ��
    while(!(p_today->month > 0 && p_today->month < 7))
    {
        cout << "����Ĳ�ѯ�·ݲ���ʵϰ�ڣ�" << endl;
        cout << "�������������ѯ�����ڣ�" << endl;
        cout << "��: ";
        cin >> p_today->year;
        cout << "��: ";
        cin >> p_today->month;
        cout << "��: ";
        cin >> p_today->day;
    }
    //������������Ƿ�Ϊ����
    flag = (p_today->year % 4 == 0 && p_today->year % 100 != 0 || p_today->year % 400 == 0);	
    //����ӱ���1��1�տ�ʼ��ָ������һ���ж�����
    for(i = 1; i < p_today->month; i++)
    {
        day=day+day_tab[flag][i];
    }
    day = day + p_today->day;
    if(day % 5 > 0 && day % 5 < 4 )	
    {
        cout << "����������." << endl;
    }
    else
    {
        cout << "������������." << endl;
    }
    return 0;
}
