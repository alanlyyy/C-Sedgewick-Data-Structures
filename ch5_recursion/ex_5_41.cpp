#include <iostream>

// method precomputing values of recurrence
static int* p3;

int compute_top_down_2(int N, int i) {
	//top down programming recurrence method.

	int ceil;
	int floor;

	//if startin position
	if ((N) == i) {
		p3 = new int[N + 1]();

		floor = i / 2;

		ceil = i / 2;

		//if i/2 contains a remainder ceil +1;
		if ((i % 2) != 0) {
			ceil = i / 2 + 1;
			//std::cout << "ceil: " << ceil << std::endl;
		}

		floor = compute_top_down_2(N, floor);
		ceil = compute_top_down_2(N, (int)ceil);

		p3[i] = (i / 2) + floor + ceil;

		//std::cout << i << " true " << p3[i] << " " << ceil << " " << floor << std::endl;
	}


	//if i = 0 or 1, return 0
	else if (i == 0 || i == 1) {
		p3[i] = 0;
		std::cout << p3[i] << std::endl;
		return p3[i];
	}

	//if N is not 0, 
	else {

		//if floor already exists skip lower level recursions
		if (p3[i/2] != 0) {
			floor = p3[i/2];
		}
		else {
			//compute the new floor 
			floor = compute_top_down_2(N, i / 2);
		}

		ceil = i / 2;

		if ((i % 2) != 0) {
			ceil = i / 2 + 1;
			//std::cout << "ceil: " << ceil << std::endl;
		}

		int val;

		//if ceil already exists skip lower level recursions.
		if (p3[ceil] != 0) {
			val = p3[ceil];
		}
		else {
			//compute the new ceil
			val = compute_top_down_2(N, ceil);
		}

		//compute the value for current position of recurrence using the sub floor and sub ceil
		p3[i] = i / 2 + floor + val;

		//return the val of current position
		return p3[i];
	}

	return p3[i];
}


int main_5_41() {
	std::cout << compute_top_down_2(23, 23) << std::endl;
	return 0;
}