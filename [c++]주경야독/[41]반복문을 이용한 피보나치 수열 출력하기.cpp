#include <iostream>
using namespace std;

int main()
{
	int p = 0; //������
	int n = 0; //��µǴ� ������ �Ǻ���ġ ��
	int t = 0; //n���� p�� �����ϱ� ���� �ӽú���

	for (int i = 0; i < 10; i++)
	{
		p = 0;
		n = 1;
		for (int j = 0; j <=i; j++)
		{
			cout << n << " , ";
			t = n;
			n = n + p;
			p = t;
		}
		cout << endl;
	}
}