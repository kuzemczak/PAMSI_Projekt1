#pragma once

#include <iostream>
#include "vectorAddon.h"

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

