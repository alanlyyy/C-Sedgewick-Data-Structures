#include <iostream>

int calc(int low, int high, int* a) {
	//calculate number of trailing zeros of an binary integer array

	//if after decrementing high = low break
	if (high == low) {
		return 0;
	}

	// if leading one is found break
	if (a[high-1] == 1) {
		return 0;
	}

	//otherwise decrement high and add 1
	else {
		return 1 + calc(low, high - 1, a);
	}
}

int num_trailing_zeros(int * a, int N) {
	
	//split array into 2 halves
	int m = N / 2;

	//computer trailing 0s in first half
	int num_zero1 = calc(0, m, a);

	//computer trailing 0s in second half
	int num_zero2 = calc(m, N, a);

	//if 1 is found in mid point, return count of trailing zeros of second half
	if (a[m] == 1) {
		return num_zero2;
	}

	else if ((N - m) > num_zero2) {
		return num_zero2;
	}

	//other wise return both counts.
	else {
		return num_zero1 + num_zero2;
	}
}


int main_5_28() {
	int arr[] = { 1, 0, 0, 1, 0 };
	int arr2[] = { 1, 0, 0, 0, 0 };
	int arr3[] = { 1, 0, 1, 0, 0 };
	int arr4[] = { 0, 1, 0, 0, 1 };
	int arr5[] = { 0, 1, 0, 0 };
	int arr6[] = { 1, 1, 1, 1 };
	int arr7[] = { 1, 0, 0, 0 };
	int arr8[] = { 1, 0, 1, 0 };
	std::cout << num_trailing_zeros(arr, 5) << std::endl;
	std::cout << num_trailing_zeros(arr2, 5) << std::endl;
	std::cout << num_trailing_zeros(arr3, 5) << std::endl;
	std::cout << num_trailing_zeros(arr4, 5) << std::endl;
	std::cout << num_trailing_zeros(arr5, 4) << std::endl;
	std::cout << num_trailing_zeros(arr6, 4) << std::endl;
	std::cout << num_trailing_zeros(arr7, 4) << std::endl;
	std::cout << num_trailing_zeros(arr8, 4) << std::endl;
	return 0;

}