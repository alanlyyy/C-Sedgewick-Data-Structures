#include <iostream>
#include <ostream>

struct Playing_card {
	friend int operator==(Playing_card, Playing_card);
	friend std::ostream& operator<<(std::ostream& t, Playing_card);
	char rank[2];
};

int operator==(Playing_card A, Playing_card B)
{
	if ((A.rank[0] == B.rank[0])
		&& (A.rank[1] == B.rank[1])) {
		return 1;
	}
	else {
		return 0;
	}
}

std::ostream& operator<<(std::ostream& t, Playing_card a) {
	std::cout << a.rank << " ";
	return t;
}
int main_4_7() {
	Playing_card A;
	A.rank[0] = 'A';
	Playing_card B;
	B.rank[0] = '5';

	Playing_card C;
	C.rank[0] = '1';
	C.rank[1] = '0';
	Playing_card D;
	D.rank[0] = '1';
	D.rank[1] = '0';

	Playing_card E;
	E.rank[0] = '10';
	Playing_card F;
	F.rank[0] = 'A';

	std::cout << A << " " << B << " " << (A == B) << std::endl;
	std::cout << C << " " << D << " "  << (C == D) << std::endl;
	std::cout << E << " " << F << " "  << (E == F) << std::endl;

	return 0;
}