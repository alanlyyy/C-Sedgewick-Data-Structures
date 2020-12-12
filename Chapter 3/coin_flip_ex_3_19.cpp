#include <iostream>
#include <stdlib.h>
#include <time.h>

int heads(int probability, int lambda) {
	return rand() < lambda* RAND_MAX / probability;
}

void coin_flip_sim(int N, int M) {
	int i, j, cnt;

	//create an array of frequencies, N +1 length
	int* f = new int[N + 1];

	for (j = 0; j <= N; j++) {
		f[j] = 0;
	} 
	
	for (i = 0; i < M; i++, f[cnt]++) {
		for (cnt = 0, j = 0; j <= N; j++) {
			if (heads(6,2)) {
				cnt++;
			}
		}
	}

	for (j = 0; j <= N; j++) {
		if (f[j] == 0) {
			std::cout << ".";
		}
		for (i = 0; i < f[j]; i += 10) {
			std::cout << "*";
		}
		std::cout << std::endl;
	}
}

int main_coin_sim() {
	/* initialize random seed: */
	//so we get generate random numbers using rand() during every compilation.
	srand(time(NULL));

	//if num < RAND_MAX /6, we declare it as heads, otherwise tails
	coin_flip_sim(32, 1000);

	return 0;
}