///**********************************************************
///  函 数 名：sortStudentByHeightAsc                       *
///  输入参数                                               *
///      stuAll     学生信息指针                            *
///      n          学生总数                                *
///  返回值                                                 *
///      无                                                 *
///  函数功能：                                             *
///      使用简单选择排序法对学生信息表按学生身高递增排序   *
///**********************************************************
void sortStudentByHeightAsc(StudentInfo *stuAll, int num) 
{
    StudentInfo *stuEnd = stuAll + num - 1; // 尾指针，指向最后一名学生
    for(; stuAll < stuEnd; stuAll++)
     // 每次循环从待排序区中选出身高最小者，交换到stuAll处，stuAll再指向待排序区第一位
    {
        StudentInfo *stuMin, *p, stu; 
        stuMin = stuAll;                    // 待排序区中身高最小者，初始指向第一人
        for(p = stuAll + 1; p <= stuEnd; p++)
        {                                   // 依次访问待排序区中学生信息
            if(stuMin->height > p->height)  // 当前学生的身高较小
            {
                stuMin = p;                 // 修改最小身高指向
            }
        }
        if(stuMin != stuAll)                // 如果第一人不是最小身高，则交换
        {
            stu = *stuMin;
            *stuMin = *stuAll;
            *stuAll = stu;
        }
    }
}
