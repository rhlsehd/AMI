#include <iostream>

using namespace std;


// static <- 정적변수
// 메모리 4영역/ code, data, stack, heap 
// code : 코드, data : 전역변수, 정적변수, stack : 매개변수, 지역변수, heap : 동적 할당 사용자 정의 변수 (new delete, malloc free)

class Minion
{
public:
	static int GetHP() // static 함수
	{
		return hp; // <- return atk; 로 바꿔보기  ->  atk는 static 변수가 아니기 때문에 오류 남. 즉. static 함수에는 static 변수만 들어올 수 있다!
	}

	static void SetHp(int a) { hp = a; } // static 함수

private:
	static int hp;
	int atk = 5;
};

int Minion::hp = 100; // static 변수의 초기화

int main() 
{
	Minion m1;
	Minion m2;
	Minion m3;

	m3.SetHp(10); // <-  이렇게 선언 해줘도 되지만 m1, m2, m3 셋중에 뭘로 함수를 호출할지에 대한 기준이 모호하다.

	Minion::SetHp(100);
}