
#include <iostream>
#include <random>
#include <chrono>
#include <string>

#include "randutils.hpp"

#include "mergesort.h"
#include "quicksort.h"
#include "heapsort.h"
#include "insertionsort.h"
#include "introspectivesort.h"
#include "tests.h"

using namespace std;

int main()
{
	while (1)
	{
		//merge_sort(tab, 0, size);
		runTests(&quicksort, "Quick sort");
		//runTests(&heap_sort, "Heap sort");
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
		//cout << "Introspective sort  ";
		//checkSorted(tab, size);
		//cout << "Insertion sort  ";
		//checkSorted(tab, size);

		if(getchar() == ' ')
			break;
	}

  return 0;
}