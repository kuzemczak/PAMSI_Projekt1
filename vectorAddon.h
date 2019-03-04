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
std::vector<T> merge(std::vector<T> &p, std::vector<T> &q, int mergedSize)
{
	int pcntr = 0, qcntr = 0;
	std::vector<T> ret;

	while (ret.size() < mergedSize)
	{
		if(pcntr == p.size())
			ret.insert(ret.end(), q.begin() + qcntr, q.end());
		else if (qcntr == q.size())
			ret.insert(ret.end(), p.begin() + pcntr, p.end());
		else if (p[pcntr] > q[qcntr])
		{
			ret.push_back(q[qcntr++]);
		}
		else
		{
			ret.push_back(p[pcntr++]);
		}
	}
	
	return ret;
}

template<typename T>
void value_swap(std::vector<T> &V, int i, int j)
{
	V[i] ^= V[j];
	V[j] ^= V[i];
	V[i] ^= V[j];
}

