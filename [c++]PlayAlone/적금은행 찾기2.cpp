#include <iostream>
#include <string>
using namespace std;

namespace NH
{
	double deposit_1year(int money)
	{
		double money_d = (double)money;
		return money_d + 0.01 * money_d;
	}
	double deposit_2year(int money)
	{
		double money_d = (double)money;
		return money_d + 0.03 * money_d;
	}
	double deposit_4year(int money)
	{
		double money_d = (double)money;
		return money_d + 0.04 * money_d;
	}
}
namespace KB
{
	double deposit_1year(int money)
	{
		double money_d = (double)money;
		return money_d + 0.01 * money_d;
	}
	double deposit_2year(int money)
	{
		double money_d = (double)money;
		return money_d + 0.02 * money_d;
	}
	double deposit_4year(int money)
	{
		double money_d = (double)money;
		return money_d + 0.05 * money_d;
	}
}
//
int main()
{
	int money;
	string bank;
	int expiration_year;
	cout << " ----------------------------------------------------------" << endl;
	cout << "[ �����(ex.����) ������ ���ݾ��� �Է��ϼ���.            ]" << endl;
	cout << "[ ������� ���⸦ �������� �Է��ϼ���.                 ]" << endl;
	cout << " ----------------------------------------------------------" << endl;
	cout << "ex) �츮 2 2000000 : ";
	cin >> bank >> expiration_year >> money;

	if (bank == "����")
	{
		if (expiration_year <= 1)
		{
			cout << "1�� ���� ��ǰ �����մϴ�." << endl;
			cout.precision(9);
			cout << "���� �� ����ݾ��� : " << NH::deposit_1year(money) << "�� �Դϴ�." << endl;
		}
		else if (expiration_year > 1 && expiration_year < 4)
		{
			cout << "2�� ���� ��ǰ �����մϴ�." << endl;
			cout.precision(9);
			cout << "���� �� ����ݾ��� : " << NH::deposit_2year(money) << "�� �Դϴ�." << endl;
		}
		else
		{
			cout << "4�� ���� ��ǰ �����մϴ�." << endl;
			cout.precision(9);
			cout << "���� �� ����ݾ��� : " << NH::deposit_4year(money) << "�� �Դϴ�." << endl;
		}
	}
	else if (bank == "����")
	{
		if (expiration_year <= 1)
		{
			cout << "1�� ���� ��ǰ �����մϴ�." << endl;
			cout.precision(9);
			cout << "���� �� ����ݾ��� : " << KB::deposit_1year(money) << "�� �Դϴ�." << endl;
		}
		else if (expiration_year > 1 && expiration_year < 4)
		{
			cout << "2�� ���� ��ǰ �����մϴ�." << endl;
			cout.precision(9);
			cout << "���� �� ����ݾ��� : " << KB::deposit_2year(money) << "�� �Դϴ�." << endl;
		}
		else
		{
			cout << "4�� ���� ��ǰ �����մϴ�." << endl;
			cout.precision(9);
			cout << "���� �� ����ݾ��� : " << KB::deposit_4year(money) << "�� �Դϴ�." << endl;
		}
	}
	else
	{
		cout << "������ �߸��Ǿ����ϴ�." << endl;
	}
	return 0;
}

