#include <iostream>
#include "Complex.h"

void complex_roots_unity_client() {
	int N = 8;

	std::cout << "Complex roots of unity " << N << std::endl;

	for (int k = 0; k < N; k++) {
		float theta = 2.0 * 3.14159 * k / N;
		Complex t(cos(theta), sin(theta)), x = t;

		std::cout << k << ":" << " " << t << " ";

		for (int j = 0; j < N - 1; j++) {
			x *= t;
		}
		std::cout << x << std::endl;
	}
}

void test_add_complex() {
	float theta = 2.0 * 3.14159;
	Complex t(cos(theta*(1.0/4.0)), sin(theta*(1.0/4.0)));
	Complex z(cos(theta * (1.0 / 4.0)), sin(theta * (1.0 / 4.0)));

	std::cout << "t: " <<t.Re() << " " << t.Im() << std::endl;
	std::cout << "z: " << z.Re() << " " << z.Im() << std::endl;
	t + z;
	std::cout << "t: " << t.Re() << " " << t.Im() << std::endl;
	std::cout << "z: " << z.Re() << " " << z.Im() << std::endl;
	t += z;
	std::cout << "t: " << t.Re() << " " << t.Im() << std::endl;

	std::cout << t << std::endl;
}

int main_4_63() {
	//test_add_complex();
	complex_roots_unity_client();
	return 0;
}