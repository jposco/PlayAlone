#include <iostream>
using namespace std;

class Job
{
protected:
	static int offensive_power; //���ݷ�
	static int full_HP; //�ִ�ü�� (�������)
public:
	Job(int offensive_power, int full_HP)
	{
		this->offensive_power = offensive_power;
		this->full_HP = full_HP;
	}
	virtual void print() = 0;
	static int getOffensive_power()
	{
		return offensive_power;
	}
	static int getFull_HP()
	{
		return full_HP;
	}
};

class Gunner : public Job //���⺰ ���ݷ� �� ü�� �����ϱ�
{
	int offensive_power = 30;
	int full_HP = 100;

public:
	Gunner() :Job(30, 100)
	{
		this->offensive_power = offensive_power;
		this->full_HP = full_HP;
	}
	void print()
	{
		cout << "--------------------------------------------------" << endl;
		cout << "���ųʷ� �����ϼ̽��ϴ�." << endl;
		cout << "������ : ������, ���ݷ� : 30, ü�� : 100" << endl;
		cout << "--------------------------------------------------" << endl;
	}
};

class Gladiator : public Job //���⺰ ���ݷ� �� ü�� �����ϱ�
{
	int offensive_power = 20;
	int full_HP = 150;

public:
	Gladiator() :Job(20, 150)
	{
		this->offensive_power = offensive_power;
		this->full_HP = full_HP;
	}
	void print()
	{
		cout << "--------------------------------------------------" << endl;
		cout << "���˻�� �����ϼ̽��ϴ�." << endl;
		cout << "������ : ��, ���ݷ� : 20, ü�� : 150" << endl;
		cout << "--------------------------------------------------" << endl;
	}
};
class Wizard : public Job //���⺰ ���ݷ� �� ü�� �����ϱ�
{
	int offensive_power = 50;
	int full_HP = 50;

public:
	Wizard() :Job(50, 50)
	{
		this->offensive_power = offensive_power;
		this->full_HP = full_HP;
	}
	void print()
	{
		cout << "--------------------------------------------------" << endl;
		cout << "��������� �����ϼ̽��ϴ�." << endl;
		cout << "������ : ������, ���ݷ� : 50, ü�� : 50" << endl;
		cout << "--------------------------------------------------" << endl;
	}
};

class Character
{
protected:
	string name;
	int level = 1;
	int monster_HP = 50;
	int exp = 0;
	int offensive_power = 0;
	int full_HP = 0;
	int current_HP = 0;

public:
	Character(string name)
	{
		this->name = name;
		this->offensive_power = Job::getOffensive_power();
		this->full_HP = Job::getFull_HP();
		this->current_HP = Job::getFull_HP();
	}
	void attack()
	{
		cout << "�����͸� �����߽��ϴ�. (���ݷ� : " << offensive_power << ")" << endl;
		monster_HP -= offensive_power;
		if (monster_HP <= 0)
		{
			exp += 100;
			cout << "������ óġ!! (Exp : " << exp << "/200)" << endl;
			if (exp >= 200)
			{
				level_up();
				cout << "������ ��! (���� ���� : " << level << " )" << endl;
				exp = 0;
			}
		}
		else
		{
			cout << "������ ü�� (" << monster_HP << "/50)" << endl;
			current_HP -= 10;
			cout << "�����Ϳ��� ���� ���߽��ϴ�. (HP:" << current_HP << "/" << full_HP << ")" << endl;
		}
	}
	void HP_potion()
	{
		if (current_HP == full_HP) { cout << "��ü���� �� á���ϴ�." << endl; }
		else if (current_HP > full_HP - 20)
		{
			current_HP = full_HP;// +20���� ���� +10�� ȸ���� �� �ֵ���,
			cout << "��HP�� ȸ���Ǿ����ϴ�. (���� HP : " << current_HP << ")" << endl;
		}
		else
		{
			current_HP += 20;
			cout << "��HP�� ȸ���Ǿ����ϴ�. (���� HP : " << current_HP << ")" << endl;
		}
	}
	void setName(string name) //setter�� �̿��� �̸� �����ϱ�
	{
		this->name = name;
		cout << "�����谡 �̸��� " << this->name << "(��)�� ����Ǿ����ϴ�." << endl;
	}
	void level_up()
	{
		level++;
		cout << "��Level Up!! -> ���ݷ� +10 (���� : " << level << ")" << endl;
		offensive_power += 10;
		exp = 0;//����ġ �ʱ�ȭ
	}
	void information()
	{
		cout << "�̸� : " << name << endl;
		cout << "���� : " << level << endl;
		cout << "���ݷ� : " << offensive_power << endl;
		cout << "ü�� : " << current_HP << endl;
		cout << "����ġ : " << exp << endl;
	}
};

int Job::offensive_power = 0;
int Job::full_HP = 0;

void creatJob(int job, string name)
{

	switch (job)
	{
	case 1:
	{
		Job* j1 = new Gunner();
		j1->print();
		delete j1;
		break;
	}
	case 2:
	{
		Job* j2 = new Gladiator();
		j2->print();
		delete j2;
		break;
	}
	case 3:
	{
		Job* j3 = new Wizard();
		j3->print();
		delete j3;
		break;
	}
	}
}

int main()
{
	string name;
	int job;

	while (1)
	{
		cout << "*******************************************" << endl;
		cout << "Q. ���谡�� �̸��� �Է����ּ��� : ";
		cin >> name;
		cout << endl << "��1. �ų� (���ݷ� : 30, ü�� : 100)" << endl;
		cout << "��2. �˻� (���ݷ� : 20, ü�� : 150)" << endl;
		cout << "��3. ������ (���ݷ� : 50, ü�� : 50)" << endl;
		cout << "��0 : ��������" << endl;
		cout << "Q. ������ �������ּ���.";
		while (1)
		{
			cin >> job;
			if (job > 0 && job < 4)
			{
				system("cls"); // �ܼ� â clear
				creatJob(job, name);
				break;
			}
			cout << "1 - 3 �߿� �������ּ���.";
		}

		cout << "*******************************************" << endl;
		cout << endl << "< ���� ������ ����ּ���. >" << endl;
		cout << "��1. Rename" << endl;
		cout << "��2. Attacking a Monster" << endl;
		cout << "��3. Level up" << endl;
		cout << "��4. HP Recovery" << endl;
		cout << "��5. Information" << endl << endl;
		Character c(name);
		while (1)
		{
			int motion_in;
			cout << "Q. � ������ �����Ͻðڽ��ϱ�? (0:����) : ";
			cin >> motion_in;
			switch (motion_in)
			{
			case 0:
				cout << "����������" << endl;
				return 0;
			case 1:
				cout << "Q. ���ο� ���谡�� �г����� �Է����ּ��� : ";
				cin >> name;
				c.setName(name);
				break;
			case 2:
				c.attack();
				break;
			case 3:
				c.level_up();
				break;
			case 4:
				c.HP_potion();
				break;
			case 5:
				c.information();
				break;
			default:
				cout << "��0~4 �߿��� ����ּ���. " << endl;
			}
		}
	}
}