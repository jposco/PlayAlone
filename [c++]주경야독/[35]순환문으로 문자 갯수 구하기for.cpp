#include <iostream>
#include <string>
using namespace std;

//ver.1
/*
int main()
{
	cout<<"[035]순환문으로 특정 문자 개수 구하기(for)"<<endl;
	string str = "the hin state was formed in southern korea by the 3rd century BC";
	 
	char find_a = 'a'; // a를 찾아낼 변수
	
	int size = str.size(); // str의 길이를 나타낼 변수

	int cnt = 0; //a가 들어있을 때마다 카운트

	for (int i = 0; i < size(); i++)
	{
		if (str[i] == ficd)
			cnt++;
	}

	cout << "문장의 a의 개수는 " << cnt << "개 입니다."<<endl;
	return 0;
}
*/

//ver.2
int main()
{
	string str = "the hin state was formed in southern korea by the 3rd century BC";

	int cnt = 0;

	for (int i = 0; i < str.size(); i++)
	{
		if (str[i] == 'a')
			cnt++;
	}
	cout << "문장의 a의 개수는 " << cnt << "개 입니다."<<endl;
	return 0;
}