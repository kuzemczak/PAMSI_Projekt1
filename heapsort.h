#pragma once

#include <vector>
#include <algorithm>

template<typename T>
int heap_sort(std::vector<T> &V, int begin, int end)
{
	heap(V, begin, end);
	deheap(V, begin, end);

	return 0;
}

template<typename T>
int heap(std::vector<T> &V, int begin, int end)
{
	for (int i = begin; i < end; i++)
	{
		int smallerBranch = i;
		int largerBranch = (smallerBranch + begin - 1) / 2;
		int inserted = V[i];

		while (smallerBranch > begin && V[largerBranch] < inserted)
		{
			V[smallerBranch] = V[largerBranch];
			smallerBranch = largerBranch;
			largerBranch = (smallerBranch + begin - 1) / 2;
		}

		V[smallerBranch] = inserted;
	}

	return 0;
}



template<typename T>
int deheap(std::vector<T> &V, int begin, int end)
{
	for (int i = end - 1; i > begin; i--)
	{
		swap(V[begin], V[i]);
		int j = begin, k = begin + 1, m;

		while (k < i)
		{
			if (k + 1 < i && V[k + 1] > V[k])
				m = k + 1;
			else
				m = k;
			if (V[m] > V[j])
			{
				swap(V[j], V[m]);
				j = m;
				k = 2 * j - begin + 1;
			}
			else
				break;
		}
	}

	return 0;
}
