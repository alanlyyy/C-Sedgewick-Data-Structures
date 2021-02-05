#include <iostream>

int depth = 3;

//initialize the array initially to all zeros, array contains N disks
int* ruler = new int[depth]();


void mark(int position, int d) {
	//bit = position - 1
	//shift indices by position bits.

	for (int i = 0; i < d; i++) {

		//if at last bit
		if (i == (d - 1)) {
			ruler[i] = 1;
		}
		//if not last bit append 0s
		else {
			ruler[i] = 0;
		}

		std::cout << ruler[i] << " ";
	}

	std::cout << std::endl;

}

void rule(int low, int high, int d) {


	int m = (low + high) / 2;

	if (d > 0) {

		//mark the left side
		rule(low, m, d-1);

		//mark the center
		mark(m, d);

		//mark the right side
		rule(m, high, d-1);
	}
}

int main5_26() {
	rule(0,7, depth);
	
	std::cout << "------------" << std::endl;
	delete [] ruler;
	depth = 5;
	ruler = new int[depth];
	rule(0, (pow(2, 5) - 1), depth);

	std::cout << "------------" << std::endl;
	delete[] ruler;
	depth = 5;
	ruler = new int[depth];
	rule(0, (pow(2, 5) - 1), depth);

	std::cout << "------------" << std::endl;
	delete[] ruler;
	depth = 4;
	ruler = new int[depth];
	rule(0, 11, depth);

	std::cout << "------------" << std::endl;
	delete[] ruler;
	depth = 4;
	ruler = new int[depth];
	rule(4, 20, depth);

	std::cout << "------------" << std::endl;
	delete[] ruler;
	depth = 5;
	ruler = new int[depth];
	rule(7, 30, depth);

	return 0;
}