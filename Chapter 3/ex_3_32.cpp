#include <iostream>
#include <stdlib.h>


void array_represent_linked_list(int num_ints, int M) {
	int* item = new int[num_ints];
	int* next = new int[num_ints];

	//populated item and next array with elements
	for (int index = 0; index < num_ints; index++) {
		item[index] = index + 1;

		if (index == (num_ints - 1)) {
			next[index] = 0;
		}
		else {
			next[index] = index + 1;
		}
	}

	int nums_left = num_ints;

	//used to track elements in item array
	int index = 0;

	//used to count number of elemenets traversed in the list
	int count = 0;

	//store the return values
	int return_index = 0;
	int return_val = 0;


	while (nums_left > 1) {

		count += 1;

		if (count == (M - 1)) {

			//reset the count after reaching 4 elements
			count = 0;

			//update next element
			next[index] = next[next[index]];

			//decrease nums found
			nums_left -= 1;
		}

		//traverse to next element
		index = next[index];
	}
	return_index = index;
	return_val = item[next[index]];

	std::cout << return_index << " " << return_val << std::endl;
}
int main_3_32() {

	array_represent_linked_list(9, 5);
	array_represent_linked_list(13, 3);
	return 0;
}