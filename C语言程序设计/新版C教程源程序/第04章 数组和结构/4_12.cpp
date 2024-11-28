//***************************************************************
//*  程 序 名：4_12.cpp                                         *
//*  主要功能：                                                 *
//*     求矩阵的乘积                                            *
//***************************************************************

#include <iostream>                 // 包含输入输出接口文件
using namespace std;                // 引用标准命名空间 

int main()                          // 主函数
{
    const int N = 10;               // 定义矩阵行、列数的最大值
    int A[N][N] = {0}, B[N][N] = {0}, C[N][N] = {0};
    int i = 0, j = 0, k = 0;        // 循环变量
    int m1 = 0, n1 = 0;             // A矩阵的行、列数
    int m2 = 0, n2 = 0;             // B矩阵的行、列数


    cout<<"请输入A矩阵的行、列数（不超过10）：";
    cin>>m1>>n1;
    if(m1 < 1 || m1 > 10 || n1 < 1 || n1 > 10)
    {
        cout<<"A矩阵维数超界！"<<endl;
        system("pause");            // 等待按任意键后关闭运行窗口
        return -1;
    }
    cout<<"请输入B矩阵的行、列数（不超过10）：";
    cin>>m2>>n2;
    if(m2 < 1 || m2 > 10 || n2 < 1 || n2 > 10)
    {
        cout<<"B矩阵维数超界！"<<endl;
        system("pause");            // 等待按任意键后关闭运行窗口
        return -2;
    }
    if(n1 != m2)
    {
        cout<<"矩阵A、B维数不匹配！"<<endl;
        system("pause");            // 等待按任意键后关闭运行窗口
        return -3;
    }

    cout<<"请输入A矩阵："<<endl;
    for(i = 0; i < m1; i++)
    {
        for(j = 0; j < n1; j++)
        {
            cout<<"A["<<i<<"]["<<j<<"]=";
            cin>>A[i][j];
        }
    }

    cout<<"请输入B矩阵："<<endl;
    for(i = 0; i < m2; i++)
    {
        for(j = 0; j < n2; j++)
        {
            cout<<"B["<<i<<"]["<<j<<"]=";
            cin>>B[i][j];
        }
    }

    cout<<"矩阵A = "<<endl;
    for(i = 0; i < m1; i++)
    {
        for(j = 0; j < n1; j++)
        {
            cout<<"\t"<<A[i][j];
        }
        cout<<endl;
    }

    cout<<"矩阵B = "<<endl;
    for(i = 0; i < m2; i++)
    {
        for(j = 0; j < n2; j++)
        {
            cout<<"\t"<<B[i][j];
        }
        cout<<endl;
    }

    // 计算A、B矩阵的乘积，结果存入C矩阵
    for(i = 0; i < m1; i++)
    {
        for(j = 0; j < n2; j++)
        {
            C[i][j] = 0;
            for(k = 0; k < n1; k++)
            {
                C[i][j] = C[i][j] + A[i][k] * B[k][j];
            }
        }
    }

    cout<<"结果矩阵C = "<<endl;
    for(i = 0; i < m1; i++)
    {
        for(j = 0; j < n2; j++)
        {
            cout<<"\t"<<C[i][j];
        }
        cout<<endl;
    }

    return 0;
}
