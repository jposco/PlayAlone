#include <iostream>
using namespace std;

int main()
{
	int p = 0; //누적값
	int n = 0; //출력되는 시점의 피보나치 값
	int t = 0; //n값을 p애 전달하기 위한 임시변수

	for (int i = 0; i < 10; i++)
	{
		p = 0;
		n = 1;
		for (int j = 0; j <=i; j++)
		{
			cout << n << " , ";
			t = n;
			n = n + p;
			p = t;
		}
		cout << endl;
	}
}