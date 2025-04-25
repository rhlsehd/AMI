#include <iostream>

using namespace std;

// Singleton <- ������������ �ϳ�
// -> Singleton���� ���� Ŭ���� ��ü��, ��ü�� �� �ϳ��� ���� �� �ִ�.
// -> SoundManager, InputManager
// 
// -> �̱��� ������ �ܿ�����!
class Manager
{
public:
	static void Create()
	{
		if (_instance == nullptr) // ó���� _instance�� nullptr �� �ʱ�ȭ, �ѹ� new Manager�� ���ְ� �Ǹ� ���̻� nullptr�� �ƴϱ� ������ ��ü ������ �ȵȴ�!
			_instance = new Manager();
	}

	static void Delete()
	{
		if (_instance != nullptr) // _instance�� ��üȭ�� �Ǿ� ������ delete�� �����ϰ� �Ǵ� ����!
			delete _instance;
	}

	static Manager* GetInstance() { return _instance; }

	void Attack()
	{
		cout << "attack" << endl;
	}

private:
	Manager();
	~Manager();

	static Manager* _instance;
};

Manager* Manager::_instance = nullptr;

int main()
{
	Manager::Create(); // _instance ��� ��ü�� �������!
	
	Manager::GetInstance()->Attack(); // _instance.Attack(); �̰Ŷ� ���� ��

	Manager::Delete(); // _instance ��ü ����
}