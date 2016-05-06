#include <iostream>
#include "VerifyClass.h"
#include "VerifyMethod.h"

using namespace std;

int main()
{
	// 1. Work with function

	cout << "Checking with method: " << endl;
	cout << "Enter string(\"exit\" for exit): " << endl;

	string currString;

	while (true)
	{
		cin >> currString;
		if (currString == "exit")
			break;
		cout << (verify(currString) ? "true" : "false") << endl;
	}

	// 2. Work with object
	system("cls");
	cout << "Checking with class: " << endl;
	cout << "Enter string(\"exit\" for exit): " << endl;

	// creating object-verifier
	StringVerifier verifier;
	// adding some symbols pairs
	verifier.addPair({ '(', ')' });
	verifier.addPair({ '[', ']' });
	verifier.addPair('<', '>');
	verifier.addPair('{', '}');

	while (true)
	{
		// string typing
		cin >> currString;
		if (currString == "exit")
			break;
		// string cheking
		cout << (verifier.verify(currString) ? "true" : "false") << endl;
	}

	// removing some pairs
	verifier.removePair('<', '>');
	verifier.removePair('{', '}');

	return 0;
}