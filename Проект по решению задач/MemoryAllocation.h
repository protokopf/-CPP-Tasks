// Написать функцию динамического распределения памяти, которая работает с адреса, которые кратны степеням двойки
#include <cmath>
#include <iostream>
using namespace std;


void* alignedMalloc(int numberOfBytes, int numberAliqoutToTwo)
{
	double degree = log2(numberAliqoutToTwo);
	if ((degree - (int)degree) != 0)
		return nullptr;
	void* memory = nullptr;
	while (true)
	{
		memory = new char[numberOfBytes];
		if ((int)memory % numberAliqoutToTwo == 0)
			return memory;
		delete[] memory;
	}
	return nullptr;
}
void* alignedFree(void* memory)
{
	delete memory;
	return nullptr;
}