

template<typename Type>
class MySharedPtr
{
private:
	int *counter = nullptr;
	Type* innerData = nullptr;

	void ClearSources()
	{
		delete counter;
		delete innerData;
		counter = nullptr;
		innerData = nullptr;
	}
public:
	MySharedPtr() {}
	MySharedPtr(Type* data);

	MySharedPtr(const MySharedPtr &src);

	MySharedPtr& operator=(const MySharedPtr &src);
	Type&		 operator*()
	{
		return *innerData;
	}

	~MySharedPtr();
};

template <typename Type>
MySharedPtr<Type>::MySharedPtr(Type* data)
{
	innerData = data;
	*(counter = new int) = 1;
}

template <typename Type>
MySharedPtr<Type>::MySharedPtr(const MySharedPtr &src)
{
	innerData = src.innerData;
	++(*(counter = src.counter));
}
template<typename Type>
MySharedPtr<Type>& MySharedPtr<Type>::operator=(const MySharedPtr &src)
{
	if (src.innerData == innerData)
		return this;
	if (--(*counter) == 0)
		ClearSources();
	innerData = src.innerData;
	++(*(counter = src.counter))
}

template<typename Type>
MySharedPtr<Type>::~MySharedPtr()
{
	if (--(*(counter)) == 0)
		ClearSources();
}