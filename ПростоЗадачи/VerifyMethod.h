#include <string>
#include <vector>
#include <initializer_list>
#include <algorithm>

using namespace std;
// function, that return appropriate close symbol from pair,
// that should be defined before runtime
char getCloseSign(char ch)
{
	switch (ch)
	{
	case '(':
		return ')';
	case '[':
		return ']';
	case '<':
		return '>';
	default:
		return 0;
	}
};
// function checks, if string has been constructed in right way
int	 verify(string str, int pos = 0, char founded = 0)
{
	static int counter = 0;
	int result = pos;

	for (; result < str.size(); ++result)
	{
		if (str[result] == '(' || str[result] == '[' || str[result] == '<')
		{
			++counter;
			if (!(result = verify(str, result + 1, getCloseSign(str[result]))))
				return (counter = 0);
		}
		else if (str[result] == ')' || str[result] == ']' || str[result] == '>')
		{
			--counter;
			return (founded == str[result]) ? result : (counter = 0);
		}
	}
	bool isLoopClosed = counter == 0;
	counter = 0;
	return 	isLoopClosed;
}


