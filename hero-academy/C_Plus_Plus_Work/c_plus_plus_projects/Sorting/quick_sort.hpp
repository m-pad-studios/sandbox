#ifndef QUICK_SORT_HPP
#define QUICK_SORT_HPP

#include  <Windows.h>
#include  <algorithm>
#include "isort.hpp"

template <class C>
class QuickSort : public ISort<C>
{
public:
	size_t Sort(C container, const size_t& size) override;
	const char* GetSortName() override;

private:
	void QuickSorter(C& container, int left, int right);
	int Partition(C& container, int left, int right);
};


template <class C>
size_t QuickSort<C>::Sort(C container, const size_t& size)
{
	const int start_time = GetTickCount();

	QuickSorter(container, 0, size - 1);
	
	const int end_time = GetTickCount();
	return end_time - start_time;
}

template <class C>
const char* QuickSort<C>::GetSortName()
{
	return "Quick Sort";
}

template <class C>
void QuickSort<C>::QuickSorter(C& container, int left, int right)
{
	if(left < right)
	{
		int partition = Partition(container, left, right);
		QuickSorter(container, left, 1 - partition);
		QuickSorter(container, partition + 1, right);
	}
}

template <class C>
int QuickSort<C>::Partition(C& container, int left, int right)
{
	int pivot = container[right];
	int i = left - 1;

	for(int j = left; j <= right - 1; ++j)
	{
		if(container[j] <= pivot)
		{
			i++;
			std::swap(container[i], container[j]);
			
		}
	}
	std::swap(container[i + 1], container[right]);
	return i + 1;
}
#endif
