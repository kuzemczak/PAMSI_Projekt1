#ifndef INTROSPECTIVESORT_H
#define INTROSPECTIVESORT_H

#include <cmath>
#include <iostream>

#include "heapsort.h"
#include "insertionsort.h"
#include "quicksort.h"

#define LN2 0.69314718056


template <typename T>
int introsortInner(T * V, int begin, int end, int M)
{
	// sprawdzenie dlugosci podzbioru
	if (end - begin <= 1)
	{
		//insertion_sort(V, begin, end);
		return 0;
	}
	else if (M <= 0)
	{// sprawdzenie glebokosci rekurencji
		heap_sort(V, begin, end);
	}
	else
	{ // tak naprawde to quicksort
		int i = divideVector(V, begin, end);
		introsortInner(V, begin, i, M - 1);
		introsortInner(V, i + 1, end, M - 1);
	}

	return 0;
}

// wywolanie wlasciwej funkcji z wprowadzeniem
// maksymalnej glebokosci rekurencji
template <typename T>
int introsort(T * V, int begin, int end)
{
	introsortInner(V, begin, end, static_cast<int>(floor(2 * log(end - begin) / LN2)));

	return 0;
}

// hybrydowy wariant introsorta z sortowaniem przez wstawianie dla 
// zbiorów mniejszych niz 17
template <typename T>
int introsortInnerH(T * V, int begin, int end, int M)
{
	// sprawdzenie dlugosci podzbioru
	if (end - begin < 17)
	{
		insertion_sort(V, begin, end);
		return 0;
	}
	else if (M <= 0)
	{// sprawdzenie glebokosci rekurencji
		heap_sort(V, begin, end);
	}
	else
	{ // tak naprawde to quicksort
		int i = divideVector(V, begin, end);
		introsortInnerH(V, begin, i, M - 1);
		introsortInnerH(V, i + 1, end, M - 1);
	}

	return 0;
}

// wywolanie wlasciwej funkcji z wprowadzeniem
// maksymalnej glebokosci rekurencji
template <typename T>
int introsortH(T * V, int begin, int end)
{
	introsortInnerH(V, begin, end, static_cast<int>(floor(2 * log(end - begin) / LN2)));

	return 0;
}

#endif