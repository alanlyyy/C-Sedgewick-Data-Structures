#include <iostream>


int find_max(int* arr, int k, int start, int stop) {

	//calculate the new midpoint
	int m = (stop + start) / k;

	int first =0, second=0;

	//if start position = calculated mid point, return array value
	if (start == stop) {
		return arr[start];
	}
	else {

		//break array from start to new mid points
		first = find_max(arr, k, start, m);

		//break array from mid point +1 to stop
		second = find_max(arr, k, m + 1, stop);
	}

	if (first > second) {
		return first;
	}
	else {
		return second;
	}
}

int find_max_k_partitions(int* arr, int start, int stop) {

	//calculate number of partitions 
	int m = (start+stop+1)/2;

	//if number of partitions is odd add 1 
	if ((start + stop +1) % 2 != 0) {
		m = ( (start + stop + 1) /  2 ) + 1;
	}

	//if start == stop, return current element
	if (start == stop) {
		return arr[start];
	}

	int prev = 0;
	int curr = 0;

	for (int i = 0; i < m; i++) {
		//for each iteration we look 2 indices per iteration, up to k parts

		int temp_prev = find_max_k_partitions(arr, i*2, i*2);

		if (temp_prev > prev) {
			prev = temp_prev;
		}

		//if we are at last position break from loop
		if ((i*2) == stop) {
			break;
		}

		int temp_curr = find_max_k_partitions(arr, (i*2) + 1, (i*2) + 1);

		if (temp_curr > curr) {
			curr = temp_curr;
		}
	}


	if (prev > curr) {
		return prev;
	}
	else {
		return curr;
	}

}
int main_5_6() {

	int arr[] = { 80,29,15,17,6,2,95,34};

	std::cout << find_max(arr, 2, 0, 7) << std::endl;
	std::cout << find_max_k_partitions(arr, 0, 7);
	return 0;
}