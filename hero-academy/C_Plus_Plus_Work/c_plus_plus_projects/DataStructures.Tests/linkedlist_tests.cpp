#include "pch.h"
#include "cppunittest.h"
#include "crt_check_memory.hpp"
#include "../datastructures/linked_list.hpp"
#include <list>
using namespace data_structures;

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace data_structures_tests
{

	TEST_CLASS(LinkedListStarterTests)
	{
	public:

		TEST_METHOD(AppendDataLeakTest)
		{
			CrtCheckMemory check;

			LinkedList<int> link;
			link.Append(7);
			Assert::IsTrue(7 == link.Last());
		}
		TEST_METHOD(LinkedListDefaultConstructor)
		{
			CrtCheckMemory check;
			try
			{
				LinkedList<int> list;

				Assert::IsTrue(list.Empty());
				Assert::IsNull(list.Head());

			}
			catch (AdtException AdtException)
			{
				Assert::Fail(AdtException.Message());
			}
		}
		/*SUNNY DAY TEST CASES FOR LINKED LIST*/
		TEST_METHOD(AppendSunnyDayShouldNeverThrowAnException)
		{
			CrtCheckMemory check;
	
				LinkedList<int> link;

				link.Append(0);
				link.Append(1);


				Assert::IsTrue(1 == link.Last());
			
		}

		TEST_METHOD(PrependSunnyDayShouldNeverThrowAnException)
		{
			CrtCheckMemory check;

			LinkedList<int> link;

			link.Prepend(0);
			link.Prepend(1);


			Assert::IsTrue(1 == link.First());

		}

		TEST_METHOD(InsertBeforeSunnyDayShouldNeverThrowAnException)
		{
			CrtCheckMemory check;

			LinkedList<int> link;

			link.Prepend(0);
			link.Prepend(1);

			link.InsertBefore(7, 0);


			Assert::IsTrue(1 == link.First());

		}

		TEST_METHOD(InserAfterSunnyDayShouldNeverThrowAnException)
		{
			CrtCheckMemory check;

			LinkedList<int> link;

			link.Prepend(0);
			link.Prepend(1);

			link.InsertAfter(7, 1);

			Assert::IsTrue(7 == link.Last());

		}

		TEST_METHOD(ExtractSunnyDayShouldNeverThrowAnException)
		{
			CrtCheckMemory check;

			LinkedList<int> link;

			link.Prepend(0);
			link.Prepend(1);
			link.Prepend(7);
			link.Append(13);
			link.Append(15);
			link.Append(17);

			link.Extract(0);
			link.Extract(1);
			link.Extract(13);
			link.Extract(15);
			link.Extract(17);

			Assert::IsTrue(7 == link.First());

		}

		TEST_METHOD(ClearSunnyDayShouldNeverThrowAnException)
		{
			CrtCheckMemory check;

			LinkedList<int> link;

			link.Prepend(0);
			link.Prepend(1);

			link.Clear();

			Assert::IsTrue(link.Empty());

		}
		/*END SUNNY DAY SECTION*/

		/*RAINY DAY TEST CASES SECTION FOR LINKED LIST*/
		TEST_METHOD(ExtractRainyDayTestCase)
		{
			CrtCheckMemory check;

			bool exceptionThrown = false;

			try
			{
				LinkedList<int> link;
				link.Extract(0);
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

		TEST_METHOD(RemoveFirstRainyDay)
		{
			CrtCheckMemory check;

			bool exceptionThrown = false;

			try
			{
				LinkedList<int> link;
				link.RemoveFirst();
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

		TEST_METHOD(RemoveLastRainyDay)
		{
			CrtCheckMemory check;

			bool exceptionThrown = false;

			try
			{
				LinkedList<int> link;
				link.RemoveLast();
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
				LinkedList<int> link;
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

		TEST_METHOD(InsertAfterRainyDay)
		{
			CrtCheckMemory check;

			bool exceptionThrown = false;

			try
			{
				LinkedList<int> link;
				link.InsertAfter(0,0);
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

		TEST_METHOD(InsertBeforeRainyDay)
		{
			CrtCheckMemory check;

			bool exceptionThrown = false;

			try
			{
				LinkedList<int> link;
				link.InsertBefore(0,0);
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



		/*END OF RAINY DAY SECTION*/
		
		TEST_METHOD(LinkedListExtract) {

			CrtCheckMemory check;

			try {
				LinkedList<int> list;

				list.Append(5);

				list.Extract(5);

				Assert::IsTrue(list.Empty());

				Assert::IsNull(list.Head());

				list.Append(5);

				list.Append(10);

				list.Append(15);

				list.Extract(10);

				Assert::AreEqual(5, list.First());

				Assert::AreEqual(15, list.Last());
			}
			catch (AdtException AdtException) { Assert::Fail(AdtException.Message()); }
		}
		TEST_METHOD(LinkedListCopyConstructor)
		{
			CrtCheckMemory check;
			try
			{
				LinkedList<int> aList;
				aList.Append(5);

				LinkedList<int> bList(aList);

				Assert::IsFalse(bList.Empty());
				Assert::AreEqual(5, bList.First());

			}
			catch (AdtException AdtException)
			{
				Assert::Fail(AdtException.Message());
			}
		}

		TEST_METHOD(LinkedListAssignmentOperator)
		{
			CrtCheckMemory check;
			try
			{
				LinkedList<size_t> aList;
				LinkedList<size_t> bList;

				size_t i;

				size_t values[] = { 5, 15, 25, 35, 45 };

				for (i = 0; i < 5; ++i)
				{
					aList.Append(values[i]);
				}

				bList = aList;

				i = 0;
				for (ListNode<size_t>* list_node = bList.Head(); list_node != nullptr; list_node = list_node->Next())
				{
					Assert::AreEqual(values[i++], list_node->Value());
				}
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
				LinkedList<int> aList;

				int values[] = { 5, 15, 25, 35, 45 };
				for (int i = 0; i < 5; ++i)
				{
					aList.Append(values[i]);
				}

				Assert::AreEqual(5, aList.Head()->Value());
				Assert::AreEqual(45, aList.Tail()->Value());

			}
			catch (AdtException AdtException)
			{
				Assert::Fail(AdtException.Message());
			}
		}

		TEST_METHOD(LinkedListAppend)
		{
			CrtCheckMemory check;
			try
			{
				LinkedList<size_t> aList;
				size_t i;

				size_t values[] = { 5, 15, 25, 35, 45 };
				for (i = 0; i < 5; ++i)
				{
					aList.Append(values[i]);
				}

				i = 0;
				for (ListNode<size_t>* list_node = aList.Head(); list_node != nullptr; list_node = list_node->Next())
				{
					Assert::AreEqual(values[i++], list_node->Value());
				}
			}
			catch (AdtException AdtException)
			{
				Assert::Fail(AdtException.Message());
			}
		}

		TEST_METHOD(LinkedListFirstAndLast)
		{
			CrtCheckMemory check;
			try
			{
				LinkedList<int> aList;

				int values[] = { 5, 15, 25, 35, 45 };
				for (int i = 0; i < 5; ++i)
				{
					aList.Append(values[i]);
				}

				Assert::AreEqual(5, aList.First());
			}
			catch (AdtException AdtException)
			{
				Assert::Fail(AdtException.Message());
			}
		}

		TEST_METHOD(LinkedListPrepend)
		{
			CrtCheckMemory check;
			try
			{
				LinkedList<size_t> aList;
				size_t i;

				size_t values[] = { 5, 15, 25, 35, 45 };
				for (i = 0; i < 5; ++i)
				{
					aList.Prepend(values[i]);
				}

				i = 5;
				for (ListNode<size_t>* list_node = aList.Head(); list_node != nullptr; list_node = list_node->Next())
				{
					Assert::AreEqual(values[--i], list_node->Value());
				}
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
				LinkedList<size_t> aList;

				size_t values[] = { 5, 15, 25, 35, 45 };
				for (size_t i = 0; i < 5; ++i)
				{
					aList.Append(values[i]);
				}

				aList.Clear();

				Assert::IsNull(aList.Head());
				Assert::IsNull(aList.Tail());
				Assert::IsTrue(aList.Empty());
			}
			catch (AdtException AdtException)
			{
				Assert::Fail(AdtException.Message());
			}
		}

		TEST_METHOD(LinkedListBefore) { CrtCheckMemory check; try { LinkedList<int> aList; int i; int values[] = { 5, 15, 25, 35, 45 }; aList.Append(values[4]); for (i = 3; i >= 0; --i) { aList.InsertBefore(values[i], values[i + 1]); }i = 0; for (ListNode<int>* list_node = aList.Head(); list_node != nullptr; list_node = list_node->Next()) { Assert::AreEqual(values[i++], list_node->Value()); } } catch (AdtException AdtException) { Assert::Fail(AdtException.Message()); } }
		TEST_METHOD(LinkedListInsertAfter) {
			CrtCheckMemory check; try {
				LinkedList<int> aList; int i; int values[] = { 5, 15, 25, 35, 45 };
				aList.Append(values[0]); for (i = 1; i < 5; ++i) { aList.InsertAfter(values[i], values[i - 1]); }i = 0; for (ListNode<int>* list_node = aList.Head(); list_node != nullptr; list_node = list_node->Next()) { Assert::AreEqual(values[i++], list_node->Value()); }
			}
			catch (AdtException AdtException) { Assert::Fail(AdtException.Message()); }
		}
			
 
		};
	};
