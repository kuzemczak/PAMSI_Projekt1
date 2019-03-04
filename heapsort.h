#pragma once

#include <vector>
#include <algorithm>

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
void Heap(std::vector<T> &V)
{
	int i;
	int N = V.size();

	for (i = V.size() / 2; i > 0; --i)
	{
		int j, k = i;
		while (k <= N / 2)
		{
			j = 2 * k;
			if (j + 1 <= N && V[j] > V[j - 1])
				j = j + 1;
			if (V[k - 1] < V[j - 1])
				swap(V[k - 1], V[j - 1]);
			else break;
			k = j;
		}
	}
}

template<typename T>
void Heap0(std::vector<T> &V)
{
	int i;
	int N = V.size();

	for (i = V.size() / 2; i > 0; --i)
	{
		int j, k = i;
		while (k <= N / 2)
		{
			j = 2 * k;
			if (j + 1 <= N && V[j] > V[j - 1])
				j = j + 1;
			if (V[k - 1] < V[j - 1])
			{
				value_swap(V, k - 1, j - 1);
			}
			else break;
			k = j;
		}
	}
}

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
	for (int i = begin + 2; i <= end; i++)
	{
		int smallerBranch = i;
		int largerBranch = smallerBranch / 2;
		int inserted = V[i-1];

		while (largerBranch > begin && V[largerBranch-1] < inserted)
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
				k = 2 * j + 1;
			}
			else
				break;
		}
	}

	return 0;
}

template<typename T>
int heap_sort_combined(std::vector<T> &V)
{
	int i;
	
	Heap0(V);
	deheap(V, 0, V.size());

	return 0;
}