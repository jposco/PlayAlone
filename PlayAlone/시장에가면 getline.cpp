#include <iostream>
#include <vector>
#include <string>
#include <sstream>

using namespace std;

class CMarket
{
public:
	CMarket(string name)
	{
		this->name = name;
		cnt++;
	}
	static int get_cnt()
	{
		return cnt;
	}
	string get_name()
	{
		return name;
	}
private:
	static int cnt; //몇 번 성공했는지 카운트
	string name; //입력한 품목 이름
};

int CMarket::cnt = 0;

int main()
{
	cout << "*************************************************" << endl;
	cout << "'시장에 가면 게임' : 앞에 말한 내용에 이어말하기" << endl;
	cout << "*************************************************" << endl;

	string things; //입력받은 물건들
	string thing; //한개씩 쪼갠 물건
	vector<CMarket> v;

	while (1)
	{
		cout << "시장에 가면 ~ ";

		bool flag = true;
		getline(cin, things); //문장단위의 things
		stringstream name_stream(things);//단어 단어로 쪼갠다
		name_stream >> thing; //한 단어씩 thing에 넣는다

		for (int i = 0; i < v.size(); i++) //한개씩 검사
		{
			if (thing != v.at(i).get_name()) //배열값이 같지 않을경우
			{
				flag = false;
				break;
			}
			name_stream >> thing;
		}
		if (!flag) { break; }
		else { v.push_back(thing); }
	}
	cout << endl << "시장에서 가져온 물건 갯수 : " << CMarket::get_cnt() << "개 입니다.";

	return 0;
}