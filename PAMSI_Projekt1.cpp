
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
	getchar();
	int size = 500;
	while (1)
	{
		
		//runTests(&merge_sort, "Merge sort");
		runTests(&quicksort, "Quick sort");
		//runTests(&quicksortf, "Quick sort f");
		//runTests(&heap_sort, "Heap sort");
		//runTests(&introsort, "Introspective sort");
		//runTests(&introsortH, "Introspective sort with insertion sort");

		if(getchar() == ' ')
			break;
	}

  return 0;
}