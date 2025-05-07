#include <iostream>

using namespace std;



// Abstract <- 순수가상함수
// 
// 순수가상함수를 하나라도 포함하고 있으면 객체 생성이 안됨!!

class Champion // <- 추상 클래스
{
public:
	Champion() {}
	~Champion() {}

	virtual void Introduce() = 0;
protected: 
	int hp;
	int atk;
};

class Player : public Champion
{
public:
	Player(){}
	~Player() {}

	void Introduce() override { cout << "Player" << endl; }
private:

};

int main()
{
	Player Ash;
}