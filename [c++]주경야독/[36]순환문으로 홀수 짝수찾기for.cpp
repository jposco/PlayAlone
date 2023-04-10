#include <iostream>

using namespace std;

int main()
{
	cout << "[036]순환문으로 홀수, 짝수 찾기(for)"<<endl;
	int data[10] = { 5, 19, 76, 3, 10, 67, 53, 86, 13, 52 };

	for (int i = 0; i < 10; i++)
	{
		if (data[i] % 2 == 0)
			cout << data[i] << "는 짝수입니다. " << endl;
		else
			cout << data[i] << "는 홀수입니다. " << endl;
	}
	return 0;
}