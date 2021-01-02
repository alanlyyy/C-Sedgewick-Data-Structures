#include "Matrix.h"

int main_4_88() {
	Matrix<float> m1(1, 2);
	Matrix<float> m2(2, 2);

	m1.insert_val(0, 0, 5);
	m1.insert_val(0, 1, 3);

	m2.insert_val(0, 0, 1);
	m2.insert_val(0, 1, 2);
	m2.insert_val(1, 0, 3);
	m2.insert_val(1, 1, 4);

	Matrix<float> D = m1*m2;

	m1.print_elements();
	m2.print_elements();
	D.print_elements();

	Matrix<float> E = m2 + m2;
	E.print_elements();


	std::cout << "incorrect dimensions addition: " << std::endl;

	Matrix<float> m3(1, 2);
	Matrix<float> m4(2, 2);

	m3.insert_val(0, 0, 5);
	m3.insert_val(0, 1, 3);

	m4.insert_val(0, 0, 1);
	m4.insert_val(0, 1, 2);
	m4.insert_val(1, 0, 3);
	m4.insert_val(1, 1, 4);
	Matrix<float> C = m3 + m4;
	C.print_elements();


	Matrix<float> P = m4/ m4;
	P.print_elements();
	return 0;
}