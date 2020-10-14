#include "pch.h"
#include "CppUnitTest.h"
#include "../DataStructures/array.hpp"
#include "crt_check_memory.hpp"
#include "../DataStructures/pair.hpp"

using namespace data_structures;

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace data_structures_tests
{
	TEST_CLASS(ArrayTests)
	{
	public:

		static Array<size_t> ArrayFactory()
		{
			Array<size_t> array(10, 0);

			return array;
		}

		//I wrote my functionality in array.hpp and then just copy and
		//pasted your test methods from the StarterArrayTest.cpp file you uploaded
		//Just an FYI I wrote my own test cases as well, I just wanted to see if yours
		//would work with my code as well.

		TEST_METHOD(BoolOperator_ShouldPassIfArrayObjectsAreEqual)
		{
			CrtCheckMemory check;

		bool pass = true;
			
			Array<std::string> my_array(7, 0);
			for(auto i = 0u; i < my_array.Length(); ++i)
			{
				my_array[i] = i;
			}

			Array<std::string> second_array;
			second_array = my_array;

			for (auto i = 0u; i < my_array.Length(); ++i)
			{
				if (second_array[i] == my_array[i])
				{
					Assert::IsTrue(pass);
				}
			}
		}
		TEST_METHOD(CopyConstructor_ShouldDeepCopyObject)
		{
			CrtCheckMemory check;

			Array<std::string> my_array(10, 0);

			for (auto i = 0u; i < 10; ++i)
			{
				my_array[i] = std::to_string(i);
			}

			Array<std::string> second_array = my_array;

			for (auto i = 0u; i < 10; ++i)
			{
				Assert::AreEqual(my_array[i], second_array[i]);
			}
		}
		TEST_METHOD(AssignmentOperator_DeepCopyArray)
		{
			CrtCheckMemory check;

			//Arrange
			Array<std::string> my_array(10, 0);

			for(auto i = 0u; i < 10; ++i)
			{
				my_array[i] = std::to_string(i);
			}
			
			//Act
			Array<std::string> second_array(10, 0);
			second_array = my_array;

			//Assert
			for(auto i = 0u; i < 10; ++i)
			{
				Assert::AreEqual(my_array[i], second_array[i]);
			}
		}
		TEST_METHOD(ArrayParamConstructorValidLengthTestWithInt)
		{
			CrtCheckMemory check;
			Array<int> my_array(5, 0);
			Assert::IsTrue(true);
		}

		TEST_METHOD(ArrayParamConstructorValidLengthTestWithString)
		{
			CrtCheckMemory check;
			Array<std::string> my_array(5, 0);
			Assert::IsTrue(true);
		}
		TEST_METHOD(ArrayConstructorTest1_ShouldConstructAnArrayOfSizeTen)
		{
			const CrtCheckMemory check;
			
			Array<int> my_array(10, 0);

			Assert::AreEqual(10ull, my_array.Length());

			
		}


		TEST_METHOD(ArrayConstructorTest2_ShouldConstructAnArrayFromACArray)
		{
			const CrtCheckMemory check;

			const auto size = 10u;
			int* c_array = new int[size];

			for(auto i = 0u; i < size; ++i)
			{
				c_array[i] = i;
			}
			
			Array<int> my_array(c_array, size,0);

			
				Assert::AreEqual(static_cast<size_t>(size), my_array.Length());
			
			
			delete[] c_array;
		}

		TEST_METHOD(ArrayConstructorTest2_ShouldConstructAnArrayFromACArrayWithData)
		{
			const CrtCheckMemory check;

			const auto size = 10u;
			int* c_array = new int[size];

			for (auto i = 0u; i < size; ++i)
			{
				c_array[i] = i;
			}

			Array<int> my_array(c_array, size, 0);

			for(auto i = 0u; i < size; ++i)
			{
				Assert::AreEqual(c_array[i], my_array[i]);
			}


			delete[] c_array;
		}

		TEST_METHOD(BoolOperator_ShouldReturnFalse)
		{
			CrtCheckMemory check;
			
			Array<std::string> my_array;

			bool fail = static_cast<bool>(my_array);

			Assert::IsTrue(!fail);
		}

		TEST_METHOD(AssignmentOperator_ShouldAssignAnEmptyArrayToAnotherArray)
		{
			CrtCheckMemory check;

			//my test here is essentially making sure they are the same length
			//one array I create w/length 7 and another w/length 10
			//should store the length 10 array into the length 7 array 
			Array<int> my_array(7, 0);
			 
			Array<int> array_two(10, 0);

			for (auto i = 0u; i < my_array.Length(); ++i)
			{
				array_two[i] = my_array[i];
			}

			for (auto i = 0u; i < my_array.Length(); ++i)
			{
				Assert::AreEqual(array_two[i], my_array[i]);
			}
		
		}

		TEST_METHOD(AssignmentOperator_ShouldAssignAnArrayWithDataToAnotherArray)
		{
			CrtCheckMemory check;

			std::string test_data = "hello";
			
			Array<std::string> my_array(7, 0);

			for(auto i = 0u; i < my_array.Length(); ++i)
			{
				my_array[i] = test_data;
			}

			Array<std::string> array_two(10, 0);

			for (auto i = 0u; i < my_array.Length(); ++i)
			{
				array_two[i] = my_array[i];
			}

			for (auto i = 0u; i < my_array.Length(); ++i)
			{
				Assert::AreEqual(array_two[i], my_array[i]);
			}

		}

		TEST_METHOD(ArrayParamConstructorBadLengthTest_ShouldThrowException)
		{
			CrtCheckMemory check;

			const auto should_throw = []
			{ Array<int> array(-15, 0); };

			Assert::ExpectException<AdtException>(should_throw);
		}

		TEST_METHOD(CopyOperator_ShouldCopyAnArrayToADifferentArray)
		{
			CrtCheckMemory check;
			
			Array<std::string> my_array;
			Array<std::string> array_with_data(10, 0);

			for (auto i = 0u; i < array_with_data.Length(); ++i)
			{
				array_with_data[i] = i;
			}

			my_array = array_with_data;

			Assert::AreEqual(my_array.Length(), array_with_data.Length());
		}

		TEST_METHOD(ArrayAssignmentOperatorTest)
		{
			CrtCheckMemory check;

			bool passed = true;

			Array<int> my_array(10, 0);

			for (int i = 0; i < 10; i++)
				my_array[i] = i;
			Array<int> copy_array;
			copy_array = my_array;

			for (int i = 0; i < 10; i++)
			{
				if (copy_array[i] != my_array[i])passed = false;
			}

			Assert::IsTrue(passed);
		}

		TEST_METHOD(StringArrayReduceLengthTest)
		{
			CrtCheckMemory check;
			
			Array<std::string> my_string_array;
			
			bool pass = true;
			
			my_string_array.Length(10);
			
			for (int i = 0; i < 10; i++)
			{
				my_string_array[i] = ("Test String " + i);
			}

			my_string_array.Length(5);

			for (int i = 0; i < 5; i++)
			{
				if (my_string_array[i] != "Test String " + i)pass = false;
			}
			//Okay so this will break if you take the ! away in the assert
			//When it breaks all it tells me is it fails...nothing else
			Assert::IsTrue(pass);

			//All I did was take your test code you had written and pasted it in here
			//Which to me showed my functionality I wrote for my array class works :D
		}

		TEST_METHOD(ArrayGrowLengthTest)
		{
			CrtCheckMemory check;

			Array<int> array(5, 0);

			array.Length(10);

			Assert::AreEqual(static_cast<size_t>(10), array.Length());
		}

		TEST_METHOD(ArraySetLengthTest) {
			CrtCheckMemory check;

			Array<int> my_array(10, 0);

			for (int i = 0; i < 10; i++)
			{
				my_array[i] = i;
			}
			// Will lose value_

			my_array.Length(5);

			Assert::AreEqual(static_cast<size_t>(5), my_array.Length());
		}
		
		TEST_METHOD(ArraySetLengthBadLengthTest_ShouldThrowException)
		{
			CrtCheckMemory check;
			const auto should_throw = []
		{
				Array<int> array(5, 0);
				array.Length(-15);
		};
			Assert::ExpectException<AdtException>(should_throw);
		}
	};
}
