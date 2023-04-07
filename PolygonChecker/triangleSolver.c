#include <stdio.h>
#include <stdbool.h>
#include <math.h>

#include "triangleSolver.h"

char* analyzeTriangle(double side1, double side2, double side3) {
	char* result = "";
	if (side1 <= 0 || side2 <= 0 || side3 <= 0) {
		result = "Not a triangle";
	}
	else
	{
		if (side1 >= (side2 + side3) || side2 >= (side1 + side3) || side3 >= (side1 + side2))
		{
			result = ("Not a triangle");
		}
		else if (side1 == side2 && side1 == side3)
		{
			result = "Equilateral triangle";
			calculateAngles(side1, side2, side3);
		}
		else if ((side1 == side2 && side1 != side3) || (side1 == side3 && side1 != side2))
		{
			result = "Isosceles triangle";
			calculateAngles(side1, side2, side3);
		}
		else
		{
			result = "Scalene triangle";
			calculateAngles(side1, side2, side3);
		}
	}
	return result;
}

void calculateAngles(double side1, double side2, double side3)
{
	char angles = "";
	double A, B, C, s, pi, R;
	pi = acos(-1);

	s = (side1 + side2 + side3) / 2;

	//  Jonathan Leffler tests

	double area = sqrt(s * (s - side1) * (s - side2) * (s - side3));
	R = (side1 * side2 * side3) / (4 * area);

	// add test
	double R2 = R * 2.0;
	A = (side1 > R2) ? 180 / pi : (180 / pi) * asin(side1 / R2);
	B = (side2 > R2) ? 180 / pi : (180 / pi) * asin(side2 / R2);
	C = (side3 > R2) ? 180 / pi : (180 / pi) * asin(side3 / R2);

	printf("Angles: %6.2f %6.2f %6.2f\n", A, B, C);

}

