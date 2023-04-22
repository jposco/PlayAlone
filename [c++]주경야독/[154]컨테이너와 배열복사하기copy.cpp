#include <iostream>
#include <vector>

using namespace std;

int main()
{
	vector<int> number1({ 1,2,3,4,5 });
	vector<int> number2({ 0, 0 });

	copy(number1.begin(), number1.end(), back_inserter(number2));
	//number1�� ó����ġ�� ��������ġ�� �����Ѵ�.
	//�׸��� ����° ���ڷ� number2�� �������� �ǹ��ϴ� back_inserter �Լ��� ȣ���Ѵ�.
	//copy�Լ��� ���� number1�� ��� �����Ͱ� number2 ����ġ���� ����ȴ�.

	for (auto i : number2)
		cout << i << " ";
	//0, 0, 1, 2, 3, 4, 5 ���
	cout << endl;
	 
	double number3[5] = { 1.2,3.4,5.6,7.8,9.9 };
	double number4[5];

	copy(begin(number3), end(number4), begin(number4));
	//�ѹ�3 ù������ �������� �ѹ� 4�� ù��°�� �����Ѵ�.
	for (auto i : number4)
		cout << i << endl;
	//1.2, 3.4, 5.6, 7.8, 9.9 ���

	return 0;
} 