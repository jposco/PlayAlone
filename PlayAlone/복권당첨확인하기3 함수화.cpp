#include <iostream>
#include <ctime>

using namespace std;

//����ȭ�� ��º�
void startScreen()
{
	cout << "-------------------------------------------------" << endl;
	cout << "|  �ζ� 1062ȸ�� (2023.04.08) ��÷��ȣ Ȯ���ϱ� |" << endl;
	cout << "|  �����Ͻ� ���� ��ȣ 6�ڸ��� �Է����ּ���.     |" << endl;
	cout << "-------------------------------------------------" << endl;
}

//�ζǹ�ȣ ���� �� ��º�
int* creatLottoNum()
{
	srand(time(NULL));
	int* lottoNum = new int[7] {}; //�����͸� �̿��� �����޸� �Ҵ�
	for (int i = 0; i < 7; i++)
	{
		bool dup = false; //���� �ߺ����� ������ BOOL
		int randNum = rand() % 45 + 1;
		for (int j = 0; j < 7; j++)
		{
			if (randNum == lottoNum[j])
			{
				dup = true; //�ߺ��� ���� �߻�
				break;
			}
		}
		if (dup) { i--; } //�ߺ��� ������ ����÷
		else { lottoNum[i] = randNum; }
	}

	cout << endl << "���ζ� 1059ȸ�� (2023.03.18) ��÷��ȣ�� : ";
	for (int i = 0; i < 6; i++)
	{
		cout << lottoNum[i] << " ";
	}
	cout << "+ " << lottoNum[6] << endl << endl;
	return lottoNum;
}

//����� �ζǹ�ȣ �Էº�
int* lottoInput()
{
	int* userNum = new int[6] {}; //�����͸� �̿��� �����޸� �Ҵ�
	int numIn = 0;
	for (int i = 0; i < 6; i++)
	{
		cout << "��" << i + 1 << "��° ���ڴ� : ";
		cin >> numIn;
		bool dup = false; //����� �Է¹�ȣ �ߺ������� BOOL
		for (int j = 0; j < 6; j++)
		{
			if (numIn == userNum[j])
			{
				dup = true; //�ߺ��� �Է¹�ȣ �߻�
				break;
			}
		}
		if (dup)
		{
			cout << "�����ϼ���. �ߺ��� �����Դϴ�." << endl;
			i--;
		} //�ߺ�������� �ٽ� �Է�
		else { userNum[i] = numIn; }
	}
	cout << endl;
	return userNum;
}

//�ζǹ�ȣ �� �� ��� ��º�
void printRank(int* creatLottoNum, int* lottoInput)
{
	int sameNum = 0;
	for (int i = 0; i < 6; i++)
	{
		for (int j = 0; j < 6; j++)
		{
			if (creatLottoNum[i] == lottoInput[j])
			{
				sameNum++; //��ġ �Ҷ����� ī��Ʈ
			}
		}
	}

	bool bonusNum = false;//���ʽ� ��ȣ ��ġ Ȯ�ο� bool
	for (int i = 0; i < 6; i++)
	{
		if (lottoInput[i] == creatLottoNum[6])
		{
			bonusNum = true; //��ġ �Ұ�� Ʈ��
			break;
		}
	}

	//���� �޸� �Ҵ� ����
	delete[] creatLottoNum;
	delete[] lottoInput;

	if (sameNum > 2) // ��÷��ȣ ������ 3�� �̻��� ���
	{
		if (sameNum == 6) //1��
		{
			cout << "��!!!!!!!!���ϵ帳�ϴ�.������ġ!!!!!!!!" << endl;
			cout << "���ζ� 1062ȸ�� 1� ��÷�Ǽ̽��ϴ�!!" << endl;
		}
		else if (sameNum == 5 && bonusNum)//2��
		{
			cout << "�����ϵ帳�ϴ�. " << sameNum << "����ȣ ��ġ + ���ʽ� ��ȣ ��ġ!!!!" << endl;
			cout << "���ζ� 1059ȸ�� 2� ��÷�Ǽ̽��ϴ�!!" << endl;
		}
		else if (sameNum == 5 || !bonusNum)//3��
		{
			cout << "�����ϵ帳�ϴ�. " << sameNum << "�� ��ȣ ��ġ!!!!" << endl;
			cout << "���ζ� 1059ȸ�� 3� ��÷�Ǽ̽��ϴ�!!" << endl;
		}
		else
		{
			cout << "�����ϵ帳�ϴ�. " << sameNum << "�� ��ȣ ��ġ!!!!" << endl;
			cout << "���ζ� 1059ȸ�� " << 8 - sameNum << "� ��÷�Ǽ̽��ϴ�!!" << endl;
		}
	}
	else //��÷��ȣ ������ 2�� ������ ���
	{
		cout << "���ƽ����ϴ�. ��÷�Դϴ�." << endl;
	}
}

int main()
{
	startScreen(); //����ȭ�� ��º�

	int* lottoNum = creatLottoNum(); //�ζǹ�ȣ ���� �� ��º�

	int* userNum = lottoInput(); //����� �ζǹ�ȣ �Էº�

	printRank(lottoNum, userNum); //�ζǹ�ȣ �� �� ��� ��º�
}