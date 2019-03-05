#pragma once

#include <vector>
#include <cmath>
#include <iostream>

#include "heapsort.h"
#include "quicksort.h"

#define LN2 0.69314718056

template <typename T>
int introsortInner(std::vector<T> &V, int begin, int end, int M)
{
	int n = end - begin;
	if (n <= 1)
		return 0;
	else if (M <= 5)
	{
		heap_sort(V, begin, end);
	}
	else
	{
 		int i = divideVector(V, begin, end);
		introsortInner(V, begin, i, M - 1);
		introsortInner(V, i + 1, end, M - 1);
	}

	return 0;
}

template <typename T>
int introsort(std::vector<T> &V, int begin, int end)
{
	introsortInner(V, begin, end, static_cast<int>(floor(2 * log(end - begin) / LN2)));

	return 0;
}

