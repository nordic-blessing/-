//***************************************************************
//*  程 序 名：10_2.cpp                                         *
//*  主要功能：                                                 *
//*     首先给选手的编号和选手的得分动态分配存储空间            *
//*     然后，根据评分规则将选手的最好得分算出并得到比赛名次    *
//***************************************************************
#include <iostream>                 // 包含输入输出接口文件
using namespace std;                // 引用标准命名空间

int main()
{
    int n = 0, m = 0, t, *p1 = NULL;
    float tt,*p2 = NULL,*p3 = NULL;
    cout << "请输入参赛选手人数和评委人数: " ;
    cin >> n >> m;
    p1 = new int[n];                // 动态定义数组，存放选手编号
    p3 = new float[n];              // 动态定义数组，存放选手最后得分
    if(!p1 || !p3)
    {
        cout << "动态内存分配失败！" << endl;
        return 1;
    }
    for(int ii = 0; ii < n; ii++)
    {
        p2 = new float[m];          // 动态定义数组,存放该选手的每个得分
        if(!p2)
        {
            cout << "动态内存分配失败！" << endl;
            return 0;
        }
        cout << "请输入参赛选手编号: " ;
        cin >> *(p1+ii);            // 输入选手编号
        cout << "请输入每位评委的打分: " ;
        for(int j = 0; j < m; j++)  // 输入每位评委打分
        {
            cin >> *(p2+j);
        }                
        for(int i = 0; i < m-1; i++)// 对评委打分排序
        {
            for(int j = i+1; j < m; j++)
            {
                if(p2[i] < p2[j])
                {
                    tt=p2[i];
                    p2[i]=p2[j];
                    p2[j]=tt;
                }
            }
        }
        float sum = 0;
        for(int k = 2; k < m-2; k++)
        {
            sum = sum + p2[k];
        }
        p3[ii] = sum / (m-4);       // 去掉1个最高分和1个最低分后取平均分
        cout << "第" << ii+1 << "号选手得分：" << p3[ii] << endl;
        delete[] p2;                // 释放存放评委打分所占用的存储单元
    }
    for(int i = 0; i < n-1; i++)    // 对每位选手最后得分排序
    {
        for(int j = i+1; j < n; j++)
        {
            if(p3[i] < p3[j])
            {
                tt = p3[i];  p3[i] = p3[j];  p3[j] = tt;
                t = p1[i];   p1[i] = p1[j];  p1[j] = t;
            }
        }
    }
    cout << "------------ 决赛最后成绩 ------------\n" << endl;
    cout << "名次\t\t编号\t\t成绩\n";
    for(int i = 0; i < n; i++)
        cout << i+1 << "\t\t" << p1[i] << "\t\t" << p3[i] << endl;
    cout << "--------------------------------------" << endl;
    delete[] p1;                    // 释放存放选手编号所占用的存储单元
    delete[] p3;                    // 释放存放选手成绩所占用的存储单元
    return 0;
}
