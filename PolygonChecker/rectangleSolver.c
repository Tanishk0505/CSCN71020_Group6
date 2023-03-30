#include <stdio.h>
#include <stdbool.h>
#include <math.h>

#include "rectangleSolver.h"

float rectangleArea(RECTANGLEAXIS* p) {
    float length, width;

    // Calculate length and width
    if (p[0].x == p[1].x) {
        length = fabs(p[1].y - p[0].y);
        width = fabs(p[2].x - p[1].x);
    }
    else {
        length = fabs(p[2].y - p[1].y);
        width = fabs(p[1].x - p[0].x);
    }

    // Calculate area
    float area = length * width;

    return area;
}
bool validateRectangle(RECTANGLEAXIS* p) {
    // Calculate the lengths of all sides
    float side1 = sqrt(pow(p[1].x - p[0].x, 2) + pow(p[1].y - p[0].y, 2));
    float side2 = sqrt(pow(p[2].x - p[1].x, 2) + pow(p[2].y - p[1].y, 2));
    float side3 = sqrt(pow(p[3].x - p[2].x, 2) + pow(p[3].y - p[2].y, 2));
    float side4 = sqrt(pow(p[0].x - p[3].x, 2) + pow(p[0].y - p[3].y, 2));

    // Calculate the diagonals
    float diagonal1 = sqrt(pow(p[2].x - p[0].x, 2) + pow(p[2].y - p[0].y, 2));
    float diagonal2 = sqrt(pow(p[3].x - p[1].x, 2) + pow(p[3].y - p[1].y, 2));

    // Check if the sides are parallel and diagonals are equal
    if (side1 == side3 && side2 == side4 && diagonal1 == diagonal2) {
        printf("it is rectangle\n");
        printf("Rectangle's area is %f\n", rectangleArea(p));
        return true;
    }
    else {

        printf("Not A Rectangle\n");
        return false;
    }
}