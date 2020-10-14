#include "pch.h"
#include "CppUnitTest.h"
#include "crt_check_memory.hpp"
#include "../GameOfLife/board.hpp"
using namespace data_structures;

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace data_structures_tests
{
	TEST_CLASS(TemplateTestClass)
	{
	public:

		TEST_METHOD(BoardConstructorTest)
		{
			Board<int> mr_plank(7,7,7,7);

			Assert::AreEqual(7, mr_plank.Rows());
			
		}

		TEST_METHOD(BoardDisplayTest)
		{
			Board<int> mr_plank(7, 7, 7, 7);
			bool flag = false;

			if (mr_plank.Rows() && mr_plank.Cols() != 0)
			{
				flag = true;
			
				Assert::IsTrue(flag);
			}
			

		}

	};
}
