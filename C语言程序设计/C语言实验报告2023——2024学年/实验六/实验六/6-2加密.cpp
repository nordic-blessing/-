//***************************************************************
//*  �� �� ����ʵѵ6_2.cpp                                      *
//*  ��Ҫ���ܣ�                                                 *
//*     �������ı�����                                            *
//***************************************************************
#include <iostream>                         // ������������ӿ��ļ�
#include <string.h>                         // �����ַ�����غ��������ͷ�ļ�
using namespace std;                        // ���ñ�׼�����ռ�
int main()                                  // ������
{
    char password[20] = "";                 // �洢������ַ�����
    char encodePass[20] = "";               // ���ܺ������
    char ch;                                // ��ǰ�ַ�
    int i;                                  // ѭ������
    int n;                                  //�����ַ�������
    int num;                                // �ַ�
    cout << "���룺" ;
    cin >> password;
    n = strlen(password);
    for (i = 0; i < n; i++)
    {                                       // ѭ���������ַ�������ǲ�ֹ
        ch = password[i];
        if (ch >= 'a' && ch <= 'z')
        {                                   // Сд��ĸ
            num = ch - 'a' + 1;             // ������ĸ���
        }
        else if (ch >= 'A' && ch <= 'Z')
        {                                   // ������ĸ
            num = ch - 'A' + 27;            // ������ĸ���
        }
        else
        {
            encodePass[i] = ch;               // �����ַ���ֱ�Ӹ���
            continue;                       // ֱ��ת������һ�ַ�
        }
        num = num * 3 % 52;
        if (num == 0)
            num = 52;
        if (num <= 26)
            ch = num + 'a' - 1;
        else
            ch = num - 27 + 'A';
        encodePass[i] = ch;
    }
    encodePass[i] = '\0';
    cout << "���ܺ������Ϊ��" << encodePass << endl;
    return 0;
}