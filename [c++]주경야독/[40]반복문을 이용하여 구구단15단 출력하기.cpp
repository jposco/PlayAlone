#include <iostream>
using namespace std;

int main()
{/*

	int offset = 0;

	for (int i = 1; i <= 15; i += offset)
	{
		for (int j = 1; j <= 9; j++)
		{
			int mul= i*j;
			cout << i << "x" << j << "=" << mul<<" ";

			for (int k = 0; k < offset; k++)
			{
				cout << "\t";
				cout << (i + k + 1) << "*" << j << " = " << (i + k + 1) * j;
			}
			cout << endl;
		}
		cout << endl;
		offset++;
	}*/

	for (int i = 1; i <= 9; i++)
	{
		for (int j = 1; j <= 9; j++)
		{
			cout << "°öÀº" << i * j << endl;
		}
		cout << endl;
	}
}