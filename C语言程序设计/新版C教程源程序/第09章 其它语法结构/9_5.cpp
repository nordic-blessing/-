//***************************************************************
//*  �� �� ����9_5.cpp                                          *
//*  ��Ҫ���ܣ�                                                 * 
//*     ʹ�����ϴ洢ѧ����Ϣ�ͽ�ʦ��Ϣ                          *
//***************************************************************
#include  <iostream> 
using namespace std;
union ClassPost                                     // �ɰ༶��ְ����ɵ���������
{
    int studentClass;                               // ѧ���༶
    char teacherPost[20];                           // ��ʦְ��
};
struct PersonInfo                                   // ��Ա��Ϣ�ṹ����
{
    int num;                                        // ���
    char name[20];                                  // ����
    char sexy[20];                                  // �Ա�
    char job[20];                                   // ְҵ        
    ClassPost classPost;                            // ѧ���༶���ʦְ��
};

int main(){
    PersonInfo personList[] = {{101, "Li", "Female", "Student"},{102, "Wang", "Male", "Teacher"}};
    int i = 0;                                                  // ѭ������
    personList[0].classPost.studentClass = 501;                 // ����ѧ���༶
    strcpy(personList[1].classPost.teacherPost, "professor");   // �����ʦְ��
    
    for(i = 0; i < 2; i++)                                      // �����������Ա��Ϣ
    {
        cout<<personList[i].num<<"\t"<<personList[i].name<<"\t"<<personList[i].sexy<<"\t"<<personList[i].job<<"\t";
        if(strcmp(personList[i].job, "Student") == 0)           // �����ǰ��Ա��ְҵΪѧ��
        {
            cout<<personList[i].classPost.studentClass<<endl;   // ���ѧ���༶
        }
        else                                                    // �����ǰ��Ա��ְҵΪ��ʦ
        {
            cout<<personList[i].classPost.teacherPost<<endl;    // �����ʦְ��
        }
    }

    return 0;
}
