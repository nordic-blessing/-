///**********************************************************
///* �� �� ����searchStudentByName                          *
///  �������                                               *
///      stuAll    ѧ����Ϣָ��                             *
///      n         ѧ������                                 *
///      name      ����ѧ��������                           *
///  ����ֵ                                                 *
///      ��ָ���ʾ���Ҳ��ɹ�                               *
///      �ǿ�ָ��ָ����ҵ���ѧ����Ϣ                       *
///  �������ܣ�                                             *
///      ������������ѧ����Ϣ                               *
///  �㷨                                                   *
///      ʹ���۰���ҷ����ң�Ҫ��stuAll�Ѱ�����������       *
///**********************************************************
StudentInfo *searchStudentByName(StudentInfo  *stuAll, int n, char name[])
{
    int low = 1;                    // �������½�
    int high = n;                   // �������Ͻ�
    int mid = 0;                    // ���Ƚ�Ԫ��
    while(low <= high)
    {
        mid = (low + high) / 2;
        if(strcmp(*(stuAll + mid).name, name) == 0)
        {
            return stuAll + mid;    //���ҳɹ������ظ�ѧ��ָ��
        }
        else if(strcmp(*(stuAll + mid).name, name) > 0)
        {
            high = mid - 1;         // ���������������
        }
        else
        {
            low = mid + 1;          // ���������Ұ�����
        }
    }
    return 0;                       // ���Ҳ��ɹ������ؿ�ָ��
}
