#include<iostream>
int Add(int a, int b)
{
	int c = a + b;
	return c;
}
int Sub(int a, int b)
{
	return a - b;
}
using namespace std;
int main()
{
	setlocale(LC_ALL, "Rus");
	int a=2;
	int b=3;
	int sum = Add(a, b);
	cout << sum << endl;
	cout << Sub(a, b) << endl;
	return 0;
}