#include <iostream>

using namespace std;

// Singleton <- 디자인패턴중 하나
// -> Singleton으로 만든 클래스 객체는, 객체를 단 하나만 가질 수 있다.
// -> SoundManager, InputManager
// 
// -> 싱글톤 구조를 외워야함!
class Manager
{
public:
	static void Create()
	{
		if (_instance == nullptr) // 처음에 _instance를 nullptr 로 초기화, 한번 new Manager를 해주게 되면 더이상 nullptr이 아니기 떄문에 객체 생성이 안된다!
			_instance = new Manager();
	}

	static void Delete()
	{
		if (_instance != nullptr) // _instance가 객체화가 되어 있으면 delete가 가능하게 되는 구조!
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
	Manager::Create(); // _instance 라는 객체가 만들어짐!
	
	Manager::GetInstance()->Attack(); // _instance.Attack(); 이거랑 같은 말

	Manager::Delete(); // _instance 객체 삭제
}