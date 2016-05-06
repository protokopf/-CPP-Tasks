#pragma once
#include <iostream>
#include <fstream>
#include <string>

using namespace std;


#pragma region Задача 1

class FileSeeker
{
private:
	fstream *mThisFile = nullptr;
public:
	FileSeeker();
	FileSeeker(string pathToFile);
	~FileSeeker();

	void OutThisFile();
	void OutLastNStrings(unsigned int lastN);
	void SetFile(string filePath);
};

#pragma endregion

