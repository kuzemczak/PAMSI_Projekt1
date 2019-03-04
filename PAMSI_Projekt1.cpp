
#include <iostream>
#include <random>

#include "mergesort.h"
#include "quicksort.h"
#include "heapsort.h"
#include "insertionsort.h"
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
	randutils::mt19937_rng rng;

	vector<int> v;
	for (int i = 0; i < 50000; i++)
		v.push_back(rng.uniform(-1000, 1000));

	vector<int> v0 = v;
	vector<int> v1 = v;
	vector<int> v2 = v;
	vector<int> v3 = v;
	vector<int> v4 = v;
	vector<int> v5 = v;

	merge_sort(v, 0, v.size());
	quicksort(v0, 0, v0.size());
	Heap_Sort(v1);
	heap_sort(v2, 0, v2.size());
	heap_sort_combined(v3);
	//insertion_sort(v4, 0, v4.size());
	//Heap(v4);
	//Heap0(v5);

	//cout << "Hello\n" << v4 << endl ;

	cout << "Merge sort ";
	checkSorted(v);
	cout << "Quick sort ";
	checkSorted(v0);
	cout << "Heap sort (Wiki) ";
	checkSorted(v1);
	cout << "Heap sort ";
	checkSorted(v2);
	cout << "Heap sort combined ";
	checkSorted(v3);
	cout << "Insertion sort  ";
	checkSorted(v4);

	getchar();

  return 0;
}

