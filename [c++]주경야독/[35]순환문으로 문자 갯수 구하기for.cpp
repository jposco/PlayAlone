#include <iostream>
#include <string>
using namespace std;

//ver.1
/*
int main()
{
	cout<<"[035]��ȯ������ Ư�� ���� ���� ���ϱ�(for)"<<endl;
	string str = "the hin state was formed in southern korea by the 3rd century BC";
	 
	char find_a = 'a'; // a�� ã�Ƴ� ����
	
	int size = str.size(); // str�� ���̸� ��Ÿ�� ����

	int cnt = 0; //a�� ������� ������ ī��Ʈ

	for (int i = 0; i < size(); i++)
	{
		if (str[i] == ficd)
			cnt++;
	}

	cout << "������ a�� ������ " << cnt << "�� �Դϴ�."<<endl;
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
	cout << "������ a�� ������ " << cnt << "�� �Դϴ�."<<endl;
	return 0;
}