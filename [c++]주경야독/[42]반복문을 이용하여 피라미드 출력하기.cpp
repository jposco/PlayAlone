#include <iostream>
using namespace std;

int main()
{
	int offset = 4;

	for(int i=1,j=0; i<=offset;i++,j=0)
	{

		for (int k = 1; k <=offset-i; k++) //공백 개수
		{//1~3까지 , 1~2까지 , 1개까지
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