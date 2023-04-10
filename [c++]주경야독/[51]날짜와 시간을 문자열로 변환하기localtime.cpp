#include <iostream>
#include <ctime>//시간을 불러오는 인클루드

using namespace std;

int main()
{
	time_t now = time(NULL);
	tm* ptm = localtime(&now);

	char buffer[64];
	strftime(buffer, 64, "예제 만드는 지금은 %Y년 %m월 %d일, %H시 %M분 %S입니다.(%p)\n", ptm);

	cout << buffer;

	return 0;
}