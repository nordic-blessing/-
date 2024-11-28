//***************************************************************
//*  ���� ����deleteTeacherInfo                                 *
//*  ��Ҫ���ܣ�                                                 *
//*     �����ʺ�Ϊno�Ľ�ʦ�ӽ�ʦ��Ϣ��teacherList��ɾ��         *
//*  ���������                                                 *
//*     teacherList��ָ���ʦ��Ϣ���ͷָ��                     *
//*     no����ʦ�Ĺ��ʺ�                                        *
//*  ����ֵ��                                                   *
//*     0��ʧ�ܣ�1���ɹ�                                        *
//***************************************************************
int deleteTeacherInfo(TeacherList teacherList, char no[])
{
    if(!teacherList)                            // ��ʦ��Ϣ��ͷ���Ϊ�գ����ش���
    {
        return 0;
    }

    TeacherNode *pre = teacherList;             // ָ��ǰ������ָ��
    TeacherNode *p = pre->next;                 // ָ��ǰ����ָ��
    
    while(p != NULL)                            // ѭ������ָ�룬����ǰ���Ĺ��ʺ���no���Ϊֹ
    {
        if(strcmp(p->data.no, no) == 0)         // ���ҳɹ�
        {
            break;
        }
        pre = p;
        p = p->next;
    }

    if(!p)                                      // ���Ҳ��ɹ�
    {
        return false;
    }
    else                                        // ���ҳɹ�
    {
        pre->next = p->next;                    // ��������ɾ����ǰ���
        delete p;                               // �ͷŵ�ǰ�����ռ�õĿռ�
        return 1;
    }
}
