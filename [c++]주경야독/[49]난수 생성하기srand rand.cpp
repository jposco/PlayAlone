#include <iostream>
#include <ctime>//�ð��� �ҷ����� ��Ŭ���

using namespace std;

int main()
{	
	int num = 0;
	srand(static_cast<unsigned int>(time(NULL))); //���ѽɱ�(�ð�����)
	srand(time(NULL));
	for (int i = 0; i < 5; i++)
	{
		cout << " ���� : " << rand() << endl;//��������
	}
	num = (rand() % 45) + 1;

	return 0;
}
