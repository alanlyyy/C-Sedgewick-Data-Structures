#include "C:\Users\Alan\source\repos\Cpp_Sedgewick_11-07-20\Number.h"
#include <iostream>
#include <cmath>

void calc_nums_r(int length, int r) {

	float sum = 0;

	//create an array of type double with variable length, length.
	double* num_arr = new double[length];

	for (int index = 0; index < length; index++) {

		//if number less than 2 > 0 we have a 1
		int num = randNum() % r;
		std::cout << num << " ";

		//assign current index of arry to num
		*num_arr = num;

		sum += num;

		//update pointer
		num_arr++;

	}

	float mean = sum / length;

	float sum_of_errors = 0;
	float error = 0;

	for (int index = 0; index < length; index++) {

		//starting from last element of array decrement 
		--num_arr;

		//calculate error for each element
		error = *num_arr - mean;

		sum_of_errors += error * error;
	}

	std::cout << mean << " " << sqrt(sum_of_errors / (length - 1)) << std::endl;

	//destroy/deallocate num_arr object after use.
	delete[] num_arr;

	std::cout << mean << " "<< sqrt(sum_of_errors/(length -1)) << std::endl;
}

void call_math_functions() {

	int N [] = { 10 * 10 * 10,10 * 10 * 10 * 10, 10 * 10 * 10 * 10 * 10, 10 * 10 * 10 * 10 * 10 *10};
	int r[] = { 10,100,1000 };

	for (int num_i : N) {
		for (int num_j : r) {
			calc_nums_r(num_i, num_j);
		}
	}

}

void calc_num_bits(int length) {

	float sum = 0;

	//create an array of type double with variable length, length.
	double* num_arr = new double[length];

	for (int index = 0; index < length; index++) {

		//takes a range of numbers from 0 to 1.99, if number is less than 1, we have a 0
		//if number less than 2 > 0 we have a 1
		int num = randNum() % 2;
		std::cout << num << " ";

		//assign current index of arry to num
		*num_arr = num;

		sum += num;

		//update pointer to next element
		num_arr++;
	}

	float mean =  sum / length;

	float sum_of_errors = 0;
	int error = 0;

	for (int index = 0; index < length; index++) {

		//starting from last element of array decrement 
		--num_arr;

		error = *num_arr - mean;

		sum_of_errors += error * error;
	}

	std::cout << mean << " "<< sqrt(sum_of_errors / (length - 1)) << std::endl;

	//destroy/deallocate num_arr object after use.
	delete[] num_arr;
}

void call_math_functions_bit() {

	int N[] = { 3,5,7 };

	for (int num_i : N) {
		calc_num_bits(num_i);
	}

}

int main5() {
	//call_math_functions();
	call_math_functions_bit();
	return 0;
}