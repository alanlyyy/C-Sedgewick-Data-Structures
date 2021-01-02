#pragma once
#include <iostream>
class Point {
	//Point ADT interface
	friend float distance(Point, Point);
	friend  int operator==(Point, Point);

private:
	float x = 0;
	float y = 0;

public:
	Point();
	Point(int);
	Point(float, float);
	const float distance(Point) ;
	const float distance_from_origin();
	float X();
	float Y();
};

