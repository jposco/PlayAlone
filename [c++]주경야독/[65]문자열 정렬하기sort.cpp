#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int main()
{
	string sort_str1 = "gojoseon";
	string sort_str2 = "AaBbCcDdEe";

	sort(sort_str1.begin(), sort_str1.end());
	sort(sort_str2.begin(), sort_str2.end());
	//���ڿ��� ���ĺ� ������ �°� ����
	//��ҹ��ڰ� �����ִٸ� �ҹ��ڴ� �빮�� �ڷ� ���ĵȴ�.

	cout << "�ҹ��ڸ� ���� : " << sort_str1 << endl;
	cout << "��ҹ��ڸ� ���� : " << sort_str2 << endl;
	//�ҹ��ڸ� ���� : egjnooos
	//��ҹ��� ���� : ABCDEabcde

	return 0;
}