#include "Poly_linked_list.h"

void polynomial_client_v2(int N, float expression) {

	Poly_linked_list<int> x(1, 1), one(1, 0), t = x + one;
	Poly_linked_list<int> v = t;

	for (int i = 0; i < N - 1; i++) {
	 t*=v;
	 t.print_coefficients();
	}

	std::cout << "Here: " << t.eval(expression) << std::endl;
}

void test_add() {

	//x^2 +2x + 1
	Poly_linked_list<int> x(1, 2);
	Poly_linked_list<int> x2(2, 1);
	Poly_linked_list<int> one(1, 0);
	Poly_linked_list<int> neg_one(-1, 0);
	Poly_linked_list<int> xb(1, 1);
	Poly_linked_list<int> oneb(1, 0);

	Poly_linked_list<int>t = x2 +one;
	std::cout << t.eval(2) << std::endl;
	t.print_coefficients();
	
	x2 += one;
	std::cout << x2.eval(2) << std::endl;
	x2.print_coefficients();

	//4x^2 + 4x +1
	t = t * t;
	std::cout << t.eval(2) << std::endl;
	t.print_coefficients();

	//4x+1
	x2 += x2;
	x2 += neg_one;

	//4x^2 +4x+1
	x2 += x;
	x2 += x;
	x2 += x;
	x2 += x;
	std::cout << x2.eval(2) << std::endl;
	x2.print_coefficients();


	//x2 +2x +1
	one += xb;
	one += x;
	one += xb;

	//x2+ 2x+1
	Poly_linked_list<int>z= xb + oneb;
	Poly_linked_list<int>g = z * z;

	std::cout << g.eval(2) << std::endl;
	g.print_coefficients();


	std::cout << one.eval(2) << std::endl;
	one.print_coefficients();
}

int test_mult() {

	//polynomial order = (x+1)  , evaluate expression when x =2;
	polynomial_client_v2(1, 2);

	//polynomial order = (x+1)^2  , evaluate expression when x =2;
	polynomial_client_v2(2, 4);

	//polynomial order = (x+1)^3  , evaluate expression when x =10;
	polynomial_client_v2(3, 8);
	return 0;
}

int main_4_80() {
	//test_add();
	test_mult();
	return 0;
}