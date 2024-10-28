#include "pch.h"
#include "CppUnitTest.h"
#include "../lab 7.2 iter/lab 7.2 iter.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest74
{
	TEST_CLASS(UnitTest74)
	{
	public:
		
		TEST_METHOD(TestMethod1)
		{
            int rows = 3, cols = 3;
            int** matrix = new int* [rows];
            for (int i = 0; i < rows; ++i) {
                matrix[i] = new int[cols];
            }

            matrix[0][0] = 4; matrix[0][1] = 5; matrix[0][2] = 6;
            matrix[1][0] = 2; matrix[1][1] = 8; matrix[1][2] = 3;
            matrix[2][0] = 1; matrix[2][1] = 2; matrix[2][2] = 4;

            int minEven;
            bool found = SearchMinEven(matrix, rows, minEven);

            Assert::IsTrue(found);
            Assert::AreEqual(2, minEven); // Мінімальний парний елемент

            for (int i = 0; i < rows; ++i) {
                delete[] matrix[i];
            }
            delete[] matrix;
		}
	};
}
