#include <stdio.h>
#include <stdbool.h>

#include "main.h"
#include "triangleSolver.h"
#include "rectangleSolver.h"

RECTANGLEAXIS* getRectanglePoint(RECTANGLEAXIS* p) {
	for (int i = 0; i < 4; i++)
	{
		printf("enter %d x,y coordinates: ", i + 1);
		scanf_s("%f %f", &p[i].x, &p[i].y);
	}
	return p;
}

double* getTriangleSides(double* triangleSides) {
	printf_s("Enter the three sides of the triangle: ");
	for (int i = 0; i < 3; i++)
	{
		scanf_s("%lf", &triangleSides[i]);
	}
	return triangleSides;
}

float main() {
	bool continueProgram = true;
	while (continueProgram) {
		printWelcome();

		int shapeChoice = printShapeMenu();

		switch (shapeChoice)
		{
		case 1:
			printf_s("Triangle selected.\n");
			double triangleSides[3] = { 0.00, 0.00, 0.00 };
			double* triangleSidesPtr = getTriangleSides(triangleSides);
			printf_s("! %f\n", triangleSidesPtr[0]);
			char* result = analyzeTriangle(triangleSidesPtr[0], triangleSidesPtr[1], triangleSidesPtr[2]);
			printf_s("%s\n", result);
			break;
		case 2:
			printf_s("Rectangle selected.\n");
			RECTANGLEAXIS p[4];
			validateRectangle(getRectanglePoint(&p));
			break;
		case 0:
			continueProgram = false;
			break;
		default:
			printf_s("Invalid value entered.\n");
			break;
		}
	}
	return 0;
}

void printWelcome() {
	printf_s("\n");
	printf_s(" **********************\n");
	printf_s("**     Welcome to     **\n");
	printf_s("**   Polygon Checker  **\n");
	printf_s(" **********************\n");
}

int printShapeMenu() {
	printf_s("1. Triangle\n");
	printf_s("2. Rectangle\n");
	printf_s("0. Exit\n");

	int shapeChoice;

	printf_s("Enter number: ");
	scanf_s("%1o", &shapeChoice);

	return shapeChoice;
}


