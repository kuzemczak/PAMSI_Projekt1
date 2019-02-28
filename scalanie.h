#pragma once

#include <vector>
#include <iostream>
#include "vectorAddon.h"

template <typename T>
int merge_sort(std::vector<T> &V, int begin, int end)
{
	if (begin < end-1)
	{
		int half = static_cast<int>((end - begin) / 2);
		std::vector<T> p = subVector<T>(V, begin, half);
		std::vector<T> q = subVector<T>(V, half, end);
		merge_sort(p, 0, p.size());
		merge_sort(q, 0, q.size());
		V = merge(p, q, V.size());
	}
	return 0;
}