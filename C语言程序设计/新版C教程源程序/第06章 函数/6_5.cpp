///**********************************************************
///  函 数 名：sortStudentByHeightAsc                       *
///  输入参数                                               *
///      stuAll     学生信息数组                            *
///      n          学生总数                                *
///  返回值                                                 *
///      无                                                 *
///  函数功能：                                             *
///      使用简单选择排序法对学生信息表按学生身高递增排序   *
///**********************************************************
void sortStudentByHeightAsc(StudentInfo  stuAll[], int n) 
{
    int i = 0;                                          // 循环的趟数
    int j = 0;                                          // 当前要比较的元素下标
    for(i = 1; i < n; i++)
    // 从待排序区i..n中选出身高最小者，交换到下标i处，
    // 下标为0的元素作为中间变量用于数据交换
    {
        int minIndex = i;                               // 最小元素的下标
        for(j = i+1; j <= n; j++)
        {
            if(stuAll[j].height < stuAll [minIndex].height)
            {
                minIndex = j;                           // 修改最小元素下标
            }
        }
        if(minIndex!=i)                                 // 如果最小元素下标不是i，则交换
        {
            stuAll[0] = stuAll[i];
            stuAll[i] = stuAll[minIndex];
            stuAll[minIndex] = stuAll[0];
        }
    }
}
