#include "data_containers.h"
#include <iostream>

int*** malloc3d(int x, int y, int z) {
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

int** malloc2d(int x, int y) {
	//create a 2d array.

	//create an pointer to an array of (int*) with width x
	int** controller = new int* [x];

	for (int i = 0; i < x; i++) {

		//for each row index, create a column index of height y
		controller[i] = new int [y];

	}

	return controller;
}

//sparse_node_2 constructor
sparse_node_2::sparse_node_2(int item2, int row_index, int col_index, sparse_node_2* n_node) {
		row_in =row_index;
		col_in = col_index;
		item = item2;
		next_node = n_node;
}

mult_list::mult_list(sparse_node_2** s_list, int row, int col) {
	sparse_list = s_list;
	num_rows = row;
	num_cols = col;
}

void print_sparse_nodes_2(sparse_node_2* t) {
	//print nodes--------------------------

	t = t->next_node;
	while (t != 0) {

		std::cout << t->item << " " << t->row_in << " " << t->col_in << std::endl;

		t = t->next_node;
	}
}

void arr_to_list_2D_2(sparse_node_2** s_node, int** arr2D, int x, int y) {
	//pointer used to traverse to each node,, append element from arr2D if element is non zero
	//copy all elements from 2D array into sparse list of 2D

	sparse_node_2* t = *s_node;

	for (int i = 0; i < x; i++) {

		for (int j = 0; j < y; j++) {

			if (arr2D[i][j] != 0) {
				//create a new node that points to first node in the row
				t = t->next_node = new sparse_node_2(arr2D[i][j],i,j, 0);
				std::cout << t->item << std::endl;
			}
		}

	}
}

