#include <iostream>
using namespace std;

int main()
{
	cout << "-------------------------------------" << endl;
	cout << "[    �ȳ��ϼ���. ��Ÿ�����Դϴ�.    ]" << endl;
	cout << "[    ��  1. �Ƹ޸�ī��               ]" << endl;
	cout << "[    ��  2. ī���                 ]" << endl;
	cout << "[    ��  3. �ֹ�����                 ]" << endl;
	cout << "[    �ֹ��Ͻ� ��ȣ�� �������ּ���.  ]" << endl;
	cout << "-------------------------------------" << endl;


	while (1)
	{
		int order;
		cin >> order;

		if (order == 1)
		{
			cout << "1. �Ƹ޸�ī�� �ֹ��ϼ̽��ϴ�." << endl;
		}
		else if (order == 2)
		{
			cout << "2. ī��� �ֹ��ϼ̽��ϴ�." << endl;
		}
		else if (order == 3)
		{
			cout << "3. �ֹ��� �Ϸ�Ǿ����ϴ�." << endl;
			break;
		}
		else
		{
			cout << "1-3������ ���ڸ� �Է����ּ���." << endl;
		}
	}
}