#include <iostream>

int*** malloc3d_extra(int x, int y, int z) {
	//create a 3d array.

	//create an pointer to an array of (int**) with width x
	int*** controller = new int** [x];

	for (int i = 0; i < x; i++) {

		//for each row index, create a column index of height y
		controller[i] = new int* [y];

		for (int j = 0; j < y; j++) {

			//for each column index create a new array of depth z
			controller[i][j] = new int[z];

			//for each element initialize element to 0
			for (int k = 0; k < z; k++) {
				controller[i][j][k] = 0;
			}
		}
	}

	return controller;
}

int main_3_62() {

	int *** arr3D = malloc3d_extra(3, 2, 2);

	arr3D[1][0][0] = 36;
	arr3D[0][0][1] = 2;
	arr3D[0][1][0] = 1;

	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 2; j++) {
			for (int k = 0; k < 2; k++) {
				std::cout << i << " " << j << " "<<k << " "<< arr3D[i][j][k] << std::endl;
			}
		}
	}
	return 0;
}