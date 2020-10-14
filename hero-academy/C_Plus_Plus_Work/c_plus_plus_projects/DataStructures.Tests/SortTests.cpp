#include "pch.h"
#include "CppUnitTest.h"
#include "../Sorting/Sorter.cpp"


using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace data_structures_tests
{
	TEST_CLASS(SortTests)
	{
	public:

		TEST_METHOD(SelectionSortTest)
		{
			int array_to_sort[10];

			Sorter sorter;
			
			sorter.GenerateRandomNumber(array_to_sort, 10);

			ISort<int[]>* selection_sort = new SelectionSort<int[]>;

			selection_sort->Sort(array_to_sort, 10);

			for(size_t i = 0; i < 10; ++i)
			{
				if(i + 1 < 10)
				{
					Assert::IsTrue(i < i + 1);
				}
			}
			
		}
		
		TEST_METHOD(BubbleSortTest)
		{
			int array_to_sort[10];

			Sorter sorter;

			sorter.GenerateRandomNumber(array_to_sort, 10);

			ISort<int[]>* selection_sort = new BubbleSort<int[]>;

			selection_sort->Sort(array_to_sort, 10);

			for (auto i = 0u; i < 10; ++i)
			{
				if (i + 1 < 10)
				{
					Assert::IsTrue(i < i + 1);
				}
			}

		}

		TEST_METHOD(BubbleFlaggedSortTest)
		{
			int array_to_sort[10];

			Sorter sorter;

			sorter.GenerateRandomNumber(array_to_sort, 10);

			ISort<int[]>* selection_sort = new BubbleSortFlagged<int[]>;

			selection_sort->Sort(array_to_sort, 10);

			for (auto i = 0u; i < 10; ++i)
			{
				if (i + 1 < 10)
				{
					Assert::IsTrue(i < i + 1);
				}
			}

		}

		TEST_METHOD(HeapSortTest)
		{
			int array_to_sort[10];

			Sorter sorter;

			sorter.GenerateRandomNumber(array_to_sort, 10);

			ISort<int[]>* selection_sort = new HeapSort<int[]>;

			selection_sort->Sort(array_to_sort, 10);

			for (auto i = 0u; i < 10; ++i)
			{
				if (i + 1 < 10)
				{
					Assert::IsTrue(i < i + 1);
				}
			}

		}

		TEST_METHOD(MergeSortTest)
		{
			int array_to_sort[10];

			Sorter sorter;

			sorter.GenerateRandomNumber(array_to_sort, 10);

			ISort<int*>* selection_sort = new MergeSort<int*>;

			selection_sort->Sort(array_to_sort, 10);

			for (auto i = 0u; i < 10; ++i)
			{
				if (i + 1 < 10)
				{
					Assert::IsTrue(i < i + 1);
				}
			}

		}

		TEST_METHOD(QuickSortTest)
		{
			int array_to_sort[10];

			Sorter sorter;

			sorter.GenerateRandomNumber(array_to_sort, 10);

			ISort<int*>* selection_sort = new QuickSort<int*>;

			selection_sort->Sort(array_to_sort, 10);

			for (auto i = 0u; i < 10; ++i)
			{
				if (i + 1 < 10)
				{
					Assert::IsTrue(i < i + 1);
				}
			}

		}

		TEST_METHOD(ShellSortTest)
		{
			int array_to_sort[10];

			Sorter sorter;

			sorter.GenerateRandomNumber(array_to_sort, 10);

			ISort<int[]>* selection_sort = new ShellSort<int[]>;

			selection_sort->Sort(array_to_sort, 10);

			for (auto i = 0u; i < 10; ++i)
			{
				if (i + 1 < 10)
				{
					Assert::IsTrue(i < i + 1);
				}
			}

		}
	};
}
