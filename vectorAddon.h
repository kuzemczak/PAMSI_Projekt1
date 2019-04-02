#ifndef VECTORADDON_H
#define VECTORADDON_H


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
void Swap(T & v0, T & v1)
{
	T tmp = v0;
	v0 = v1;
	v1 = tmp;
}

#endif

