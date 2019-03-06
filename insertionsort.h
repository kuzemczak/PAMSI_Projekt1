#pragma once

#include <vector>

template <typename T>
int insertion_sort(std::vector<T> &V, int begin, int end)
{
	int tmp;

	for (int i = begin + 1; i < end; i++)
	{
		int j;
		tmp = V[i];
		for (j = i; j > begin && tmp < V[j - 1]; j--)
			V[j] = V[j - 1];
		V[j] = tmp;
	}

	return 0;
}

template <typename T>
int insertion_sort(T * V, int begin, int end)
{
	int tmp;

	for (int i = begin + 1; i < end; i++)
	{
		int j;
		tmp = V[i];
		for (j = i; j > begin && tmp < V[j - 1]; j--)
			V[j] = V[j - 1];
		V[j] = tmp;
	}

	return 0;
}