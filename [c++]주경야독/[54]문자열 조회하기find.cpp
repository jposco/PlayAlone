#include <iostream>
#include <string>

using namespace std;

int main()
{
	string baekhap_war = "백합벌 전투 : 백제 왕자 부여창의 일기토로 유명한 전투";
	int rtn = baekhap_war.find("부여창");

	if (rtn >= 0) //문자열을 찾았으면 0이거나 위치(ex.24)
		cout << "문자열을 찾았습니다. 위치는 " << rtn << "입니다." << endl;
	else // 못찾았으면 -1을 출력
		cout << "문자열을 찾을 수 없습니다." << endl;

	return 0;
}