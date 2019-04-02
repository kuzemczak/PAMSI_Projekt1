#ifndef MERGESORT_H
#define MERGESORT_H

#include <iostream>
#include "vectorAddon.h"

/*
* funkcja scalajaca dwa podzbiory.
* V - wskaznik do tablicy
* begin - poczatek pierwszego podzbioru
* half - koniec pierwszego i poczatek drugiego podzbioru
* end - koniec drugiego podzbioru
*/
template<typename T>
int merge(T * V, int begin, int half, int end)
{
	int pcntr = 0,					// licznik pierwszego podzbioru
		qcntr = half - begin,	// licznik drugiego podzbioru
		retcntr = begin;			// licznik zbioru wyjsciowego

	// tymczasowa tablica przechowujaca elementy do scalenia
	T * tmp = new T[end - begin];

	// wypelnienie tablicy tymczasowej
	for (int i = 0; i < end - begin; i++)
	{
		tmp[i] = V[begin + i];
	}

	// petla scalajaca, wykonuje sie dopoki
	// zaden z licznikow nie dotarl do konca
	// swojego podzbioru
	while (pcntr < half - begin && qcntr < end - begin)
	{
		// wrzucenie mniejszego elementu z dwoch podzbiorow
		// na nastepne miejsce w zbiorze wyjsciowym
		if (tmp[pcntr] > tmp[qcntr])
		{
			V[retcntr++] = tmp[qcntr++];
		}
		else
		{
			V[retcntr++] = tmp[pcntr++];
		}
	}

	// jesli pierwszy zbior skonczyl sie pierwszy
	// to koniec roboty, elementy sa na swoich miejscach,
	// natomiast jesli drugi zbior skonczyl sie pierwszy,
	// treba przerzucic reszte elementow ze zbioru
	// pierwszego na koniec.
	while (pcntr < half - begin)
		V[retcntr++] = tmp[pcntr++];

	delete[] tmp;

	return 0;
}

// sortowanie przez scalanie
template <typename T>
int merge_sort(T  V[], int begin, int end)
{
	// jesli podzbior o wielkosci 2,
	// ustaw elementy w odpowiedniej kolejnosci
	if (begin == end - 2)
	{
		if (V[begin] > V[end - 1])
			Swap(V[begin], V[end - 1]);
		return 0;
	}

	// dla wielkosci wiekszych od 2
	// dzielimy podzbior na dwa
	// i na kazdej czesci
	// stosujemy wywolanie rekurencyjne,
	// a potem scalamy te czesci w jedna
	if (begin < end - 1)
	{
		int half = static_cast<int>(begin + (end - begin) / 2);
		merge_sort(V, begin, half);
		merge_sort(V, half, end);
		merge(V, begin, half, end);
	}
	return 0;
}

#endif