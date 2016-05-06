#include <iostream>
#include <cmath>

using namespace std;


// 1. Вычислить значение суммы
// S = 1 / 1!+ 1 / 2!+ ... + 1 / k!

double Sum(int k)
{
	double sum = 0;
	sum = 1 * ((1 - pow(0.5, k)) / (1 - 0.5));
	return sum;
}

// 2. Написать программу определения количества шестизначных 'счастливых' билетов,
// у которых сумма первых 3 десятичных цифр равна сумме 3 последних десятичных цифр.

int countNumbersInNumber(int number)
{
	int numbers = 1;
	while (number /= 10)
		++numbers;
	return numbers;
}
int getSumOfNumbers(float number)
{
	int sum = 0;
	int numbers = countNumbersInNumber(number);
	for (int i = 0; i <= numbers; ++i, number /= 10)
		sum += ((number / 10) - (int(number/10))) * 10;
	return sum;
}
int CountLuckyTickets()
{
	int luckyCount = 1;
	for (float i = 1001; i < 1000000; ++i)
	{
		float firstPart = int(i / 1000);
		float secondPart =int((i / 1000 - firstPart) * 1000);
		if (getSumOfNumbers((int)firstPart) == getSumOfNumbers((int)secondPart))
			++luckyCount;
	}
	return luckyCount;
}

// 3. Написать программу определения количества 2*N -значных билетов,
// у которых сумма первых N десятичных цифр равна сумме N последних десятичных цифр;
// при этом N -произвольное натуральное число.

int getSumOfFirstNNumbers(int value, int countNumbers, int N)
{
	int sum = 0;
	int divider = pow(10, countNumbers - 1);
	for (int i = 0; i < N; ++i, divider /= 10)
	{
		sum += value / divider;
		value %= divider;
	}
	return sum;
}
int getSumOfLastNNumbers(int value, int countNumbers, int N)
{
	int sum = 0;
	float fvalue = value;
	for (int i = 0; i < N; ++i, value /= 10)
	{
		sum += value % ((int((float)value / 10)) * 10);
	}
	return sum;
}

int GetQuantityTickets(int N)
{
	int  count = 0;
	int  countNumbers = 0;
	for (int i = 0; i < pow(10, N * 2); ++i)
		if ((countNumbers = countNumbersInNumber(i)) == N * 2)
			if (getSumOfFirstNNumbers(i, countNumbers, N) == getSumOfLastNNumbers(i, countNumbers, N))
				count++;
	return count;
}
