///**********************************************************
///  �� �� ����6_1.cpp                                      *
///  ��Ҫ���ܣ�                                             *
///     ��ʾ����ѡ����ʾ��ͬ���û���¼����                  *
///**********************************************************
#include  <iostream>
using namespace std;                            // ���ñ�׼�����ռ�
struct  StudentPick                     // ѧ��ѡ�νṹ������
{
    int num;                            // ѧ��ѡ�μ�¼���
    char teacherNo[20];                 // ��ʦ���
    char courseNo[20];                  // �γ̺�
    int lessonNum;                      // �����
    char studentNo[20];                 // ѧ��
    double peacetimeScore;              // ƽʱ�ɼ�
    double experimentScore;             // ʵ��ɼ�
    double finalExamScore;              // ���տ��Գɼ�
    double termScore;                   // ѧ�ڳɼ�
};
void  updateScore(struct  StudentPick *pick);   // �����޸�ѧ���ɼ�����
int main()
{
    return 0;
}

///**********************************************************
///  �� �� ����updateScore                                  *
///  ���������                                             *
///      pick��ѧ��ѡ�νṹ��                               *
///  ����ֵ                                                 *
///      ��                                                 *
///  �������ܣ�                                             *
///      �޸ĸ�ѡ�νṹ���е�ѧ���ɼ�                       *
///**********************************************************
void  updateScore(StudentPick *pick)
{
    do
    {
        cout<<"ƽʱ�ɼ�("<<pick->peacetimeScore<<")��\t";
        cin>>pick->peacetimeScore;
        if(pick->peacetimeScore < 0)
        {
            cout<<"ƽʱ�ɼ�����Ϊ����"<<endl;
        }
    }while(pick->peacetimeScore < 0);
    do
    {
        cout<<"ʵ��ɼ�("<<pick->experimentScore<<")��\t";
        cin>>pick->experimentScore;
        if(pick->experimentScore < 0)
        {
            cout<<"ʵ��ɼ�����Ϊ����"<<endl;
        }
    }while(pick->experimentScore < 0);
    do
    {
        cout<<"���ճɼ�("<<pick->finalExamScore<<")��\t";
        cin>>pick->finalExamScore;
        if(pick->finalExamScore < 0)
        {
            cout<<"���ճɼ�����Ϊ����"<<endl;
        }
    }while(pick->finalExamScore < 0);
    do
    {
        cout<<"ѧ�ڳɼ�("<<pick->termScore<<")��\t";
        cin>>pick->termScore;
        if(pick->termScore < 0)
        {
            cout<<"ѧ�ڳɼ�����Ϊ����"<<endl;
        }
    }while(pick->termScore < 0);
}
