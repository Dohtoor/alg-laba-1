// alg laba 1.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <string>

struct TABLE
{
	char R = NULL;
	int k = INT_MAX;
};

void swap(TABLE &one, TABLE &two)
{
	TABLE three;
	three.R = one.R;
	three.k = one.k;
	one.R = two.R;
	one.k = two.k;
	two.R = three.R;
	two.k = three.k;
	return;
}

int main()
{
	const int N = 15;
	int i;
	int number;
	int count = 1;
	int i_last;
	int i_first;
	TABLE table[N+1];
	int k;
	std::string string;
	bool success = false;

	for (i = 0; i < N; i++)
	{
		table[i].R = i+66;
		table[i].k = pow((-2),i);
		std::cout << table[i].k << "\t" << table[i].R << std::endl;
	}

	std::cout << "\nEnter key: ";
	std::cin >> k;

	i = 0;

	for (i = 0; i < N; i++)
	{
		count++;
		if (table[i].k == k)
		{
			std::cout << "S: " << count << "\t" << table[i].R << std::endl;
			success = true;
		}
		count++;
	}

	if (!success)
		std::cout << std::endl << "S: We were unable to find a matching key. It took us " << count << " comparisons." << std::endl;

	std::cout << std::endl;
	table[N].k = k;
	count = 0;
	i = 0;
	success = false;

	while (true)
	{
		count++;
		if (table[i].k == k)
		{
			if (i != N)
			{
				std::cout << "Q: " << count << "\t" << table[i].R << std::endl;
				success = true;
			}
			else break;
		}
		i++;
	}

	count++;
	if (!success)
		std::cout << "Q: We were unable to find a matching key. It took us " << count << " comparisons." << std::endl;

	for (i = 0; i < N - 1; i++)
		for (int n = i + 1; n < N; n++)
		{
			if (table[i].k < table[n].k)
				swap(table[i], table[n]);
		}

	std::cout << "\nSorted table:" << std::endl;

	for (i = 0; i < N; i++)
	{
		std::cout << table[i].k << "\t" << table[i].R << std::endl;
	}

	i = 0;
	count = 1;
	success = false;
	table[N].k = INT_MAX;

	std::cout << std::endl;
	
	while (k < table[i].k)
	{
		count++;
		i++;
	}

	count++;
	while (k == table[i].k)
	{
		std::cout << "T: " << count << "\t" << table[i].R << std::endl;
		success = true;
		i++;
		count++;
	}

	if (!success)
	 std::cout << "T: We were unable to find a matching key. It took us " << count << " comparisons." << std::endl;

	std::cout << std::endl;
	i = 0;
	i_first = 0;
	i_last = N - 1;
	count = 1;
	success = false;

	while (i_first <= i_last)
	{
		i = (i_first + i_last) / 2;
		count++;
		if (table[i].k < k)
			i_last = i - 1;
		else
		{
			count++;
			if (k == table[i].k)
			{
				number = i;
				success = true;
				break;
			}
			else i_first = i + 1;
		}
	}

	count++;
	if (!success)
		std::cout << "B: We were unable to find a matching key. It took us " << count << " comparisons." << std::endl;
	else
	{
		i = 1;
		count = count + 4;
		std::cout << "B: " << count << "\t" << table[number].R << std::endl;
		while ((table[number + i].k == k) || (table[number - i].k == k))
		{
			if (table[number + i].k == k)
				std::cout << "B: " << count << "\t" << table[number + i].R << std::endl;
			if (table[number - i].k == k)
				std::cout << "B: " << count << "\t" << table[number - i].R << std::endl;
			i++;
			count = count + 4;
		}
	}

	system("pause");
    return 0;
}

