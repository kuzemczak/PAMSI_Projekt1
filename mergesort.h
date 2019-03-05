#pragma once

#include <vector>
#include <iostream>
#include "vectorAddon.h"

template<typename T>
std::vector<T> merge(std::vector<T> &p, std::vector<T> &q, int mergedSize)
{
	int pcntr = 0, qcntr = 0;
	std::vector<T> ret;

	while (ret.size() < mergedSize)
	{
		if (pcntr == p.size())
			ret.insert(ret.end(), q.begin() + qcntr, q.end());
		else if (qcntr == q.size())
			ret.insert(ret.end(), p.begin() + pcntr, p.end());
		else if (p[pcntr] > q[qcntr])
		{
			ret.push_back(q[qcntr++]);
		}
		else
		{
			ret.push_back(p[pcntr++]);
		}
	}

	return ret;
}

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