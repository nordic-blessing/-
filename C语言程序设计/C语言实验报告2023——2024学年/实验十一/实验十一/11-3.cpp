#include<iostream>
using namespace std;
struct Result {
	double ave;  // ƽ��ֵ
	int max;     // ���ֵ
	int min;     // ��Сֵ
};

// ͳ�ƺ����������ʮ�������ҳ����ֵ����Сֵ�Լ����ǵ�ƽ��ֵ
Result count()
{
	int num[21];  // �洢����Ķ�ʮ����
	int i, j, max = 0, min = 0;  // max���ڱ������ֵ��min���ڱ�����Сֵ
	double sum = 0, ave = 0;    // sum���ڱ����ۼӺͣ�ave���ڱ���ƽ��ֵ
	for (i = 1; i <= 20; i++)
	{
		cout << "�������" << i << "������";
		cin >> num[i];
	}
	max = num[1], min = num[1], sum = num[1];  // ��ʼ��max��min��sumΪ��һ����
	for (j = 2; j <= 20; j++)
	{
		if (num[j] > max)   // �����ǰ������max�������max
		{
			max = num[j];
		}
		else if (num[j] < min)  // �����ǰ��С��min�������min
		{
			min = num[j];
		}
		else
		{
			continue;
		}
		sum = sum + num[j];  // �ۼ�ÿ������sum��
	}
	ave = sum / 19;  // ����ƽ��ֵ��ע��Ҫ����19������20����Ϊ��һ�����Ѿ�������sum��
	Result res = { ave, max, min };  // ��������ṹ�岢��ֵ
	return res;  // ���ؽ���ṹ��
}

int main()
{
	Result res = count();  // ����ͳ�ƺ�����ȡ���
	cout << "���ֵΪ��" << res.max << endl;  // ������ֵ
	cout << "��СֵΪ��" << res.min << endl;  // �����Сֵ
	cout << "ƽ��ֵΪ��" << res.ave << endl;  // ���ƽ��ֵ
	return 0;
}