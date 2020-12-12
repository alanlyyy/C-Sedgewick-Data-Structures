#include <iostream>
#include "data_containers.h"


int** matrix_multiplication(int** arr2D_A, int** arr2D_B,int row_a, int col_a, int row_b, int col_b) {

	if (col_a != row_b) {
		std::cout << "insufficient dimensions, col_a does not match row_b" << std::endl;
		return 0;
	}

	int ** arr2D_C = malloc2d(row_a, col_b);

	for (int i = 0; i < row_a; i++) {
		for (int j = 0; j < col_b; j++) {
			for (int k = 0; k < row_a; k++) {

				if (k == 0) {
					arr2D_C[i][j] = arr2D_A[i][k] * arr2D_B[k][j];
				}
				else {
					arr2D_C[i][j] += arr2D_A[i][k] * arr2D_B[k][j];
				}
			}

			std::cout << arr2D_C[i][j] << std::endl;
		}
	}

	return arr2D_C;
}

void fill_array(int** arr2D,int x,int y) {
	int count = 1;

	for (int i = 0; i < x; i++) {
		for (int j = 0; j < y; j++) {
			arr2D[i][j] = count;
			std::cout << count << std::endl;
			count++;
		}
	}
}

float search(mult_list* table_x, int row, int col) {
	//takes a copy of table_x finds the val at row and col index
	//return the value stored in the node
	sparse_node_2* start = (*(table_x->sparse_list));

	while (start != NULL) {
		if (start->row_in == row && start->col_in == col && start->item != 0) {
			return start->item;
		}

		start = start->next_node;
	}
	return 0;
}

mult_list* matrix_multiplication(mult_list* table1,mult_list * table2) {
	//take matrix table 1 and table 2, create a copy of resultant table 3


	//break out of loop if dimensions don't match
	if (table1->num_cols != table2->num_rows) {
		std::cout << "multiplication cannot be done" << std::endl;
		return 0;
	}

	//create a header node for sparse_list C 
	sparse_node_2* headerC = new sparse_node_2(0, 0, 0, 0);

	//create a multlist that points to pointer to pointer of sparse_node, with rows and cols dims.
	mult_list* table3 = new mult_list(&headerC, table1->num_rows, table2->num_cols);

	//cursor to first node in table3 sparse_list
	sparse_node_2* currC = (*(table3->sparse_list));


	float prod = 0,t1 = 0, t2 = 0;

	//algorithm is similar to array implementation. 
	//search for node linearly that match the indicies.
	//get the sum of products and append to tableC sparselist
	for (int i = 0; i < table1->num_rows; i++) {
		for (int j = 0; j < table2->num_cols; j++) {

			//reset prod for next iteration
			prod = 0;

			for (int k = 0; k < table1->num_cols; k++) {

				//find val for row i, col k in sparse_list 1
				t1 = search(table1, i, k);

				//find val for row k, col j in sparse_list 2
				t2 = search(table2, k, j);

				prod += t1 * t2;
			}

			//if product is not 0 create a node and append to sparse_list C
			if (prod != 0) {
				currC = currC->next_node = new sparse_node_2(prod, i, j, 0);
			}
		}
	}

	//return a copy of table 3 with copy of sparse_list
	return table3;
}

void print_array(int** arr2D,int x , int y) {
	for (int i = 0; i < x; i++) {
		for (int j = 0; j < y; j++) {
			//std::cout << arr2D[i][j] << " ";
		}
	}
	std::cout << std::endl;
}

void sparse_list_test() {
	//test creating an array
	//fill array
	//create a sparse list with array content
	//initialize mult list object
	//print nodes of mult list object

	int x1 = 2;
	int y1 = 2;

	int x2 = 2;
	int y2 = 1;
	int ** arr2D_A = malloc2d(x1, y1);
	int** arr2D_B = malloc2d(x2, y2);

	fill_array(arr2D_A, x1, y1);
	fill_array(arr2D_B, x2, y2);

	//create a header node
	sparse_node_2* header_A = new sparse_node_2(0, 0, 0, 0);
	sparse_node_2* header_B = new sparse_node_2(0, 0, 0, 0);

	//sparse list points to pointer to first node
	sparse_node_2** sparse_listA = &header_A;
	sparse_node_2** sparse_listB = &header_B;
	
	//create a pointer to mult list which manages the sparse list table
	mult_list* tableA = new mult_list(sparse_listA, x1, y1);
	mult_list* tableB = new mult_list(sparse_listB, x2, y2);

	//fill sparse list with numbers
	arr_to_list_2D_2(tableA->sparse_list, arr2D_A, x1, y1);
	arr_to_list_2D_2(tableB->sparse_list, arr2D_B, x2, y2);

	//print sparse list for testing
	//print_sparse_nodes_2(*(tableA->sparse_list));
	//print_sparse_nodes_2(*(tableA->sparse_list));
	std::cout << "---------------------------" << std::endl;

	mult_list* C = matrix_multiplication(tableA, tableB);

	print_sparse_nodes_2(*(C->sparse_list));
}
int array_test() {

	int x = 2, y = 3;

	int** m1 = malloc2d(2, 2);
	fill_array(m1, 2, 2);
	int** m2 = malloc2d(2, 1);
	fill_array(m2, 2, 1);
	print_array(m1, 2, 2);
	print_array(m2, 2, 1);

	int**mm = matrix_multiplication(m1, m2,2,2,2,1);
	print_array(mm,2,1);

	return 0;
}

int main_3_67() {
	array_test();
	sparse_list_test();
	return 0;
}