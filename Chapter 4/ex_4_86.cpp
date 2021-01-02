#include "Poly_linked_list.h"
#include <iostream>

float integral_client(Poly_linked_list<float>& expression, float upper, float lower) {

	//integrate expression
	Poly_linked_list<float> e1 = expression;
	Poly_linked_list<float> e2 = expression;
	e1.integrate();
	e2.integrate();

	//evaluate expression with limits.
	return (e1.eval(upper) - e2.eval(lower));
}
int main_4_86() {
	Poly_linked_list<float> x_squared(1, 2);
	Poly_linked_list<float> two_x(2, 1);
	Poly_linked_list<float> one(1, 0);
	
	Poly_linked_list<float> func = x_squared + two_x;
	func+=one;

	std::cout << integral_client(func, 4.0,2.0) << std::endl;


	return 0;
}