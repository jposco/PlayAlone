#include <iostream>

using namespace std;

int main()
{
	cout << "[036]��ȯ������ Ȧ��, ¦�� ã��(for)"<<endl;
	int data[10] = { 5, 19, 76, 3, 10, 67, 53, 86, 13, 52 };

	for (int i = 0; i < 10; i++)
	{
		if (data[i] % 2 == 0)
			cout << data[i] << "�� ¦���Դϴ�. " << endl;
		else
			cout << data[i] << "�� Ȧ���Դϴ�. " << endl;
	}
	return 0;
}