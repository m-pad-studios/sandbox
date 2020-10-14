#ifndef MERGE_SORT_HPP
#define MERGE_SORT_HPP

#include  <Windows.h>
#include "isort.hpp"

template <class C>
class MergeSort : public ISort<C>
{
public:
	size_t Sort(C container, const size_t& size) override;
	const char* GetSortName() override;

private:
	void MergeSorter(C& container, int i, int j);
	void Merge(C& container, int i, int mid, int j);
};


template <class C>
size_t MergeSort<C>::Sort(C container, const size_t& size)
{
	const int start_time = GetTickCount();

	MergeSorter(container, 0, size - 1);

	const int end_time = GetTickCount();
	return end_time - start_time;
}

template <class C>
const char* MergeSort<C>::GetSortName()
{
	return "Merge Sort";
}

template <class C>
void MergeSort<C>::MergeSorter(C& container, int i, int j)
{
	// to sort data from a[i] to a[j], where i<j
	if (i < j) {
		int mid = (i + j) / 2; // divide
		MergeSorter(container, i, mid); // recursion
		MergeSorter(container, mid + 1, j);
		Merge(container, i, mid, j); //conquer: merge a[i..mid] and
		//a[mid+1..j] back into a[i..j]
	}
}

template <class C>
void MergeSort<C>::Merge(C& container, int i, int mid, int j)
{
	// Merges the 2 sorted sub-arrays a[i..mid] and
// a[mid+1..j] into one sorted sub-array a[i..j]
	int size = j - i + 1;
	int* temp = new int[j - i + 1]; // temp storage
	int left = i, right = mid + 1, it = 0;
	
	// it = next index to store merged item in temp[]
	while (left <= mid && right <= j) { // output the smaller
		if (container[left] <= container[right])
			temp[it++] = container[left++];
		else
			temp[it++] = container[right++];
	}
	// Copy the remaining elements into temp.
	while (left <= mid) temp[it++] = container[left++];
	while (right <= j) temp[it++] = container[right++];
	
	// Copy the result in temp back into
	// the original array a

	//how are you getting the length of temp here? This will not run for me if I don't specify temp this way it throws an exception
	for (int k = 0; k < size; k++)
	{
		container[i + k] = temp[k];
	}
	delete[] temp;
	
}
#endif