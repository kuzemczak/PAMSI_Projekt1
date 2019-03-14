#pragma once

#include <chrono>
#include <random>
#include <iostream>
#include <string>
#include <fstream>

#include "randutils.hpp"

#define CONSOLE_OUTPUT
//#define FILE_COMMENT_OUTPUT
#define FILE_OUTPUT

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
	file.open("wyniki.csv", ios_base::app);

#ifdef FILE_OUTPUT
	file << "\n" << name << "\n";
#endif
	
	for (int k = 0; k < 5; k++)
	{
		for (int l = 0; l < 8; l++)
		{
#ifdef CONSOLE_OUTPUT 
			std::cout << name << " of a vector with ";
#endif
#ifdef FILE_COMMENT_OUTPUT 
			file << name << " of a vector with ";
#endif
			if (cases[l])
			{
#ifdef CONSOLE_OUTPUT 
				std::cout << "All reverse sorted:\n";
#endif
#ifdef FILE_OUTPUT 
				file << "All_rev,";
#endif
			}
			else
			{
#ifdef CONSOLE_OUTPUT 
				std::cout << partSorted[l] * 100 << "% first elements sorted:\n";
#endif
#ifdef FILE_OUTPUT 
				file << partSorted[l] * 100 << "%\,";
#endif
			}
#ifdef CONSOLE_OUTPUT 
			std::cout << "\taverage time for:\n";
#endif
#ifdef FILE_COMMENT_OUTPUT 
			file << "\taverage time for:\n";
#endif
			double mean = 0;
#ifdef CONSOLE_OUTPUT 
			std::cout << "\t\t" << sizes[k] << " elements: ";
#endif
#ifdef FILE_OUTPUT 
			file << sizes[k] << ",";
#endif
			int iterations = 100;
			for (int i = 0; i < iterations; i++)
			{
				int *tab = new int[sizes[k]];
				for (int j = 0; j < sizes[k]; j++)
				{
					if (!cases[l])
					{
						if (j < static_cast<int>(partSorted[l] * sizes[k]))
							tab[j] = j;
						else
							tab[j] = rng.uniform(-1000000, 1000000);
					}
					else
						tab[j] = sizes[k] - j;
				}

				mean += testSortingTime(testedFunction, tab, 0, sizes[k]);
				if (!checkSorted(tab, sizes[k]))
				{
#ifdef CONSOLE_OUTPUT 
					std::cout << "Sorting failed. Size: " << sizes[k]
						<< ", iteration: " << i << std::endl;
#endif
#ifdef FILE_COMMENT_OUTPUT 
					file << "Sorting failed. Size: " << sizes[k]
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
			file << mean << "\n";
#endif
		}
	}
	file.close();

	return 0;
}