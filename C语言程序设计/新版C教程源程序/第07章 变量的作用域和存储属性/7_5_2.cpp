//***************************************************************
//*  程 序 名：7_5_2.cpp                                        *
//*  主要功能：                                                 *
//*     测试外部变量作用域的延伸                                *
//***************************************************************
//引用性声明,将源文件7_6_1.cpp中定义的数组score作用域扩展到本源文件
extern int score[10];
// 引用性声明,将源文件7_6_1.cpp中定义的变量maxScore，minScore作用域扩展到本源文件
extern int maxScore, minScore;
void find_Max_Min()                         //求最大值和最小值函数
{
    int i = 0;                              //数组下标变量
    for(i = 0; i < 10; i++)
    { 
        if(score[i] > maxScore)
        {
            maxScore = score[i];
        }
        if(score[i] < minScore)
        {
            minScore = score[i];
        }
    }
    return;//将程序的执行流程带回到主调函数
}
