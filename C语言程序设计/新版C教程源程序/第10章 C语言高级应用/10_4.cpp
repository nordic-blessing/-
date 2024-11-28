//***************************************************************
//*  ���� ����writeTeacherInfo                                  *
//*  ��Ҫ���ܣ�                                                 *
//*     ��һ���������ʦ��Ϣ                                    *
//*  ���������                                                 *
//*     teacher����ʦ����Ϣ                                     *
//*  ����ֵ��                                                   *
//*     ��                                                      *
//***************************************************************
void writeTeacherInfo(TeacherInfo teacher)
{
    cout<<"  ���ʺţ� ";
    cout<<teacher.no << "\t";    
    cout<<"  ������ ";
    cout<<teacher.name << "\t";        
    cout<<" "<<(teacher.sexy==1?"��":"Ů")<<"  ";    
    cout << endl;
    return;
}

//***************************************************************
//*  ���� ����browseTeacherList                                 *  
//*  ��Ҫ���ܣ�                                                 *
//*     ����̹���Ϣ��                                          *
//*  ���������                                                 *
//*     teacherList��ָ���ʦ��Ϣ���ͷָ��                     *
//*  ����ֵ��                                                   *
//*     ��                                                      *
//***************************************************************
void browseTeacherList(TeacherList teacherList)
{
    if(!teacherList)                        // ��ʦ��Ϣ��ͷ���Ϊ��ֱ�ӷ���
    {
        return;
    }

    TeacherNode *p = teacherList->next;     // ָ��ǰ��ʦ����ָ��
    int n = 0;                              // ��ʦ����

      while(p != NULL)                      // ѭ������ָ�룬��pָ���ʦ������һ�����Ϊֹ
    {
        writeTeacherInfo(p->data);          // �����ǰ��ʦ��Ϣ
        p = p->next;                        // ָ�����
        n++;
    }
    cout<<"  ���н�ʦ "<<n<<" ��"<<endl;
}
