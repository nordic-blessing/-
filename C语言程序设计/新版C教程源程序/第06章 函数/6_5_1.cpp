///**********************************************************
///  �� �� ����sortStudentByHeightAsc                       *
///  �������                                               *
///      stuAll     ѧ����Ϣָ��                            *
///      n          ѧ������                                *
///  ����ֵ                                                 *
///      ��                                                 *
///  �������ܣ�                                             *
///      ʹ�ü�ѡ�����򷨶�ѧ����Ϣ��ѧ����ߵ�������   *
///**********************************************************
void sortStudentByHeightAsc(StudentInfo *stuAll, int num) 
{
    StudentInfo *stuEnd = stuAll + num - 1; // βָ�룬ָ�����һ��ѧ��
    for(; stuAll < stuEnd; stuAll++)
     // ÿ��ѭ���Ӵ���������ѡ�������С�ߣ�������stuAll����stuAll��ָ�����������һλ
    {
        StudentInfo *stuMin, *p, stu; 
        stuMin = stuAll;                    // ���������������С�ߣ���ʼָ���һ��
        for(p = stuAll + 1; p <= stuEnd; p++)
        {                                   // ���η��ʴ���������ѧ����Ϣ
            if(stuMin->height > p->height)  // ��ǰѧ������߽�С
            {
                stuMin = p;                 // �޸���С���ָ��
            }
        }
        if(stuMin != stuAll)                // �����һ�˲�����С��ߣ��򽻻�
        {
            stu = *stuMin;
            *stuMin = *stuAll;
            *stuAll = stu;
        }
    }
}
