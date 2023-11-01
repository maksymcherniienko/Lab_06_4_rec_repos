#include "pch.h"
#include "CppUnitTest.h"
#include "../Lab_06_4_rec/Lab_06_4_rec.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest1
{
	TEST_CLASS(UnitTest1)
	{
	public:

		TEST_METHOD(TestMethod1)
		{
			const int n = 4;
			int a[n] = { 0, 4, 5, 0 };
			Assert::AreEqual(Calculate(a, n, 0, -1, -1), 20, 1e-1);
		}
	};
}
