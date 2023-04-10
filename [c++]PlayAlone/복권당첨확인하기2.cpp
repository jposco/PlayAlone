#include <iostream>
#include <ctime>
using namespace std;

int main()
{
	srand(time(NULL));
	int lotteryNum[7] = {}; //복권 당첨번호 벡터
	int userNum[6] = {}; //유저가 입력한 번호 벡터
	int randNum = 0; //생성된 난수
	int numIn = 0; //유저가 입력한 변수
	int sameNum = 0; //두 벡터값 일치 변수

	cout << "-------------------------------------------------" << endl;
	cout << "|  로또 1062회차 (2023.04.08) 당첨번호 확인하기 |" << endl;
	cout << "|  선택하신 복권 번호 6자리를 입력해주세요.     |" << endl;
	cout << "-------------------------------------------------" << endl;

	//로또 당첨번호 생성하기
	for (int i = 0; i < 7; i++)
	{
		bool flag = true; //난수 중복생성 방지용 BOOL
		randNum = rand() % 45 + 1;
		for (int j = 0; j < 7; j++)
		{
			if (randNum == lotteryNum[j])
			{
				flag = false; //중복된 난수 발생
				break;
			}
		}
		if (!flag) { i--; } //중복된 난수는 재추첨
		else { lotteryNum[i] = randNum; }
	}

	//로또 당첨번호 출력하기
	cout << endl << "▶로또 1059회차 (2023.03.18) 당첨번호는 : ";
	for (int i = 0; i < 6; i++)
	{
		cout << lotteryNum[i] << " ";
	}
	cout << "+ " << lotteryNum[6] << endl << endl;

	//로또 선택번호 6개 입력하기
	for (int i = 0; i < 6; i++)
	{
		cout << "▷" << i + 1 << "번째 숫자는 : ";
		cin >> numIn;
		userNum[i] = numIn;
	}
	cout << endl;

	//로또 당첨번호 비교하기
	for (int i = 0; i < 6; i++)
	{
		for (int j = 0; j < 6; j++)
		{
			if (lotteryNum[i] == userNum[j])
			{
				sameNum++; //일치 할때마다 적립
			}
		}
	}

	//로또 보너스번호 비교하기
	bool bonusNum = false; //보너스 숫자일치 확인용 bool
	for (int i = 0; i < 6; i++)
	{
		if (userNum[i] == lotteryNum[6])
		{
			bonusNum = true;
			break;
		}
	}

	//로또 당첨순위 출력하기
	if (sameNum > 2) // 당첨번호 개수가 3개 이상일 경우
	{
		if (sameNum == 6) //1등
		{
			cout << "▶!!!!!!!!축하드립니다.만장일치!!!!!!!!" << endl;
			cout << "▶로또 1062회차 1등에 당첨되셨습니다!!" << endl;
		}
		else if (sameNum == 5 && bonusNum)//2등
		{
			cout << "▶축하드립니다. " << sameNum << "개번호 일치 + 보너스 번호 일치!!!!" << endl;
			cout << "▶로또 1059회차 2등에 당첨되셨습니다!!" << endl;
		}
		else if (sameNum == 5 || !bonusNum)//3등
		{
			cout << "▶축하드립니다. " << sameNum << "개 번호 일치!!!!" << endl;
			cout << "▶로또 1059회차 3등에 당첨되셨습니다!!" << endl;
		}
		else
		{
			cout << "▶축하드립니다. " << sameNum << "개 번호 일치!!!!" << endl;
			cout << "▶로또 1059회차 " << 8 - sameNum << "등에 당첨되셨습니다!!" << endl;
		}
	}
	else //당첨번호 개수가 2개 이하일 경우
	{
		cout << "▶아쉽습니다. 낙첨입니다." << endl;
	}
}