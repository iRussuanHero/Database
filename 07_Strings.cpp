#include<iostream>
#include<Windows.h>
using namespace std;

void input_line(char str[], const int n);
void to_upper(char str[], const int n);
void to_lower(char str[], const int n);
bool is_number(char str[], const int n);
bool is_palindrome(char str[], const int n);
void shrink(char str[], const int n);
int str_len(char str[]);
bool is_bin(char str[]);
bool is_hex(char str[]);
//int to_int(char str[]);
int bin_to_dec(char str[]);
int hex_to_dec(char str[]);
bool is_mac(char str[]);
bool is_ip(char str[]);

int main()
{
	setlocale(LC_ALL, "Rus");
	const int n = 50;
	char str[n];
	int input;
	cout << "Введите строку: "; input_line(str, n);	cout << "Длинна строки: " << str_len(str) << " символа(ов). "; (is_number(str, n) == true) ? (cout << "Это число") : (cout << "Это не число"); (is_palindrome(str, n) == true) ? (cout << ", палиндром") : (cout << ", не палиндром"); (is_mac(str) == true) ? (cout << ", MAC-адрес") : (cout << ", не MAC-адрес"); (is_ip(str) == true) ? (cout << " и IP-адрес.") : (cout << " и не IP-адрес."); cout << endl;
	cout << "\n1. Перевод в верхний регистр: abc-ABC\n2. Перевод в нижний регистр: ABC-abc\n3. Удаление лишних пробелов: a  b   c-a b c\n4. Конвертация в другую СС: BIN или HEX в DEC" << endl;
	cout << endl << "Введите номер операции от 1 до 4: "; cin >> input; cout << endl;
	cout << "Результат: ";
	switch (input)
	{
	case 1: to_upper(str, n); cout << str << endl; break;
	case 2:	to_lower(str, n); cout << str << endl; break;
	case 3:	shrink(str, n); cout << str << endl; break;
	case 4: is_bin(str)==true ? cout << bin_to_dec(str) << endl: cout<< "не BIN, "; is_hex(str) == true ? cout << hex_to_dec(str) << endl : cout << "не HEX, "; break;
	default: cout << "Ошибка: введено неверное значение!!!" << endl;
	} 
}
void input_line(char str[], const int n)
{
	SetConsoleCP(1251);
	cin.getline(str, n);
	SetConsoleCP(866);
	cout << endl;
}
void to_upper(char str[], const int n)
{
	for (int i = 0; i < n; i++)
	{
if (str[i] >= 'a' && str[i] <= 'z')
{
	str[i] -= ' ';
}
if (str[i] >= -32 && str[i] <= -1)
{
	str[i] -= ' ';
}
	}
}
void to_lower(char str[], const int n)
{
	for (int i = 0; i < n; i++)
	{
		if (str[i] >= 'A' && str[i] <= 'Z')
		{
			str[i] += 32;
		}
		if (str[i] >= 'А' && str[i] <= 'Я')
		{
			str[i] += 32;
		}
	}
}
bool is_number(char str[], const int n)
{
	for (int i = 0; str[i]; i++)
	{
		if (str[i] < '0' || str[i] > '9')
		{
			return false;
		}
	}
	return true;
}
bool is_palindrome(char str[], const int n)
{
	to_lower(str, n);
	int y = str_len(str);
	for (int i = 0; i < str_len(str); i++)
	{
		if (str[i] == ' ')
		{
			for (int j = i; j < y; j++)
			{
				str[j] = str[j + 1];
			}
		}
	}
	y = str_len(str);
	for (int i = 0; i < str_len(str); i++)
	{
		if (str[i] != str[y - 1])
		{
			return false;
			break;
		}
		y--;
	}
	return true;
}
void shrink(char str[], const int n)
{
	int x = str_len(str);
	for (int k = 0; k < (x / 2); k++) // больше половины текса не может быть лишних пробелов
	{
		for (int i = 0; str[i]; i++)
		{
			if (str[i] == ' ') // находим пробел
			{
				if (str[i] == str[i + 1]) // если после пробела стоит следующий пробел
				{
					for (int j = i; j < x; j++) // смещение влево
					{
						str[j] = str[j + 1];
					}
				}
			}
		}
	}
}
int str_len(char str[])
{
	int i = 0;
	for (; str[i]; i++);
	{
		return i;
	}
}
bool is_bin(char str[])
{
	int count = 0;
	int y = str_len(str);
	for (int i = 0; i < y; i++)
	{
		if (str[i] == '0' || str[i] == '1')
		{
			count++;
		}
	}
	if (count == y)
	{
		return true;
	}
	return false;
}
bool is_hex(char str[])
{
	int count = 0;
	int y = str_len(str);
	for (int i = 0; i < y; i++)
	{
		if (str[i] >= '0' && str[i] <= '9') //проверка на допустимые знаки
		{
			if (str[i] >= 'A' && str[i] <= 'F') //проверка на допустимые знаки
			{
				count++;
			}
			if (str[i] >= 'a' && str[i] <= 'f') //проверка на допустимые знаки
			{
				count++;
			}
		}
	}
	if (count == y)
	{
		return true;
	}
	return false;
}
//int to_int(char str[])
int bin_to_dec(char str[])
{
	int buffer = 0, decimal = 0;
	int y = str_len(str);
	int x = y;
	for (int i = 0; i < y; i++)
	{
		buffer = str[i] - 48;
		for (int j = 1; j < x; j++)
		{
			buffer *= 2;
		}
		x--;
		decimal += buffer;
	}
	return decimal;
}
int hex_to_dec(char str[])
{
	int a = 97, b = 98, c = 99, d = 100, e = 101, f = 102;
	int buffer = 0, decimal = 0;
	int y = str_len(str);
	int x = y;
	for (int i = 0; i < y; i++)
	{

	}
}
bool is_mac(char str[])
{
	int y = str_len(str);
	if (y == 17) //проверка размера введённого значения
	{
		for (int i = 0; i < y; i++)
		{
			if (str[i] >= '0' && str[i] <= '9' || str[i] == ':' || str[i] == '-') //проверка на допустимые знаки
			{
				if (str[i] >= 'A' && str[i] <= 'F' || str[i] == ':' || str[i] == '-') //проверка на допустимые знаки
				{
					if (str[2] == ':' && str[5] == ':' && str[8] == ':' && str[11] == ':' && str[14] == ':') //проверка на положение знаков
					{
						return true;
					}
					if (str[2] == '-' && str[5] == '-' && str[8] == '-' && str[11] == '-' && str[14] == '-') //проверка на положение знаков
					{
						return true;
					}
				}
				if (str[i] >= 'a' && str[i] <= 'f' || str[i] == ':' || str[i] == '-') //проверка на допустимые знаки
				{
					if (str[2] == ':' && str[5] == ':' && str[8] == ':' && str[11] == ':' && str[14] == ':') //проверка на положение знаков
					{
						return true;
					}
					if (str[2] == '-' && str[5] == '-' && str[8] == '-' && str[11] == '-' && str[14] == '-') //проверка на положение знаков
					{
						return true;
					}
				}
			}
		}
	}
	return false;
}
bool is_ip(char str[])
{
	int y = str_len(str);
	if (y >= 7 && y <= 15) //проверка размера введённого значения
	{
		for (int i = 0; i < y; i++)
		{
			if (str[i] >= '0' && str[i] <= '9' || str[i] == '.') //проверка на допустимые знаки
			{
				return true;
			}
		}
	}
	return false;
}