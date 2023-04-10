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
	cout << "[ 만기 년수로 적합한 은행과 예상 만기출금액 찾아드립니다. ]" << endl;
	cout << "[ 원하시는 만기 년수와 예상 입금액을 입력해주세요  .      ]" << endl;
	cout << " ----------------------------------------------------------" << endl;
	cout << "원하시는 만기 년수를 입력해주세요. (ex.1, 2, 3, 4) : ";
	cin >> expiration_year;
	cout << endl;
	cout << "예정 월 입금액을 입력해주세요. (ex. 100000) : ";
	cin >> money;
	cout << endl << "----------------------검색 중 입니다----------------------" << endl << endl;
	if (expiration_year == 1)
	{
		if (NH::deposit_1year(money) > KB::deposit_1year(money) && NH::deposit_1year(money) > HN::deposit_1year(money)) {
			cout << "1년 만기 적금이율이 가장 높은 은행은 농협은행입니다." << endl;
			cout << endl;
			cout << "1년 만기 예상 출금 금액은 : ";
			cout.precision(8);
			cout << NH::deposit_1year(money);
			cout << "원 입니다." << endl;
			cout << "(상황에 따라 변할 수 있으니 전문가와 상의하세요.)" << endl;
		}
		else if (KB::deposit_1year(money) > NH::deposit_1year(money) && KB::deposit_1year(money) > HN::deposit_1year(money)) {
			cout << "1년 만기 적금이율이 가장 높은 은행은 국민은행입니다." << endl;
			cout << endl;
			cout << "1년 만기 예상 출금 금액은 : ";
			cout.precision(8);
			cout << KB::deposit_1year(money);
			cout << "원 입니다." << endl;
			cout << "(상황에 따라 변할 수 있으니 전문가와 상의하세요.)" << endl;
		}
		else {
			cout << "1년 만기 적금이율이 가장 높은 은행은 하나은행입니다." << endl;
			cout << endl;
			cout << "1년 만기 예상 출금 금액은 : ";
			cout.precision(8);
			cout << HN::deposit_1year(money);
			cout << "원 입니다." << endl;
			cout << "(상황에 따라 변할 수 있으니 전문가와 상의하세요.)" << endl;
		}
	}
	if (expiration_year == 2)
	{
		if (NH::deposit_2year(money) > KB::deposit_2year(money) && NH::deposit_2year(money) > HN::deposit_2year(money)) {
			cout << "2년 만기 적금이율이 가장 높은 은행은 농협은행입니다." << endl;
			cout << endl;
			cout << "2년 만기 예상 출금 금액은 : ";
			cout.precision(8);
			cout << NH::deposit_2year(money);
			cout << "원 입니다." << endl;
			cout << "(상황에 따라 변할 수 있으니 전문가와 상의하세요.)" << endl;
		}
		else if (KB::deposit_2year(money) > NH::deposit_2year(money) && KB::deposit_2year(money) > HN::deposit_2year(money)) {
			cout << "2년 만기 적금이율이 가장 높은 은행은 국민은행입니다." << endl;
			cout << endl;
			cout << "2년 만기 예상 출금 금액은 : ";
			cout.precision(8);
			cout << KB::deposit_2year(money);
			cout << "원 입니다." << endl;
			cout << "(상황에 따라 변할 수 있으니 전문가와 상의하세요.)" << endl;
		}
		else {
			cout << "2년 만기 적금이율이 가장 높은 은행은 하나은행입니다." << endl;
			cout << endl;
			cout << "2년 만기 예상 출금 금액은 : ";
			cout.precision(8);
			cout << HN::deposit_2year(money);
			cout << "원 입니다." << endl;
			cout << "(상황에 따라 변할 수 있으니 전문가와 상의하세요.)" << endl;
		}
	}
	if (expiration_year == 3)
	{
		if (NH::deposit_3year(money) > KB::deposit_3year(money) && NH::deposit_3year(money) > HN::deposit_3year(money)) {
			cout << "3년 만기 적금이율이 가장 높은 은행은 농협은행입니다." << endl;
			cout << endl;
			cout << "3년 만기 예상 출금 금액은 : ";
			cout.precision(8);
			cout << NH::deposit_3year(money);
			cout << "원 입니다." << endl;
			cout << "(상황에 따라 변할 수 있으니 전문가와 상의하세요.)" << endl;
		}
		else if (KB::deposit_3year(money) > NH::deposit_3year(money) && KB::deposit_3year(money) > HN::deposit_3year(money)) {
			cout << "3년 만기 적금이율이 가장 높은 은행은 국민은행입니다." << endl;
			cout << endl;
			cout << "3년 만기 예상 출금 금액은 : ";
			cout.precision(8);
			cout << KB::deposit_3year(money);
			cout << "원 입니다." << endl;
			cout << "(상황에 따라 변할 수 있으니 전문가와 상의하세요.)" << endl;
		}
		else {
			cout << "4년 만기 적금이율이 가장 높은 은행은 하나은행입니다." << endl;
			cout << endl;
			cout << "4년 만기 예상 출금 금액은 : ";
			cout.precision(8);
			cout << HN::deposit_3year(money);
			cout << "원 입니다." << endl;
			cout << "(상황에 따라 변할 수 있으니 전문가와 상의하세요.)" << endl;
		}
	}
	if (expiration_year == 4)
	{
		if (NH::deposit_4year(money) > KB::deposit_4year(money) && NH::deposit_4year(money) > HN::deposit_4year(money)) {
			cout << "4년 만기 적금이율이 가장 높은 은행은 농협은행입니다." << endl;
			cout << endl;
			cout << "4년 만기 예상 출금 금액은 : ";
			cout.precision(8);
			cout << NH::deposit_4year(money);
			cout << "원 입니다." << endl;
			cout << "(상황에 따라 변할 수 있으니 전문가와 상의하세요.)" << endl;
		}
		else if (KB::deposit_4year(money) > NH::deposit_4year(money) && KB::deposit_4year(money) > HN::deposit_4year(money)) {
			cout << "4년 만기 적금이율이 가장 높은 은행은 국민은행입니다." << endl;
			cout << endl;
			cout << "4년 만기 예상 출금 금액은 : ";
			cout.precision(8);
			cout << KB::deposit_4year(money);
			cout << "원 입니다." << endl;
			cout << "(상황에 따라 변할 수 있으니 전문가와 상의하세요.)" << endl;
		}
		else {
			cout << "4년 만기 적금이율이 가장 높은 은행은 하나은행입니다." << endl;
			cout << endl;
			cout << "4년 만기 예상 출금 금액은 : ";
			cout.precision(8);
			cout << HN::deposit_4year(money);
			cout << "원 입니다." << endl;
			cout << "(상황에 따라 변할 수 있으니 전문가와 상의하세요.)" << endl;
		}
	}
	return 0;
}