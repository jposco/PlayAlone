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
		cout << "���� ���� ������� ���⸦ �������� �Է��ϼ��� " << endl;;
		cin >> bank >> money; //�츮 10000

		if (bank == "�츮")
			cout << "���� ��� �ݾ�: " << wooriBank::deposit(money) << endl;
		else if (bank == "�ϳ�")
			cout << "���� ��� �ݾ�: " << hanaBank::deposit(money) << endl;
		else { cout << "������ �߸��Ǿ����ϴ�."; }
		cout << "-------------------------------------------------" << endl;
	}
	int money;
	string bank;
	cout << "���� ���� ������� ���⸦ �������� �Է��ϼ��� " << endl;;
	cin >> bank >> money; //�츮 10000

	if (bank == "�츮") {
		cout.precision(8);
		cout << "���� ��� �ݾ�: " << wooriBank::deposit(money) << endl;
	}
	else if (bank == "�ϳ�") {
		cout.precision(8);
		cout << "���� ��� �ݾ�: " << hanaBank::deposit(money) << endl;
	}
	else { cout << "������ �߸��Ǿ����ϴ�."; }

}