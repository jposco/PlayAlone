#include <iostream>
#include <vector>

using namespace std;

int main()
{
	vector<int> data1({ 1, 2, 3 });
	vector<int> data2 = { 10, 20, 40 };
	  
	data1.swap(data2); //data1과 data2가 바뀐다
	data1.insert(data1.begin() + 1, 20); //삽입한다, 두번째엔 삽입할 내용

	cout << "==data1==" << endl;
	// 10 20 20 40


	for (int i = 0; i < data1.size(); i++)
		cout << "data1 (" << i << ") : " << data1.at(i) << endl;

	cout << endl << " ==data2==" << endl;
	// 1 2 3

	for (int i = 0; i < data2.size(); i++)
		cout << "data2 (" << i << ") : " << data2.at(i) << endl;

	data2.erase(data2.begin(), data2.begin() + 2); //정해진 범위의 데이터를 삭제한다.(첫번째 두번째 삭제)

	data2.push_back(100);
	data2.push_back(200);
	data2.push_back(300); //마지막에 삽입한다
	data2.pop_back(); //마지막 수를 뺸다

	data2.insert(data2.end(), data1.begin(), data1.end()); 
	// 벡터에 삽입될 위치, 복사할 벡터의 시작위치, 복사할 벡터의 종료 위치

	cout << endl << "==data2== " << endl;
	//3 100 200 10 20 20 40

	for (int i = 0; i < data2.size(); i++)
		cout << "data2 (" << i << ") : " << data2.at(i) << endl;

	return 0; 
}