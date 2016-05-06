#include "FileSeeker.h"
#include "NodeCopier.h"
#include "MySharedPtr.h"
#include "MemoryAllocation.h"
#include "MemoryFor2DArray.h"

using namespace std;
using NodeInt = Node < int > ;

int main()
{
	int x = 10;
	int y = 15;
	char** memory = My2DAlloc(x, y);
	for (int i = 0; i < y; ++i)
	{
		for (int j = 0; j < x; ++j)
			cout << memory[i][j];
		cout << endl;
	}
	return 0;
}