
#include "pch.h"
#include "CppUnitTest.h"
#include "../PolygonChecker/triangleSolver.h"



using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace triangleSolverunitTests
{
	TEST_CLASS(triangleSolverunitTests)
	{
	public:
		
		TEST_METHOD(analyzeTriangle_test)
		{

			double x = 3;
			double y = 3;
			double z = 3;

			char* answer = analyzeTriangle(x, y, z);

		Assert:AreEqual();
		}
	};
}
