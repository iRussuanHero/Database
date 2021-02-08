#include <iostream>
using namespace std;
#define CALC
//#define CALC_IF
void main()
{
	setlocale(LC_ALL, "RUS");
	double a, b; //числа вводимые с клавиатуры
	char s; //Sign - знак операции
	cout << "¬ведите выражение: ";
	cin >> a >> s >> b;
	switch (s)
	{
	case '+': cout << a << "+" << b << "=" << a + b << endl; break;
	case '-': cout << a << "-" << b << "=" << a - b << endl; break;
	case '*': cout << a << "*" << b << "=" << a * b << endl; break;
	case '/': cout << a << "/" << b << "=" << a / b << endl; break;
	defult: cout << "Error: No operations!" << endl;
	}
#ifdef CALC_IF
	if (s == '+')
		cout << a << "+" << b << "=" << a + b << endl;
	else if (s == '-')
		cout << a << "-" << b << "=" << a - b << endl;
	else if (s == '*')
		cout << a << "*" << b << "=" << a * b << endl;
	else if (s == '/')
		cout << a << "/" << b << "=" << a / b << endl;
	else
		cout << "Error: No operations!" << endl;
#endif // CALC_IF
	main();
}