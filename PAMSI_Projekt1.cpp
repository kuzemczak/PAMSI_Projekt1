
#include <iostream>
#include <random>
#include <chrono>
#include <string>

#include "mergesort.h"
#include "quicksort.h"
#include "heapsort.h"
#include "insertionsort.h"
#include "introspectivesort.h"
#include "randutils.hpp"

using namespace std;

thread_local std::mt19937 gen{ std::random_device{}() };

template<typename T>
T random(T min, T max) {
	return std::uniform_int_distribution<T>{min, max}(gen);
}


template<typename T>
bool checkSorted(T * V, int size)
{
	for (int i = 1; i < size; i++)
		if (V[i - 1] > V[i])
		{
			cout << "NOT OK\n";
			return false;
		}

	cout << "OK\n";
	return true;
}

template <typename T>
int testSortingTime(int(*testedFunction)(T*, int, int), T * V = NULL, int begin = 0, int end = 0)
{
	if (V == NULL)
		return 1;
	if (begin == 0 && end == 0)
		return 0;
	if (end == 0)
	{
		end = begin;
		begin = 0;
	}

	typedef std::chrono::high_resolution_clock Clock;

	if (testedFunction)
	{
		auto t1 = Clock::now();
		testedFunction(V, begin, end);
		auto t2 = Clock::now();
		
		return static_cast<int>(std::chrono::duration_cast<std::chrono::milliseconds>(t2 - t1).count());;
	}

	return 1;
}

int main()
{
	const int size = 200000;

	int tab[size];
	
	while (1)
	{
		randutils::mt19937_rng rng;

		vector<int> v;
		for (int i = 0; i < size; i++)
			tab[i] = rng.uniform(-1000, 1000);


		//merge_sort(tab, 0, size);
		//quicksort(tab, 0, size);
		
		cout << "Czas trwania Heap sort: " << testSortingTime(&heap_sort, tab, 0, size) << " ms" << endl;
		//heap_sort(tab, 0, size);
		//introsort(tab, 0, size);
		//insertion_sort(tab, 0, size);

		//cout << "Hello\n" << v4 << endl ;

		//cout << "Merge sort ";
		//checkSorted(tab, size);
		//cout << "Quick sort ";
		//checkSorted(tab, size);
		//cout << "Heap sort ";
		//checkSorted(tab, size);
		cout << "Introspective sort  ";
		checkSorted(tab, size);
		//cout << "Insertion sort  ";
		//checkSorted(tab, size);

		if(getchar() == ' ')
			break;
	}

  return 0;
}

