//define point implementation
#include "Point.h"
#include <math.h>

Point::Point() {
	x = 1.0 * rand() / RAND_MAX;
	y = 1.0 * rand() / RAND_MAX;
}

Point::Point(int scale) {
	x = scale * rand() / RAND_MAX;
	y = scale * rand() / RAND_MAX;
}

Point::Point(float val, float val2) {
	x = val;
	y = val2;
}

const float Point :: distance(Point a) {
	//function returns a const float that you cannot change the value of.
	float dx = x - a.x;
	float dy = y - a.y;

	return sqrt(dx * dx + dy * dy);
}

const float Point::distance_from_origin() {

	int dx = X();
	int dy = Y();
	return sqrt(dx*dx + dy*dy);
}

float Point::X() {
	return this->x;
}

float Point::Y() {
	return this->y;
}

float distance(Point a,Point b) {
	//method 2 to calculate distance add member functions X and Y to extract data members x and y of "this" instance
	float dx = b.X() - a.X();
	float dy = b.Y() - a.Y();

	return sqrt(dx * dx + dy * dy);

}

int operator==(Point a, Point b) {
	return (distance(a, b) < .001);
}