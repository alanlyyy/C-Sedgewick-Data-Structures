#include <iostream>


float * bio_arr;


float compute_binomial(int N, int k, int v, int N_max) {

	//v and N_max are starting constants used to initialize the array at the beginning
	//v and N_max are the same throughout the program.

	if (k == v && N == N_max) {

		bio_arr = new float[N]();

		float first_half = compute_binomial(N - 1, k, v, N_max);
		float second_half = compute_binomial(N - 1, k - 1, v, N_max);


		return first_half + second_half;
	}

	//if element already exists in the array return the item, skip all computations
	if (bio_arr[k] != 0) {
		return bio_arr[k];
	}

	//if kth value does not exist in the binomial array compute and store into array.
	if (k == 0 || k == N)
	{
		//if item is currently 0, replace with 1
		if (bio_arr[k] == 0)
		{
			bio_arr[k] = 1;
		}
		return bio_arr[k];
	}
	else {

		//compute combinatorics equation denominator
		float val = 1;
		float val2 = 1;

		//compute numerator
		float val3 = 1;

		for (int i = 1; i <= k; i++) {
			val *= i;
		}

		for (int i = 1; i <= (N-k); i++) {
			val2 *= i;
		}

		for (int i = 1; i <= N; i++) {
			val3 *= i;
		}

		//store the kth value into array
		bio_arr[k] = val3 / (val*val2);

		//return kth value
		return bio_arr[k];
	}
}

int main_5_55() {
	std::cout <<compute_binomial(3, 2,2, 3) << std::endl;
	return 0;
}