#ifndef BC_224
#define BC_224
/*Implement a basic calculator to evaluate a simple expression string.

The expression string may contain open ( and closing parentheses ), the plus + or minus sign -, non-negative integers and empty spaces .

You may assume that the given expression is always valid.

Some examples:
"1 + 1" = 2
" 2-1 + 2 " = 3
"(1+(4+5+2)-3)+(6+8)" = 23
Note: Do not use the eval built-in library function.*/

#include <iostream>
#include <string>
#include <Windows.h>

using namespace std;


class Solution {

private:
	void cutSpaces(string &str);
	int pullNumber(const string &str, int& index);
	int recursiveCalculation(const string &str, int& pos);
public:
	int calculate(string s) 
	{
		cutSpaces(s);
		int index = 0;
		return recursiveCalculation(s, index);
	}
};

#endif