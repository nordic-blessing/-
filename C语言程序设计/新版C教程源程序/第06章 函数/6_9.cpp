#include <iostream>                 // ������������ӿ��ļ�
#include "student.h"                // ����ѧ����Ϣͷ�ļ�
using namespace std;                // ���ñ�׼�����ռ�
int main()
{
    int n = 8;
    cout << n << "!=" << fact(n) << endl;
	return 0;
}

//***********************************************************
//* �� �� ����quickSortStudentByWeightAsc                   *
//* �������                                                *
//*     stuList ������ѧ����Ϣ˳���ָ��                    *
//*     low     �±��½�                                    *
//*     high    �±��Ͻ�                                    *
//* ����ֵ                                                  *
//*     ��                                                  *
//* �㷨                                                    *
//*     ʹ�ÿ������򷨣����±�lowΪ��׼�����л���           *
//* �������ܣ�                                              *
//*     �������ص������ѧ����������                        *
//***********************************************************
struct StudentList                          // ѧ����Ϣ˳���ṹ������
{
    StudentInfo data[MAX_SIZE];             // �洢ѧ����Ϣ������
    int length;                             // ѧ������
};
void quickSortStudentByWeightAsc(StudentList *stuList, int low, int high)
{
    int i = low;                            // ǰ��Ԫ�ص��±�
    int j = high;                           // ���Ԫ�ص��±�
    if(low >= high)                         // ��������Ԫ�ز�����1��������
    {
        return;
    }
    stuList->data[0] = stuList->data[low];  // �ݴ��׼��
    while(i < j)                            // ǰ��ָ���Сʱѭ��
    {
        while(i < j && stuList->data[j].weight >= stuList->data[0].weight)
        {                                   // �Ӻ���ǰ�Ƚϣ�������Ԫ�ؽϴ���
            j--;                            // ���ָ��ǰ��
        }
        if(i < j)
        {                                   // ����˽�СԪ������ǰ��
            stuList->data[i] = stuList->data[j];
            i++;
        }
        while(i < j && stuList->data[i].weight <= stuList->data[0].weight)
        {                                   // ��ǰ����Ƚϣ����ǰ��Ԫ�ؽ�С��
            i++;                            // ǰ��ָ����� 
        }
        if(i < j)
        {                                   // ��ǰ�˽ϴ�Ԫ��������
            stuList->data[j] = stuList->data[i];
            j--;
        }
    }
    stuList->data[i] = stuList->data[0];    // ��׼����λ�������±�i��
    if(low < i-1)                           // �ݹ�����Ԫ������
    {
        quickSortStudentByWeightAsc(stuList, low, i-1);
    }
    if(i+1 < high)                          // �ݹ���Ҳ�Ԫ������
    {
        quickSortStudentByWeightAsc(stuList, i+1, high);
    }
}
