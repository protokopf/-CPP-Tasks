
int getIntegerComplement(int N)
{
	unsigned int mask = 1 << 31;
	while ((N & mask) == 0)
		mask >>= 1;
	mask <<= 1;
	mask -= 1;
	N ^= mask;
	return N;
}

int countBitsInNumber(int N)
{
	if (N == 0) return 0;
	unsigned int mask = 1 << 31;
	while ((N&mask) == 0)
		mask >>= 1;
	int count = 0;
	while (mask != 0)
	{
		mask >>= 1;
		++count;
	}
	return count;
}

int setNBitInValueInTrue(int val, int Nbit)
{
	int mask = 1 << (Nbit - 1);
	val |= mask;
	return val;
}

int invertNBitInValue(int val, int NBit)
{
	int mask = 1 << (NBit - 1);
	val ^= mask;
	return val;
}

bool isValueDegreeOfTwo(int val)
{
	return (val & (val - 1)) == 0;
}

void bitSwap(int &a, int &b)
{
	a = a ^ b;
	b = a ^ b;
	a = a ^ b;
}
void bitSwapV2(int &a, int &b)
{
	a ^= b ^= a ^= b;  // операции выполняются слева направо
}

int negative(int value)
{
	return (~value) + 1;
}

bool isOdd(int value)
{
	return value & 1;
}
int mod(int value, int m) // делит по модулю только на числа, являющиеся степенью двойки
{
	return value & (m - 1);
}

int absolute(int value)
{

	return (value ^ (value >> 31)) - (value >> 31);
}