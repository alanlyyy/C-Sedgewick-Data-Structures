#include <iostream>
#include "data_containers.h"


struct mult_list_pair {
	int row = 0;
	int col = 0;
	mult_list_pair* next_pair;

	mult_list_pair(int row_num, int col_num, mult_list_pair* next) {
		row = row_num;
		col = col_num;
		next_pair = next;
	}

};

struct mult_list_v2 {
	mult_list_pair* header;
	mult_list_pair* curr;
	void insertNode(int row, int col) {
		//given row and col, we insert data into mult_list pair list

		curr = curr->next_pair = new mult_list_pair(row, col, 0);
	}

	mult_list_v2(mult_list_pair* firstNode) {
		//constructor to initialize header of mult list
		header = firstNode;
		curr = firstNode;
	}

};

int** adjacency_matrix(int size, mult_list_pair* head_node) {

	int i,j;
	int** adj_matrix = malloc2d(size, size);


	//fill  diagonal with 1s rest of array with 0's
	for (i = 0; i < size; i++) {
		for (j = 0; j < size; j++) {

			if (i != j)
				adj_matrix[i][j] = 0;
			else
				adj_matrix[i][j] = 1;
		}
	}

	mult_list_pair* curr_pair = head_node->next_pair;

	while (curr_pair != 0) {

		//set row and col equal to 1
		int row_index = curr_pair->row;
		int col_index = curr_pair->col;
		adj_matrix[row_index][col_index] = 1;
		adj_matrix[col_index][row_index] = 1;

		//move onto next pair
		curr_pair = curr_pair->next_pair;
	}

	return adj_matrix;
}

void print_adjaceny_matrix(int** adj, int size) {

	std::cout << "  ";
	for (int i = 0; i < size; i++) {
		std::cout << i << " ";
	}
	std::cout << std::endl;
	
	for (int i = 0; i < size; i++) {

		//print header row
		std::cout << i << " ";

		for (int j = 0; j < size; j++) {
			std::cout << adj[i][j] << " ";
		}

		std::cout << std::endl;
	}
}

int main_ex_3_68() {

	mult_list_pair* first_node = new mult_list_pair(0, 0, 0);
	mult_list_v2* curr_list = new mult_list_v2(first_node);

	curr_list->insertNode(0,2);
	curr_list->insertNode(1, 4);
	curr_list->insertNode(2, 5);
	curr_list->insertNode(3, 6);
	curr_list->insertNode(0, 4);
	curr_list->insertNode(6, 0);
	curr_list->insertNode(1, 3);


	//print mult_list_pair inputs to adjacency matrix
	mult_list_pair* t = curr_list->header->next_pair;

	while (t != 0) {
		std::cout << " row: " << t->row << " col: " << t->col << std::endl;

		t = t->next_pair;
	}

	//reset pointer to first pair
	t = curr_list->header;

	int** adj_mat = adjacency_matrix(7, t);

	print_adjaceny_matrix(adj_mat,7);

	return 0;
}
