#include "FileSeeker.h"


		FileSeeker::FileSeeker()
{
}
		FileSeeker::FileSeeker(string pathToFile) : FileSeeker()
{
	mThisFile = new fstream(pathToFile, ios_base::in);
}

void	FileSeeker::OutLastNStrings(unsigned int n)
{
	int countString = 0;
	char* buffer = new char[_MAX_PATH];
	while (!mThisFile->eof())
	{
		mThisFile->getline(buffer, _MAX_PATH);
		++countString;
	}
	int fromPosition = countString - n;
	countString = 0;
	mThisFile->seekg(SEEK_SET);
	while (!mThisFile->eof())
	{
		mThisFile->getline(buffer, _MAX_PATH);
		++countString;
		if (countString > fromPosition)
			cout << buffer << endl;
	}
	delete[] buffer;
}

void	FileSeeker::SetFile(string pathToFile)
{
	if (mThisFile == nullptr)
		mThisFile = new fstream();
	if (mThisFile->is_open())
		mThisFile->close();
	mThisFile->open(pathToFile, ios_base::in);
}


		FileSeeker::~FileSeeker()
{
	mThisFile->close();
	delete mThisFile;
}
