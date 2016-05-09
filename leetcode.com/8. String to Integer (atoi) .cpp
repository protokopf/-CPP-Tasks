#include "8. String to Integer (atoi) .h"


StringToInteger::StringToInteger()
{
}
StringToInteger::~StringToInteger()
{
}

bool StringToInteger::checkOnInteger(const string &str)
{
	regex reg("^(-?(0|[1-9][0-9]*))$");
	return regex_match(str,reg);
}
