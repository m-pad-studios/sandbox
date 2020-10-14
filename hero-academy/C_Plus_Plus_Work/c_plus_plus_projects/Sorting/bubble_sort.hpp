#ifndef BUBBLE_SORT_HPP
#define BUBBLE_SORT_HPP

#include <windows.h>
#include <algorithm>
#include "isort.hpp"

template <class C>
class BubbleSort : public ISort<C>
{
public:
	size_t Sort(C container, const size_t& size) override;
	const char* GetSortName() override;
};

template <class C>
size_t BubbleSort<C>::Sort(C container, const size_t& size)
{
	const int start_time = GetTickCount();

	for (auto i = 1u; i < size; i++) {
		for (auto j = 0u; j < size - i; j++) {
			if (container[j] > container[j + 1]) { // the larger item bubbles down (swap)
				std::swap(container[j], container[j + 1]);
			}
		}
	}
	const int end_time = GetTickCount();

	return end_time - start_time;
}

template <class C>
const char* BubbleSort<C>::GetSortName()
{
	return "Bubble Sort";
}
#endif
