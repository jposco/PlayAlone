#include <iostream>
using namespace std;

class Info //Ŭ����
{
public : // 1. Public : ������ ����. �ܺ� ���� ���
		 // 2. Pritected : ���ѵ� ����. �ش� Ŭ���������� Ŭ���������� ���� ���
		 // 3. Private : ���ѵ� ����. �ش� Ŭ���������� ���� ���
	Info()
	{
		data = new int; //���ÿ���, ������, ���̳ʸ�����
		data_arr = new int[3];
	}
	//~Info()
	//{
	//	delete data;       // �Ҹ��� : �޸� ����(leak) ����
	//	delete[] data_arr; // �Ҹ��� : �޸� ����(leak) ����
	//}

	void Dispose() // �Ҹ��� : �޸� ����(leak) ����
	{
		delete data;
		delete[] data_arr;
	}
private :// 3. Private : ���ѵ� ����. �ش� Ŭ���������� ���� ���
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