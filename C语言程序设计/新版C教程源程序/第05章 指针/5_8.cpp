//***************************************************************
//*  �� �� ����5_8.cpp                                          *
//*  ��Ҫ���ܣ�                                                 *
//*     ����ð�ݷ�����߶�ѧ����Ϣ��������                      *
//***************************************************************
#include <iostream>                             // �����Ԥ��������
#include "student.h"                            // ����ѧ����Ϣͷ�ļ�
using namespace std;                            // ���ñ�׼�����ռ�
int main()                                      //������
{
    const int STU_NUM = 20;                     // ѧ������
    StudentInfo stu[STU_NUM+1];                 // ����ṹ����stu�����ڴ洢ͬѧ��Ϣ��
                                                // �±�i���洢��iλͬѧ����Ϣ��stu[0]��ʹ��
    StudentInfo *p_stuInfo = 0;                 // ָ��ѧ����Ϣ��ָ�룬��ʼ��Ϊ0
    int i = 0, j = 0;                           // ѭ������
    int changed = 0;                            // ������־��Ϊ0��ʾ����������δ���н���
    p_stuInfo = stu+1;                          //p_stuInfoָ��stu[1]
    for(; p_stuInfo <= stu+STU_NUM; p_stuInfo++)
    {		
        *p_stuInfo = readStudent();             // ���뵱ǰѧ����Ϣ
    }
    p_stuInfo = stu;                            //p_stuInfoָ��ṹ����Ŀ�ʼ
    // ����ߴӵ͵��߶���nλͬѧ����
    for(i =1; i < STU_NUM; i++)                 // nλͬѧ����ɨ��n-1��
    {
        changed = 0;                            // �ý�����־Ϊ0����ʾδ����
        for(j=1; j <= STU_NUM-i; j++)           // ÿ��Ƚ�n-i��
        {
            if((p_stuInfo[j].height) > (p_stuInfo[j+1].height)) 
            {                                   // ��stu[0]Ϊ��ʱ��������stu[j]��stu[j+1]
                stu[0] = p_stuInfo[j];
                p_stuInfo[j] = p_stuInfo[j+1];
                p_stuInfo[j+1] = stu[0];
                changed = 1;	                // �ý�����־Ϊ1
            }
        }
        if(changed == 0)                        // �������������δ���������˳�ѭ��
        {
            break;
        }
	}
    cout << endl << "�����ѧ����ϢΪ��������������У���" << endl;

    for(p_stuInfo++; p_stuInfo <= stu+STU_NUM; p_stuInfo++)
	{  
        writeStudent(*p_stuInfo);               // �������������Ϣ
    }
    return 0;
}                                               // ����������
