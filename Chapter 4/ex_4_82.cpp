#include "Poly_linked_list.h"
#include <iostream>

int main_4_82() {

	//x^5 +2x
	Poly_linked_list<float> x(1, 4), onex(1, 1);
	Poly_linked_list<float> x2(1, 2);
	Poly_linked_list<float> two_x(2, 1);
	Poly_linked_list<float> one(1, 0);
	Poly_linked_list<float> neg_one(-1, 0);
	Poly_linked_list<float> zero(0, 0, 3);

	zero += x;
	zero += onex;

	zero.print_coefficients();
	zero +=x2;
	zero.print_coefficients();
	zero += two_x;
	zero.print_coefficients();

	zero.integrate();
	zero.print_coefficients();
	zero.derive();
	zero.print_coefficients();
	zero.derive();

	return 0;
}