#include <iostream>
#include <tuple>
#include <string>

using namespace std;

int main()
{
	typedef tuple<string, int, double> Data; //Ʃ���� �����Ѵ�.

	Data data1("���ڿ�", 10, 1.2);
	auto data2 = make_tuple("���ڿ�", 10, 1.2);//���� �ǹ��̴�.

	cout << get<0>(data1) << ", " << get<1>(data1) << " , "
		<< get<2>(data1) << endl;
	//��� : get<�ε��� ��ȣ>(Ʃ�� ��ü�̸�)
		
	return 0;
} //���ڿ� , 10 ,1.2 ���

//tuple�� �����̳��̴�.