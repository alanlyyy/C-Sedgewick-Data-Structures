#include "C:\Users\Alan\source\repos\Cpp_Sedgewick_11-07-20\Number.h"
#include <iostream>
#include <cmath>


double generate_nums(int max) {
	//use rand() from math library to generate a number in the range from 0 to max
	int num = randNum()*(max);

	return num;
}



void calc_nums(int length, int max) {
	//calculates mean and standard deviation for each r and N case
	
	//stores running sum
	double sum = 0, mean =0;

	//create an array of type double with variable length, length.
	double *num_arr = new double[length];

	//calculate mean
	for (int num = 0; num < length; num++) {
		
		double val = generate_nums(max);

		//add element to array
		*num_arr = val;

		//add value to running sum
		sum += val;

		//update to next element in array
		num_arr++;
	}

	mean = sum / length;

	//calculate stdev
	double sum_of_errors = 0;
	double error = 0;

	for (int index = 0; index < length; index++) {

		//decrement the array  starting from the end
		--num_arr;

		//compute parts of stdev
		error = (*num_arr - mean);
		sum_of_errors += error * error;

	}

	//compute stdev
	float stdev = sqrt(sum_of_errors / (length - 1));

	std::cout << mean << " " << stdev << std::endl;

	//deallocate/destroy pointer to array once all numbers are processed
	delete[] num_arr;
}

void wrapper() {
	//function calls calc_nums for N and r paramenters

	int r[] = { 10,100,1000 };
	int N[] = { 10 * 10 * 10,10 * 10 * 10 * 10, 10 * 10 * 10 * 10 * 10, 10 * 10 * 10 * 10 * 10 * 10 };

	for (int num_i : r) {
		for (int num_j : N) {
			calc_nums(num_j, num_i);
		}
	}
}

int main2() {
	wrapper();
	return 0;
}