//�� N���� �־����� �� i��° ������ n��° �������� ���� ���ϴ� ���α׷��� �ۼ��Ͻÿ�.
#include <iostream>
using namespace std;

int main()
{
	int N = 0; //���� � �Է��Ұ���
	int Q = 0; //������ ������ �����
	cin >> N >> Q;

	int S[100] = {};
	int A = 0;
	for (int i = 1; i <= N; i++) //���Ⱑ �߿��ϴ�.
	{
		cin >> A;
		S[i] = S[i - 1] + A; //�� �迭 ����
	}
	int I, J; // I < J
	int result[100];
	for (int i = 0; i < Q; i++)
	{
		cin >> I >> J;
		result[i] = S[J] - S[I - 1]; //���� �� ����
	}
	for (int i=0;i<Q;i++)
		cout << result[i];
	return 0;
}