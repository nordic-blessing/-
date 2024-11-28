//***************************************************************
//*  ���� ����insertTeacherInfo                                 *
//*  ��Ҫ���ܣ�                                                 *
//*     ���̹��Ų���̹���Ϣ������Ľ̹���Ϣ���У�              *
//*     ���������Ѱ��̹��Ŵ�С���ӵ�                            *
//*  ���������                                                 *
//*     teacherList��ָ���ʦ��Ϣ���ͷָ��                     *
//*     teacher����ʦ����Ϣ                                     *
//*  ����ֵ��                                                   *
//*     ָ���ʦ��Ϣ���ͷָ��                                  *
//***************************************************************
TeacherList insertTeacherInfo(TeacherList teacherList, TeacherInfo teacher)
{
    TeacherList pNew = NULL;                // ָ�������ɽ���ָ��
    TeacherNode *p = teacherList;           // ָ��ǰ��ʦ����ǰ������ָ��
    TeacherNode *q = NULL                   // ָ��ǰ��ʦ����ָ��
    pNew = new TeacherNode;                 // �����½��
    pNew->data = teacher;
    pNew->next = NULL;
    if(!teacherList)                        // ��ʦ��Ϣ��ͷָ��Ϊ��
    {
        teacherList = initTeacherList();    // ����һ���յĽ�ʦ��Ϣ��ֻ��ͷ��㣩
    }
    q = teacherList->next;                  // ָ���һ�����; 
    while(q)                                // Ѱ�Ҳ���λ��
    {
        if(strcmp(q->data.no, pNew->data.no) > 0)
        {
            break;
        }
        else
        {
            p = q;                          // pָ�����
            q = q->next;                    // qָ�����
        }
    }
    pNew->next = q;                         // �½��ĺ��ָ��ָ��q
    p->next = pNew;                         // ǰ�����p�ĺ��ָ���½��
    return teacherList;
}
