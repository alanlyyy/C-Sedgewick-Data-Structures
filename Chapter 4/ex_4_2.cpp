#include "Point.h"
#include <iostream>

int main_4_2() {

	//create new point a
	Point a;
	Point b(10);

	std::cout << a.X() << " " << a.Y() << std::endl;
	std::cout << a.distance_from_origin() << std::endl;

	std::cout << b.X() << " " << b.Y() << std::endl;
	std::cout << b.distance_from_origin() << std::endl;

	return 0;
}