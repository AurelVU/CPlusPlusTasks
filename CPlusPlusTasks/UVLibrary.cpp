#include "UVLibrary.h"
namespace uvlibrary {
	char* itoa(int value, char* buffer, int radix)
	{
		int size = 0;
		int currer_number = 1;
		while (currer_number < value && !(currer_number * radix > value)) // вычисление необходимой длины байт
		{
			size++;
			currer_number *= radix;
		}
		size++;
		
		for (int i = 0; i < size; i++, value /= radix) //вычисление остатков деления
			if (value % radix <= 9)
				buffer[size - i - 1] = (char)('0' + value % radix);
			else
				buffer[size - i - 1] = (char)('A' + value % radix - 10);
		buffer[size] = '\0';
		return buffer;
	}
}