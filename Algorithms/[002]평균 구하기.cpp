//과목의 갯수 N개, 최댓값 M, 평균 구하는 법 result

#include <iostream>
using namespace std;

int main()
{
	int N = 0;
	int A[1000] = {};
	cin >> N;

	for (int i = 0; i < N; i++)
	{
		cin >> A[i]; //제한을 두고 값 입력받기
	}

	long sum = 0;  //총합 저장
	long max = 0; //최고값 저장

	for (int i = 0; i < N; i++)
	{
		if (A[i] > max)//최고값을 받는 방법
		{
			max = A[i];
		}
		sum += + A[i]; //총합을 구하는 방법
	}

	double result = sum * 100.0 / max / N;
	cout << result << endl;

	return 0;
}

//과목의 갯수 N개, 최댓값 M, 평균 구하는 법 result

#include <iostream>
using namespace std;

int main()
{
	int N = 0;
	int A[1000] = {};

	cin >> N;

	for (int i = 0; i < N; i++)
	{
		cin >> A[i];
	}

	int max = 0;
	int sum = 0;

	for (int i = 0; i < N; i++)
	{
		if (A[i] > max)
		{
			max = A[i];
		}
		sum += A[i];
	}
	double result = sum * 100.0 / max / N;
	cout << result << endl;

	return 0;
}