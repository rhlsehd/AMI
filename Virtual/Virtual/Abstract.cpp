#include <iostream>

using namespace std;



// Abstract <- ���������Լ�
// 
// ���������Լ��� �ϳ��� �����ϰ� ������ ��ü ������ �ȵ�!!

class Champion // <- �߻� Ŭ����
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