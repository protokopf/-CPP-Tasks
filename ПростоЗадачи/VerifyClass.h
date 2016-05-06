#pragma once
#include <string>
#include <vector>
#include <initializer_list>
#include <algorithm>

using namespace std;

class StringVerifier
{
public:
	// structure, that contain pairs "open symbol - close symbol"
	struct SignPair
	{
		char openSign;
		char closeSign;
		bool operator==(const SignPair &p)
		{
			return (p.openSign == openSign) && (p.closeSign == closeSign);
		}
	};
private:
	// pairs storage
	vector<SignPair> *pairsShouldBeChecked;
	// counter, that checks equality of open and close symbols
	int counter = 0;
	// inner method, that is invoked recursively
	int verifyRecurs(string str, int pos, char founded);
	// inner method, thar returns appropriate close symbol (if user add appropriate pair)
	char getCloseSign(char sign);

	bool isMatchOpenSign(char ch);
	bool isMatchCloseSign(char ch);
public:
	// default constructor
	StringVerifier();
	// constructor, thar receives pairs
	StringVerifier(const initializer_list<SignPair> &list);
	// copy constructor
	StringVerifier(const StringVerifier& src);
	// moce constructor
	StringVerifier(StringVerifier &&src);
	// overloaded copy and move assignment operators
	StringVerifier& operator=(const StringVerifier& src);
	StringVerifier& operator=(StringVerifier &&src);
	// destructor
	~StringVerifier();

	// open funtional methods:
	bool verify(string str);

	// add new pair
	void addPair(char openSign, char closeSign);
	void addPair(SignPair pair);

	// remove pair
	void removePair(char openSign, char closeSign);
	void removePair(SignPair pair);
};
