///**********************************************************
///* 函 数 名：searchStudentByName                          *
///  输入参数                                               *
///      stuAll    学生信息指针                             *
///      n         学生总数                                 *
///      name      待查学生的姓名                           *
///  返回值                                                 *
///      空指针表示查找不成功                               *
///      非空指针指向查找到的学生信息                       *
///  函数功能：                                             *
///      根据姓名查找学生信息                               *
///  算法                                                   *
///      使用折半查找法查找，要求stuAll已按递增序排序       *
///**********************************************************
StudentInfo *searchStudentByName(StudentInfo  *stuAll, int n, char name[])
{
    int low = 1;                    // 待查找下界
    int high = n;                   // 待查找上界
    int mid = 0;                    // 待比较元素
    while(low <= high)
    {
        mid = (low + high) / 2;
        if(strcmp(*(stuAll + mid).name, name) == 0)
        {
            return stuAll + mid;    //查找成功，返回该学生指针
        }
        else if(strcmp(*(stuAll + mid).name, name) > 0)
        {
            high = mid - 1;         // 继续查找左半区间
        }
        else
        {
            low = mid + 1;          // 继续查找右半区间
        }
    }
    return 0;                       // 查找不成功，返回空指针
}
