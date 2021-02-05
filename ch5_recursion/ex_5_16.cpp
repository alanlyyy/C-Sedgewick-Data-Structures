#include <iostream>

//global variable
int si = 5;
int* arr = new int[si];

int find_max_recursive(int ind,int length) {

	if (ind == length - 1) {
		return arr[0];
	}
	else {

		int val1 = arr[0];
		int val2 = arr[ind];

		//if max at pos 0 is smaller than current value, do a swap.
		if (val1 < val2) {
			arr[0] = val2;
			arr[ind] = val1;
		}

		return find_max_recursive(ind + 1, length);

	}
}

int main_5_16() {
	arr[0] = 5;
	arr[1] = 7;
	arr[2] = 19;
	arr[3] = 2;
	arr[4] = 3;

	std::cout << find_max_recursive(1, 5) << std::endl;

	for (int i = 0; i < si; i++) {
		std::cout << arr[i] << " " << std::endl;
	}


	return 0;
}