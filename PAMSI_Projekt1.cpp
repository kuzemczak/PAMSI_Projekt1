
#include <iostream>
#include <random>

#include "scalanie.h"
#include "quicksort.h"

using namespace std;

int main()
{
	std::default_random_engine generator;
	std::uniform_int_distribution<int> distribution(-1000, 1000);

	vector<int> v;
	for (int i = 0; i < 20; i++)
		v.push_back(distribution(generator));

	vector<int> v0 = v;
	vector<int> v1 = v;

	merge_sort(v, 0, v.size());
	quicksort(v0, 0, v0.size()-1);

	cout << "Hello\n" << v << endl << v0 << endl;
	getchar();

  return 0;
}

