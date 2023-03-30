#pragma once
#include<stdbool.h>
typedef struct rectangleAxis {

	float x, y;
}RECTANGLEAXIS;

float rectangleArea(RECTANGLEAXIS*);
bool validateRectangle(RECTANGLEAXIS*);