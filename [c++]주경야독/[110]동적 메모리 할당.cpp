#include <iostream>
using namespace std;

class Info //클래스
{
public : // 1. Public : 공개된 정보. 외부 접근 허용
		 // 2. Pritected : 제한된 정보. 해당 클래스나서브 클래스에서만 접근 허용
		 // 3. Private : 제한된 정보. 해당 클래스에서만 접근 허용
	Info()
	{
		data = new int; //스택영역, 힙영역, 바이너리영역
		data_arr = new int[3];
	}
	//~Info()
	//{
	//	delete data;       // 소멸자 : 메모리 누수(leak) 방지
	//	delete[] data_arr; // 소멸자 : 메모리 누수(leak) 방지
	//}

	void Dispose() // 소멸자 : 메모리 누수(leak) 방지
	{
		delete data;
		delete[] data_arr;
	}
private :// 3. Private : 제한된 정보. 해당 클래스에서만 접근 허용
	int* data;
	int* data_arr;
};

int main()
{
	Info* info = new Info();

	info->Dispose();
	delete info;

	return 0;
}