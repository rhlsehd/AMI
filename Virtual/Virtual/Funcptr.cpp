#include <iostream>

using namespace std;

// 함수포인터

void HelloWorld()
{
	cout << "Hello World" << endl;
}

void Hello()
{
	cout << "Hello" << endl;
}

void(*func)(void);

int(*func)(int);


//void(*func)(void);

int Square(int a) { return a * a; }

int A(int a) { return a - 10 / 2; }

int Add(int a);

int Max(int* arr, int size, int(*func)(int) )
{
	int max = arr[0];

	for (int i = 0; i < size; i++)
	{
		if (max < func(arr[i]))
			max = func(arr[i]);
	}

	return max;
}

int main()
{
	int a[5] = { 1,7,17,3,0 };

	cout << Max(a,5, Add) << endl;
}









