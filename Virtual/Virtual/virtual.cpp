#include <iostream>

using namespace std;

// virtual Ű���� ���� ���� �������鼭 Ȯ���ϱ�
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

int main()
{
	Pet* p = new Dog();
	p->Sound();
	delete p;
}

