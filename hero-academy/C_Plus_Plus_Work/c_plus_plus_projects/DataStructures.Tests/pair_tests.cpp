#include "pch.h"
#include "CppUnitTest.h"
#include "iostream"
#include "../DataStructures/pair.hpp"
#include "crt_check_memory.hpp"
#include <string>

using std::string;


using namespace Microsoft::VisualStudio::CppUnitTestFramework;
using namespace data_structures;
namespace data_structures_tests
{
	TEST_CLASS(PairTests)
	{
	public:
		Pair<string, string> GetPair()
		{
			Pair<string, string> the_pair("1", "2");

			return the_pair;
		}
		TEST_METHOD(ParameterizedCtorTest)
		{
			CrtCheckMemory check_memory;
			Pair<string, string> pair1("Key", "value");
		}

		TEST_METHOD(GetFirstTest)
		{
			CrtCheckMemory check_memory;
			Pair<string, string> pair1("key", "value");

			Assert::AreEqual(std::string("key"), pair1.First());
		}

		TEST_METHOD(GetSecondTest)
		{
			CrtCheckMemory check_memory;
			Pair<string, string> pair2("key", "value");

			Assert::AreEqual(std::string("value"), pair2.Second());
		}
	
		TEST_METHOD(MoveConstructorTest)
		{
			CrtCheckMemory check_memory;

			Pair<string, string> pair1 = std::move(GetPair());

			Assert::AreEqual(std::string("1"), pair1.First());
		}

		TEST_METHOD(CopyConstructorTest)
		{

			/*
			I honestly wasn't too sure on how to implement the copy constructor properly.
			I just figured creating a new pair and then just storing the_pair in it would suffice
			But just doesn't seem right :O.
			*/
			
			CrtCheckMemory check_memory;

			Pair<string, string> pair1 = GetPair();
			
				Assert::AreEqual(GetPair().First(), pair1.First());
		}

		TEST_METHOD(AssignmentOperatorConstructorTest)
		{
			CrtCheckMemory check_memory;
			
			Pair<int, string> pair(1, "Lucas");
			Pair<int, string> pair2(2, "Mike");

			pair = pair2;

			Assert::AreEqual(2 , pair.First());
		}

		// I am done with my assignment!
		// Now to check it in and submit.

	};
}
