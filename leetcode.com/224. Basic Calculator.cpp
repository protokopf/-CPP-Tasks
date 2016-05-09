#include "224. Basic Calculator.h"

void Solution::cutSpaces(string &str)
{
	for (auto it = str.begin(); it != str.end(); ++it)
		if ((*it) == ' ' || (*it) == '\t')
		{
			(it = str.erase(it));
			if (it != str.begin())
				--it;
		}
}
int	 Solution::pullNumber(const string &str, int &index)
{
	string number;
	while (true)
	{
		if (str[index] >= '0' && str[index] <= '9')
			number.push_back(str[index++]);
		else
			break;
	}
	--index;
	return atoi(number.c_str());
}

int	 Solution::recursiveCalculation(const string &str, int& pos)
{
	int result = 0;
	for (; pos < str.size(); ++pos)
	{
		switch (str[pos])
		{
		case '+':
			result += recursiveCalculation(str, (++pos));
			break;
		case '-':
			result -= recursiveCalculation(str, (++pos));
			break;
		case '(':
			continue;
			break;
		case ')':
			return result;
			break;
		default:
			result += pullNumber(str, pos);
			break;
		}
	}
	return result;
}