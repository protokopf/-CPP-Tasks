template<typename Type>
void MySwap(Type &a, Type &b)
{
	Type temp = a;
	a = b;
	b = temp;
}


template<typename Type>
void InsertSort(Type *arr, int size)
{
	for (int i = 0, j = 0; i < size; ++i)
	{
		Type temp = arr[i];
		for (j = i - 1; j >= 0 && arr[j] > temp; --j)
			arr[j + 1] = arr[j];
		arr[j + 1] = temp;
	}

}

template <typename Type>
void QuickSort(Type *arr, int left, int right)
{
	int begin = left;
	int end = right;

	Type average = arr[(left + right) >> 1];

	while (begin <= end)
	{
		while (arr[begin] < average)
			++begin;
		while (arr[end] > average)
			--end;
		if (begin <= end)
			MySwap(arr[begin++], arr[end--]);
	}
	if (left < end)
		QuickSort(arr,left, end);
	if (begin < right)
		QuickSort(arr,begin,right);

}


template<typename Type>
void v2QuickSort(Type *arr, int left, int right)
{
	int beg = left, end = right;
	Type av = arr[(beg + end) >> 1];
	while (end >= beg)
	{
		while (arr[beg] < av)
			++beg;
		while (arr[end] > av)
			--end;
		if (end >= beg)
			MySwap(arr[beg++], arr[end--]);
	}
	if (beg < right)
		v2QuickSort(arr, beg, right);
	if (end > left)
		v2QuickSort(arr, left, end);
}
