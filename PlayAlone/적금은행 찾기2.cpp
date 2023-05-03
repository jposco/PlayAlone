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
	cout << "[ 은행명(ex.농협) 만기년수 예금액을 입력하세요.            ]" << endl;
	cout << "[ 순서대로 띄어쓰기를 기준으로 입력하세요.                 ]" << endl;
	cout << " ----------------------------------------------------------" << endl;
	cout << "ex) 우리 2 2000000 : ";
	cin >> bank >> expiration_year >> money;

	if (bank == "농협")
	{
		if (expiration_year <= 1)
		{
			cout << "1년 만기 상품 존재합니다." << endl;
			cout.precision(9);
			cout << "만기 시 예상금액은 : " << NH::deposit_1year(money) << "원 입니다." << endl;
		}
		else if (expiration_year > 1 && expiration_year < 4)
		{
			cout << "2년 만기 상품 존재합니다." << endl;
			cout.precision(9);
			cout << "만기 시 예상금액은 : " << NH::deposit_2year(money) << "원 입니다." << endl;
		}
		else
		{
			cout << "4년 만기 상품 존재합니다." << endl;
			cout.precision(9);
			cout << "만기 시 예상금액은 : " << NH::deposit_4year(money) << "원 입니다." << endl;
		}
	}
	else if (bank == "국민")
	{
		if (expiration_year <= 1)
		{
			cout << "1년 만기 상품 존재합니다." << endl;
			cout.precision(9);
			cout << "만기 시 예상금액은 : " << KB::deposit_1year(money) << "원 입니다." << endl;
		}
		else if (expiration_year > 1 && expiration_year < 4)
		{
			cout << "2년 만기 상품 존재합니다." << endl;
			cout.precision(9);
			cout << "만기 시 예상금액은 : " << KB::deposit_2year(money) << "원 입니다." << endl;
		}
		else
		{
			cout << "4년 만기 상품 존재합니다." << endl;
			cout.precision(9);
			cout << "만기 시 예상금액은 : " << KB::deposit_4year(money) << "원 입니다." << endl;
		}
	}
	else
	{
		cout << "은행이 잘못되었습니다." << endl;
	}
	return 0;
}

