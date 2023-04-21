#include <iostream>
#include <vector>

using namespace std;

int main()
{
	vector<int> number1({ 1,2,3,4,5 });
	vector<int> number2({ 0, 0 });

	copy(number1.begin(), number1.end(), back_inserter(number2));
	//number1의 처음위치와 마지막위치를 전달한다.
	//그리고 세번째 인자로 number2의 마지막을 의미하는 back_inserter 함수도 호출한다.
	//copy함수를 통해 number1의 모든 데이터가 number2 끝위치부터 복사된다.

	for (auto i : number2)
		cout << i << " ";
	//0, 0, 1, 2, 3, 4, 5 출력
	cout << endl;

	double number3[5] = { 1.2,3.4,5.6,7.8,9.9 };
	double number4[5];

	copy(begin(number3), end(number4), begin(number4));
	//넘버3 첫번쨰와 마지막을 넘버 4의 첫번째에 삽입한다.
	for (auto i : number4)
		cout << i << endl;
	//1.2, 3.4, 5.6, 7.8, 9.9 출력

	return 0;
}