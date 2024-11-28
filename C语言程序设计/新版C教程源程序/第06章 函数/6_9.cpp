#include <iostream>                 // 包含输入输出接口文件
#include "student.h"                // 包含学生信息头文件
using namespace std;                // 引用标准命名空间
int main()
{
    int n = 8;
    cout << n << "!=" << fact(n) << endl;
	return 0;
}

//***********************************************************
//* 函 数 名：quickSortStudentByWeightAsc                   *
//* 输入参数                                                *
//*     stuList 待排序学生信息顺序表指针                    *
//*     low     下标下界                                    *
//*     high    下标上界                                    *
//* 返回值                                                  *
//*     无                                                  *
//* 算法                                                    *
//*     使用快速排序法，以下标low为基准数进行划分           *
//* 函数功能：                                              *
//*     按照体重递增序对学生进行排序                        *
//***********************************************************
struct StudentList                          // 学生信息顺序表结构体类型
{
    StudentInfo data[MAX_SIZE];             // 存储学生信息的数组
    int length;                             // 学生人数
};
void quickSortStudentByWeightAsc(StudentList *stuList, int low, int high)
{
    int i = low;                            // 前端元素的下标
    int j = high;                           // 后端元素的下标
    if(low >= high)                         // 待排序区元素不超过1个，返回
    {
        return;
    }
    stuList->data[0] = stuList->data[low];  // 暂存基准数
    while(i < j)                            // 前端指针较小时循环
    {
        while(i < j && stuList->data[j].weight >= stuList->data[0].weight)
        {                                   // 从后往前比较，如果后端元素较大则
            j--;                            // 后端指针前移
        }
        if(i < j)
        {                                   // 将后端较小元素移至前方
            stuList->data[i] = stuList->data[j];
            i++;
        }
        while(i < j && stuList->data[i].weight <= stuList->data[0].weight)
        {                                   // 从前往后比较，如果前端元素较小则
            i++;                            // 前端指针后移 
        }
        if(i < j)
        {                                   // 将前端较大元素移至后方
            stuList->data[j] = stuList->data[i];
            j--;
        }
    }
    stuList->data[i] = stuList->data[0];    // 基准数就位，移至下标i处
    if(low < i-1)                           // 递归对左侧元素排序
    {
        quickSortStudentByWeightAsc(stuList, low, i-1);
    }
    if(i+1 < high)                          // 递归对右侧元素排序
    {
        quickSortStudentByWeightAsc(stuList, i+1, high);
    }
}
