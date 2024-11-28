///**********************************************************
///  函 数 名：searchStudentByNo                            *
///  输入参数                                               *
///      stuList    学生信息表                              *
///      no         待查学生的学号                          *
///  返回值                                                 *
///      整型       为0表示查找不成功                       *
///                 大于0为查找到的学生的下标               *
///  函数功能：                                             *
///      根据学号查找学生信息                               *
///  算法                                                   *
///      使用顺序查找法查找，在下标0处设置监视哨            *
///**********************************************************
struct  StudentList                                     // 学生信息表结构体类型
{
    StudentInfo  data[MAX_SIZE];                        // 存储学生信息的数组
    int length;                                         // 学生人数
};
int  searchStudentByNo(StudentList  stuList, char no[])
{
    int n = stuList.length;                             // 表长
    int i = 0;                                          // 待查找下标
    strcpy(stuList.data[0].no, no);                     // 设置监视哨
    for(i=n; strcmp(stuList.data[i].no, no) != 0; i--); // 顺序查找
    return i;                                           // 返回查找结果
}
