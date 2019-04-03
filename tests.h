#ifndef TESTS_H
#define TESTS_H

#include <chrono>
#include <random>
#include <iostream>
#include <string>
#include <fstream>

#include "randutils.hpp"
#include "quicksort.h"

#define CONSOLE_OUTPUT
#define FILE_OUTPUT

// funkcja sprawdzajaca posortowanie tablicy
template<typename T>
bool checkSorted(T * V, int size)
{
	for (int i = 1; i < size; i++)
		if (V[i - 1] > V[i])
		{
			return false;
		}

	return true;
}

// funkcja testujaca czas wykonywania funkcji sortujacej.
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

thread_local std::mt19937 gen{ std::random_device{}() };

template<typename T>
T random(T min, T max) {
	return std::uniform_int_distribution<T>{min, max}(gen);
}

int runTests(int(*testedFunction)(int*, int, int), std::string name)
{
	int sizes[5] = { 10000, 50000, 100000, 500000, 1000000 };
	double partSorted[7] = { 0, 0.25, 0.50, 0.75, 0.95, 0.99, 0.997 };
	char cases[8] = { 0,0,0,0,0,0,0,1 };
	randutils::mt19937_rng rng;
	std::ofstream file;
	file.open("wyniki.csv", std::ios_base::app);

#ifdef FILE_OUTPUT
	file << "\n" << name << "\n";
#endif

#ifdef FILE_OUTPUT
	file << name;
	for (int i = 0; i < 5; i++)
		file << "\t" << sizes[i];
	file << std::endl;
#endif // FILE_OUTPUT

	// petla wyboru przypadku (0%, 25% itd.)
	//for (int l = 0; l < 8; l++)
	//{
	int l = 7; // wybor szczegolnego
		// wypisanie przypadku
		if (cases[l])
		{
#ifdef CONSOLE_OUTPUT 
			std::cout << "All reverse sorted:\n";
#endif
#ifdef FILE_OUTPUT 
			file << "All_rev";
#endif
		}
		else
		{
#ifdef CONSOLE_OUTPUT 
			std::cout << partSorted[l] * 100 << "% first elements sorted:\n";
#endif
#ifdef FILE_OUTPUT 
			file << partSorted[l] * 100 << "%";
#endif
		}
#ifdef CONSOLE_OUTPUT 
		std::cout << "\taverage time for:\n";
#endif
		// petla wyboru wielkosci tablicy
		for (int k = 0; k < 5; k++)
		{
		// int k = 3; // wybor szczegolnego
#ifdef CONSOLE_OUTPUT 
			std::cout << "\t\t" << sizes[k] << " elements: ";
#endif
			double mean = 0;      // srednia
			int iterations = 100;	// liczba prob

			// petla wywolujaca funkcje sortujaca
			for (int i = 0; i < iterations; i++)
			{
				int *tab = new int[sizes[k]];
				
				// petla wypelniajaca tablice
				for (int j = 0; j < sizes[k]; j++)
				{
					if (!cases[l])
					{
							tab[j] = rng.uniform(-1000000, 1000000);
					}
					else
						tab[j] = sizes[k] - j;
				}
				if (!cases[l]) // sortowanie czesci tablicy
					merge_sort(tab, 0, partSorted[l] * sizes[k]);

				mean += testSortingTime(testedFunction, tab, 0, sizes[k]);
				//showPivots(); // pokazanie wynikow wyborow pivota dla quicksorta
				// sprawdzenie posortowania tablicy
				if (!checkSorted(tab, sizes[k]))
				{
#ifdef CONSOLE_OUTPUT 
					std::cout << "Sorting failed. Size: " << sizes[k]
						<< ", iteration: " << i << std::endl;
#endif
					file.close();
					return 1;
				}

				delete tab;
			}
			mean /= (double)iterations;

#ifdef CONSOLE_OUTPUT 
			std::cout << "\t" << mean << " ms\n";
#endif
#ifdef FILE_OUTPUT 
			file << "\t" << mean;
#endif
		}
#ifdef FILE_OUTPUT
		file << std::endl;
#endif
	}
	file.close();

	return 0;
}

#endif