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
	const int N = 18;
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
		table[i].k = i + pow((-1),i) * 19 * 3;
		std::cout << table[i].k << "\t" << table[i].R << std::endl;
	}

	std::cout << "Enter key: ";
	std::cin >> k;

	i = 0;

	while (table[i].k != k)
	{
		count++;
		i++;
		if (i == N)
			break;
		count++;
	}

	if (i < N)
	{
		std::cout << std::endl << "S: " << count << "\t" << table[i].R << std::endl;
	}
	else std::cout << std::endl << "S: We were unable to find a matching key. It took us " << count << " comparisons." << std::endl;

	table[N+1].k = k;
	count = 1;
	i = 0;

	while (table[i].k != k)
	{
		i++;
		count++;
	}

	count++;

	if (i < N)
		std::cout << "Q: " << count << "\t" << table[i].R << std::endl;
	else std::cout << "Q: We were unable to find a matching key. It took us " << count << " comparisons." << std::endl;

	for (i = 0; i < N - 1; i++)
		for (int n = i + 1; n < N; n++)
		{
			if (table[i].k > table[n].k)
				swap(table[i], table[n]);
		}

	std::cout << "\nSorted table:" << std::endl;

	for (i = 0; i < N; i++)
	{
		std::cout << table[i].k << "\t" << table[i].R << std::endl;
	}

	i = 0;
	count = 1;
	
	while (k > table[i].k)
	{
		count++;
		i++;
	}

	count++;

	if (k == table[i].k)
		std::cout << std::endl << "T: " << count << "\t" << table[i].R << std::endl;
	else std::cout << std::endl << "T: We were unable to find a matching key. It took us " << count << " comparisons." << std::endl;

	i = 0;
	i_first = 0;
	i_last = N - 1;
	count = 1;

	while (i_first < i_last)
	{
		i = (i_first + i_last) / 2;
		count++;
		if (table[i].k > k)
			i_last = i - 1;
		else
		{
			count++;
			if (k == table[i].k)
			{
				std::cout << "B: " << count << "\t" << table[i].R << std::endl;
				break;
			}
			else i_first = i + 1;
		}
	}

	count++;
	if (i_first >= i_last)
		std::cout << "B: We were unable to find a matching key. It took us " << count << " comparisons." << std::endl;

	system("pause");
    return 0;
}

