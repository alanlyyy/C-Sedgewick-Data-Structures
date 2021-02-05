#include <iostream>

int num_disks = 5;

//initialize the array initially to all zeros, array contains N disks
int* tower_of_hanoi = new int[num_disks]();

void shift(int position, int d) {
	//bit = position - 1
	//shift indices by position bits.

	//if position is bigger num_disks do nothing.
	if (position <= num_disks) {

		for (int i = 0; i < position; i++) {

			//if at last bit
			if (i == (position - 1)) {
				tower_of_hanoi[i] = 1;
			}
			//if not last bit append 0s
			else {
				tower_of_hanoi[i] = 0;
			}

			std::cout << tower_of_hanoi[i] << " ";
		}

		std::cout << std::endl;
	}
}

void hanoi(int N, int d) {

	if (N == 0) return;

	//mark the left side
	hanoi(N - 1, -d);

	//mark the center
	shift(N, d);

	//mark the right side
	hanoi(N - 1, -d);
}

int main_5_24() {
	hanoi(num_disks, 1);
	return 0;
}