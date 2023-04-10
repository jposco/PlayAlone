#include <iostream>
using namespace std;

int main()
{
	cout << "-------------------------------------" << endl;
	cout << "[    안녕하세요. 스타벅스입니다.    ]" << endl;
	cout << "[    ▶  1. 아메리카노               ]" << endl;
	cout << "[    ▶  2. 카페라떼                 ]" << endl;
	cout << "[    ▶  3. 주문종료                 ]" << endl;
	cout << "[    주문하실 번호를 선택해주세요.  ]" << endl;
	cout << "-------------------------------------" << endl;


	while (1)
	{
		int order;
		cin >> order;

		if (order == 1)
		{
			cout << "1. 아메리카노 주문하셨습니다." << endl;
		}
		else if (order == 2)
		{
			cout << "2. 카페라떼 주문하셨습니다." << endl;
		}
		else if (order == 3)
		{
			cout << "3. 주문이 완료되었습니다." << endl;
			break;
		}
		else
		{
			cout << "1-3까지의 숫자만 입력해주세요." << endl;
		}
	}
}