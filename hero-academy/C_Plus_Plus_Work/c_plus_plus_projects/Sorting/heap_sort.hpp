#ifndef HEAP_SORT_HPP
#define HEAP_SORT_HPP
#include "isort.hpp"

template <class C>
class HeapSort : public ISort<C>
{
public:
	size_t Sort(C container, const size_t& size) override;
	const char* GetSortName() override;
private:
	void Heapify_(C sort_me, int size, int root);
	void HeapSorter(C arr, int size);
};


template <class C>
size_t HeapSort<C>::Sort(C container, const size_t& size)
{
	const int start_time = GetTickCount();

	HeapSorter(container, size - 1);

	const int end_time = GetTickCount();
	return end_time - start_time;
	
}

template <class C>
const char* HeapSort<C>::GetSortName()
{
	return "Heap Sort";
}

template <class C>
void HeapSort<C>::Heapify_(C sort_me, int size, int root)
{
	auto largest = root;
	auto left_child = 2 * root + 1;
	auto right_child = 2 * root + 2;
	if (left_child < size && sort_me[left_child] > sort_me[largest])
		largest = left_child;
	if (right_child < size && sort_me[right_child] >
		sort_me[largest])
		largest = right_child;
	if (largest != root)
	{
		std::swap(sort_me[root], sort_me[largest]);
		Heapify_(sort_me, size, largest);
	}
}

template <class C>
void HeapSort<C>::HeapSorter(C arr, int size)
{
	for (int i = (size / 2) - 1; i >= 0; i--)
		Heapify_(arr, size, i);
	for (int i = size - 1; i >= 0; i--)
	{
		std::swap(arr[0], arr[i]);
		Heapify_(arr, i, 0);
	}
}
#endif
