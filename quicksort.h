#pragma once

#include <vector>
#include <iostream>
#include <algorithm>
#include "vectorAddon.h"

template<typename T>
int quicksort(std::vector<T> &V, int begin, int end)
{
	if (begin < end - 1)
	{
		int i = divideVector(V, begin, end);
		quicksort(V, begin, i);
		quicksort(V, i + 1, end);
	}

	return 0;
}

template<typename T>
int divideVector(std::vector<T> &V, int begin, int end)
{
	if (begin == end)
		return begin;

	int index = static_cast<int>(begin + (end - 1 - begin) / 2);
	int value = V[index];

	swap(V[index], V[end - 1]);

	int pos = begin;

	for (int i = begin; i < end - 1; i++)
	{
		if (V[i] < value)
		{
			swap(V[i], V[pos]);
			pos++;
		}
	}
	swap(V[pos], V[end - 1]);
	return pos;
}

template<typename T>
int divideVector(T *V, int begin, int end)
{
	if (begin == end)
		return begin;

	int index = static_cast<int>(begin + (end - 1 - begin) / 2);
	int value = V[index];

	swap(V[index], V[end - 1]);

	int pos = begin;

	for (int i = begin; i < end - 1; i++)
	{
		if (V[i] < value)
		{
			swap(V[i], V[pos]);
			pos++;
		}
	}
	swap(V[pos], V[end - 1]);
	return pos;
}


template<typename T>
int quicksort(T *V, int begin, int end)
{
	if (begin < end - 1)
	{
		int i = divideVector(V, begin, end);
		quicksort(V, begin, i);
		quicksort(V, i + 1, end);
	}

	return 0;
}

