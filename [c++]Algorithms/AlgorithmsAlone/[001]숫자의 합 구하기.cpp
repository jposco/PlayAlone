#include <iostream>

using namespace std;

int main()
{
	//숫자합 구하기 예제

	int N = 0;
	string numbers = "";

	cin >> N;
	cin >> numbers;

	int sum = 0;
	for (int i = 0; i < numbers.length(); i++)
	{
		sum += numbers[i] - '0';
	}
	cout << sum << endl;
}


//N개의 숫자가 공백 없이 쓰여 있다. 이 숫자를 모두 합해 출력하는 프로그램을 작성하라.
#include <iostream>
using namespace std;

int main()
{
	int N = 0;
	string numbers = "";

	cin >> N;
	cin >> numbers;

	int sum = 0;
	for (int i = 0; i < numbers.length(); i++)
	{
		sum += numbers[i]-'0';
	}
	
	cout << sum << endl;
}