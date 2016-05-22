#include <iostream>
#include "sort algorythms.h"

using namespace std;

int main()
{
	int arr[] = { 1, 5, 6, 7, 9, 2, 3, 10, 4, 23,15};

	//quickSort(arr,0, 10);
	v2QuickSort(arr, 0,10);

	for (int i = 0; i < 11; ++i)
		cout << arr[i] << " ";
	cout << endl;

	return 0;
}