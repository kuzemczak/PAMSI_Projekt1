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

template<typename T>
int merge(std::vector<T> &V, int begin, int half, int end)
{
	int pcntr = begin, qcntr = half;
	std::vector<T> ret;

	while (ret.size() < end - begin)
	{
		if (pcntr == half)
			ret.insert(ret.end(), V.begin() + qcntr, V.begin() + end);
		else if (qcntr == end)
			ret.insert(ret.end(), V.begin() + pcntr, V.begin() + half);
		else if (V[pcntr] > V[qcntr])
		{
			ret.push_back(V[qcntr++]);
		}
		else
		{
			ret.push_back(V[pcntr++]);
		}
	}

	for (int i = 0; i < end - begin; i++)
	{
		V[begin + i] = ret[i];
	}

	return 0;
}




template <typename T>
int merge_sort(std::vector<T> &V, int begin, int end)
{
	if (begin == end - 2)
	{
		if (V[begin] > V[end - 1])
			swap(V[begin], V[end - 1]);
		return 0;
	}
	
	if (begin < end-1)
	{
		int half = static_cast<int>(begin + (end - begin) / 2);
		merge_sort(V, begin, half);
		merge_sort(V, half, end);
		merge(V, begin, half, end);
	}
	return 0;
}

template<typename T>
int merge(T * V, int begin, int half, int end)
{
	int pcntr = begin, qcntr = half, retcntr = 0;
	T * ret = new T[end - begin];

	while (retcntr < end - begin)
	{
		if (pcntr == half)
		{
			for (int i = qcntr; i < end; i++)
			{
				ret[retcntr++] = V[i];
			}
		}
		else if (qcntr == end)
		{
			for (int i = pcntr; i < half; i++)
			{
				ret[retcntr++] = V[i];
			}
		}
		else if (V[pcntr] > V[qcntr])
		{
			ret[retcntr++] = V[qcntr++];
		}
		else
		{
			ret[retcntr++] = V[pcntr++];
		}
	}

	for (int i = 0; i < end - begin; i++)
	{
		V[begin + i] = ret[i];
	}

	delete[] ret;

	return 0;
}




template <typename T>
int merge_sort(T * V, int begin, int end)
{
	if (begin == end - 2)
	{
		if (V[begin] > V[end - 1])
			swap(V[begin], V[end - 1]);
		return 0;
	}

	if (begin < end - 1)
	{
		int half = static_cast<int>(begin + (end - begin) / 2);
		merge_sort(V, begin, half);
		merge_sort(V, half, end);
		merge(V, begin, half, end);
	}
	return 0;
}

