#include <iostream>
#include <math.h>

float lg_factorial_2(int N, int M) {
	//compute N! % M
	
	if (N <= 0) {
		return 0;
	}
	else if ((N % M)==0) {
		//if N is divisible by factor M, add 1, recursively call next value N-M away
		return 1 + lg_factorial_2(N-M,M);
	}
	else {
		//if N is not dvisible by M, subtract 1 from N and recursively call function
		return lg_factorial_2(N - 1, M);
	}
}
int main_5_2() {
	int M = 997;
	std::cout << lg_factorial_2(1000,997) << " mod"	<<  M << std::endl;
	std::cout << lg_factorial_2(10000, 997) << " mod"  <<  M << std::endl;
	std::cout << lg_factorial_2(100000, 997) << " mod" <<  M << std::endl;
	std::cout << lg_factorial_2(1000000, 997) << " mod"<<  M << std::endl;
	return 0;
}