#ifndef SHELL_SORT_HPP
#define SHELL_SORT_HPP

#include "isort.hpp"
#include <Windows.h>


template <class C>
class ShellSort final : public ISort<C>
{
public:
	size_t Sort(C container, const size_t& size) override;
	const char* GetSortName() override;
};


template <class C>
size_t ShellSort<C>::Sort(C container, const size_t& size)
{
	const auto start = GetTickCount();
	
	int j;
	for (int h = size / 2; h > 0; h /= 2) {
		for (int i = h; i < size; i++) {
			size_t tmp = container[i];
			for (j = i; j >= h && tmp < container[j - h];
				j -= h) {
				container[j] = container[j - h];
			}
			container[j] = tmp;
		}
	}
	const auto end = GetTickCount();

	return end - start;
}

template <class C>
const char* ShellSort<C>::GetSortName()
{
	return "Shell Sort";
}
#endif
