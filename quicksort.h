#pragma once

#include <vector>
#include <iostream>
#include <algorithm>
#include "vectorAddon.h"

template<typename T>
int quicksort(std::vector<T> &V, int begin, int end)
{
	if (begin < end)
	{
		int i = divideVector(V, begin, end);
		quicksort(V, begin, i-1);
		quicksort(V, i+1, end);
	}

	return 0;
}

template<typename T>
int divideVector(std::vector<T> &V, int begin, int end)
{
	int index = static_cast<int>(begin + (end - begin) / 2);
	int value = V[index];

	iter_swap(V.begin() + index, V.begin() + end);

	int pos = begin;

	for (int i = begin; i < end; i++)
	{
		if (V[i] < value)
		{
			iter_swap(V.begin() + i, V.begin() + pos);
			pos++;
		}
	}
	iter_swap(V.begin() + pos, V.begin() + end);
	return pos;
}