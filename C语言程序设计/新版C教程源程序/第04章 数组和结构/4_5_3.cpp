//***************************************************************
//*  �� �� ����4_5_3.cpp                                        *
//*  ��Ҫ���ܣ�                                                 * 
//*     �ַ�����غ���ʾ��                                      *
//***************************************************************

#include <iostream>                 // ������������ӿ��ļ�
#include <string.h>                 // �����ַ�����غ��������ͷ�ļ�
using namespace std;                // ���ñ�׼�����ռ� 
int main()                          // ������
{
    char userName[20] = "Chengdu";  // �洢�û������ַ����飬ʵ�����鳤��Ϊ20
    char userName1[10] = "Sichuan";
    char password[20] = " Chengdu"; // �洢������ַ����飬ʵ�����鳤��Ϊ20
    
    cout<<"userNameԭΪ��"<<userName<<endl;
    cout<<"���е��ַ�����"<<strlen(userName)<<endl;
    
    strcpy(userName, userName1);    // userName1���Ƶ�userName��
    cout<<"��userName1���Ƶ�userName��userNameΪ��"<<userName<<endl;
    
    strncpy(userName, password, 3); // ��password��ǰ�����ַ����Ƶ�userName��
    cout<<"��passwordǰ�����ַ����Ƶ�userName��userNameΪ��"<<userName<<endl;

    //strcat(userName, "1234567890123");    // �ַ���ƴ�ӣ���ƴ�Ӻ���ַ������ȳ�����userName�����鳤�ȣ�ִ�к��������Խ�����
    strcat(userName, password);     // ��password�е��ַ�ƴ�ӵ�userName��
    cout<<"��passwordƴ�ӵ�userName��userNameΪ��"<<userName<<endl;

    strcpy(userName, "Chengdu");
    strcpy(userName1, "Sichuan");   // �ָ�userName��userName1��ԭֵ
    cout<<"userName<userName1="<<(userName>userName1)<<endl;
    cout<<"strcmp(userName, userName1)="<<strcmp(userName, userName1)<<endl;

    return 0;
}
