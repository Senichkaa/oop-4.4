#include "pch.h"
#include "CppUnitTest.h"
#include "../OOP 4.4/Pair.cpp"
#include "../OOP 4.4/FuzzyNumber.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UTOOP44
{
	TEST_CLASS(UTOOP44)
	{
	public:
		
		TEST_METHOD(TestMethod1)
		{
			Pair* A = new FuzzyNumber(1, 7, 4);
			Pair* B = new FuzzyNumber(3, 9, 6);
			Pair* C = new FuzzyNumber();
			C = *A + B;
			Assert::AreEqual(C->get_a(), 6.0);
		}
	};
}
