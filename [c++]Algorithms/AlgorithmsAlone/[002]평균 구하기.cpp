#include <iostream>
using namespace std;

int main()
{
	//
	int N = 0;
	int A[1000];
	cin >> N;

	for (int i = 0; i < N; i++)
	{
		cin >> A[i]; //������ �ΰ� �� �Է¹ޱ�
	}

	long sum = 0;  //���� ����
	long max = 0; //�ְ� ����

	for (int i = 0; i < N; i++)
	{
		if (A[i] > max)//�ְ��� �޴� ���
		{
			max = A[i];
		}
		sum += + A[i]; //������ ���ϴ� ���
	}

	double result = sum * 100.0 / max / N;
	cout << result << endl;
}