#include "pch.h"
#include "CppUnitTest.h"

extern "C" char* analyzeTriangle(double, double, double); 
extern "C" void calculateAngles(double, double, double);
typedef struct rectangleAxis {

	float x, y;
}RECTANGLEAXIS;

extern "C" float rectangleArea(RECTANGLEAXIS*);
extern "C" bool validateRectangle(RECTANGLEAXIS*);
extern "C" float rectangleperimeter(RECTANGLEAXIS*);

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
		TEST_METHOD(TestRectangleArea_SmallRectangle)
		{
			RECTANGLEAXIS p[4] = { {0, 0}, {0, 2}, {3, 2}, {3, 0} };
			float area = rectangleArea(p);
			Assert::AreEqual(6.0f, area);
		}

		TEST_METHOD(TestRectangleArea_LargeRectangle)
		{
			RECTANGLEAXIS p[4] = { {0, 0}, {0, 20}, {30, 20}, {30, 0} };
			float area = rectangleArea(p);
			Assert::AreEqual(600.0f, area);
		}

		TEST_METHOD(TestRectangleArea_Square)
		{
			RECTANGLEAXIS p[4] = { {0, 0}, {0, 5}, {5, 5}, {5, 0} };
			float area = rectangleArea(p);
			Assert::AreEqual(25.0f, area);
		}

		TEST_METHOD(TestRectangleArea_RectangleWithNegativeCoordinates)
		{
			RECTANGLEAXIS p[4] = { {-4, -3}, {-4, 1}, {2, 1}, {2, -3} };
			float area = rectangleArea(p);
			Assert::AreEqual(24.0f, area);
		}
		TEST_METHOD(TestValidateRectangle_PositiveCoordinates)
		{
			RECTANGLEAXIS p[4] = { {0, 0}, {0, 4}, {6, 4}, {6, 0} };
			Assert::IsTrue(validateRectangle(p));
		}

		TEST_METHOD(TestValidateRectangle_NegativeCoordinates)
		{
			RECTANGLEAXIS p[4] = { {-4, -3}, {-4, 1}, {2, 1}, {2, -3} };
			Assert::IsTrue(validateRectangle(p));
		}

		TEST_METHOD(TestValidateRectangle_NotRectangle)
		{
			RECTANGLEAXIS p[4] = { {0, 0}, {1, 1}, {2, 2}, {3, 3} };
			Assert::IsFalse(validateRectangle(p));
		}

		TEST_METHOD(TestValidateRectangle_Square)
		{
			RECTANGLEAXIS p[4] = { {0, 0}, {0, 5}, {5, 5}, {5, 0} };
			Assert::IsTrue(validateRectangle(p));
		}

		TEST_METHOD(TestValidateRectangle_Rhombus)
		{
			RECTANGLEAXIS p[4] = { {0, 0}, {3, 4}, {6, 0}, {3, -4} };
			Assert::IsFalse(validateRectangle(p));
		}
		TEST_METHOD(TestRectanglePerimeter_SmallRectangle)
		{
			RECTANGLEAXIS p[4] = { {0, 0}, {0, 2}, {3, 2}, {3, 0} };
			float perimeter = rectangleperimeter(p);
			Assert::AreEqual(10.0f, perimeter);
		}

		TEST_METHOD(TestRectanglePerimeter_LargeRectangle)
		{
			RECTANGLEAXIS p[4] = { {0, 0}, {0, 20}, {30, 20}, {30, 0} };
			float perimeter = rectangleperimeter(p);
			Assert::AreEqual(100.0f, perimeter);
		}

		TEST_METHOD(TestRectanglePerimeter_Square)
		{
			RECTANGLEAXIS p[4] = { {0, 0}, {0, 5}, {5, 5}, {5, 0} };
			float perimeter = rectangleperimeter(p);
			Assert::AreEqual(20.0f, perimeter);
		}

		TEST_METHOD(TestRectanglePerimeter_RectangleWithNegativeCoordinates)
		{
			RECTANGLEAXIS p[4] = { {-4, -3}, {-4, 1}, {2, 1}, {2, -3} };
			float perimeter = rectangleperimeter(p);
			Assert::AreEqual(20.0f, perimeter);
		}
	};
}
