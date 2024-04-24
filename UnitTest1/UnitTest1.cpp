#include "pch.h"
#include "CppUnitTest.h"
#include "../oop_2.4/Matrix.h"
#include "../oop_2.4/Matrix.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest1
{
	TEST_CLASS(UnitTest1)
	{
	public:
		
		TEST_METHOD(TestMethod1)
		{
			Matrix matrix(2);
			matrix.setElement(0, 0, 3);
			matrix.setElement(0, 1, 4);
			matrix.setElement(1, 0, 1);
			matrix.setElement(1, 1, 2);

			double norm = matrix.calculateNorm();

			Assert::AreEqual(sqrt(30.0), norm);
		}
	};
}
