#include <iostream>
using namespace std;

int main()
{
	int correct[7] = { 7,10, 22, 25, 34, 40, 27 };
	int user[7];

	cout << " -----------------------------------------------" << endl;
	cout << "[  �ζ� 1059ȸ�� (2023.03.18) ��÷��ȣ Ȯ���ϱ� ]" << endl;
	cout << "[  ������ ���� ��ȣ 7�ڸ��� �Է����ּ���.       ]" << endl;
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
		cout << "���ϵ帳�ϴ�. 7�� ��ȣ ��ġ!!!!" << endl;
		cout << "1� ��÷ �Ǽ̽��ϴ�!!!!!!!!!!" << endl;;
	}
	else if (count == 6)
	{
		cout << "���ϵ帳�ϴ�. 6�� ��ȣ ��ġ!!!!" << endl;
		cout << "2� ��÷ �Ǽ̽��ϴ�.!!!!!!!!!!" << endl;;
	}
	else if (count == 5)
	{
		cout << "���ϵ帳�ϴ�. 5�� ��ȣ ��ġ!!!!" << endl;
		cout << "3� ��÷ �Ǽ̽��ϴ�.!!!!!!!!!!" << endl;;
	}
	else if (count == 4)
	{
		cout << "���ϵ帳�ϴ�. 4�� ��ȣ ��ġ!!!!" << endl;
		cout << "4� ��÷ �Ǽ̽��ϴ�.!!!!!!!!!!" << endl;;
	}
	else if (count == 3)
	{
		cout << "���ϵ帳�ϴ�. 3�� ��ȣ ��ġ!!!!" << endl;
		cout << "5� ��÷ �Ǽ̽��ϴ�.!!!!!!!!!!" << endl;;
	}
	else
	{
		cout << "�ƽ����ϴ�.. ��÷�Դϴ�." << endl;
	}
}