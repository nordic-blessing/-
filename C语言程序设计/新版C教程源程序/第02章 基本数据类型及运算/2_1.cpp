#include  <iostream>
using namespace std;                            // 引用标准命名空间

int main()
{
    const double USUAL_TEST_SCORE_RATIO = 0.3;  //常量，平时成绩占总成绩的比率：30%
    const double EXPERIMENT_SCORE_RATIO = 0.2;  //常量，实验成绩占总成绩的比率：20%
    const double FINAL_EXAM_SCORE_RATIO = 0.5;  //常量，期末成绩占总成绩的比率：50%
    int studentID;                              //变量，存放学生的学号
    double usualTestScore;                      //变量，存放课程的平时成绩
    double experimentScore;                     //变量，存放课程的实验成绩
    double finalExamScore;                      //变量，存放课程的期末成绩
    double termScore;                           //变量，存放课程的学期总成绩
    printf("please input studentID:");          //提示输入学生学号
    scanf("%d",&studentID);                     //从键盘输入学号，存入studentID变量里
    printf("\nC Programming Language\n");       //提示课程是《C语言程序设计》
    printf("\nplease input the usual test score of the couse:");    //提示输入课程平时成绩
    scanf("%lf",&usualTestScore);               //3e输入平时成绩，存入usualTestScore变量
    printf("\nplease input the experiment score of the couse:");    //提示输入课程实验成绩
    scanf("%lf",&experimentScore);              //输入实验成绩，存usualTestScore变量
    cout<<'\n'<<"please input the final exam score of the couse:";  //又一种输出提示的方法
    cin>>finalExamScore;                        //又一种输入数据，并存入变量的方法
    termScore = usualTestScore * USUAL_TEST_SCORE_RATIO 
                + experimentScore * EXPERIMENT_SCORE_RATIO 
                + finalExamScore*FINAL_EXAM_SCORE_RATIO;            //计算总成绩
    cout<<"Student ID is "<<studentID<<endl;    //输出显示学号
    cout<<"C Programming Language"<<endl;       //输出显示课程
    cout<<"Term Score is "<<termScore <<endl;   //输出显示该门课程总成绩
    return 0;
}
