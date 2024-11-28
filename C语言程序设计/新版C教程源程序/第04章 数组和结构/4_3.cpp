//***************************************************************
//*  程 序 名：4_3.cpp                                          *
//*  主要功能：                                                 * 
//*     使用折半查找法在已排好序的成绩数组中查找学生成绩        *
//*     查找成功输出下标，查找不成功输出0                       *
//***************************************************************

#include <iostream>                 // 包含输入输出接口文件
using namespace std;                // 引用标准命名空间
int main()                          // 主函数
{
    const int n = 10;               // 使用常1变量定义学生人数
    int score[n + 1] = {0, 80, 82, 84, 86, 88, 90, 92, 94, 96, 98};                   
                                    // 定义成绩数组，有n+1个整型元素，其中下标0处未存放学生成绩
    int low = 1;                    // 待查找区间的下界下标
    int high = n;                   // 待查找区间的上界下标
    int mid = 0;                    // 中间元素下标
    int x;                          // 等查找的学生成绩

    cout<<"请输入待查找的学生成绩：";
    cin>>x;

    while(low <= high)              // 只有待查找区间不为空，就循环
    {
        mid = (low + high) / 2;     // 计算中间元素下标
        if(score[mid] == x)         // 中间元素与待查找元素相等，查找成功
        {
            break;                  // 退出循环
        }
        else if(score[mid] > x)     // 中间元素较大，继续查找前半区间
        {
            high = mid - 1;         // 修改待查找区间上界
        }
        else                        // 中间元素较小，继续查找后半区间
        {
            low = mid + 1;          // 修改待查找区间下界
        }
    }

    if(low <= high)                 // 待查找区间不为空，查找成功
    {
        cout<<"查找成功，待查找成绩是第 "<<mid<<" 位同学的成绩"<<endl;
    }
    else                            // 待查找区间为空，查找不成功
    {
        cout<<"未查找到该成绩！"<<endl;
    }

    return 0;
}
