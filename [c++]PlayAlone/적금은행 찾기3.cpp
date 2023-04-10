#include <iostream>
#include <string>
using namespace std;
namespace NH
{
	double deposit_1year(int money)
	{
		int sum = money * 12;
		double money_d = (double)money;
		return money_d + 0.015 * money_d;
	}
	double deposit_2year(int money)
	{
		int sum = money * 24;
		double money_d = (double)money;
		return money_d + 0.02 * money_d;
	}
	double deposit_3year(int money)
	{
		int sum = money * 36;
		double money_d = (double)money;
		return money_d + 0.03 * money_d;
	}
	double deposit_4year(int money)
	{
		int sum = money * 48;
		double money_d = (double)sum;
		return money_d + 0.05 * money_d;
	}
}
namespace KB
{
	double deposit_1year(int money)
	{
		int sum = money * 12;
		double money_d = (double)money;
		return money_d + 0.015 * money_d;
	}
	double deposit_2year(int money)
	{
		int sum = money * 24;
		double money_d = (double)money;
		return money_d + 0.02 * money_d;
	}
	double deposit_3year(int money)
	{
		int sum = money * 36;
		double money_d = (double)money;
		return money_d + 0.03 * money_d;
	}
	double deposit_4year(int money)
	{
		int sum = money * 48;
		double money_d = (double)sum;
		return money_d + 0.05 * money_d;
	}
}
namespace HN
{
	double deposit_1year(int money)
	{
		int sum = money * 12;
		double money_d = (double)sum;
		return money_d + 0.015 * money_d;
	}
	double deposit_2year(int money)
	{
		int sum = money * 24;
		double money_d = (double)sum;
		return money_d + 0.02 * money_d;
	}
	double deposit_3year(int money)
	{
		int sum = money * 36;
		double money_d = (double)sum;
		return money_d + 0.03 * money_d;
	}
	double deposit_4year(int money)
	{
		int sum = money * 48;
		double money_d = (double)sum;
		return money_d + 0.05 * money_d;
	}
}
int main()
{
	int money;
	string bank;
	int expiration_year;
	cout << " ----------------------------------------------------------" << endl;
	cout << "[ ���� ����� ������ ����� ���� ������ݾ� ã�Ƶ帳�ϴ�. ]" << endl;
	cout << "[ ���Ͻô� ���� ����� ���� �Աݾ��� �Է����ּ���  .      ]" << endl;
	cout << " ----------------------------------------------------------" << endl;
	cout << "���Ͻô� ���� ����� �Է����ּ���. (ex.1, 2, 3, 4) : ";
	cin >> expiration_year;
	cout << endl;
	cout << "���� �� �Աݾ��� �Է����ּ���. (ex. 100000) : ";
	cin >> money;
	cout << endl << "----------------------�˻� �� �Դϴ�----------------------" << endl << endl;
	if (expiration_year == 1)
	{
		if (NH::deposit_1year(money) > KB::deposit_1year(money) && NH::deposit_1year(money) > HN::deposit_1year(money)) {
			cout << "1�� ���� ���������� ���� ���� ������ ���������Դϴ�." << endl;
			cout << endl;
			cout << "1�� ���� ���� ��� �ݾ��� : ";
			cout.precision(8);
			cout << NH::deposit_1year(money);
			cout << "�� �Դϴ�." << endl;
			cout << "(��Ȳ�� ���� ���� �� ������ �������� �����ϼ���.)" << endl;
		}
		else if (KB::deposit_1year(money) > NH::deposit_1year(money) && KB::deposit_1year(money) > HN::deposit_1year(money)) {
			cout << "1�� ���� ���������� ���� ���� ������ ���������Դϴ�." << endl;
			cout << endl;
			cout << "1�� ���� ���� ��� �ݾ��� : ";
			cout.precision(8);
			cout << KB::deposit_1year(money);
			cout << "�� �Դϴ�." << endl;
			cout << "(��Ȳ�� ���� ���� �� ������ �������� �����ϼ���.)" << endl;
		}
		else {
			cout << "1�� ���� ���������� ���� ���� ������ �ϳ������Դϴ�." << endl;
			cout << endl;
			cout << "1�� ���� ���� ��� �ݾ��� : ";
			cout.precision(8);
			cout << HN::deposit_1year(money);
			cout << "�� �Դϴ�." << endl;
			cout << "(��Ȳ�� ���� ���� �� ������ �������� �����ϼ���.)" << endl;
		}
	}
	if (expiration_year == 2)
	{
		if (NH::deposit_2year(money) > KB::deposit_2year(money) && NH::deposit_2year(money) > HN::deposit_2year(money)) {
			cout << "2�� ���� ���������� ���� ���� ������ ���������Դϴ�." << endl;
			cout << endl;
			cout << "2�� ���� ���� ��� �ݾ��� : ";
			cout.precision(8);
			cout << NH::deposit_2year(money);
			cout << "�� �Դϴ�." << endl;
			cout << "(��Ȳ�� ���� ���� �� ������ �������� �����ϼ���.)" << endl;
		}
		else if (KB::deposit_2year(money) > NH::deposit_2year(money) && KB::deposit_2year(money) > HN::deposit_2year(money)) {
			cout << "2�� ���� ���������� ���� ���� ������ ���������Դϴ�." << endl;
			cout << endl;
			cout << "2�� ���� ���� ��� �ݾ��� : ";
			cout.precision(8);
			cout << KB::deposit_2year(money);
			cout << "�� �Դϴ�." << endl;
			cout << "(��Ȳ�� ���� ���� �� ������ �������� �����ϼ���.)" << endl;
		}
		else {
			cout << "2�� ���� ���������� ���� ���� ������ �ϳ������Դϴ�." << endl;
			cout << endl;
			cout << "2�� ���� ���� ��� �ݾ��� : ";
			cout.precision(8);
			cout << HN::deposit_2year(money);
			cout << "�� �Դϴ�." << endl;
			cout << "(��Ȳ�� ���� ���� �� ������ �������� �����ϼ���.)" << endl;
		}
	}
	if (expiration_year == 3)
	{
		if (NH::deposit_3year(money) > KB::deposit_3year(money) && NH::deposit_3year(money) > HN::deposit_3year(money)) {
			cout << "3�� ���� ���������� ���� ���� ������ ���������Դϴ�." << endl;
			cout << endl;
			cout << "3�� ���� ���� ��� �ݾ��� : ";
			cout.precision(8);
			cout << NH::deposit_3year(money);
			cout << "�� �Դϴ�." << endl;
			cout << "(��Ȳ�� ���� ���� �� ������ �������� �����ϼ���.)" << endl;
		}
		else if (KB::deposit_3year(money) > NH::deposit_3year(money) && KB::deposit_3year(money) > HN::deposit_3year(money)) {
			cout << "3�� ���� ���������� ���� ���� ������ ���������Դϴ�." << endl;
			cout << endl;
			cout << "3�� ���� ���� ��� �ݾ��� : ";
			cout.precision(8);
			cout << KB::deposit_3year(money);
			cout << "�� �Դϴ�." << endl;
			cout << "(��Ȳ�� ���� ���� �� ������ �������� �����ϼ���.)" << endl;
		}
		else {
			cout << "4�� ���� ���������� ���� ���� ������ �ϳ������Դϴ�." << endl;
			cout << endl;
			cout << "4�� ���� ���� ��� �ݾ��� : ";
			cout.precision(8);
			cout << HN::deposit_3year(money);
			cout << "�� �Դϴ�." << endl;
			cout << "(��Ȳ�� ���� ���� �� ������ �������� �����ϼ���.)" << endl;
		}
	}
	if (expiration_year == 4)
	{
		if (NH::deposit_4year(money) > KB::deposit_4year(money) && NH::deposit_4year(money) > HN::deposit_4year(money)) {
			cout << "4�� ���� ���������� ���� ���� ������ ���������Դϴ�." << endl;
			cout << endl;
			cout << "4�� ���� ���� ��� �ݾ��� : ";
			cout.precision(8);
			cout << NH::deposit_4year(money);
			cout << "�� �Դϴ�." << endl;
			cout << "(��Ȳ�� ���� ���� �� ������ �������� �����ϼ���.)" << endl;
		}
		else if (KB::deposit_4year(money) > NH::deposit_4year(money) && KB::deposit_4year(money) > HN::deposit_4year(money)) {
			cout << "4�� ���� ���������� ���� ���� ������ ���������Դϴ�." << endl;
			cout << endl;
			cout << "4�� ���� ���� ��� �ݾ��� : ";
			cout.precision(8);
			cout << KB::deposit_4year(money);
			cout << "�� �Դϴ�." << endl;
			cout << "(��Ȳ�� ���� ���� �� ������ �������� �����ϼ���.)" << endl;
		}
		else {
			cout << "4�� ���� ���������� ���� ���� ������ �ϳ������Դϴ�." << endl;
			cout << endl;
			cout << "4�� ���� ���� ��� �ݾ��� : ";
			cout.precision(8);
			cout << HN::deposit_4year(money);
			cout << "�� �Դϴ�." << endl;
			cout << "(��Ȳ�� ���� ���� �� ������ �������� �����ϼ���.)" << endl;
		}
	}
	return 0;
}