#ifndef STI_8
#define STI_8

#include <string>
#include <regex>
#include <iostream>
#include <cmath>

using namespace std;
class StringToInteger
{
private:
	bool checkOnInteger(const string &str);
public:
	StringToInteger();
	~StringToInteger();

	int myAtoi(string str) 
	{
		if (!checkOnInteger(str))
			return 0;
		int number = 0;
		int multiplier = 0;
		int stringSize = str.size();
		while (multiplier != stringSize)
		{
			if ((str[stringSize - 1 - multiplier] == '-'))
				return (number *= (-1));
			number += ((str[stringSize - 1 - multiplier] - 48)*pow(10, multiplier));
			++multiplier;
		}
		return number;
	}
};
#endif

