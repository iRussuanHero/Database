#include<iostream>
using namespace std;

//#define START
//#define POINTER_ARIFMETICS
void main()
{
#ifdef START
	setlocale(LC_ALL, "Rus");
	int a = 2;	//���������� ����������
	int* pa = &a;	//Pointer to 'a'
	//& - �������� ������ ������
	cout << a << endl;	//����� ���������� "�" �� �����
	cout << &a << endl;	//��������� ������ ���������� "�" ��� ������
	cout << pa << endl;	//����� ������ ���������� "�", ������������ � ��������� "pa"
	cout << *pa << endl;//������������� ��������� "��" � ��������� �������� �� ������ � ���� ���������. 
	//* - ������� ������������� (Dereference operator)


	///////////////////////////////////////
	int* pointer;
	int b = 3;
	pointer = &b;
#endif // START

#ifdef POINTER_ARIFMETICS
	const int n = 5;
	int arr[n] = { 3, 5, 8, 13, 21 };
	using std::cin;
	using std::cout;
	using std::endl;
	cout << arr << endl;
	cout << *arr << endl;
	for (int i = 0; i < n; i++)
	{
		cout << arr + i << "\t";
	}
	cout << endl;
	for (int i = 0; i < n; i++)
	{
		cout << *(arr + i) << "\t";
	}
	cout << endl;
#endif // POINTER_ARIFMETICS

	using std::cin;
	using std::cout;
	using std::endl;
	int a = 2;
	int& ra = a;
	ra += 3;
	cout << a << endl;
	cout << ra << endl;
}