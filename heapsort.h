#ifndef HEAPSORT_H
#define HEAPSORT_H

#include <algorithm>

/*
* Tworzenie kopca w postaci:
*                      0
*          ^    1              2
*   w gore/  3     4       5       6
*           7 8   9 10   11 12   13 14
*                    ...
* Przesuwanie w 
* gore galezi, ¿eby u podstawy
* byly najwieksze elementy.
*/
template<typename T>
int heap(T * V, int begin, int end)
{
	for (int i = begin; i < end; i++)
	{
		int smallerBranch = i;				// index odnogi galezi
		int largerBranch = (smallerBranch + begin - 1) / 2;	// indeks podstawy (1 wyzej)
		int inserted = V[i];	// element wstawiany do kopca

		// przesuwanie w gore dopoki element wyzej jest mniejszy
		while (smallerBranch > begin && V[largerBranch] < inserted)
		{
			// mniejszy element z wyzszej na nizsza galaz
			V[smallerBranch] = V[largerBranch]; 

			// przejscie indeksami wyzej
			smallerBranch = largerBranch;
			largerBranch = (smallerBranch + begin - 1) / 2;
		}

		// wstawienie elementu na galaz
		// do ktorej dotarla petla
		V[smallerBranch] = inserted;
	}

	return 0;
}

template<typename T>
int deheap(T * V, int begin, int end)
{
	for (int i = end - 1; i > begin; i--)
	{
		// przerzucenie elementu ze szczytu kopca na koniec
		// bo jest najwiekszy
		Swap(V[begin], V[i]);

		// j - galaz wyzsza, k, m - galaz nizsza
		int j = begin, k = begin + 1, m;

		while (k < i)
		{
			// decyzja: lewa czy prawa odnoga?
			if (k + 1 < i && V[k + 1] > V[k])
				m = k + 1;
			else
				m = k;

			// jesli jest nizej wiekszy element,
			// to zamiana miejscami wyzszego z nizszym.
			if (V[m] > V[j])
			{
				Swap(V[j], V[m]);
				j = m;
				k = 2 * j - begin + 1;
			}
			else
				break;
		}
	}

	return 0;
}

template<typename T>
int heap_sort(T * V, int begin, int end)
{
	heap(V, begin, end);
	deheap(V, begin, end);

	return 0;
}

#endif