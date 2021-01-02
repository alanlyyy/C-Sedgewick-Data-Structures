#include "Poly_linked_list.h"
#include <iostream>


void polynomial_client(int N, float expression) {
	
	Poly_linked_list<int> x(1, 1), one(1, 0), t = x + one, y = t;

	for (int i = 0; i < N-1; i++) {
		y = y * t;
		y.print_coefficients();
	}

	std::cout << "Here: " << y.eval(expression) << std::endl;
}

int main_4_78() {

	//polynomial order = (x+1)  , evaluate expression when x =2;
	polynomial_client(1, 2);

	//polynomial order = (x+1)^2  , evaluate expression when x =2;
	polynomial_client(2, 4);

	//polynomial order = (x+1)^3  , evaluate expression when x =10;
	polynomial_client(4, 10);
	return 0;
}