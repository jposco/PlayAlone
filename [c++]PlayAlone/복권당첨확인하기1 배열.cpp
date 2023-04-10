#include <iostream>
using namespace std;

int main()
{
	int correct[7] = { 7,10, 22, 25, 34, 40, 27 };
	int user[7];

	cout << " -----------------------------------------------" << endl;
	cout << "[  로또 1059회차 (2023.03.18) 당첨번호 확인하기 ]" << endl;
	cout << "[  찍으신 복권 번호 7자리를 입력해주세요.       ]" << endl;
	cout << " -----------------------------------------------" << endl;

	for (int i = 0; i < sizeof(user) / sizeof(user[0]); i++)
	{
		cin >> user[i];
	}

	int count = 0;
	for (int i = 0; i < sizeof(correct) / sizeof(correct[0]); i++)
	{
		for (int j = 0; j < sizeof(correct) / sizeof(correct[0]); j++)
		{
			if (correct[i] == user[j]) {
				count++;
			}
		}

	}
	if (count == 7)
	{
		cout << "축하드립니다. 7개 번호 일치!!!!" << endl;
		cout << "1등에 당첨 되셨습니다!!!!!!!!!!" << endl;;
	}
	else if (count == 6)
	{
		cout << "축하드립니다. 6개 번호 일치!!!!" << endl;
		cout << "2등에 당첨 되셨습니다.!!!!!!!!!!" << endl;;
	}
	else if (count == 5)
	{
		cout << "축하드립니다. 5개 번호 일치!!!!" << endl;
		cout << "3등에 당첨 되셨습니다.!!!!!!!!!!" << endl;;
	}
	else if (count == 4)
	{
		cout << "축하드립니다. 4개 번호 일치!!!!" << endl;
		cout << "4등에 당첨 되셨습니다.!!!!!!!!!!" << endl;;
	}
	else if (count == 3)
	{
		cout << "축하드립니다. 3개 번호 일치!!!!" << endl;
		cout << "5등에 당첨 되셨습니다.!!!!!!!!!!" << endl;;
	}
	else
	{
		cout << "아쉽습니다.. 낙첨입니다." << endl;
	}
}