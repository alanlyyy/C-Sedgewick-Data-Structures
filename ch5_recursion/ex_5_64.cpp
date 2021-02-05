#include <iostream>

bool is_isomorphic(int* arr1, int size1, int* arr2, int size2) {

	//if sizes of 2 arrays are not equal, the number of vertices of both array are different
	//both arrays are not isomorphic.

	int num_edges1 = 0;
	int num_edges2 = 0;

	if (size1 != size2) {
		return false;
	}

	else {

		for (int i = 0; i < size1; i++) {

			//if there is an edge (i is different than a[i]) add 1 to count
			if (i != arr1[i]) {
				num_edges1 += 1;
			} 

			if (i != arr2[i]) {
				num_edges2 += 1;
			}

		}
	}

	return (num_edges1 == num_edges2);
}
int main_5_64() {

	int arr1[] = { 0,2,3,4.1 };
	int arr2[] = { 0,1,2,3,4 };


	int arr3[] = { 0,1,2,3,4 };

	std:: cout << " 4 edges, 5 vertices vs 0edges 5 vertices: " << is_isomorphic(arr1,5, arr2,5) << std::endl;

	std::cout << "5 vertices, 0 edges both the same: " << is_isomorphic(arr3, 5, arr2, 5) << std::endl;


	return 0;
}