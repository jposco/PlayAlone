#include <iostream>
using namespace std;
namespace wooriBank {
	int balance = 0;
	double deposit(int money) {
		double money_d = (double)money;
		return money_d + 0.03 * money_d;
	}
}
namespace hanaBank {
	int balance = 0;
	double deposit(int money) {
		double money_d = (double)money;
		return money_d + 0.05 * money_d;
	}
}

int main() {
	for (int i = 0; i < 2; i++) {
		int money;
		string bank;
		cout << "은행 돈을 순서대로 띄어쓰기를 기준으로 입력하세요 " << endl;;
		cin >> bank >> money; //우리 10000

		if (bank == "우리")
			cout << "예상 출금 금액: " << wooriBank::deposit(money) << endl;
		else if (bank == "하나")
			cout << "예상 출금 금액: " << hanaBank::deposit(money) << endl;
		else { cout << "은행이 잘못되었습니다."; }
		cout << "-------------------------------------------------" << endl;
	}
	int money;
	string bank;
	cout << "은행 돈을 순서대로 띄어쓰기를 기준으로 입력하세요 " << endl;;
	cin >> bank >> money; //우리 10000

	if (bank == "우리") {
		cout.precision(8);
		cout << "예상 출금 금액: " << wooriBank::deposit(money) << endl;
	}
	else if (bank == "하나") {
		cout.precision(8);
		cout << "예상 출금 금액: " << hanaBank::deposit(money) << endl;
	}
	else { cout << "은행이 잘못되었습니다."; }

}