#include <iostream>

using namespace std;


// static <- ��������
// �޸� 4����/ code, data, stack, heap 
// code : �ڵ�, data : ��������, ��������, stack : �Ű�����, ��������, heap : ���� �Ҵ� ����� ���� ���� (new delete, malloc free)

class Minion
{
public:
	static int GetHP() // static �Լ�
	{
		return hp; // <- return atk; �� �ٲ㺸��  ->  atk�� static ������ �ƴϱ� ������ ���� ��. ��. static �Լ����� static ������ ���� �� �ִ�!
	}

	static void SetHp(int a) { hp = a; } // static �Լ�

private:
	static int hp;
	int atk = 5;
};

int Minion::hp = 100; // static ������ �ʱ�ȭ

int main() 
{
	Minion m1;
	Minion m2;
	Minion m3;

	m3.SetHp(10); // <-  �̷��� ���� ���൵ ������ m1, m2, m3 ���߿� ���� �Լ��� ȣ�������� ���� ������ ��ȣ�ϴ�.

	Minion::SetHp(100);
}