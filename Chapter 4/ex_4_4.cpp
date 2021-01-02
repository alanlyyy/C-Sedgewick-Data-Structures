#include "Point.h"

int main_4_4() {
	Point a(1,0), b(1,0.00001); 

	std::cout << (a == b) << std::endl;

	return 0;
}