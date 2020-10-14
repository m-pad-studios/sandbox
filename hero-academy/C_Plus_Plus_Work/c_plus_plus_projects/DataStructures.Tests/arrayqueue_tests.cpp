#include "pch.h"
#include "CppUnitTest.h"
#include "../DataStructures/array_queue.hpp"
#include "crt_check_memory.hpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;
using namespace data_structures;

namespace data_structures_tests
{
	TEST_CLASS(TemplateTestClass)
	{
	public:

		TEST_METHOD(QueueConstructorTest)
		{
			CrtCheckMemory check;

			ArrayQueue<int> my_queue(7);

			Assert::IsTrue(my_queue.Size() == 7);
		}

		TEST_METHOD(QueueEnqueueTest)
		{
			CrtCheckMemory check;

			ArrayQueue<int> my_queue(7);

			my_queue.Enqueue(7);
			
			Assert::IsTrue(my_queue.Front() == 7);
		}

		TEST_METHOD(QueueDequeueTest)
		{
			CrtCheckMemory check;

			ArrayQueue<int> my_queue(7);

			my_queue.Enqueue(7);

			my_queue.Dequeue();

			Assert::IsTrue(my_queue.Empty());
		}


		TEST_METHOD(CopyConstructorTest)
		{
			CrtCheckMemory check;

			ArrayQueue<int> the_big_le_stacky(10);
			//Act
			ArrayQueue<int> copy_array(the_big_le_stacky);
			//Assert
			Assert::IsTrue(10 == copy_array.Size());
		}

		TEST_METHOD(TheGlutonTest) // proper name: [TryToPushToAFullQueStackTest]
		{
			CrtCheckMemory check;

			bool exceptionThrown = false;

			try
			{
				//all the puns intended
				ArrayQueue<int> the_big_le_que(7);

				//lets fill that sucker up
				for (auto i = 0u; i < the_big_le_que.Size(); ++i)
				{
					the_big_le_que.Enqueue(i);
				}

				the_big_le_que.Enqueue(12);
				the_big_le_que.Enqueue(12);
				the_big_le_que.Enqueue(12);
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

		TEST_METHOD(QueueEmptyTest)
		{
			ArrayQueue<int> the_big_le_que(7);

			Assert::IsTrue(the_big_le_que.Empty());
		}

		TEST_METHOD(QueueFullTest)
		{
			ArrayQueue<int> the_big_le_que(7);

			for (auto i = 0u; i < the_big_le_que.Size(); ++i)
			{
				the_big_le_que.Enqueue(i);
			}

			Assert::IsTrue(the_big_le_que.Full());

		}

	};
}
