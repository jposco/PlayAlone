#include <iostream>
using namespace std;

int main()
{
	int offset = 4;

	for(int i=1,j=0; i<=offset;i++,j=0)
	{

		for (int k = 1; k <=offset-i; k++) //���� ����
		{//1~3���� , 1~2���� , 1������
			cout << " - ";
		}
		while (j != 2 * i - 1)
		{
			cout << " * ";
			j++;
		}
		cout << endl;
	}
}