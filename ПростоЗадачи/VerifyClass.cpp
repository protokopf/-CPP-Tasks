#include "VerifyClass.h"


				StringVerifier::StringVerifier()
{
	pairsShouldBeChecked = new vector<SignPair>();
}

				StringVerifier::StringVerifier(const initializer_list<SignPair> &list) : StringVerifier()
{
	for (const auto &pair : list)
		pairsShouldBeChecked->push_back(pair);
}

				StringVerifier::StringVerifier(const StringVerifier& src)
{
	pairsShouldBeChecked = new vector<SignPair>(*(src.pairsShouldBeChecked));
}
				StringVerifier::StringVerifier(StringVerifier &&src)
{
	pairsShouldBeChecked = src.pairsShouldBeChecked;
	src.pairsShouldBeChecked = nullptr;
}

StringVerifier& StringVerifier::operator=(const StringVerifier& src)
{
	delete pairsShouldBeChecked;
	pairsShouldBeChecked = new vector<SignPair>(*(src.pairsShouldBeChecked));
	return *this;
}
StringVerifier& StringVerifier::operator=(StringVerifier &&src)
{
	pairsShouldBeChecked = src.pairsShouldBeChecked;
	src.pairsShouldBeChecked = nullptr;
	return *this;
}

				StringVerifier::~StringVerifier()
{
	delete pairsShouldBeChecked;
}

int				StringVerifier::verifyRecurs(string str, int pos, char founded)
{
	int result = pos;

	for (; result < str.size(); ++result)
	{
		if (isMatchOpenSign(str[result]))
		{
			++counter;
			if (!(result = verifyRecurs(str, result + 1, getCloseSign(str[result]))))
				return 0;
		}
		else if (isMatchCloseSign(str[result]))
		{
			--counter;
			return founded == str[result] ? result : 0;
		}
	}
	return (counter == 0);
}
char			StringVerifier::getCloseSign(char ch)
{
	// looking for pair, that includes open symbol from param
	auto foundIt = find_if(pairsShouldBeChecked->begin(), pairsShouldBeChecked->end(),
		[&ch](const SignPair& pair) { return pair.openSign == ch; });
	// checking, if symbol has been found
	if (foundIt != pairsShouldBeChecked->end())
		return (*foundIt).closeSign;
	else
		return 0;
}

bool			StringVerifier::isMatchOpenSign(char ch)
{
	auto it = find_if(pairsShouldBeChecked->begin(), pairsShouldBeChecked->end(),
		[&ch](const SignPair& pair) { return pair.openSign == ch; });
	return it != pairsShouldBeChecked->end();
}
bool			StringVerifier::isMatchCloseSign(char ch)
{
	auto it = find_if(pairsShouldBeChecked->begin(), pairsShouldBeChecked->end(),
		[&ch](const SignPair& pair) { return pair.closeSign == ch; });
	return it != pairsShouldBeChecked->end();
}

bool			StringVerifier::verify(string str)
{
	bool result = verifyRecurs(str, 0, 0);
	counter = 0;
	return result;
}

void			StringVerifier::addPair(char openSign, char closeSign)
{
	SignPair p{ openSign, closeSign };
	pairsShouldBeChecked->push_back(p);
}
void			StringVerifier::addPair(SignPair pair)
{
	pairsShouldBeChecked->push_back(pair);
}

void			StringVerifier::removePair(char openSign, char closeSign)
{
	SignPair p{ openSign, closeSign };
	remove_if(pairsShouldBeChecked->begin(), pairsShouldBeChecked->end(),
		[&p](SignPair pair){return pair == p; });
}
void			StringVerifier::removePair(SignPair pair)
{
	remove_if(pairsShouldBeChecked->begin(), pairsShouldBeChecked->end(),
		[&pair](SignPair p){return pair == p; });
}
