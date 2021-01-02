#include "Vector_Algebraic.h"
#include <iostream>

int main_4_87() {
	Vec<float> p(2);
	Vec<float> d(2);
	Vec<float> g(1);
	Vec<float> f(1);


	p.push(1);
	p.push(2);
	p.push(3);
	p.push(4);

	p.print_elements();

	d.push(1);
	d.push(2);
	d.push(3);
	d.push(4);


	d.print_elements();

	//test overload += operator
	p += d;

	p.print_elements();

	//+= operator with constant
	d += 2;

	d.print_elements();

	//test overloaded *= operator
	d *= 10;

	d.print_elements();

	g.push(1);
	g.push(1);
	g.push(1);
	g.push(1);

	g *= d;

	g.print_elements();

	//test copy constructor
	f = p;

	f.print_elements();

	return 0;
}