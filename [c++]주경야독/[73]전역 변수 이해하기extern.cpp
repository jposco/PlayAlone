#include <iostream>

using namespace std;

extern int g_number = 100;
//extern 키워드를 이용해 전역 변수를 선언
//어느 곳에서 접근하여 사용할 수 있는 변수
//쓰면 안된다 정도로 기억

int Func1()
{ 
	return g_number++;
}

int Func2()
{
	return g_number++;
}

int main()
{
	int number = g_number++;

	cout << "main number : " << number << endl;
	cout << "Func1 number : " << Func1() << endl;
	cout << "Func2 number : " << Func2() << endl;
	//100, 101, 102 출력
	return 0;
}