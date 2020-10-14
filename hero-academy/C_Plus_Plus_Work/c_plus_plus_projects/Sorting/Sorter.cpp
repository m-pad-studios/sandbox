#include <iostream>
#include <random>
#include <vector>
#include <fstream>

#include "../DataStructures/array.hpp"
#include "bubble_sort.hpp"
#include "bubble_sort_flagged.hpp"
#include "heap_sort.hpp"
#include "insertion_sort.hpp"
#include "isort.hpp"
#include "merge_sort.hpp"
#include "quick_sort.hpp"
#include "selection_sort.hpp"
#include "shell_sort.hpp"

using namespace data_structures;

using std::cout;
using std::endl;
using std::vector;
using std::ofstream;

class Sorter
{
public:
	void RunSortsForSizeN(const int numbers_to_sort[], const int& size)
	{
		ofstream fout;
		fout.open("SortingGraphNums.txt");
		
		Array<int> adt_array(size);
		int* c_array = new int[size];
		vector<int> vector_array(size);

		for (size_t i = 0; i < size; ++i)
		{
			adt_array[i] = c_array[i] = vector_array[i] = numbers_to_sort[i];
		}

		ISort<Array<int>>* adt_array_sorts[]
		{
			new SelectionSort<Array<int>>(),
			new BubbleSort<Array<int>>(),
			new BubbleSortFlagged<Array<int>>(),
			new QuickSort<Array<int>>(),
			new MergeSort<Array<int>>(),
			new HeapSort<Array<int>>(),
			new InsertionSort<Array<int>>(),
			new ShellSort<Array<int>>()
		};

		cout << "\nADT Arrays at N = " << size << "\n" << endl;
		for (ISort<Array<int>>* adt_array_sort : adt_array_sorts)
		{
			const size_t sort_time = adt_array_sort->Sort(adt_array, size);
			cout << adt_array_sort->GetSortName() << " : " << sort_time << endl;
			fout << adt_array_sort->GetSortName() << "\t" << sort_time << "\t\n" << endl;
			delete adt_array_sort;
		}
		
		cout << "\nC-arrays at N = " << size << "\n" << endl;
		ISort<int*>* c_array_sorts[]
		{
			new SelectionSort<int*>(),
			new BubbleSort<int*>(),
			new BubbleSortFlagged<int*>(),
			new QuickSort<int*>,
			new MergeSort<int*>,
			new HeapSort<int*>,
			new InsertionSort<int*>,
			new ShellSort<int*>
		};

		for (ISort<int*>* c_array_sort : c_array_sorts)
		{
			int* c_array_copy = new int[size];
			for (size_t i = 0; i < size; ++i)
			{
				c_array_copy[i] = c_array[i];
			}
			const size_t sort_time = c_array_sort->Sort(c_array, size);

			cout << c_array_sort->GetSortName() << " : " << sort_time << endl;
			fout << c_array_sort->GetSortName() << "\t" << sort_time << "\t\n" << endl;
			
			delete[] c_array_copy;
			delete c_array_sort;
		}

		cout << "\nVector Arrays at N = " << size << "\n" << endl;

		ISort<vector<int>>* vector_array_sorts[]
		{
			new SelectionSort<vector<int>>(),
			new BubbleSort<vector<int>>(),
			new BubbleSortFlagged<vector<int>>(),
			new QuickSort<vector<int>>(),
			new MergeSort<vector<int>>(),
			new HeapSort<vector<int>>(),
			new InsertionSort<vector<int>>(),
			new ShellSort<vector<int>>()
		};
		//enhanced for loop
		for (ISort<vector<int>>* vector_array_sort : vector_array_sorts)
		{
			const size_t sort_time = vector_array_sort->Sort(vector_array, size);
			cout << vector_array_sort->GetSortName() << " : " << sort_time << endl;
			fout << vector_array_sort->GetSortName() << "\t" << sort_time << "\t\n" << endl;
			delete vector_array_sort;
		}
		delete[] c_array;
		fout.close();
	}

	void GenerateRandomNumber(int numbers_to_sort[], const int& size)
	{
		std::random_device rd;
		std::mt19937 gen(rd());
		const std::uniform_int_distribution<int> dis(0, size);

		for (size_t i = 0; i < size; ++i)
		{
			const int random_number = dis(gen);
			numbers_to_sort[i] = random_number;
		}
	}

	void  Run()
	{
		{
			const long ten_k = 200000;
			int ten_k_array[ten_k];
			GenerateRandomNumber(ten_k_array, ten_k);
			RunSortsForSizeN(ten_k_array, ten_k);

			cout << "~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;	
		}
	}
};