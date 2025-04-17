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

class Func
{
public:
	Func() {}
	int operator()(int a)
	{
		int res;
		res = a * a;
		return res;
	}
private:
	int num;
};
int Square(int a) { return a * a; }
int A(int a) { return a - 10 / 2; }

int Max(int* arr, int size, int(*func)(int))
{
	int max = func(arr[0]);

	for (int i = 0; i < size; i++)
	{
		if (max < func(arr[i]))
			max = func(arr[i]);
	}

	return max;
}


void(*f)(void);
int(*func)(int);

int main()
{
	Func f;
	Max
	
}