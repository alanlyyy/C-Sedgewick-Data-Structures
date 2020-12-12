#include "data_containers.h"
#include <iostream>
#include <math.h>

int gcd(int i_index, int j_index) {
	//get the gcd of current num

	int max = 0;

	for (int i = 0; i <= i_index; i++) {
		
		for (int j = 0; j <= j_index; j++)
		{
			if( ((i_index % (i+1)) == 0) && ((j_index % (j+1)) == 0) 
							&& ((i+1) == (j+1)) ){
				max = i+1;
			}
		}
	}

	return max;
}
void arr2D_allocate(int x, int y) {
	//pass in dimensions of array
	//if gcd bettween i and j is 1, set arr[i][j] =1, else set to arr[i][j] = 0

	int **arr2D = malloc2d(x, y);

	for (int i = 0; i < x; i++) {

		for (int j = 0; j < y; j++) {

			if ((i+1) ==1 || (j+1) ==1){
				arr2D[i][j] = 1;
			}
			else{
				int min_val = std::min((i + 1), (j + 1));
				int max_val = std::max(i + 1, j + 1);

				if ((max_val % min_val) == 0) {
					arr2D[i][j] = 0;
				}
				else {
					arr2D[i][j] = 1;
				}

			}

			std::cout << " i: " << i+1 << " j: " << j+1 << " gcd val: " << arr2D[i][j] <<std::endl;
		}

	}

}

int main_3_64() {
	std::cout << gcd(17, 8) << std::endl;

	arr2D_allocate(5,5);
	return 0;
}