#pragma once

#include <vector>

template <typename T>
void Heap_Sort(std::vector<T> &V)
{
	int i;
	for (i = V.size() / 2; i > 0; --i)
		Heapify(V, i, V.size());
	for (i = V.size() - 1; i > 0; --i)
	{
		iter_swap(V.begin() + 0, V.begin() + i);
		Heapify(V, 1, i);
	}
}

template <typename T>
void Heapify(std::vector<T> &V, int i, int N)
{
	int j;
	while (i <= N / 2)
	{
		j = 2 * i;
		if (j + 1 <= N && V[j]>V[j-1])
			j = j + 1;
		if (V[i-1]<V[j-1])
			iter_swap(V.begin() + i - 1, V.begin() + j - 1);
		else break;
		i = j;
	}
}

template<typename T>
int heap_sort(std::vector<T> &V)
{
	heap(V);
	deheap(V);

	return 0;
}


template<typename T>
int heap(std::vector<T> &V)
{
	for (int i = 2; i <= V.size(); i++)
	{
		int smallerBranch = i;
		int largerBranch = smallerBranch / 2;
		int inserted = V[i-1];

		while (largerBranch > 0 && V[largerBranch-1] < inserted)
		{
			V[smallerBranch-1] = V[largerBranch-1];
			smallerBranch = largerBranch;
			largerBranch = smallerBranch / 2;
		}

		V[smallerBranch-1] = inserted;
	}

	return 0;
}

template<typename T>
int deheap(std::vector<T> &V)
{
	for (int i = V.size() - 1; i > 0; i--)
	{
		iter_swap(V.begin(), V.begin() + i);
		int j = 0, k = 1, m;

		while (k < i)
		{
			if (k + 1 < i && V[k + 1] > V[k])
				m = k + 1;
			else
				m = k;
			if (V[m] > V[j])
			{
				iter_swap(V.begin() + j, V.begin() + m);
				j = m;
				k = 2 * j + 1;
			}
			else
				break;
		}
	}

	return 0;
}