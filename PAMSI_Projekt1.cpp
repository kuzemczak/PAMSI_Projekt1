
#include <iostream>
#include <random>

#include "scalanie.h"
#include "quicksort.h"
#include "kopcowanie.h"
#include "randutils.hpp"

using namespace std;

thread_local std::mt19937 gen{ std::random_device{}() };

template<typename T>
T random(T min, T max) {
	return std::uniform_int_distribution<T>{min, max}(gen);
}

int main()
{
	randutils::mt19937_rng rng;

	vector<int> v;
	for (int i = 0; i < 10000; i++)
		v.push_back(rng.uniform(-1000, 1000));

	vector<int> v0 = v;
	vector<int> v1 = v;
	vector<int> v2 = v;

	merge_sort(v, 0, v.size());
	quicksort(v0, 0, v0.size()-1);
	Heap_Sort(v1);
	heap_sort(v2);

	//cout << "Hello\n" << v << endl << v0 << endl << v1 << endl;
	getchar();

  return 0;
}

