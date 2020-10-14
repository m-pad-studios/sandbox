#include "pch.h"
#include "CppUnitTest.h"
#include "../DataStructures/array_deque.hpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;
using namespace data_structures;

namespace data_structures_tests
{
	TEST_CLASS(TemplateTestClass)
	{
	public:

		TEST_METHOD(DequeConstructorTest)
		{
			ArrayDeque<int> my_deck(7);

			Assert::IsTrue(my_deck.Size() == 7);
		}

		TEST_METHOD(PushFrontTest)
		{
			ArrayDeque<int> my_deck(7);

			my_deck.PushFront(7);

			Assert::IsTrue(my_deck.Front() == 7);
		}

		TEST_METHOD(PushFront_RemoveFrontTest)
		{
			ArrayDeque<int> my_deck(7);

			my_deck.PushFront(7);

			my_deck.RemoveFront();

			Assert::IsTrue(my_deck.Empty());
		}

		TEST_METHOD(PushBack)
		{
			ArrayDeque<int> my_deck(7);

			my_deck.PushBack(7);

			Assert::IsTrue(my_deck.Back() == 7);
		}

		TEST_METHOD(PushBack_RemoveBackTest)
		{
			ArrayDeque<int> my_deck(7);

			my_deck.PushBack(7);

			my_deck.RemoveBack();

			Assert::IsTrue(my_deck.Empty());
		}

		TEST_METHOD(DequeClearFunctionTest)
		{
			ArrayDeque<int> my_deck(7);

			my_deck.PushFront(7);
			my_deck.PushBack(7);
			my_deck.PushFront(7);

			my_deck.Clear();

			Assert::IsTrue(my_deck.Empty());
		}

		TEST_METHOD(CopyConstructorTest)
		{
			ArrayDeque<int> my_deck(10);
			//Act
			ArrayDeque<int> copy_deck(my_deck);
			//Assert
			Assert::IsTrue(10 == copy_deck.Size());
		}
	};
}