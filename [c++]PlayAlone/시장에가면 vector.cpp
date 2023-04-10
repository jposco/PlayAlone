#include <iostream>
#include <vector>
using namespace std;

class CMarket
{
public:
	CMarket(string name_in)
	{
		this->name = name_in;
		cnt++; //입력 들어올 때 카운트
	}
	static int get_cnt()//스태틱 멤버 사용하기
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

	string thing;
	vector<CMarket> v;
	// vector<string> v;
	// v = {"abc", "bcd"}
	// v = {Market market("참돔")}
	while (1)
	{
		cout << "시장에 가면 ~ ";
		bool flag = true; //게임의 종료를 알리는 변수
		cin >> thing;
		for (int i = 0; i < v.size(); i++)
		{
			if (thing != v.at(i).get_name())
			{
				flag = false;
				break;
			}
			cin >> thing; //입력한 내용이 같을 시 새로운 입력받기
		}
		if (!flag) { break; }
		else { v.push_back(CMarket(thing)); }
	}
	cout << endl << "시장에서 가져온 물건 갯수 : " << CMarket::get_cnt() << "개 입니다.";

	return 0;
}