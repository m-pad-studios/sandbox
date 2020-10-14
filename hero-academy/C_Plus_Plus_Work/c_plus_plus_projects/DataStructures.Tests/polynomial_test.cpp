#include "pch.h"
#include "CppUnitTest.h"
#include "crt_check_memory.hpp"

#include "../DataStructures/polynomial.hpp"

using namespace data_structures;
using namespace Microsoft::VisualStudio::CppUnitTestFramework;
using namespace data_structures_tests;

namespace data_structures_test
{
	TEST_CLASS(T14_Polynomial_Test)
	{
	public:

		TEST_METHOD(ConstructorTest)
		{
			const CrtCheckMemory check;

			const double coefficients_of_polynomial_1[]{ 20.0, 30.0, 40.0, 50.0, 60.0 };
			const Polynomial<double> polynomial_1{ coefficients_of_polynomial_1, 5 };


			// 60x^4 + 50x^3 + 40x^2 + 30^x + 20 
			const double coefficients_of_polynomial_2[]{ 20.0, 30.0, 40.0, 50.0, 60.0 };
			const Polynomial<double> polynomial_2{ coefficients_of_polynomial_1, 5 };

			Assert::IsTrue(polynomial_1 == polynomial_2);
		}
		
		TEST_METHOD(PolynomialAddSameNumberCoefficients)
		{
			const CrtCheckMemory check;

			// 60x^4 + 50x^3 + 40x^2 + 30^x + 20 
			const double coefficients_of_polynomial_1[]{ 20.0, 30.0, 40.0, 50.0, 60.0 };
			const Polynomial<double> polynomial_1{ coefficients_of_polynomial_1, 5 };

			// 6x^4 + 7x^3 + 8x^2 + 9^x + 10 
			const double coefficients_of_polynomial_2[]{ 10.0, 9.0, 8.0, 7.0, 6.0 };
			const Polynomial<double> polynomial_2{ coefficients_of_polynomial_2, 5 };

			const Polynomial<double> your_answer = polynomial_2 + polynomial_1;

			const double coefficients_of_answer[] = { 30.0, 39.0, 48.0, 57.0, 66.0 };
			const Polynomial<double> correct_answer(coefficients_of_answer, 5);

			Assert::IsTrue(correct_answer == your_answer);
		}

		TEST_METHOD(PolynomialSubtractSameNumberCoefficients)
		{
			const CrtCheckMemory check;

			const double coefficients_of_polynomial_1[]{ 20.0, 30.0, 40.0, 50.0, 60.0 };
			const Polynomial<double> polynomial_1{ coefficients_of_polynomial_1, 5 };

			double coefficients_of_polynomial_2[]{ 10.0, 9.0, 8.0, 7.0, 6.0 };
			const Polynomial<double> polynomial_2{ coefficients_of_polynomial_2, 5 };

			const auto your_answer{ polynomial_1 - polynomial_2 };

			double coefficients_of_answer[]{ 10.0, 21.0, 32.0, 43.0, 54.0 };
			const Polynomial<double> correct_answer{ coefficients_of_answer, 5 };

			Assert::IsTrue(correct_answer == your_answer);
		}

		TEST_METHOD(PolynomialAddDifferentNumberCoefficients_LeftLarger)
		{
			const CrtCheckMemory check;

			// 60x^4 + 50x^3 + 40x^2 + 30^x + 20
			const double coefficients_of_polynomial_1[]{ 20.0, 30.0, 40.0, 50.0, 60.0 };
			const Polynomial<double> polynomial_1{ coefficients_of_polynomial_1, 5 };

			// 6x^3 + 7x^2 + 8x + 9
			const double coefficients_of_polynomial_2[]{ 9.0, 8.0, 7.0, 6.0 };
			const Polynomial<double> polynomial_2{ coefficients_of_polynomial_2, 4 };

			const auto your_answer{ polynomial_1 + polynomial_2 };

			const double coefficients_of_answer[]{ 29.0, 38.0, 47.0, 56.0, 60.0 };
			const Polynomial<double> correct_answer{ coefficients_of_answer, 5 };

			Assert::IsTrue(your_answer == correct_answer);
		}

		TEST_METHOD(PolynomialAddDifferentNumberCoefficients_RightLarger)
		{
			const CrtCheckMemory check;

			// 6x^3 + 7x^2 + 8x + 9
			const double coefficients_of_polynomial_1[]{ 9.0, 8.0, 7.0, 6.0 };
			const Polynomial<double> polynomial_1(coefficients_of_polynomial_1, 4);

			// 60x^4 + 50x^3 + 40x^2 + 30^x + 20
			const double coefficients_of_polynomial_2[]{ 20.0, 30.0, 40.0, 50.0, 60.0 };
			const Polynomial<double> polynomial_2{ coefficients_of_polynomial_2, 5 };

			const auto your_answer{ polynomial_1 + polynomial_2 };

			const double coefficients_of_answer[]{ 29.0, 38.0, 47.0, 56.0, 60.0 };
			const Polynomial<double> correct_answer{ coefficients_of_answer, 5 };

			Assert::IsTrue(correct_answer == your_answer);
		}

		TEST_METHOD(PolynomialSubtractDifferentNumberCoefficients_LeftLarger)
		{
			const CrtCheckMemory check;

			const double coefficients_of_polynomial_1[]{ 20.0, 30.0, 40.0, 50.0, 60.0 };
			const Polynomial<double> polynomial_1{ coefficients_of_polynomial_1, 5 };

			const double coefficients_of_polynomial_2[]{ 9.0, 8.0, 7.0, 6.0 };
			const Polynomial<double> polynomial_2{ coefficients_of_polynomial_2, 4 };

			const auto your_answer{ polynomial_1 - polynomial_2 };

			const double coefficients_of_answer[]{ 11.0, 22.0, 33.0, 44.0, 60.0 };
			const Polynomial<double> correct_answer{ coefficients_of_answer, 5 };

			Assert::IsTrue(correct_answer == your_answer);
		}

		TEST_METHOD(PolynomialSubtractDifferentNumberCoefficients_RightLarger)
		{
			const CrtCheckMemory check;

			const double coefficients_of_polynomial_1[4] = { 9.0, 8.0, 7.0, 6.0 };
			const Polynomial<double> polynomial_1(coefficients_of_polynomial_1, 4);

			const double coefficients_of_polynomial_2[5] = { 20.0, 30.0, 40.0, 50.0, 60.0 };
			const Polynomial<double> polynomial_2(coefficients_of_polynomial_2, 5);

			const auto your_answer = polynomial_1 - polynomial_2;
			
			const double coefficients_of_answer[5] = { -11.0, -22.0, -33.0, -44.0, 60.0 };
			const Polynomial<double> correct_answer(coefficients_of_answer, 5);

			Assert::IsTrue(correct_answer == your_answer);
		}

		TEST_METHOD(PolynomialAddNegativeNumbers)
		{
			CrtCheckMemory check;

			const double coefficients_of_polynomial_1[]{ -20.0, 30.0, -40.0, 50.0, 60.0 };
			const Polynomial<double> polynomial_1{ coefficients_of_polynomial_1, 5 };

			const double coefficients_of_polynomial_2[]{ 9.0, -8.0, 7.0, -6.0 };
			const Polynomial<double> polynomial_2{ coefficients_of_polynomial_2, 4 };

			const auto your_answer{ polynomial_1 + polynomial_2 };

			double coefficients_of_answer[]{ -11.0, 22.0, -33.0, 44.0, 60.0 };
			const Polynomial<double> correct_answer{ coefficients_of_answer, 5 };

			Assert::IsTrue(correct_answer == your_answer);
		}
			TEST_METHOD(PolynomialSubtractNegativeNumbers)
		{
			const CrtCheckMemory check;

			const double coefficients_of_polynomial_1[]{ -20.0, 30.0, -40.0, 50.0, 60.0 };
			const Polynomial<double> polynomial_1{ coefficients_of_polynomial_1, 5 };

			const double coefficients_of_polynomial_2[]{ 9.0, -8.0, 7.0, -6.0};
			const Polynomial<double> polynomial_2{ coefficients_of_polynomial_2, 4 };

			const auto your_answer{ polynomial_1 - polynomial_2 };

			const double coefficients_of_answer[]{ -29.0, 38.0, -47.0, 56.0, 60.0 };
			const Polynomial<double> correct_answer{ coefficients_of_answer, 5 };

			Assert::IsTrue(correct_answer == your_answer);
		}

		TEST_METHOD(PolynomialAssignmentOperator)
		{
			const CrtCheckMemory check;

			const double coefficients_of_polynomial_1[]{ -20.0, 30.0, -40.0, 50.0, 60.0 };
			const Polynomial<double> polynomial_1{ coefficients_of_polynomial_1, 5 };

			const auto polynomial_2{ polynomial_1 };

			Assert::IsTrue(polynomial_1 == polynomial_2);
		}
	};
}