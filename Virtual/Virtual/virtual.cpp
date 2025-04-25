#include <iostream>

using namespace std;

// virtual 키워드 유무 차이 지워보면서 확인하기
// virtual 가상함수 
class Pet
{
public:
	Pet()
	{
		cout << "Pet 기본생성자" << endl;
	}

	virtual ~Pet()
	{
		cout << "Pet 소멸자" << endl;
	}

	virtual void Sound()
	{
		cout << "동물 소리" << endl;
	}

private:
	
};

class Dog : public Pet
{
public:
	Dog()
	{
		cout << "Dog 기본생성자" << endl;
	}

	~Dog()
	{
		cout << "Dog 소멸자" << endl;
	}

	void Sound()
	{
		cout << "멍멍" << endl;
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
	Pet* p = new Dog(); // 업캐스팅
	p->Sound();
	delete p;
}

