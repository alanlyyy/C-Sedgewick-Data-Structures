#include <iostream>


float lg_factorial_5_3(int N, int M) {
	//compute N! % M

	if (N <= 0) {
		return 0;
	}
	else if ((N % M) == 0) {
		//if N is divisible by factor M, add 1, recursively call next value N-M away
		return 1 + lg_factorial_5_3(N - M, M);
	}
	else {
		//if N is not dvisible by M, subtract 1 from N and recursively call function
		return lg_factorial_5_3(N - 1, M);
	}
}

int main_ex_5_3() {
	for (int i = 1; i < 10; i++) {

		for (int j = 1; j < 10; j++) {
			std::cout << lg_factorial_5_3(i,j) << " ";
		}
		std::cout << std::endl;
	}
	return 0;
}