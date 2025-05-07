#include <iostream>

using namespace std;


template<typename T>
T Add(T a, T b)
{
	return a + b;
}



int main()
{
	cout << Add(1, 2) << endl;
	cout << Add(1.1f, 2.2f);
}