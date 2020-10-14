#include "pch.h"
#include "CppUnitTest.h"
#include "crt_check_memory.hpp"
#include "..//DataStructures/list_queue.hpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;
using namespace data_structures;

namespace data_structures_tests
{
	TEST_CLASS(List_Queue_Tests)
	{
	public:
		TEST_METHOD(MakeQueue_CheckEmpty)
		{
			CrtCheckMemory check;

			ListQueue<int> my_queue;

			Assert::IsTrue(my_queue.Empty());
		}
		TEST_METHOD(MakeQueue_CheckEmpty_WithCopyConstructor)
		{
			CrtCheckMemory check;

			ListQueue<int> my_queue;

			ListQueue<int> second_queue(my_queue);

			Assert::IsTrue(second_queue.Empty());
		}
		TEST_METHOD(MakeQueue_CheckEmpty_WithAssignmentOperator)
		{
			CrtCheckMemory check;

			ListQueue<int> my_queue;

			ListQueue<int> second_queue;
			second_queue = my_queue;

			Assert::IsTrue(second_queue.Empty());
		}
	
		TEST_METHOD(CheckValue_EnqueFiveValues_ThenCheckNotEmpty_WithCopyConstructor)
		{
			CrtCheckMemory check;

			ListQueue<int> my_queue;

			my_queue.Enqueue(5);
			my_queue.Enqueue(14);
			my_queue.Enqueue(21);
			my_queue.Enqueue(27);
			my_queue.Enqueue(33);

			ListQueue<int> second_queue(my_queue);

			Assert::AreEqual(5, second_queue.Front());
		}
		TEST_METHOD(CheckValue_EnqueFiveValues_ThenCheckNotEmpty_WithAssignmentOperator)
		{
			CrtCheckMemory check;

			ListQueue<int> my_queue;

			my_queue.Enqueue(5);
			my_queue.Enqueue(14);
			my_queue.Enqueue(21);
			my_queue.Enqueue(27);
			my_queue.Enqueue(33);

			ListQueue<int> second_queue;
			second_queue = my_queue;

			Assert::AreEqual(5, second_queue.Front());
		}
		TEST_METHOD(CheckValue_EnqueFiveValues_WithDequeue_ThenCheckNotEmpty)
		{
			CrtCheckMemory check;

			ListQueue<int> my_queue;

			my_queue.Enqueue(5);
			my_queue.Enqueue(14);
			my_queue.Dequeue();
			my_queue.Enqueue(21);
			my_queue.Enqueue(27);
			my_queue.Dequeue();
			my_queue.Enqueue(33);
			my_queue.Dequeue();

			Assert::AreEqual(27, my_queue.Front());
		}
		TEST_METHOD(CheckValue_EnqueFiveValues_WithDequeue_ThenCheckNotEmpty_WithCopyConstructor)
		{
			CrtCheckMemory check;

			ListQueue<int> my_queue;

			my_queue.Enqueue(5);
			my_queue.Enqueue(14);
			my_queue.Dequeue();
			my_queue.Enqueue(21);
			my_queue.Enqueue(27);
			my_queue.Dequeue();
			my_queue.Enqueue(33);
			my_queue.Dequeue();

			ListQueue<int> second_queue(my_queue);

			Assert::AreEqual(27, second_queue.Front());
		}
		TEST_METHOD(CheckValue_EnqueFiveValues_WithDequeue_ThenCheckNotEmpty_WithAssignmentOperator)
		{
			CrtCheckMemory check;

			ListQueue<int> my_queue;

			my_queue.Enqueue(5);
			my_queue.Enqueue(14);
			my_queue.Dequeue();
			my_queue.Enqueue(21);
			my_queue.Enqueue(27);
			my_queue.Dequeue();
			my_queue.Enqueue(33);
			my_queue.Dequeue();

			ListQueue<int> second_queue;
			second_queue = my_queue;

			Assert::AreEqual(27, second_queue.Front());
		}
		TEST_METHOD(CheckValue_WithEnque_AndLoop)
		{
			CrtCheckMemory check;

			ListQueue<int> my_queue;
			int list[] = { 5,10,15,20,25,30 };

			for (auto i = 0; i < 6; ++i)
			{
				my_queue.Enqueue(list[i]);
			}

			Assert::AreEqual(5, my_queue.Front());
		}
		TEST_METHOD(CheckValue_WithEnque_AndLoop_WithCopyConstructor)
		{
			CrtCheckMemory check;

			ListQueue<int> my_queue;
			int list[] = { 5,10,15,20,25,30 };

			for (auto i = 0; i < 6; ++i)
			{
				my_queue.Enqueue(list[i]);
			}
			ListQueue<int> second_queue(my_queue);

			Assert::AreEqual(5, second_queue.Front());
		}
		TEST_METHOD(CheckValue_WithEnque_AndLoop_WithAssignmentOperator)
		{
			CrtCheckMemory check;

			ListQueue<int> my_queue;
			int list[] = { 5,10,15,20,25,30 };

			for (auto i = 0; i < 6; ++i)
			{
				my_queue.Enqueue(list[i]);
			}
			ListQueue<int> second_queue;
			second_queue = my_queue;

			Assert::AreEqual(5, second_queue.Front());
		}
		TEST_METHOD(CheckValue_WithEnque_AndLoop_ThenLoopCheckEveryElement)
		{
			CrtCheckMemory check;

			ListQueue<int> my_queue;
			int list[] = { 5,10,15,20,25,30 };

			for (auto i = 0; i < 6; ++i)
			{
				my_queue.Enqueue(list[i]);
			}
				my_queue.Dequeue();
			Assert::AreEqual(10, my_queue.Front());
		}
	
		TEST_METHOD(CheckEmpty_WithEnque_AndLoop_AndThenCheckThat_ItIsNotEmpty)
		{
			CrtCheckMemory check;

			ListQueue<int> my_queue;
			int list[] = { 5,10,15,20,25,30 };

			for (auto i = 0; i < 6; ++i)
			{
				my_queue.Enqueue(list[i]);
			}

			Assert::IsFalse(my_queue.Empty());
		}
		TEST_METHOD(CheckEmpty_WithEnque_AndLoop_WithCopyConstructor_AndThenCheckThat_ItIsNotEmpty)
		{
			CrtCheckMemory check;

			ListQueue<int> my_queue;
			int list[] = { 5,10,15,20,25,30 };

			for (auto i = 0; i < 6; ++i)
			{
				my_queue.Enqueue(list[i]);
			}
			ListQueue<int> second_queue(my_queue);

			Assert::IsFalse(second_queue.Empty());
		}
		TEST_METHOD(CheckEmpty_WithEnque_AndLoop_WithAssignmentOperator_AndThenCheckThat_ItIsNotEmpty)
		{
			CrtCheckMemory check;

			ListQueue<int> my_queue;
			int list[] = { 5,10,15,20,25,30 };

			for (auto i = 0; i < 6; ++i)
			{
				my_queue.Enqueue(list[i]);
			}
			ListQueue<int> second_queue;
			second_queue = my_queue;

			Assert::IsFalse(second_queue.Empty());
		}
		TEST_METHOD(CheckEmpty_WithEnque_AndLoop_AndThenCheckThat_ItIsEmpty)
		{
			CrtCheckMemory check;

			ListQueue<int> my_queue;
			int list[] = { 5,10,15,20,25,30 };

			for (auto i = 0; i < 6; ++i)
			{
				my_queue.Enqueue(list[i]);
			}
			my_queue.Clear();

			Assert::IsTrue(my_queue.Empty());
		}
		TEST_METHOD(CheckEmpty_WithEnque_AndLoop_WithCopyConstructor_AndThenCheckThat_ItIsEmpty)
		{
			CrtCheckMemory check;

			ListQueue<int> my_queue;
			int list[] = { 5,10,15,20,25,30 };

			for (auto i = 0; i < 6; ++i)
			{
				my_queue.Enqueue(list[i]);
			}
			ListQueue<int> second_queue(my_queue);

			second_queue.Clear();

			Assert::IsTrue(second_queue.Empty());
		}
		TEST_METHOD(CheckEmpty_WithEnque_AndLoop_WithAssignmentOperator_AndThenCheckThat_ItIsEmpty)
		{
			CrtCheckMemory check;

			ListQueue<int> my_queue;
			int list[] = { 5,10,15,20,25,30 };

			for (auto i = 0; i < 6; ++i)
			{
				my_queue.Enqueue(list[i]);
			}
			ListQueue<int> second_queue;
			second_queue = my_queue;

			second_queue.Clear();

			Assert::IsTrue(second_queue.Empty());
		}
		TEST_METHOD(CheckSize_WithEnque_AndLoop_AndClear)
		{
			CrtCheckMemory check;

			ListQueue<int> my_queue;
			int list[] = { 5,10,15,20,25,30 };

			for (auto i = 0; i < 6; ++i)
			{
				my_queue.Enqueue(list[i]);
			}
			my_queue.Clear();

			Assert::AreEqual(0ull, my_queue.Size());
		}
		TEST_METHOD(CheckSize_WithEnque_AndLoop_WithCopyConstructor_AndClear)
		{
			CrtCheckMemory check;

			ListQueue<int> my_queue;
			int list[] = { 5,10,15,20,25,30 };

			for (auto i = 0; i < 6; ++i)
			{
				my_queue.Enqueue(list[i]);
			}
			ListQueue<int> second_queue(my_queue);

			second_queue.Clear();

			Assert::AreEqual(0ull, second_queue.Size());
		}
		TEST_METHOD(CheckSize_WithEnque_AndLoop_WithAssignmentOperator_AndClear)
		{
			CrtCheckMemory check;

			ListQueue<int> my_queue;
			int list[] = { 5,10,15,20,25,30 };

			for (auto i = 0; i < 6; ++i)
			{
				my_queue.Enqueue(list[i]);
			}
			ListQueue<int> second_queue;
			second_queue = my_queue;

			second_queue.Clear();

			Assert::AreEqual(0ull, second_queue.Size());
		}
		TEST_METHOD(CheckSize_WithEnque_AndLoop)
		{
			CrtCheckMemory check;

			ListQueue<int> my_queue;
			int list[] = { 5,10,15,20,25,30 };

			for (auto i = 0; i < 6; ++i)
			{
				my_queue.Enqueue(list[i]);
			}

			Assert::AreEqual(6ull, my_queue.Size());
		}
		TEST_METHOD(CheckSize_WithEnque_AndLoop_WithCopyConstructor)
		{
			CrtCheckMemory check;

			ListQueue<int> my_queue;
			int list[] = { 5,10,15,20,25,30 };

			for (auto i = 0; i < 6; ++i)
			{
				my_queue.Enqueue(list[i]);
			}
			ListQueue<int> second_queue(my_queue);

			Assert::AreEqual(6ull, second_queue.Size());
		}
		TEST_METHOD(CheckSize_WithEnque_AndLoop_WithAssignmentOperator)
		{
			CrtCheckMemory check;

			ListQueue<int> my_queue;
			int list[] = { 5,10,15,20,25,30 };

			for (auto i = 0; i < 6; ++i)
			{
				my_queue.Enqueue(list[i]);
			}
			ListQueue<int> second_queue;
			second_queue = my_queue;

			Assert::AreEqual(6ull, second_queue.Size());
		}
	};
}