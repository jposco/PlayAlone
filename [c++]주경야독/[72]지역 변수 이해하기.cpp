#include <iostream>

using namespace std;

int Temp1(const int arg)
{
	int number = 20;
	//지역변수 : 특정 지역에서만 유효한 변수

	return number + 1;
}

int Temp2(const int arg)
{
	int number = arg;
	//지역변수 : 특정 지역에서만 유효한 변수


	return number + 1;
}

int main()
{
	int number = 10;

	int rtn1 = Temp1(number);
	int rtn2 = Temp2(number);

	cout << "main 함수 number : " << number << endl;
	cout << "Temp 함수 number : " << rtn1 << endl;
	cout << "Temp 함수 number : " << rtn2 << endl;
	//10, 21, 11 출력

	return 0;
}