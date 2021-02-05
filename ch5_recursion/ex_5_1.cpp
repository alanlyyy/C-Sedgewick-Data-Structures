#include <iostream>
#include <math.h>

float lg_factorial(int N) {
	
	if (N == 0) {
		return 0;
	}
	else {
		//std::cout << log10(N)<< " ";
		return log10(N) + lg_factorial(N - 1);
	}
}
int main_5_1() {
	std::cout << lg_factorial(10000) <<std::endl;
	return 0;
}