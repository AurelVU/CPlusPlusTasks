#include <iostream>
#include <stdlib.h>
#include "UVLibrary.h"


using namespace std;

int getValue() 
{
	int value;

	while (!(cin >> value))
	{
		cout << "Неверный формат числа. Повторите ввод\n";
		cin.clear();                                        //сбрасываем ошибку
		cin.ignore(numeric_limits<streamsize>::max(), '\n'); //удаляем все из буфера до перевода строки
		cout << "Введите исходное число: ";
	}

	return value;
}

void main(int argc, char** argv)
{
	setlocale(LC_ALL, "Russian");

	int value = 0;
	int radix = 0;
	char* str = NULL;
	
	cout << "Введите исходное число: ";

	value = getValue();

	cout << "Введите основание системы счисления: ";
	
	radix = getValue();
	while (radix < 2 || radix > 36) 
	{
		cout << "Неверный диапазон системы счисления. Повторите ввод\n";
		radix = getValue();
	}

	char* buffer = new char[100];
	buffer = uvlibrary::itoa(value, buffer, radix);

	printf("Результирующая строка: %s\n", buffer);
}