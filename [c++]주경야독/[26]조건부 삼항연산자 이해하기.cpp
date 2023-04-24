#include <iostream>

using namespace std;

int main()
{
	int x = 1;
	int y = 2;
	int z = 0;

	z = x > y ? x : y;
	//삼항연산자 이해하기 참일 경우 전자 : 펄스일경우 후자

	cout << "x와 y 중 더 큰 값은 : " << z << endl;

	return 0;
}