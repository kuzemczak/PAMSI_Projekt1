#pragma once

#include <vector>
#include <iostream>

template <typename T>
std::ostream& operator<< (std::ostream& out, const std::vector<T>& v) {
	if (!v.empty()) {
		out << '[';

		for (T element : v)
			out << element << ", ";

		out << "\b\b]";
	}
	return out;
}

template<typename T>
std::vector<T> subVector(std::vector<T> &V, int start, int end)
{
	typename std::vector<T>::const_iterator first;
	first = V.begin() + start;
	typename std::vector<T>::const_iterator last;
	last = V.begin() + end;
	std::vector<T> ret(first, last);

	return ret;
}



template<typename T>
void value_swap(std::vector<T> &V, int i, int j)
{
	V[i] ^= V[j];
	V[j] ^= V[i];
	V[i] ^= V[j];
}

