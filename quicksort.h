#ifndef QUICKSORT_H
#define QUICKSORT_H

#include <iostream>
#include <algorithm>
#include "vectorAddon.h"

int depth = 0, max_depth = 0;
std::vector<double> pivots;
/*
* Wybiera element w po³owie wektora (pivot) i dzieli go na
* dwa podzbiory sk³adaj¹ce siê z elementów wiêkszych
* i mniejszych. Zwraca index pivota.
*/
template<typename T>
int divideVector(T *V, int begin, int end)
{
	if (begin == end)
		return begin;

	// wyznaczenie indeksu pivota
	int index = static_cast<int>((begin + end - 1) / 2);

	// wartoœæ pivota
	int value = V[index];

	// pivot na koniec, zeby nie przeszkadzal
	Swap(V[index], V[end - 1]);

	// zmienna kontrolujaca lewa strone
	int pos = begin;

	// iteracja przez caly podzbior
	// wyrzuca mniejsze od pivota na lewo
	for (int i = begin; i < end - 1; i++)
	{
		if (V[i] < value)
		{
			Swap(V[i], V[pos]);
			pos++;
		}
	}

	// wrzucenie pivota miedzy czesciami
	Swap(V[pos], V[end - 1]);

	// testy, kontrola odleglosci pivota od srodka podzbioru
	//for(int i = 0; i < (end - begin)/100; i++)
		//pivots.push_back(fabs(((double)((double)end - (double)pos)/ (double)((double)end - (double)begin))-0.5));

	return pos;
}


template<typename T>
int quicksort(T *V, int begin, int end)
{
	// spradzenie, czy podzbior dluzszy od 1
	if (begin < end - 1)
	{
		// wyznaczenie pivota i podzielenie podzbioru
		int i = divideVector(V, begin, end);

		// rekurencja dla dwoch czesci podzbioru
		quicksort(V, begin, i);
		quicksort(V, i + 1, end);
	}

	return 0;
}

// testy, wyswietlenie zmiennych kontrolujacych
void showPivots()
{
	sort(pivots.begin(), pivots.end());
	double mean = 0;
	for (double i : pivots)
		mean += i;
	mean /= pivots.size();
	std::cout << mean;
	pivots.clear();
	std::cout << "\t" << max_depth << std::endl;
	max_depth = 0;
	depth = 0;
}


// wersja z wyborem pivota na poczatku podzbioru
template<typename T>
int divideVectorf(T *V, int begin, int end)
{
	if (begin == end)
		return begin;

	int index = begin;
	int value = V[index];

	Swap((V[index]), (V[end - 1]));

	//swap(V[index], V[end - 1]);

	int pos = begin;

	for (int i = begin; i < end - 1; i++)
	{
		if (V[i] < value)
		{
			Swap((V[i]), (V[pos]));
			pos++;
		}
	}
	Swap((V[pos]), (V[end - 1]));
	return pos;
}


// wersja z wyborem pivota na poczatku podzbioru
template<typename T>
int quicksortf(T *V, int begin, int end)
{
	if (begin < end - 1)
	{
		depth++;
		if (depth > max_depth)
			max_depth = depth;
		//std::cout << "depth: " << depth << std::endl;
		int i = divideVectorf(V, begin, end);
		quicksortf(V, begin, i);
		quicksortf(V, i + 1, end);
		depth--;
		//std::cout << "depth: " << depth << std::endl;
	}

	return 0;
}

#endif