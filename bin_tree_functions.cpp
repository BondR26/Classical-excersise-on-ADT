
#include<iostream>

#include "bin_tree_int.h"

ARR::ARR(int sz) :arr{ new int[sz] }, size{ sz }{}

int ARR::operator[](int i)
{
	return arr[i];
}

void ARR::fill_rand()
{
	for (int i = 0; i < size; i++)
	{
		arr[i] = rand() % 100;
	}
}

void ARR::sort()
{
	for (int i = 0; i < size; i++)
	{
		int N = size - 1 - i;

		for (int j = i; j < N; j++)
		{
			if (arr[i] > arr[j])
			{
				std::swap(arr[i], arr[j]);
			}

			if (arr[N] < arr[j])
			{
				std::swap(arr[N], arr[j]);
			}
		}
	}
}

bool ARR::find_bin_way(int num)
{
	bool flag = false;

	for (int i = size / 2, attempt = 0, extra_cup = i / 2; (i > 0 || i > size) and attempt < size / 2; attempt++)
	{
		if (num > arr[i])
		{

			i += extra_cup;
		}
		else if (num < arr[i])
		{

			i -= extra_cup;
		}
		else if (num == arr[i])
		{
			flag = true;
			break;
		}

		if (extra_cup > 1)
		{
			extra_cup /= 2;
		}
	}

	return flag;
}


void ARR::show()
{
	for (int i = 0; i < size; i++)
	{
		std::cout << arr[i] << std::endl;
	}
}

