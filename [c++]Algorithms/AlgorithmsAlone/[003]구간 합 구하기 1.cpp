//수 N개가 주어졌을 때 i번째 수에서 n번째 수까지의 합을 구하는 프로그램을 작성하시오.
#include <iostream>
using namespace std;

int main()
{
	int N = 0; //숫자 몇개 입력할건지
	int Q = 0; //구간합 질문이 몇개인지
	cin >> N >> Q;

	int S[100] = {};
	int A = 0;
	for (int i = 1; i <= N; i++) //여기가 중요하다.
	{
		cin >> A;
		S[i] = S[i - 1] + A; //합 배열 공식
	}
	int I, J; // I < J
	int result[100];
	for (int i = 0; i < Q; i++)
	{
		cin >> I >> J;
		result[i] = S[J] - S[I - 1]; //구간 합 공식
	}
	for (int i=0;i<Q;i++)
		cout << result[i];
	return 0;
}