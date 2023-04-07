#include "pch.h"
#include "CppUnitTest.h"

typedef struct rectangleAxis {

	float x, y;
}RECTANGLEAXIS;

extern "C" float rectangleArea(RECTANGLEAXIS*);
extern "C" bool validateRectangle(RECTANGLEAXIS*);
extern "C" float rectangleperimeter(RECTANGLEAXIS*);

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTestingRectangle
{
	TEST_CLASS(UnitTestingRectangle)
	{
	public:
		//Validation.
		TEST_METHOD(ValidatingWithPositveCasesForTrue)
		{
			RECTANGLEAXIS p[4];
			p[0].x = 0;
			p[0].y = 0;
			p[1].x = 4;
			p[1].y = 0;
			p[2].x = 0;
			p[2].y = 3;
			p[3].x = 4;
			p[3].y = 3;
			Assert::IsTrue(validateRectangle(p));
		}
		TEST_METHOD(ValidatingWithPositveCasesForFalse)
		{
			RECTANGLEAXIS p[4];
			p[0].x = 0;
			p[0].y = 0;
			p[1].x = 4;
			p[1].y = 0;
			p[2].x = 4;
			p[2].y = 0;
			p[3].x = 0;
			p[3].y = 3;
			Assert::IsTrue(validateRectangle(p));
		}
		TEST_METHOD(ValidatingWithNegativeCasesForTrue)
		{
			RECTANGLEAXIS p[4];
			p[0].x = -4;
			p[0].y = -3;
			p[1].x = -4;
			p[1].y = 1;
			p[2].x = 2;
			p[2].y = 1;
			p[3].x = 2;
			p[3].y = -3;
			Assert::IsTrue(validateRectangle(p));
		}
		TEST_METHOD(ValidatingForSquare)
		{
			RECTANGLEAXIS p[4];
			p[0].x = 0;
			p[0].y = 0;
			p[1].x = 0;
			p[1].y = 5;
			p[2].x = 5;
			p[2].y = 5;
			p[3].x = 5;
			p[3].y = 0;
			Assert::IsTrue(validateRectangle(p));
		}
		TEST_METHOD(ValidatingForRhombus)
		{
			RECTANGLEAXIS p[4];
			p[0].x = 0;
			p[0].y = 0;
			p[1].x = 3;
			p[1].y = 4;
			p[2].x = 6;
			p[2].y = 0;
			p[3].x = 3;
			p[3].y = -4;
			Assert::IsTrue(validateRectangle(p));
		}
		//Area
		TEST_METHOD(AreaForPositivePoints)
		{
			RECTANGLEAXIS p[4];
			p[0].x = 0;
			p[0].y = 0;
			p[1].x = 4;
			p[1].y = 0;
			p[2].x = 0;
			p[2].y = 3;
			p[3].x = 4;
			p[3].y = 3;
			float result;
			result = rectangleArea(p);
			Assert::AreEqual(12.0f, result);
		}
		TEST_METHOD(AreaForLargeRec)
		{
			RECTANGLEAXIS p[4];
			p[0].x = 0;
			p[0].y = 0;
			p[1].x = 0;
			p[1].y = 20;
			p[2].x = 30;
			p[2].y = 20;
			p[3].x = 30;
			p[3].y = 0;
			float result;
			result = rectangleArea(p);
			Assert::AreEqual(600.0f, result);
		}
		TEST_METHOD(AreaForSquare)
		{
			RECTANGLEAXIS p[4];
			p[0].x = 0;
			p[0].y = 0;
			p[1].x = 0;
			p[1].y = 5;
			p[2].x = 5;
			p[2].y = 5;
			p[3].x = 5;
			p[3].y = 0;
			float result;
			result = rectangleArea(p);
			Assert::AreEqual(25.0f, result);
		}
		TEST_METHOD(AreaForNegativePoints)
		{
			RECTANGLEAXIS p[4];
			p[0].x = -4;
			p[0].y = -3;
			p[1].x = -4;
			p[1].y = 1;
			p[2].x = 2;
			p[2].y = 1;
			p[3].x = 2;
			p[3].y = -3;
			float result;
			result = rectangleArea(p);
			Assert::AreEqual(24.0f, result);
		}
		//Perimeter
		TEST_METHOD(PerimeterForPositivePoints)
		{
			RECTANGLEAXIS p[4];
			p[0].x = 0;
			p[0].y = 0;
			p[1].x = 4;
			p[1].y = 0;
			p[2].x = 0;
			p[2].y = 3;
			p[3].x = 4;
			p[3].y = 3;
			float result;
			result = rectangleperimeter(p);
			Assert::AreEqual(14.0f, result);
		}
		TEST_METHOD(PerimeterForLargeRec)
		{
			RECTANGLEAXIS p[4];
			p[0].x = 0;
			p[0].y = 0;
			p[1].x = 0;
			p[1].y = 20;
			p[2].x = 30;
			p[2].y = 20;
			p[3].x = 30;
			p[3].y = 0;
			float result;
			result = rectangleperimeter(p);
			Assert::AreEqual(100.0f, result);
		}
		TEST_METHOD(perimeterForSquare)
		{
			RECTANGLEAXIS p[4];
			p[0].x = 0;
			p[0].y = 0;
			p[1].x = 0;
			p[1].y = 5;
			p[2].x = 5;
			p[2].y = 5;
			p[3].x = 5;
			p[3].y = 0;
			float result;
			result = rectangleperimeter(p);
			Assert::AreEqual(20.0f, result);
		}
		TEST_METHOD(PerimeterForNegativePoints)
		{
			RECTANGLEAXIS p[4];
			p[0].x = -4;
			p[0].y = -3;
			p[1].x = -4;
			p[1].y = 1;
			p[2].x = 2;
			p[2].y = 1;
			p[3].x = 2;
			p[3].y = -3;
			float result;
			result = rectangleperimeter(p);
			Assert::AreEqual(20.0f, result);
		}
	};
}
