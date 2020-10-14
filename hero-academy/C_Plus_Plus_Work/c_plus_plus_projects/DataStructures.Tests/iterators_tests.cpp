#include "pch.h"
#include "CppUnitTest.h"
#include "crt_check_memory.hpp"
#include "../DataStructures/linked_list.hpp"
using namespace data_structures;

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace data_structures_tests
{
	TEST_CLASS(TemplateTestClass)
	{
	public:
		//Had a harder time coming up with Rainy Day tests/Sunny Day ones for this. 
		//ITERATOR FUNCTION TESTS HERE
		TEST_METHOD(PreAndPostFixOperations_ShouldIncrementPreAndPost)
		{
			CrtCheckMemory check;

			LinkedList<int> link;

			int values[] = { 0,1,2,3,4 };

			for (auto& value : values)
			{
				link.Append(value);
			}
			auto it = link.ForwardBegin();

			for (; !it.Done(); ++it);

			Assert::AreEqual(values[4], *it);
		}

		TEST_METHOD(ForwardIteratorAssignmentOperator_ShouldAssign)
		{
			CrtCheckMemory check;

			LinkedList<size_t> list;

			for (size_t i = 0; i < 5; ++i)
			{
				list.Append(i * 5);
			}

			auto forward_iterator_1 = list.ForwardBegin();
			auto forward_iterator_2 = ForwardIterator<size_t>();
			forward_iterator_2 = forward_iterator_1; Assert::IsTrue(*forward_iterator_2 == *forward_iterator_1);
		}

		TEST_METHOD(ForwardIteratorBeginTest_FirstShoulEqualOperatorStar)
		{
			CrtCheckMemory check;

			LinkedList<size_t> list;

			for (size_t i = 0; i < 5; ++i)
			{
				list.Append(i * 5);
			}

			const auto forward_iterator = list.ForwardBegin();
			Assert::AreEqual(list.First(), *forward_iterator);
		}

		TEST_METHOD(BackwardIteratorBeginTest_LastShouldEqualOperatorStar)
		{

			CrtCheckMemory check; LinkedList<size_t> list;

			for (size_t i = 0; i < 5; ++i)
			{
				list.Append(i * 5);
			}

			const auto backward_iterator = list.BackwardBegin();

			Assert::AreEqual(list.Last(), *backward_iterator);
		}

		TEST_METHOD(ForwardIteratorEndTest_ForwardIteratorShouldBeDone) {
			CrtCheckMemory check;

			LinkedList<size_t> list;

			for (size_t i = 0; i < 5; ++i)
			{
				list.Append(i * 5);
			}
			auto forward_iterator = list.ForwardEnd();

			Assert::IsTrue(forward_iterator.Done());
		}

		TEST_METHOD(BackwardIteratorEndTest_BackwardIteratorShouldBeDone) {

			CrtCheckMemory check;

			LinkedList<size_t> list;

			for (size_t i = 0; i < 5; ++i)
			{
				list.Append(i * 5);
			}
			auto backward_iterator = list.BackwardEnd();

			Assert::IsTrue(backward_iterator.Done());
		}

		TEST_METHOD(ForwardIteratorAssignment_ForwardBeginShouldReturnFirst)
		{

			CrtCheckMemory check;

			LinkedList<size_t> list;

			for (size_t i = 0; i < 5; ++i)
			{
				list.Append(i * 5);
			}

			const auto forward_iterator = list.ForwardBegin();

			Assert::AreEqual(list.First(), *forward_iterator);

		}


		TEST_METHOD(BackwardIteratorAssignment_BackwardBeginShouldReturnLast)
		{

			CrtCheckMemory check;

			LinkedList<size_t> list;

			for (size_t i = 0; i < 5; ++i)
			{
				list.Append(i);
			}

			const auto backward_iterator = list.BackwardBegin();

			Assert::AreEqual(list.Last(), *backward_iterator);

		}

		TEST_METHOD(ForwardIteratorReset)
		{

			CrtCheckMemory check;

			LinkedList<size_t> list;

			list.Append(1);
			list.Append(2);
			list.Append(3);
			list.Append(4);
			list.Append(5);
			list.Append(6);
			list.Append(7);

			auto forward_iterator = list.ForwardBegin();

			for (int i = 0; i < 3; i++) {
				for (int j = 0; j < 3; j++)
				{
					++forward_iterator;
				}

				forward_iterator.Reset();

			}

			Assert::AreEqual(list.First(), *forward_iterator);

		}

		TEST_METHOD(ForwardIteratorMoveNext_ShouldMoveNext)
		{

			CrtCheckMemory check;

			size_t values[] = { 1, 2, 3, 4, 5, 6, 7 };

			size_t i = 0;

			LinkedList<size_t> list;

			list.Append(1);
			list.Append(2);
			list.Append(3);
			list.Append(4);
			list.Append(5);
			list.Append(6);
			list.Append(7);

			auto forward_iterator = list.ForwardBegin();

			while (!forward_iterator.Done())
			{
				Assert::AreEqual(values[i++], *forward_iterator++);
			}
		}

		TEST_METHOD(PreAndPostFixOperations_ShouldIncrementPreAndPos)
		{

			CrtCheckMemory check;

			size_t values[] = { 1, 2, 3, 4, 5, 6, 7 };

			LinkedList<size_t> list;

			list.Append(1);
			list.Append(2);
			list.Append(3);
			list.Append(4);
			list.Append(5);

			auto forward_iterator = list.ForwardBegin();

			const auto current_value = *forward_iterator; Assert::AreEqual(static_cast<size_t>(1), current_value);

			const auto value_with_post_increment = *forward_iterator++; Assert::AreEqual(static_cast<size_t>(1), value_with_post_increment);

			const auto value_after_post_increment = *forward_iterator; Assert::AreEqual(static_cast<size_t>(2), value_after_post_increment);

			const auto value_with_pre_increment = *++forward_iterator; Assert::AreEqual(static_cast<size_t>(3), value_with_pre_increment);

			const auto value_after_pre_increment = *forward_iterator; Assert::AreEqual(static_cast<size_t>(3), value_after_pre_increment);
		}
	
		TEST_METHOD(BackwardIteratorReset_ShouldReset) { 
			
			CrtCheckMemory check; 
			size_t values[] = { 1, 2, 3, 4, 5, 6, 7 };

			size_t i = 0;

			LinkedList<size_t> list;

			list.Append(1);
			list.Append(2);
			list.Append(3);
			list.Append(4);
			list.Append(5);
			list.Append(6);
			list.Append(7);

			auto backward_iterator = list.BackwardBegin();

			while (!backward_iterator.Done())
			{
				Assert::AreEqual(values[i--], *backward_iterator);
			}
			 }
	};
}
