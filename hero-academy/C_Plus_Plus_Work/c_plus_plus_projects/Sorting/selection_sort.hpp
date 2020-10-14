#ifndef SELECTION_SORT_HPP
#define SELECTION_SORT_HPP

#include "isort.hpp"
#include <Windows.h>

template <class C>
class SelectionSort final : public ISort<C>
{
public:
	size_t Sort(C container, const size_t& size) override;
	const char* GetSortName() override;
};


template <class C>
size_t SelectionSort<C>::Sort(C container, const size_t &size)
{
	const auto start = GetTickCount();

	for (int i = size - 1; i >= 1; i--) {
		int index = i; // i is the last item position and
		// index is the largest element position
		// loop to get the largest element
		for (int j = 0; j < i; j++) {
			if (container[j] > container[index])
				index = j; // j is the current largest item
		}
		// Swap the largest item a[index] with the last item a[i]
		std::swap(container[i], container[index]);
	}
	const auto end = GetTickCount();

	return end - start;
}

template <class C>
const char* SelectionSort<C>::GetSortName()
{
	return "Selection Sort";
}
#endif
