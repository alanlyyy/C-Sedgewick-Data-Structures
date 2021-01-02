#include "Poly_linked_list.h"

int main_4_79() {
	
	Poly_linked_list<int> c(1, 1);
	Poly_linked_list<int> d = c;

	std::cout << "d: ";
	d.print_coefficients();


	std::cout << "c: ";
	c.print_coefficients();

	Poly_linked_list<int> e = d + c;

	std::cout << "e: ";
	e.print_coefficients();

	Poly_linked_list<int> f(0, 1);

	Poly_linked_list<int> g = c +f;
	std::cout << "g: ";
	g.print_coefficients();

	return 0;
}