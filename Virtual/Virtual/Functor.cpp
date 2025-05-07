#include <iostream>

using namespace std;


void HelloWorld()
{
	cout << "Hello World" << endl;
}

void Hello()
{
	cout << "Hello" << endl;
}


class Square
{
public:
	int operator()(int a)
	{
		return a / a;
	}
};


class A
{
public:
	int operator()(int a)
	{
		return a * a;
	}
};



template<typename T>
int Print(T func, int a)
{
	return func(a);
}


void(*f)(void);
int(*func)(int);


class Myfunc
{
public:

	void operator()()
	{
		cout << num << endl;
		cout << "Myfunc" << endl;
	}

	int num;
};

int main()
{

}