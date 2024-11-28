///**********************************************************
///  �� �� ����sortStudentByHeightAsc                       *
///  �������                                               *
///      stuAll     ѧ����Ϣ����                            *
///      n          ѧ������                                *
///  ����ֵ                                                 *
///      ��                                                 *
///  �������ܣ�                                             *
///      ʹ�ü�ѡ�����򷨶�ѧ����Ϣ��ѧ����ߵ�������   *
///**********************************************************
void sortStudentByHeightAsc(StudentInfo  stuAll[], int n) 
{
    int i = 0;                                          // ѭ��������
    int j = 0;                                          // ��ǰҪ�Ƚϵ�Ԫ���±�
    for(i = 1; i < n; i++)
    // �Ӵ�������i..n��ѡ�������С�ߣ��������±�i����
    // �±�Ϊ0��Ԫ����Ϊ�м�����������ݽ���
    {
        int minIndex = i;                               // ��СԪ�ص��±�
        for(j = i+1; j <= n; j++)
        {
            if(stuAll[j].height < stuAll [minIndex].height)
            {
                minIndex = j;                           // �޸���СԪ���±�
            }
        }
        if(minIndex!=i)                                 // �����СԪ���±겻��i���򽻻�
        {
            stuAll[0] = stuAll[i];
            stuAll[i] = stuAll[minIndex];
            stuAll[minIndex] = stuAll[0];
        }
    }
}
