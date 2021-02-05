#include <iostream>



int compute(int N) {
	//bottom up method precomputing values of recurrence
	int* p = new int[N+1]();

	float ceil;
	int floor;

	std::cout << p[0] << " ";

	for (int i = 1; i < (N+1); i++) {
		
		ceil = (i / 2.0);
		floor = (i / 2);

		if ((ceil - 0.5) == floor) {
			ceil = ceil + 0.5;
		}

		p[i] = floor + p[floor] + p[(int)ceil];

		std::cout << p[i] << " ";
	}
	std::cout << std::endl;

	return p[N];
}

// method precomputing values of recurrence
static int* p2;

int compute_top_down(int N, int i) {
	//recursion without top down programming. program runs at O(N^2)
	//every indice in array, is calculated more than 1 time.
	
	int ceil;
	int floor;

	//if startin position
	if ((N) == i) {
		p2 = new int[N+1]();

		floor = i / 2;

		ceil = i / 2;

		//if i/2 contains a remainder ceil +1;
		if ((i%2) != 0) {
			ceil = i/2 + 1;
			//std::cout << "ceil: " << ceil << std::endl;
		}

		floor = compute_top_down(N, floor);
		ceil = compute_top_down(N, (int)ceil);

		p2[i] = (i / 2) + floor + ceil;

		//std::cout << i << " true " << p2[i] << " " << ceil << " " << floor << std::endl;
	}
	

	//if i = 0 or 1, return 0
	else if (i == 0 || i ==1) {
		p2[i] = 0;
		std::cout << p2[i] << std::endl;
		return p2[i];
	}

	//if N is not 0, 
	else {

		//compute the new floor 
		floor = compute_top_down(N,i/2);

		ceil = i / 2;

		if ((i % 2) != 0) {
			ceil = i / 2 + 1;
			//std::cout << "ceil: " << ceil << std::endl;
		}

		//compute the new ceil
		int val =  compute_top_down(N, ceil);

		//compute the current p2N using the sub floor and sub ceil
		p2[i] = i/2 + floor + val;

		//return the val of current position
		return p2[i];
	}

	return p2[i];
}


int main_5_4() {


	std::cout << compute(23) << " " << std::endl;
	std::cout << std::endl;
	std::cout << compute_top_down(23, 23) << std::endl;

	for (int i = 0; i < 23;  i++) {
		std::cout << p2[i] << " ";
	}

	std::cout << std::endl;

	return 0;
}