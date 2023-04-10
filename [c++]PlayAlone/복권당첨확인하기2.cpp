#include <iostream>
#include <ctime>
using namespace std;

int main()
{
	srand(time(NULL));
	int lotteryNum[7] = {}; //���� ��÷��ȣ ����
	int userNum[6] = {}; //������ �Է��� ��ȣ ����
	int randNum = 0; //������ ����
	int numIn = 0; //������ �Է��� ����
	int sameNum = 0; //�� ���Ͱ� ��ġ ����

	cout << "-------------------------------------------------" << endl;
	cout << "|  �ζ� 1062ȸ�� (2023.04.08) ��÷��ȣ Ȯ���ϱ� |" << endl;
	cout << "|  �����Ͻ� ���� ��ȣ 6�ڸ��� �Է����ּ���.     |" << endl;
	cout << "-------------------------------------------------" << endl;

	//�ζ� ��÷��ȣ �����ϱ�
	for (int i = 0; i < 7; i++)
	{
		bool flag = true; //���� �ߺ����� ������ BOOL
		randNum = rand() % 45 + 1;
		for (int j = 0; j < 7; j++)
		{
			if (randNum == lotteryNum[j])
			{
				flag = false; //�ߺ��� ���� �߻�
				break;
			}
		}
		if (!flag) { i--; } //�ߺ��� ������ ����÷
		else { lotteryNum[i] = randNum; }
	}

	//�ζ� ��÷��ȣ ����ϱ�
	cout << endl << "���ζ� 1059ȸ�� (2023.03.18) ��÷��ȣ�� : ";
	for (int i = 0; i < 6; i++)
	{
		cout << lotteryNum[i] << " ";
	}
	cout << "+ " << lotteryNum[6] << endl << endl;

	//�ζ� ���ù�ȣ 6�� �Է��ϱ�
	for (int i = 0; i < 6; i++)
	{
		cout << "��" << i + 1 << "��° ���ڴ� : ";
		cin >> numIn;
		userNum[i] = numIn;
	}
	cout << endl;

	//�ζ� ��÷��ȣ ���ϱ�
	for (int i = 0; i < 6; i++)
	{
		for (int j = 0; j < 6; j++)
		{
			if (lotteryNum[i] == userNum[j])
			{
				sameNum++; //��ġ �Ҷ����� ����
			}
		}
	}

	//�ζ� ���ʽ���ȣ ���ϱ�
	bool bonusNum = false; //���ʽ� ������ġ Ȯ�ο� bool
	for (int i = 0; i < 6; i++)
	{
		if (userNum[i] == lotteryNum[6])
		{
			bonusNum = true;
			break;
		}
	}

	//�ζ� ��÷���� ����ϱ�
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