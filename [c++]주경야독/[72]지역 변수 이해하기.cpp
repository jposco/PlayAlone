#include <iostream>

using namespace std;

int Temp1(const int arg)
{
	int number = 20;
	//�������� : Ư�� ���������� ��ȿ�� ����

	return number + 1;
} 

int Temp2(const int arg)
{ 
	int number = arg;
	//�������� : Ư�� ���������� ��ȿ�� ����


	return number + 1;
}

int main()
{
	int number = 10;

	int rtn1 = Temp1(number);
	int rtn2 = Temp2(number);

	cout << "main �Լ� number : " << number << endl;
	cout << "Temp �Լ� number : " << rtn1 << endl;
	cout << "Temp �Լ� number : " << rtn2 << endl;
	//10, 21, 11 ���

	return 0;
}