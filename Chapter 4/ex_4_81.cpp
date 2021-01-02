#include "Poly_linked_list.h"
#include <iostream>


void test_derive() {
	Poly_linked_list<float> x(1, 1);
	Poly_linked_list<float> one(1, 0);
	Poly_linked_list<float> t = x + one;

	//x^2 + 2x + 1
	t *= t;

	t.print_coefficients();

	t.derive();

	t.print_coefficients();

	Poly_linked_list<float> x2(2, 2);
	Poly_linked_list<float> one2(1, 0);
	Poly_linked_list<float> t2 = x2 + one2;

	//(2x^2 + 1)^2
	t2 *= t2;

	t2.print_coefficients();

	t2.derive();

	t2.print_coefficients();

}

void test_integrate() {
	Poly_linked_list<float> x(2, 2);
	Poly_linked_list<float> one(1, 0);
	Poly_linked_list<float> t = x + one;

	//(2x^2 + 1)^2
	t *= t;

	t.print_coefficients();

	t.integrate();

	t.print_coefficients();

	t.derive();

	t.print_coefficients();
}
int main_4_81() {
	test_integrate();
	test_derive();
	return 0;
}