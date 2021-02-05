#include <iostream>

float compute_recurrence(int i) {

	//initialize all elements to 0
	float* c = new float[i+1]();

	c[0] = 1;

	for (int j = 1; j <= i; j++) {

		//std::cout << "pre: " << c[j] <<std::endl;

		for (int k = 1; k <= j; k++) {
			c[j] += c[k - 1] + c[j - k];
		}

		c[j] = c[j] / float(j);

		c[j] += j;

		//std::cout << "post: " << c[j] << std::endl;
	}

	return c[i];
}

static float* c2;

float compute_recurrence_top_down(int i, int N) {
	//top down recurrence storing precomputed values into array

	//if start of recursion
	if (i == N) {

		//initialize array to N elements with value of 0;
		c2 = new float[N+1]();

		//compute running sum
		for (int j = 1; j <= i; j++) {
			c2[i] += compute_recurrence_top_down(j - 1, N);
			c2[i] += compute_recurrence_top_down(i - j, N);
		}

		c2[i] = c2[i] / i;
		c2[i] += i;

		return c2[i];
	}

	//if index 0 , c0 = 1;
	else if (i == 0) {

		if (c2[i] == 0)
		{
			c2[i] = 1;
		}

		return c2[i];
	}
	else {

		//if c2[i] already exist in the array, return the value 
		if (c2[i] != 0) {
			return c2[i];
		}
		//otherwise compute c2[i]
		else {

			//for each c2[i] compute running sum
			for (int j = 1; j <= i; j++) {
				c2[i] += compute_recurrence_top_down(j - 1, N);
				c2[i] += compute_recurrence_top_down(i-j,N);
			}
			c2[i] = c2[i] / i;
			c2[i] += i;

			return c2[i];
		}
	}
}
int main_5_44() {
	std::cout << compute_recurrence(100) << std::endl;
	std::cout << compute_recurrence_top_down(100,100) << std::endl;
	return 0;
}