#include "pch.h"
#include "cppunittest.h"
#include "crt_check_memory.hpp"
#include "../datastructures/list_stack.hpp"
#include <list>
using namespace data_structures;

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace data_structures_tests
{

	TEST_CLASS(LinkedListStarterTests)
	{
	public:

		TEST_METHOD(PushDataLeakTest)
		{
			CrtCheckMemory check;

			ListStack<int> link;
			link.Push(7);
			Assert::IsTrue(7 == link.Peek());
		}
		TEST_METHOD(LinkedListDefaultConstructor)
		{
			CrtCheckMemory check;
			try
			{
				ListStack<int> list;

				Assert::IsTrue(list.Empty());
				Assert::IsFalse(list.Peek());

			}
			catch (AdtException AdtException)
			{
				Assert::Fail(AdtException.Message());
			}
		}
		/*SUNNY DAY TEST CASES FOR LINKED LIST*/
		TEST_METHOD(PushSunnyDayShouldNeverThrowAnException)
		{
			CrtCheckMemory check;

			ListStack<int> link;

			link.Push(0);
			link.Push(1);


			Assert::IsTrue(1 == link.Peek());

		}


		


		TEST_METHOD(PopRainyDay)
		{
			CrtCheckMemory check;

			bool exceptionThrown = false;

			try
			{
				ListStack<int> link;
				link.Pop();
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

		TEST_METHOD(PopRainyDay2)
		{
			CrtCheckMemory check;

			bool exceptionThrown = false;

			try
			{
				ListStack<int> link;
				link.Pop();
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

		TEST_METHOD(CallClearOnEmptyListRainyDay)
		{
			CrtCheckMemory check;

			bool exceptionThrown = true;

			try
			{
				ListStack<int> link;
				link.Clear();
			}
			catch (AdtException&) // special exception type
			{
				exceptionThrown = false;
			}
			catch (...) // or any exception at all
			{
				exceptionThrown = false;
			}

			Assert::IsTrue(exceptionThrown);
		}

	

		TEST_METHOD(LinkedListCopyConstructor)
		{
			CrtCheckMemory check;
			try
			{
				ListStack<int> aList;
				aList.Push(5);

				ListStack<int> bList(aList);

				Assert::IsFalse(bList.Empty());
				Assert::AreEqual(5, bList.Peek());

			}
			catch (AdtException AdtException)
			{
				Assert::Fail(AdtException.Message());
			}
		}

	
		TEST_METHOD(LinkedListAccessors)
		{
			CrtCheckMemory check;
			try
			{
				ListStack<int> aList;

				int values[] = { 5, 15, 25, 35, 45 };
				for (int i = 0; i < 5; ++i)
				{
					aList.Push(values[i]);
				}

				Assert::AreEqual(5, aList.Peek());
			
			}
			catch (AdtException AdtException)
			{
				Assert::Fail(AdtException.Message());
			}
		}

		/*TEST_METHOD(LinkedListPush)
		{
			CrtCheckMemory check;
			try
			{
				ListStack<size_t> aList;
				size_t i;

				size_t values[] = { 5, 15, 25, 35, 45 };
				for (i = 0; i < 5; ++i)
				{
					aList.Push(values[i]);
				}

				i = 0;
				for (ListNode<size_t>* list_node = aList.Peek(); list_node != nullptr; list_node = list_node->Next())
				{
					Assert::AreEqual(values[i++], list_node->Value());
				}
			}
			catch (AdtException AdtException)
			{
				Assert::Fail(AdtException.Message());
			}
		}*/

		TEST_METHOD(LinkedListPeekAndPeek)
		{
			CrtCheckMemory check;
			try
			{
				ListStack<int> aList;

				int values[] = { 5, 15, 25, 35, 45 };
				for (int i = 0; i < 5; ++i)
				{
					aList.Push(values[i]);
				}

				Assert::AreEqual(45, aList.Peek());
			}
			catch (AdtException AdtException)
			{
				Assert::Fail(AdtException.Message());
			}
		}

	

		TEST_METHOD(LinkedListPurge)
		{
			CrtCheckMemory check;
			try
			{
				ListStack<size_t> aList;

				size_t values[] = { 5, 15, 25, 35, 45 };
				for (size_t i = 0; i < 5; ++i)
				{
					aList.Push(values[i]);
				}

				aList.Clear();

				Assert::IsTrue(45 == aList.Peek());
				
				Assert::IsTrue(aList.Empty());
			}
			catch (AdtException AdtException)
			{
				Assert::Fail(AdtException.Message());
			}
		}

		


	};
};
