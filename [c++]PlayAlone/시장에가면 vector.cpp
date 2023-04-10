#include <iostream>
#include <vector>
using namespace std;

class CMarket
{
public:
	CMarket(string name_in)
	{
		this->name = name_in;
		cnt++; //�Է� ���� �� ī��Ʈ
	}
	static int get_cnt()//����ƽ ��� ����ϱ�
	{
		return cnt;
	}
	string get_name()
	{
		return name;
	}
private:
	static int cnt; //�� �� �����ߴ��� ī��Ʈ
	string name; //�Է��� ǰ�� �̸�
};
int CMarket::cnt = 0;

int main()
{
	cout << "*************************************************" << endl;
	cout << "'���忡 ���� ����' : �տ� ���� ���뿡 �̾�ϱ�" << endl;
	cout << "*************************************************" << endl;

	string thing;
	vector<CMarket> v;
	// vector<string> v;
	// v = {"abc", "bcd"}
	// v = {Market market("����")}
	while (1)
	{
		cout << "���忡 ���� ~ ";
		bool flag = true; //������ ���Ḧ �˸��� ����
		cin >> thing;
		for (int i = 0; i < v.size(); i++)
		{
			if (thing != v.at(i).get_name())
			{
				flag = false;
				break;
			}
			cin >> thing; //�Է��� ������ ���� �� ���ο� �Է¹ޱ�
		}
		if (!flag) { break; }
		else { v.push_back(CMarket(thing)); }
	}
	cout << endl << "���忡�� ������ ���� ���� : " << CMarket::get_cnt() << "�� �Դϴ�.";

	return 0;
}