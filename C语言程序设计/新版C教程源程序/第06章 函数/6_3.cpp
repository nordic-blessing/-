///**********************************************************
///  �� �� ����searchStudentByNo                            *
///  �������                                               *
///      stuList    ѧ����Ϣ��                              *
///      no         ����ѧ����ѧ��                          *
///  ����ֵ                                                 *
///      ����       Ϊ0��ʾ���Ҳ��ɹ�                       *
///                 ����0Ϊ���ҵ���ѧ�����±�               *
///  �������ܣ�                                             *
///      ����ѧ�Ų���ѧ����Ϣ                               *
///  �㷨                                                   *
///      ʹ��˳����ҷ����ң����±�0�����ü�����            *
///**********************************************************
struct  StudentList                                     // ѧ����Ϣ��ṹ������
{
    StudentInfo  data[MAX_SIZE];                        // �洢ѧ����Ϣ������
    int length;                                         // ѧ������
};
int  searchStudentByNo(StudentList  stuList, char no[])
{
    int n = stuList.length;                             // ��
    int i = 0;                                          // �������±�
    strcpy(stuList.data[0].no, no);                     // ���ü�����
    for(i=n; strcmp(stuList.data[i].no, no) != 0; i--); // ˳�����
    return i;                                           // ���ز��ҽ��
}
