#pragma once
#include "Point.h"

class Polar_Point : public Point {
	//Polar point is a subclass of point
private:
	float r = 0;
	float theta = 0;	//radians

public:
	Polar_Point();
	Polar_Point(int);
	Polar_Point(float, float);
	const float distance(Polar_Point);
	float get_r();
	float get_theta();
};