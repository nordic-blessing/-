#include  <iostream>
using namespace std;                            // ���ñ�׼�����ռ�

int main()
{
    const double USUAL_TEST_SCORE_RATIO = 0.3;  //������ƽʱ�ɼ�ռ�ܳɼ��ı��ʣ�30%
    const double EXPERIMENT_SCORE_RATIO = 0.2;  //������ʵ��ɼ�ռ�ܳɼ��ı��ʣ�20%
    const double FINAL_EXAM_SCORE_RATIO = 0.5;  //��������ĩ�ɼ�ռ�ܳɼ��ı��ʣ�50%
    int studentID;                              //���������ѧ����ѧ��
    double usualTestScore;                      //��������ſγ̵�ƽʱ�ɼ�
    double experimentScore;                     //��������ſγ̵�ʵ��ɼ�
    double finalExamScore;                      //��������ſγ̵���ĩ�ɼ�
    double termScore;                           //��������ſγ̵�ѧ���ܳɼ�
    printf("please input studentID:");          //��ʾ����ѧ��ѧ��
    scanf("%d",&studentID);                     //�Ӽ�������ѧ�ţ�����studentID������
    printf("\nC Programming Language\n");       //��ʾ�γ��ǡ�C���Գ�����ơ�
    printf("\nplease input the usual test score of the couse:");    //��ʾ����γ�ƽʱ�ɼ�
    scanf("%lf",&usualTestScore);               //3e����ƽʱ�ɼ�������usualTestScore����
    printf("\nplease input the experiment score of the couse:");    //��ʾ����γ�ʵ��ɼ�
    scanf("%lf",&experimentScore);              //����ʵ��ɼ�����usualTestScore����
    cout<<'\n'<<"please input the final exam score of the couse:";  //��һ�������ʾ�ķ���
    cin>>finalExamScore;                        //��һ���������ݣ�����������ķ���
    termScore = usualTestScore * USUAL_TEST_SCORE_RATIO 
                + experimentScore * EXPERIMENT_SCORE_RATIO 
                + finalExamScore*FINAL_EXAM_SCORE_RATIO;            //�����ܳɼ�
    cout<<"Student ID is "<<studentID<<endl;    //�����ʾѧ��
    cout<<"C Programming Language"<<endl;       //�����ʾ�γ�
    cout<<"Term Score is "<<termScore <<endl;   //�����ʾ���ſγ��ܳɼ�
    return 0;
}
