#include <iostream>

// method precomputing values of recurrence
static int* p4;

int compute_top_down_3(int N, int i) {
	//top down programming recurrence method.

	int ceil;
	int floor;

	//if startin position
	if ((N) == i) {
		p4 = new int[N + 1]();

		floor = i / 2;

		ceil = i / 2;

		//if i/2 contains a remainder ceil +1;
		if ((i % 2) != 0) {
			ceil = i / 2 + 1;
			//std::cout << "ceil: " << ceil << std::endl;
		}

		floor = compute_top_down_3(N, floor);
		ceil = compute_top_down_3(N, (int)ceil);

		p4[i] = (i / 2) + floor + ceil;

		//std::cout << i << " true " << p4[i] << " " << ceil << " " << floor << std::endl;
	}


	//if i = 0 or 1, return 0
	else if (i == 0 || i == 1) {
		p4[i] = 0;
		std::cout << p4[i] << std::endl;
		return p4[i];
	}

	//if N is not 0, 
	else {

		//if floor already exists skip lower level recursions
		if (p4[i / 2] != 0) {
			floor = p4[i / 2];
		}
		else {
			//compute the new floor 
			floor = compute_top_down_3(N, i / 2);
		}

		ceil = i / 2;

		if ((i % 2) != 0) {
			ceil = i / 2 + 1;
			//std::cout << "ceil: " << ceil << std::endl;
		}

		int val;

		//if ceil already exists skip lower level recursions.
		if (p4[ceil] != 0) {
			val = p4[ceil];
		}
		else {
			//compute the new ceil
			val = compute_top_down_3(N, ceil);
		}

		//compute the value for current position of recurrence using the sub floor and sub ceil
		p4[i] = i / 2 + floor + val;

		//return the val of current position
		return p4[i];
	}

	return p4[i];
}


int main_5_43() {
	//std::cout << compute_top_down_3(23, 23) << std::endl;
	for (int i = 2; i < 1024; i++) {
		std::cout << i << " : " << compute_top_down_3(i, i) << std::endl;

		//deallocate current array, to be ready for initialization for next computation.
		delete[] p4;
	}
	return 0;
}