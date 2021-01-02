#include <iostream>
#include "Polar_Point.h"

void test() {
	Polar_Point a, b, c(1, 1), d(1,0.5);

	std::cout << a.get_r() << " ";
	std::cout << a.get_theta() << std::endl;
	std::cout << b.get_r() << " ";
	std::cout << b.get_theta() << std::endl;

	std::cout << a.distance(b) << std::endl;

	std::cout << c.get_r() << " ";
	std::cout << c.get_theta() << std::endl;
	std::cout << d.get_r() << " ";
	std::cout << d.get_theta() << std::endl;
	std::cout << c.distance(d) << std::endl; 
}
int main_4_3() {
	test();
	return 0;
}