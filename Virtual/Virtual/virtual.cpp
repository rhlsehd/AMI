#include <iostream>

using namespace std;

// virtual Ű���� ���� ���� �������鼭 Ȯ���ϱ�
// virtual �����Լ� 
class Pet
{
public:
	Pet()
	{
		cout << "Pet �⺻������" << endl;
	}

	virtual ~Pet()
	{
		cout << "Pet �Ҹ���" << endl;
	}

	virtual void Sound()
	{
		cout << "���� �Ҹ�" << endl;
	}

private:
	
};

class Dog : public Pet
{
public:
	Dog()
	{
		cout << "Dog �⺻������" << endl;
	}

	~Dog()
	{
		cout << "Dog �Ҹ���" << endl;
	}

	void Sound()
	{
		cout << "�۸�" << endl;
	}
};


class Player
{
public:
	void SetHp(int a)
	{
		hp = a;
		atk = a;
	}


	 
private:
	int hp;
	int atk;
};

int main()
{
	Pet* p = new Dog(); // ��ĳ����
	p->Sound();
	delete p;
}

