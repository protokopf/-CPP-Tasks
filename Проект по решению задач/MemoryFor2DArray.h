
char** My2DAlloc(int x, int y)
{
	char **memory = new char*[y];
	for (int i = 0; i < y; ++i)
		memory[i] = new char[x]{'x'};
	return memory;
}