
#include <iostream>
#include <random>

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
bool checkSorted(vector<T> &V)
{
	for (int i = 1; i < V.size(); i++)
		if (V[i - 1] > V[i])
		{
			cout << "NOT OK\n";
			return false;
		}

	cout << "OK\n";
	return true;
}

int main()
{

	
	while (1)
	{
		randutils::mt19937_rng rng;

		vector<int> v;
		for (int i = 0; i < 100001; i++)
			v.push_back(rng.uniform(-1000, 1000));

		vector<int> v0 = v;
		vector<int> v1 = v;
		vector<int> v2 = v;
		vector<int> v3 = v;

		merge_sort(v, 0, v.size());
		quicksort(v0, 0, v0.size());
		heap_sort(v1, 0, v1.size());
		introsort(v2, 0, v2.size());
		insertion_sort(v3, 0, v3.size());

		//cout << "Hello\n" << v4 << endl ;

		cout << "Merge sort ";
		checkSorted(v);
		cout << "Quick sort ";
		checkSorted(v0);
		cout << "Heap sort ";
		checkSorted(v1);
		cout << "Introspective sort  ";
		checkSorted(v2);
		cout << "Insertion sort  ";
		checkSorted(v3);

		if(getchar() == ' ')
			break;
	}

  return 0;
}

