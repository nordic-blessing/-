#include <iostream>                 // ������������ӿ��ļ�
using namespace std;                // ���ñ�׼�����ռ�
char *strlmt(char str[], char ch, int n);
void createMenu(char menuTitle[20], char menuItem[][20], int n);
void showMenu(char menuTitle[20], char menuItem[][20], void (*menuExecFun[])(), int n);
void showAdminCourseManagerMenu();
void returnFunc();
void courseAppend();                // �����γ̺���
void courseQuery();                 // �γ̲�ѯ����
void courseDelete();                // �γ�ɾ������
void courseUpdate();                // �γ��޸ĺ���
void courseBrowse();                // �γ��������
int main()
{
    showAdminCourseManagerMenu();   // ��ʾ�γ���Ϣ�˵���ִ����Ӧѡ��
	return 0;
}

char *strlmt(char str[], char ch, int n)
// ���ַ���str��չ������Ϊ|n|�����nС��0����str���������ַ�ch��������str���ұ�����ַ�ch
// ���str����n����ضϡ���nС��0ʱ���ض�����ַ�������ض��Ҳ��ַ�
{
    int m = strlen(str);                    // �ַ���ԭ����
    int len = n > 0?n:-n;                   // �ַ����³���
    int i = 0;
    char* strReturn  = new char[100]; 
    if(len == 0)                            // �ַ����³���Ϊ�㣬�򷵻ؿ��ַ���
    {
        return "";
    }

    if(ch == '\0')
    {
        return str;
    }


    if(m < len)
    {   
        if(n < 0)
        {
            // ���ɺ���ַ���
            for(i = 0; i < len-m; i++)
            {
                strReturn[i] = ch;
            }
            strReturn[i] = '\0';
            return strcat(strReturn, str);
        }
        else
        {
            strcpy(strReturn, str);
            // ���ɺ���ַ���
            for(i = m; i < len; i++)
            {
                strReturn[i] = ch;
            }
            strReturn[i] = '\0';
        }
    }
    else
    {
        if(n < 0)
        {   // �ض�����ַ�
            for(i = m; i > m - len; i--)
            {
                strReturn[i - m + len] = str[i];
            }
        }
        else
        {   // �ض��Ҳ��ַ�
            for(i = 0; i < len; i++)
            {
                strReturn[i] = str[i];
            }
            strReturn[i] = '\0';
        }
    }
    return strReturn;
}

void createMenu(char menuTitle[20], char menuItem[][20], int n)     
// ���ɲ˵�
//      menuTitle   �˵�����
//      menuItem    ���˵���
//      n           �˵�������0-n)
{
    int len = strlen(menuTitle);
    int i = 0;
    char itemNo = ' ';

    system("cls");
    cout<<"\n\n\n\n\n";
    cout<<"\t\t|"<<strlmt("-", '-', 21 - len/2)<<menuTitle<<strlmt("-", '-', 21 - len/2)<<"|\n";
    for(i = 0; i <= n; i++)
    {
        if(i < 10)
        {
            itemNo = '0' + i;
        }
        else
        {
            itemNo = 'a' + (i - 10);
        }
        cout<<"\t\t|         "<<itemNo<<". "<<strlmt(menuItem[i], ' ', 30)<<"|\n";
    }
    cout<<"\t\t|------------------------------------------|\n\n";
    cout<<"\t\t\t������ģ����(0-"<<itemNo<<"):";
}

///**********************************************************
///  �� �� ����showMenu                                     *
///  ���������                                             *
///      menuTile��     �˵�����                            *
///      menuItem��     �˵�ѡ������                        *
///      menuExecFun��  �˵�ѡ��ִ�к�������                *
///      n��            �˵�����                            *
///  ����ֵ                                                 *
///      ��                                                 *
///  �������ܣ�                                             *
///      ��ʾ�˵��������û������ģ����                   *
///      ������Ӧģ���ִ�к���                             *
///**********************************************************
void showMenu(char menuTitle[20], char menuItem[][20], void (*menuExecFun[])(), int n)
{
    while(1)
    {                                           // ѭ������ʾ�˵���ֱ���û�ѡ��0Ϊֹ
        char choice = ' ';                      // �û�ѡ���ģ����
        int nChoice = 0;                        // ģ������ֵ
        createMenu(menuTitle, menuItem, n);     // ���ɲ���ʾ�˵�
        cin>>choice;                            // ����ѡ���ܵı��
        nChoice = choice - '0';                 // ��ģ��Ŵ��ַ�ת��Ϊ��ֵ
        if(nChoice >= 0 || nChoice <= n)        // ���ģ��źϷ�
        {
            (menuExecFun[nChoice])();           // ִ�в˵�����
        }
        if(choice == '0')                       // ģ���Ϊ0ʱ
        {
            break;                              // �˳�ѭ��
        }   
    }
}

void showAdminCourseManagerMenu()  
// ��ʾ��ִ�й���Ա�γ���Ϣ����˵�
{
    void (*menuExecFuns[6])();
    menuExecFuns[0] = returnFunc;
    menuExecFuns[1] = courseAppend;             // �����γ̺���
    menuExecFuns[2] = courseQuery;              // �γ̲�ѯ����
    menuExecFuns[3] = courseDelete;             // �γ�ɾ������
    menuExecFuns[4] = courseUpdate;             // �γ��޸ĺ���
    menuExecFuns[5] = courseBrowse;             // �γ��������
    char menuTitle[20] = "�γ���Ϣ����";
    char menuItem[][20] = {"����", "�����γ���Ϣ", "��ѯ�γ���Ϣ", "ɾ���γ���Ϣ", "�޸Ŀγ���Ϣ", "����γ���Ϣ"};
    showMenu(menuTitle, menuItem, menuExecFuns, 5);
}

void returnFunc()
{
}
void courseAppend()                 // �����γ̺���
{
}
void courseQuery()                  // �γ̲�ѯ����
{
}
void courseDelete()                 // �γ�ɾ������
{
}
void courseUpdate()                 // �γ��޸ĺ���
{
}
void courseBrowse()                 // �γ��������
{
}
