

//--------------������ ���� ����� ��� �����ϱ�--------------------------------------------------------
//������ : �޸��� �ּҸ� ���� ����
//������ ������ * �� �̿��Ͽ� ����
//int* p; //������ ���� ����
//int n = 10;
//p = &n; // ������ ���� p�� n�� �޸� �ּ�(&n)�� ������
//�ᱹ int* p = &n -> '10'�� ��µȴ�.
//�׷����� int* p = n -> 215326�� ��µȴ� (�޸� �ּ�) 

//--------------���� �迭 ����� �Ҵ� �����ϱ�------------------------------------------------
//���� �迭�� ����� ���ؼ� '������ ����'�� 'new' Ű���� ���
//int n2;
//cout << "���ڸ� �Է��ϼ���: ";
//cin >> n2;
//int* arr = new int[n2] //n2�� ���� �迭�� �ִ´�.
// 1. ���� �޸𸮸� ����Ű�� ������ ����
// 2. new��� Ű���带 ����Ͽ�, ���� �迭 �Ҵ�.
//delete[] arr; ���� �迭�� �ݳ��ؾ��Ѵ�.

//------------��ĳ����-------------------------------------------------
//��ĳ���� : �θ�Ŭ������ ������Person*�� �ڽ�Ŭ������ �ν��Ͻ��� ����Ű�� ��.
	//Person p = Student(); //������ ��ĳ�����̱�� ������ c++������ ������ ���� �����θ� ����Ѵ�.
	//p.test(); //�׳� ���ϰ� ����.

	//Student s; //�ڽ�Ŭ���� s ����    (=int n;)
	//Person* p2 = &s; // ��ĳ����(�����޸�x)      (=int* p = &n;)
	//p2->test();           // => �θ� Ŭ����
	//Student s�� �ּҸ� ��� �ִ� Person p2
	//�����ʹ� �ּҸ� ��� ���� ������ �� ��ΰ� �����޸𸮴� �ƴϴ�.
	//p2�� �ּҸ� ��� ���� �� �����޸𸮴� �ƴϴ�.
	//delete p2; => ��Ÿ�� ���� �߻�
//*************��ĳ���� ����**********************************************
	//Person* p3 = new Student(); //�����޸� ���� ��ĳ����
	//new�� ���ԵǾ��� ������ �����޸𸮰� �ȴ�.
	//p3->test();// ���� :  �θ� Ŭ����
	//p3->test_stu(); //�Ұ��� :  �ڽ�Ŭ����
	//delete p3; //�����޸� ������ ������Ѵ�.

#include <iostream>

using namespace std;

class Calculator
{
protected:
	static double resultNum;
	double x = 0;
	double y = 0;
public:
	virtual void calculation() = 0;
	//���� �Լ� ���� : �ڽ�Ŭ������ ������(�������̵�) �� ���̶�� ����ϴ� �Լ�
	//���� ���ε��� ��Ÿ�Ӷ�  �ϱ� ����
	//�θ� Ŭ�������� ���� - > �ڽ�Ŭ�������� ������ �ϱ⶧���� �ڽĿ��� ���
	static double getResult()
	{
		return resultNum;
	}
};

class Plus : public Calculator
{
public:
	Plus(double x, double y) :Calculator()
	{
		this->x = x;
		this->y = y;
	}
	void calculation() //�ڽ�Ŭ������ ������(�������̵�)
	{
		resultNum = x + y;
		cout << "--------------------------------------------------" << endl;
		cout << "����� : " << this->resultNum << endl;
		cout << "--------------------------------------------------" << endl;
	}
};

class Minus : public Calculator
{
public:
	Minus(double x, double y) :Calculator()
	{
		this->x = x;
		this->y = y;
	}
	void calculation() //�ڽ�Ŭ������ ������(�������̵�)
	{
		resultNum = x - y;
		cout << "--------------------------------------------------" << endl;
		cout << "����� : " << this->resultNum << endl;
		cout << "--------------------------------------------------" << endl;
	}
};

class Multi : public Calculator
{
public:
	Multi(double x, double y) : Calculator()
	{
		this->x = x;
		this->y = y;
	}
	void calculation() //�ڽ�Ŭ������ ������(�������̵�)
	{
		resultNum = x * y;
		cout << "--------------------------------------------------" << endl;
		cout << "����� : " << this->resultNum << endl;
		cout << "--------------------------------------------------" << endl;
	}
};

class Division : public Calculator
{
public:
	Division(double x, double y) :Calculator()
	{
		this->x = x;
		this->y = y;
	}
	void calculation() //�ڽ�Ŭ������ ������(�������̵�)
	{
		resultNum = x / y;
		cout << "--------------------------------------------------" << endl;
		cout << "����� : " << this->resultNum << endl;
		cout << "--------------------------------------------------" << endl;
	}
};

double Calculator::resultNum = 0;

void function(double x, char oper, double y)
{
	Calculator* cal;
	switch (oper)
	{
	case '+':
	{
		cal = new Plus(x, y);
		break;
	}
	case '-':
	{
		cal = new Minus(x, y);
		break;
	}
	case '/':
	{
		cal = new Division(x, y);
		break;
	}
	case '*':
	{
		cal = new Multi(x, y);
		break;
	}
	default:
		cout << "������ ��Ȯ�� �Է����ּ���." << endl;
		break;
	}
	cal->calculation();
	delete cal;
}

int main()
{
	double x = 0, y = 0;

	cout << "�����ڸ� �Է��ϼ���   : ";
	cin >> x;
	while (1)
	{
		char operate;
		cout << "�������ڸ� �Է��ϼ��� : ";
		cin >> operate;
		cout << "�����ڸ� �Է��ϼ���   : ";
		cin >> y;
		function(x, operate, y);

		char continuePro;
		cout << "�������� ��� �����Ͻðڽ��ϱ�? (Y=���, I:�ʱ�ȭ,E:����) : ";
		cin >> continuePro;
		switch (continuePro)
		{
		case 'Y':
			x = Calculator::getResult();
			break;
		case 'I':
			x = 0;
			break;
		case 'E':
			return -1;
		}
	}

	return 0;
}