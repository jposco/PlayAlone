#include <iostream>
#include <ctime>

using namespace std;

//메인화면 출력부
void startScreen()
{
	cout << "-------------------------------------------------" << endl;
	cout << "|  로또 1062회차 (2023.04.08) 당첨번호 확인하기 |" << endl;
	cout << "|  선택하신 복권 번호 6자리를 입력해주세요.     |" << endl;
	cout << "-------------------------------------------------" << endl;
}

//로또번호 생성 및 출력부
int* creatLottoNum()
{
	srand(time(NULL));
	int* lottoNum = new int[7] {}; //포인터를 이용한 동적메모리 할당
	for (int i = 0; i < 7; i++)
	{
		bool dup = false; //난수 중복생성 방지용 BOOL
		int randNum = rand() % 45 + 1;
		for (int j = 0; j < 7; j++)
		{
			if (randNum == lottoNum[j])
			{
				dup = true; //중복된 난수 발생
				break;
			}
		}
		if (dup) { i--; } //중복된 난수는 재추첨
		else { lottoNum[i] = randNum; }
	}

	cout << endl << "▶로또 1059회차 (2023.03.18) 당첨번호는 : ";
	for (int i = 0; i < 6; i++)
	{
		cout << lottoNum[i] << " ";
	}
	cout << "+ " << lottoNum[6] << endl << endl;
	return lottoNum;
}

//사용자 로또번호 입력부
int* lottoInput()
{
	int* userNum = new int[6] {}; //포인터를 이용한 동적메모리 할당
	int numIn = 0;
	for (int i = 0; i < 6; i++)
	{
		cout << "▷" << i + 1 << "번째 숫자는 : ";
		cin >> numIn;
		bool dup = false; //사용자 입력번호 중복방지용 BOOL
		for (int j = 0; j < 6; j++)
		{
			if (numIn == userNum[j])
			{
				dup = true; //중복된 입력번호 발생
				break;
			}
		}
		if (dup)
		{
			cout << "진정하세요. 중복된 숫자입니다." << endl;
			i--;
		} //중복됐을경우 다시 입력
		else { userNum[i] = numIn; }
	}
	cout << endl;
	return userNum;
}

//로또번호 비교 및 등수 출력부
void printRank(int* creatLottoNum, int* lottoInput)
{
	int sameNum = 0;
	for (int i = 0; i < 6; i++)
	{
		for (int j = 0; j < 6; j++)
		{
			if (creatLottoNum[i] == lottoInput[j])
			{
				sameNum++; //일치 할때마다 카운트
			}
		}
	}

	bool bonusNum = false;//보너스 번호 일치 확인용 bool
	for (int i = 0; i < 6; i++)
	{
		if (lottoInput[i] == creatLottoNum[6])
		{
			bonusNum = true; //일치 할경우 트루
			break;
		}
	}

	//동적 메모리 할당 해제
	delete[] creatLottoNum;
	delete[] lottoInput;

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

int main()
{
	startScreen(); //메인화면 출력부

	int* lottoNum = creatLottoNum(); //로또번호 생성 및 출력부

	int* userNum = lottoInput(); //사용자 로또번호 입력부

	printRank(lottoNum, userNum); //로또번호 비교 및 등수 출력부
}