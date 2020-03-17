#include <iostream>
#include <stdlib.h>
#include "UVLibrary.h"


using namespace std;

int getValue() 
{
	int value;

	while (!(cin >> value))
	{
		cout << "�������� ������ �����. ��������� ����\n";
		cin.clear();                                        //���������� ������
		cin.ignore(numeric_limits<streamsize>::max(), '\n'); //������� ��� �� ������ �� �������� ������
		cout << "������� �������� �����: ";
	}

	return value;
}

void main(int argc, char** argv)
{
	setlocale(LC_ALL, "Russian");

	int value = 0;
	int radix = 0;
	char* str = NULL;
	
	cout << "������� �������� �����: ";

	value = getValue();

	cout << "������� ��������� ������� ���������: ";
	
	radix = getValue();
	while (radix < 2 || radix > 36) 
	{
		cout << "�������� �������� ������� ���������. ��������� ����\n";
		radix = getValue();
	}

	char* buffer = new char[100];
	buffer = uvlibrary::itoa(value, buffer, radix);

	printf("�������������� ������: %s\n", buffer);
}