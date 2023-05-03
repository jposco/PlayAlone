

//--------------포인터 변수 선언과 출력 복습하기--------------------------------------------------------
//포인터 : 메모리의 주소를 가진 변수
//포인터 변수는 * 을 이용하여 선언
//int* p; //포인터 변수 선언
//int n = 10;
//p = &n; // 포인터 변수 p에 n의 메모리 주소(&n)를 저장함
//결국 int* p = &n -> '10'이 출력된다.
//그렇지만 int* p = n -> 215326이 출력된다 (메모리 주소) 

//--------------동적 배열 선언과 할당 복습하기------------------------------------------------
//동적 배열을 만들기 위해선 '포인터 변수'와 'new' 키워드 사용
//int n2;
//cout << "숫자를 입력하세요: ";
//cin >> n2;
//int* arr = new int[n2] //n2에 동적 배열을 넣는다.
// 1. 동적 메모리를 가리키는 포인터 선언
// 2. new라는 키워드를 사용하여, 동적 배열 할당.
//delete[] arr; 동적 배열을 반납해야한다.

//------------업캐스팅-------------------------------------------------
//업캐스팅 : 부모클래스의 포인터Person*로 자식클래스의 인스턴스를 가리키는 것.
	//Person p = Student(); //일종의 업캐스팅이기는 하지만 c++에서는 다형성 실현 정도로만 취급한다.
	//p.test(); //그냥 편하게 잊자.

	//Student s; //자식클래스 s 선언    (=int n;)
	//Person* p2 = &s; // 업캐스팅(동적메모리x)      (=int* p = &n;)
	//p2->test();           // => 부모 클래스
	//Student s의 주소를 담고 있는 Person p2
	//포인터는 주소를 담기 위해 존재할 뿐 모두가 동적메모리는 아니다.
	//p2는 주소를 담고 있을 뿐 동적메모리는 아니다.
	//delete p2; => 업타임 오류 발생
//*************업캐스팅 문법**********************************************
	//Person* p3 = new Student(); //동적메모리 선언 업캐스팅
	//new가 포함되었기 때문에 동적메모리가 된다.
	//p3->test();// 가능 :  부모 클래스
	//p3->test_stu(); //불가능 :  자식클래스
	//delete p3; //동적메모리 해제를 해줘야한다.

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
	//가상 함수 선언 : 자식클래스가 재정의(오버라이딩) 할 것이라고 기대하는 함수
	//동적 바인딩을 런타임때  하기 위해
	//부모 클래스에서 정의 - > 자식클래스에서 재정의 하기때문에 자식에서 출력
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
	void calculation() //자식클래스가 재정의(오버라이딩)
	{
		resultNum = x + y;
		cout << "--------------------------------------------------" << endl;
		cout << "▶결과 : " << this->resultNum << endl;
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
	void calculation() //자식클래스가 재정의(오버라이딩)
	{
		resultNum = x - y;
		cout << "--------------------------------------------------" << endl;
		cout << "▶결과 : " << this->resultNum << endl;
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
	void calculation() //자식클래스가 재정의(오버라이딩)
	{
		resultNum = x * y;
		cout << "--------------------------------------------------" << endl;
		cout << "▶결과 : " << this->resultNum << endl;
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
	void calculation() //자식클래스가 재정의(오버라이딩)
	{
		resultNum = x / y;
		cout << "--------------------------------------------------" << endl;
		cout << "▶결과 : " << this->resultNum << endl;
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
		cout << "▶식을 정확히 입력해주세요." << endl;
		break;
	}
	cal->calculation();
	delete cal;
}

int main()
{
	double x = 0, y = 0;

	cout << "▶숫자를 입력하세요   : ";
	cin >> x;
	while (1)
	{
		char operate;
		cout << "▶연산자를 입력하세요 : ";
		cin >> operate;
		cout << "▶숫자를 입력하세요   : ";
		cin >> y;
		function(x, operate, y);

		char continuePro;
		cout << "▶연산을 계속 진행하시겠습니까? (Y=계속, I:초기화,E:종료) : ";
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