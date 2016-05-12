#include <iostream>
#include "BitOperations.h"

using namespace std;

int main()
{
	int value = 0;
	int bit = 0;

	while (true)
	{
		cout << "Enter value: ";
		cin >> value;
		cout << isValueDegreeOfTwo(value) << endl;

	}

	return 0;
}