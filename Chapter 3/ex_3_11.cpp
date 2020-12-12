#include <iostream>
#include <vector>
#include <cmath>

void sieves_of_eratosthenes(int N) {
	//prints all prime numbers less than N

	//use unsigned int for n > 1000, otherwise we have overflow error
	unsigned int i;

	int count = 0;

	//declare arry of size N
	int * a = new int[N];

	//set all elements in array to 1
	for (i = 2; i < N; i++) {
		a[i] = 1;
	}
	for (i = 2; i < N; i++) {

		// for values j multiples of i, set value to 1
		if (a[i]) {

			//use unsigned int for n> 1000, otherwise we have overflow error.
			unsigned int j = i;
			while(j * i < N) {
				a[i * j] = 0;
				j++;
			}
		}
	}

	for (i = 2; i < N; i++) {
		if (a[i]) {
			count += 1;
		}
	}
	std::cout << "Num integers N: "<< N << " num primes: " << count<< std::endl;
}

void ex_311() {

	//print list of primes for all vaue of N
	std::vector<int> num_N = { 10*10*10, 10 * 10 * 10*10, 10 * 10 * 10*10*10, 10 * 10 * 10* 10 * 10 * 10 };
	for (auto num : num_N)
	{
		sieves_of_eratosthenes(num);
		std::cout << std::endl;
	}
}

int main_311() {
	ex_311();
	return 0;
}