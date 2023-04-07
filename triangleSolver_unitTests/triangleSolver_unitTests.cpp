#include "pch.h"
#include "CppUnitTest.h"

extern "C" char* analyzeTriangle(double, double, double); void calculateAngles(double, double, double);

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace triangleSolverunitTests
{
	TEST_CLASS(triangleSolverunitTests)
	{
	public:
		
		TEST_METHOD(analyzeTriangle_test1)
		{

			double x = 3;
			double y = 3;
			double z = 3;

			char* answer = analyzeTriangle(x, y, z);

			Assert::AreEqual("Equilateral triangle", answer);
		}

		TEST_METHOD(analyzeTriangle_test2)
		{

			double x = 3;
			double y = 4;
			double z = 5;

			char* answer = analyzeTriangle(x, y, z);

			Assert::AreEqual("Scalene triangle", answer);
		}

		TEST_METHOD(analyzeTriangle_test3)
		{

			double x = 3;
			double y = 3;
			double z = 2;

			char* answer = analyzeTriangle(x, y, z);

			Assert::AreEqual("Isosceles triangle", answer);
		}

		TEST_METHOD(analyzeTriangle_test4)
		{

			double x = 0;
			double y = 3;
			double z = 2;

			char* answer = analyzeTriangle(x, y, z);

			Assert::AreEqual("Not a triangle", answer);
		}

		TEST_METHOD(analyzeTriangle_test5)
		{

			double x = 1;
			double y = 3;
			double z = 16;

			char* answer = analyzeTriangle(x, y, z);

			Assert::AreEqual("Not a triangle", answer);
		}
	};
}
