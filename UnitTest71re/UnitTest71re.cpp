#include "pch.h"
#include "CppUnitTest.h"
#include "../lab71re/lab71re.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest71re
{
	TEST_CLASS(UnitTest71re)
	{
	public:
		
		TEST_METHOD(TestMethod1)
		{
			const int rowCount = 2;
			const int colCount = 3;
			int** a = new int* [rowCount];
			for (int i = 0; i < rowCount; i++)
				a[i] = new int[colCount];

			a[0][0] = 1; a[0][1] = 6; a[0][2] = 7;
			a[1][0] = -3; a[1][1] = 9; a[1][2] = 2;

			int S = 0;
			int k = 0;

			Calc(a, rowCount, colCount, S, k);

			
			Assert::AreEqual(S, 10); 
			Assert::AreEqual(k, 3);

			
			Assert::AreEqual(a[0][0], 0);
			Assert::AreEqual(a[0][2], 0);
			Assert::AreEqual(a[1][2], 0);

			for (int i = 0; i < rowCount; i++)
				delete[] a[i];
			delete[] a;
		}
	};
}
