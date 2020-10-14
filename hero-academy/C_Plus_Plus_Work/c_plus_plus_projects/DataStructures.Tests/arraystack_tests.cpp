#include "pch.h"
#include "CppUnitTest.h"
#include "../DataStructures/array_stack.hpp"
#include <cassert>
#include "crt_check_memory.hpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;
using namespace data_structures;

namespace data_structures_tests
{
	TEST_CLASS(TemplateTestClass)
	{
	public:

		TEST_METHOD(CheckFrontWithEmptyStackTest)
		{
			ArrayStack<int> the_big_le_stacky(7);

			//true that the front is -1 so empty
			Assert::IsTrue(the_big_le_stacky.Peek() == true);
		}



		TEST_METHOD(BuildSomeRacksWithStacksTest) //proper name: ConstructorArrayStackTest
		{
			CrtCheckMemory check;
			//all the puns intended
			ArrayStack<int> the_big_le_stacky(7);

			//lets fill that sucker up
			for (auto i = 0u; i < the_big_le_stacky.Size(); ++i)
			{
				the_big_le_stacky.Push(i);
			}

			Assert::IsTrue(the_big_le_stacky.Size() != 0);
		}

		TEST_METHOD(MIBFlashyWandStackTest) //proper name: ClearAllElementsInArrayStackTest
		{
			CrtCheckMemory check;
			//all the puns intended
			ArrayStack<int> the_big_le_stacky(7);

			//lets fill that sucker up
			for (auto i = 0u; i < the_big_le_stacky.Size(); ++i)
			{
				the_big_le_stacky.Push(i);
			}

			the_big_le_stacky.Clear();

			Assert::IsTrue(the_big_le_stacky.Empty());
		}

		TEST_METHOD(PopDatStackTest) //proper name: PopArrayStackTest
		{
			CrtCheckMemory check;
			//all the puns intended
			ArrayStack<int> the_big_le_stacky(7);

			//lets fill that sucker up
			for (auto i = 0u; i < the_big_le_stacky.Size(); ++i)
			{
				the_big_le_stacky.Push(i);
			}

			the_big_le_stacky.Pop();

			Assert::IsTrue(the_big_le_stacky.Size() == 7);
		}

		TEST_METHOD(TheGlutonTest) // proper name: [TryToPushToAFullArrayStackTest]
		{
			CrtCheckMemory check;

			bool exceptionThrown = false;

			try
			{
				//all the puns intended
				ArrayStack<int> the_big_le_stacky(7);

				//lets fill that sucker up
				for (auto i = 0u; i < the_big_le_stacky.Size(); ++i)
				{
					the_big_le_stacky.Push(i);
				}

				the_big_le_stacky.Push(12);
			}
			catch (AdtException&) // special exception type
			{
				exceptionThrown = true;
			}
			catch (...) // or any exception at all
			{
				exceptionThrown = true;
			}

			Assert::IsTrue(exceptionThrown);
		}

		TEST_METHOD(CopyConstructorTest)
		{
			CrtCheckMemory check;

			ArrayStack<int> the_big_le_stacky(10);
			//Act
			ArrayStack<int> copy_array(the_big_le_stacky);
			//Assert
			Assert::IsTrue(10 == copy_array.Size());
		}

		TEST_METHOD(TwoCopiedArrayStacksTest)
		{
			CrtCheckMemory check;

			ArrayStack<int> the_big_le_stacky(10);
			//Act
			ArrayStack<int> copy_array(the_big_le_stacky);
			//Assert
			Assert::IsTrue(the_big_le_stacky.Size() == copy_array.Size());

		}

		TEST_METHOD(CreateAZeroStackTest)
		{
			CrtCheckMemory check;

			bool exceptionThrown = false;
			try
			{
				ArrayStack<int> the_big_le_stacky(0);
			}

			catch (AdtException&)
			{
				exceptionThrown = true;
			}
			catch (...) // or any exception at all
			{
				exceptionThrown = true;
			}

			Assert::IsTrue(exceptionThrown);
		}

		TEST_METHOD(AssignmentOperatorTest)
		{
			CrtCheckMemory check;

			ArrayStack<int> the_big_le_stacky;

			ArrayStack<int> copy_stack(7);

			the_big_le_stacky = copy_stack;

			Assert::IsTrue(the_big_le_stacky.Size() == 7);
		}

		
		//This test  should technically work but I can't get the work around to have it not crash with the abort() error. 
		TEST_METHOD(TryToClearAnEmptyStackTest)
		{
			CrtCheckMemory check;

			bool exceptionThrown = false;

			try
			{
				ArrayStack<int> the_big_le_stacky(7);

				the_big_le_stacky.Clear();

			}
			catch (AdtException e)
			{
				exceptionThrown = true;
			}

			catch (...)
			{
				exceptionThrown = true;
			}

			Assert::IsFalse(exceptionThrown);
		}

	};
}
	