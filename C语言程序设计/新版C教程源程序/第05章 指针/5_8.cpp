//***************************************************************
//*  程 序 名：5_8.cpp                                          *
//*  主要功能：                                                 *
//*     采用冒泡法按身高对学生信息进行排序                      *
//***************************************************************
#include <iostream>                             // 宏包含预编译命令
#include "student.h"                            // 包含学生信息头文件
using namespace std;                            // 引用标准命名空间
int main()                                      //主函数
{
    const int STU_NUM = 20;                     // 学生人数
    StudentInfo stu[STU_NUM+1];                 // 定义结构数组stu，用于存储同学信息，
                                                // 下标i处存储第i位同学的信息，stu[0]不使用
    StudentInfo *p_stuInfo = 0;                 // 指向学生信息的指针，初始化为0
    int i = 0, j = 0;                           // 循环变量
    int changed = 0;                            // 交换标志，为0表示本遍排序中未进行交换
    p_stuInfo = stu+1;                          //p_stuInfo指向stu[1]
    for(; p_stuInfo <= stu+STU_NUM; p_stuInfo++)
    {		
        *p_stuInfo = readStudent();             // 输入当前学生信息
    }
    p_stuInfo = stu;                            //p_stuInfo指向结构数组的开始
    // 按身高从低到高对这n位同学排序
    for(i =1; i < STU_NUM; i++)                 // n位同学，需扫描n-1遍
    {
        changed = 0;                            // 置交换标志为0，表示未交换
        for(j=1; j <= STU_NUM-i; j++)           // 每遍比较n-i次
        {
            if((p_stuInfo[j].height) > (p_stuInfo[j+1].height)) 
            {                                   // 以stu[0]为临时变量交换stu[j]和stu[j+1]
                stu[0] = p_stuInfo[j];
                p_stuInfo[j] = p_stuInfo[j+1];
                p_stuInfo[j+1] = stu[0];
                changed = 1;	                // 置交换标志为1
            }
        }
        if(changed == 0)                        // 如果本遍排序中未交换，则退出循环
        {
            break;
        }
	}
    cout << endl << "输入的学生信息为（按身高升序排列）：" << endl;

    for(p_stuInfo++; p_stuInfo <= stu+STU_NUM; p_stuInfo++)
	{  
        writeStudent(*p_stuInfo);               // 依次输出个人信息
    }
    return 0;
}                                               // 主函数结束
