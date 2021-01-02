#include "Poly_linked_list.h"
#include <iostream>
int main_4_83() {

	//x^5 +2x
	Poly_linked_list<float> x(1, 2), onex(1, 1);
	Poly_linked_list<float> x2(1, 2);
	Poly_linked_list<float> two_x(2, 1);
	Poly_linked_list<float> one(1, 0);
	Poly_linked_list<float> neg_one(-1, 0);
	Poly_linked_list<float> zero(0, 0, 3);
	Poly_linked_list<float> zero_2(0, 0);
	Poly_linked_list<float> zero_3(0, 0);
	Poly_linked_list<float> five_x(-5, 1);
	Poly_linked_list<float> zero_4(0, 0);
	Poly_linked_list<float> zero_5(0, 0);
	Poly_linked_list<float> x6(1, 6);
	Poly_linked_list<float> two_x4(2, 4);
	Poly_linked_list<float> six_x(6, 1);
	Poly_linked_list<float> minus_nine(-9, 0);
	Poly_linked_list<float> zero_6(0, 0);
	Poly_linked_list<float> x3(1, 3);
	Poly_linked_list<float> three(3, 0);
	Poly_linked_list<float> zero_comp(0, 0);

	//x2 +2x + 1 
	zero += x;
	zero += (onex+onex);
	zero += one;

	zero.print_coefficients();

	//x+1
	zero_2 += onex;
	zero_2 += one;

	Poly_linked_list<float> t = zero / zero_2;

	//Poly_linked_list<float> t2 = zero_2 / zero;

	
	std::cout << "Remainder: " << std::endl;
	//2x^2 -5x -1
	zero_3 += five_x;
	zero_3 += (x2 + x2);
	zero_3 += neg_one;

	zero_3.print_coefficients();

	//x-3
	zero_4 += (neg_one + neg_one);
	zero_4 += neg_one;
	zero_4 += onex;

	zero_4.print_coefficients();

	Poly_linked_list<float> t3  = zero_3 / zero_4;

	//Poly_linked_list<float> t4 = zero_4 / zero_3;


	std::cout << "Missing Terms:" << std::endl;

	//x^6 + 2x^4 + 6x -9
	zero_5 += x6;
	zero_5 += two_x4;
	zero_5 += six_x;
	zero_5 += minus_nine;

	zero_5.print_coefficients();

	//x^3 + 3
	zero_6 += x3;
	zero_6 += three;

	zero_6.print_coefficients();

	zero_5 / zero_6;

	//x2 +2x + 1 
	zero_comp += x;
	zero_comp += (onex + onex);
	zero_comp += one;

	//test composition
	std::cout << "f(g(4) = 11 :" << zero_4.eval(7.0) << std::endl;
	std::cout << "f(g(4) = 11 :" << zero_comp.eval(4) << std::endl;
	std::cout << "f(g(4) = 11 :" << zero_comp.composition(zero_4, 7.0) << std::endl;

	return 0;
}