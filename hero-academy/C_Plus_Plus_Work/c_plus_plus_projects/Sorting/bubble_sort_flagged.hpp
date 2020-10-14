#ifndef BUBBLE_SORT_FLAGGED_HPP
#define BUBBLE_SORT_FLAGGED_HPP

#include <windows.h>
#include <algorithm>
#include "isort.hpp"

template <class C>
class BubbleSortFlagged : public ISort<C>
{
public:
	size_t Sort(C container, const size_t& size) override;
	const char* GetSortName() override;
};

template <class C>
size_t BubbleSortFlagged<C>::Sort(C container, const size_t& size)
{
	const int start_time = GetTickCount();

	for (int i = 1; i < size; i++) {
		bool is_sorted = true; // is_sorted = true if a[] is sorted
		for (int j = 0; j < size - i; j++) {
			if (container[j] > container[j + 1]) { // the larger item bubbles up
				int temp = container[j]; // and is_sorted is set to false,
				container[j] = container[j + 1]; // i.e. the data was not sorted
				container[j + 1] = temp;
				is_sorted = false;
			}
		}
		const int end_time = GetTickCount();
		if (is_sorted) return end_time - start_time; // Why?
	}
}

template <class C>
const char* BubbleSortFlagged<C>::GetSortName()
{
	return "Bubble Sort Flagged";
}
#endif
