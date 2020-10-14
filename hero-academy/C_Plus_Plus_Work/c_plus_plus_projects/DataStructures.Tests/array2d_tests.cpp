#include "pch.h"
#include "CppUnitTest.h"
#include "../DataStructures/array2d.hpp"
#include "crt_check_memory.hpp"
#include <iostream>

using namespace Microsoft::VisualStudio::CppUnitTestFramework;
using namespace data_structures;
namespace data_structures_tests
{
	TEST_CLASS(Array2DTest)
	{
	public:

		TEST_METHOD(CreateRowsTest)
		{
			CrtCheckMemory check;

			Array2D<int> ghost2D(7, 7);
			Array2D<int> array2D(7,7);

			Assert::AreEqual(ghost2D.Rows(), array2D.Rows());
		}

		TEST_METHOD(ResizeSameColumnsTest)
		{
			CrtCheckMemory check;

			Array2D<int> ghost2D(7, 7);

			ghost2D.Columns(5);
			ghost2D.Columns(7);
			
			Assert::AreEqual(ghost2D.Columns(), ghost2D.Columns());
		}
		TEST_METHOD(CreateColumnsTest)
		{
			CrtCheckMemory check;

			Array2D<int> ghost2D(7, 13);
			Array2D<int> array2D(7, 13);

			Assert::AreEqual(ghost2D.Columns(), array2D.Columns());
		}

		TEST_METHOD(ResizeRowsTest)
		{
			CrtCheckMemory check;
			
			Array2D<int> ghost2D(2, 3);
			Array2D<int> array2D(7, 7);
			
			ghost2D.Rows(7);

			Assert::AreEqual(array2D.Rows(), ghost2D.Rows());
		}

		TEST_METHOD(ResizeColumnsTest)
		{
			CrtCheckMemory check;
			
			Array2D<int> ghost2D(2, 3);
			Array2D<int> array2D(7, 7);

			ghost2D.Columns(7);

			Assert::AreEqual(array2D.Columns(), ghost2D.Columns());
		}

		TEST_METHOD(ResizeColumnsBiggerDataLossTest)
		{
			CrtCheckMemory check;

			Array2D<int> ghost2D(3, 3);
			auto index = 0;

			for (size_t i = 0; i < 3; i++)
			{
				for (size_t j = 0; j < 3; j++)
				{
					ghost2D[i][j] = i * j;
					index += i * j;
				}
			}

			ghost2D.Columns(4);

			auto sum = 0;
			for(size_t i = 0; i < 3; ++i)
			{
				for(size_t j = 0; j < 4; ++j)
				{
					ghost2D[i][j] = i * j;
					sum += i * j;
				}
			}
			Assert::AreEqual(sum, sum);
		}
		TEST_METHOD(Array2DSetColumnDataLossTest) {
			CrtCheckMemory check;
			Array2D<int> myArray(3, 3);
			int index = 0;
			
			for (int i = 0; i < 3; i++)
			{
				for (int j = 0; j < 3; j++)
				{
					myArray[i][j] = index++;
				}
			}
			
			myArray.Columns(2);
			
			int total = 0;
			for (int i = 0; i < myArray.Rows(); ++i)
			{
				for (int j = 0; j < myArray.Columns(); ++j)
				{
					total += myArray[i][j];
					
				}
			}
			
			Assert::IsTrue(total == 21);
		}

		TEST_METHOD(Array2DSetRowDataLossTest) {
			CrtCheckMemory check;
			Array2D<int> myArray(3, 3);
			int index = 0;

			for (int i = 0; i < 3; i++)
				for (int j = 0; j < 3; j++)
					myArray[i][j] = index++;
			
			myArray.Rows(2);
			int total = 0;

			for (int i = 0; i < myArray.Rows(); i++)
				for (int j = 0; j < myArray.Columns(); j++)
					total += myArray[i][j];
			Assert::IsTrue(total == 15);
		}

		TEST_METHOD(BoolEqualOperatorCheck)
		{
			CrtCheckMemory check;

			bool pass = true;
			Array2D<int> my_array(3, 3);
			int index = 0;
			
			for (auto i = 0u; i < my_array.Rows(); ++i)
			{
				for(auto j = 0u; j < my_array.Columns(); ++j)
				{
					my_array[i][j] = index++;
				}
			}

			Array2D<int> second_array;
			second_array = my_array;

			for (auto i = 0u; i < my_array.Rows(); ++i)
			{
				for (auto j = 0u; j < my_array.Columns(); ++j)
				{
					if (second_array[i][j] == my_array[i][j])
					{
						Assert::IsTrue(pass);
					}
				}
			}
		}
		
	};
}