#include <iostream>

static float* c3;

float compute_recurrence_top_down_2(int i, int N) {
	//top down recurrence storing precomputed values into array

	//if start of recursion
	if (i == N) {

		//initialize array to N elements with value of 0;
		c3 = new float[N + 1]();

		//compute running sum
		for (int j = 1; j <= i; j++) {
			c3[i] += compute_recurrence_top_down_2(j - 1, N);
			c3[i] += compute_recurrence_top_down_2(i - j, N);
		}

		c3[i] = c3[i] / i;
		c3[i] += i;

		return c3[i];
	}

	//if index 0 , c0 = 1;
	else if (i == 0) {

		if (c3[i] == 0)
		{
			c3[i] = 1;
		}

		return c3[i];
	}
	else {

		//if c3[i] already exist in the array, return the value 
		if (c3[i] != 0) {
			//std::cout << i << " : " <<c3[i] <<std::endl;
			return c3[i];
		}
		//otherwise compute c3[i]
		else {

			//for each c3[i] compute running sum
			for (int j = 1; j <= i; j++) {
				c3[i] += compute_recurrence_top_down_2(j - 1, N);
				c3[i] += compute_recurrence_top_down_2(i - j, N);
			}
			c3[i] = c3[i] / i;
			c3[i] += i;

			return c3[i];
		}
	}
}
int main_5_45() {
	//std::cout << compute_recurrence_top_down_2(23, 23) << std::endl;

	for (int v = 1; v <= 1024; v++) {
		std::cout << v <<  " " <<compute_recurrence_top_down_2(v, v) << std::endl;

		delete[] c3;
	}
	return 0;
}