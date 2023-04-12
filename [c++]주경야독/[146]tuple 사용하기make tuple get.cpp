#include <iostream>
#include <tuple>
#include <string>

using namespace std;

int main()
{
	typedef tuple<string, int, double> Data; //튜플을 정의한다.

	Data data1("문자열", 10, 1.2);
	auto data2 = make_tuple("문자열", 10, 1.2);//같은 의미이다.

	cout << get<0>(data1) << ", " << get<1>(data1) << " , "
		<< get<2>(data1) << endl;
	//출력 : get<인덱스 번호>(튜플 객체이름)
		
	return 0;
} //문자열 , 10 ,1.2 출력

//tuple은 컨테이너이다.