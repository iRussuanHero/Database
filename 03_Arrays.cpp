#include<iostream>
using namespace std;
int main()
{
	setlocale(LC_ALL, "Rus");
	const int SIZE = 5; //������ �������
	int arr[SIZE]{ 3, 5, 8 }; //������
	cout << "������� �������� ��������� �������: " << endl;
	for (int i = 0; i < SIZE; i++)
	{
		cin >> arr[i];
	}
	for (int i = 0; i < SIZE; i++)
	{
		cout << arr[i] << "\t";
	}
	cout << endl;
	for (int i = SIZE - 1; 0 <= i; i--)
	{
		cout << arr[i] << "\t";
	}
	cout << endl;
	int sum = 0;
	for (int i = 0; i < SIZE; i++)
	{
		sum = sum + arr[i];
	}
	double avg = (double)sum / (double)SIZE;
	cout << "����� ��������� �������� " << sum << endl;
	cout << "������� �������������� ��������� �������: " << avg << endl;
	int min, max;
	min = max = arr[0];
	for (int i = 0; i < SIZE; i++)
	{
		if (arr[i] < min)min = arr[i];
		if (arr[i] > max)max = arr[i];
	}
	cout << "����������� �������� � �������: " << min << endl;
	cout << "������������ �������� � �������: " << max << endl;
}