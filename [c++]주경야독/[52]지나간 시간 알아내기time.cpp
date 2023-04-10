#include <iostream>
#include <ctime> //시간을 불러오는 인클루드

using namespace std;

int main()
{
	//time_t:날짜와 시간을 얻을 수 있는 함수
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

	cout << "1을 100억번 더하는 시간 : " << difftime(finish, start) << "초\n";

	return 0;
}

