#ifndef INSERTION_SORT_HPP
#define INSERTION_SORT_HPP

#include <windows.h>
#include <algorithm>
#include "isort.hpp"


template <class C>
class InsertionSort : public ISort<C>
{
public:
	size_t Sort(C container, const size_t& size) override;
	const char* GetSortName() override;
};


template <class C>
size_t InsertionSort<C>::Sort(C container, const size_t& size)
{
	const int start_time = GetTickCount();
	
	for (int i = 1; i < size; i++) {
		// a[i] is the next data to insert
		int next = container[i];
		// Scan backwards to find a place.
		int j;
		for (j = i - 1; j >= 0 && container[j] > next; j--)
			container[j + 1] = container[j];
		// Now insert the value next after index j at the end of loop
		container[j + 1] = next;
	}
	const int end_time = GetTickCount();

	return end_time - start_time;
}

template <class C>
const char* InsertionSort<C>::GetSortName()
{
	return "Insertion Sort";
}


#endif
