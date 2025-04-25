#include <iostream>

using namespace std;


class Creature
{
public:
	Creature() : _name(""), _hp(0), _atk(0)
	{
	}

	Creature(string name, int hp, int atk) : _name(name), _hp(hp), _atk(atk)
	{

	}

	~Creature(){}

	void Attack(Creature* other)
	{

	}

	bool IsDead()
	{

	}
protected:
	string _name;
	int _hp;
	int _atk;
};

class Player : public Creature
{
public:
	Player() : Creature()
	{

	}

	Player(string name, int hp, int atk) : Creature(name, hp, atk)
	{

	}

	~Player(){}
		
};

class Monster : public Creature
{
public:
	Monster() : Creature()
	{

	}

	Monster(string name, int hp, int atk) : Creature(name, hp, atk)
	{

	}

	~Monster(){}

	bool monsterAllDead(Monster* monster[])
	{

	}
};
int main()
{
	Creature* player = new Player("Player", 100,10);
	Creature* monster[10];


	

	for (int i = 0; i < 10; i++)
	{
		monster[i] = new Monster("Monster", 10,9);
	}

	while (true)
	{
	
	}

	return 0;
}