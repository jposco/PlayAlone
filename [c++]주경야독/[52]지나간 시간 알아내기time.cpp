#include <iostream>
#include <ctime> //�ð��� �ҷ����� ��Ŭ���

using namespace std;

int main()
{
	//time_t:��¥�� �ð��� ���� �� �ִ� �Լ�
	time_t start = time(NULL);
	time_t finish = time(NULL);

	int pass_int = 1;

	time(&start);

	for (int i = 1; i < 100000; i++)
	{
		for (int j = 1; j < 100000; j++)
			pass_int += 1;
	}

	time(&finish);

	cout << "1�� 100��� ���ϴ� �ð� : " << difftime(finish, start) << "��\n";

	return 0;
}

