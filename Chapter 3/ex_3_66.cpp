//convert a 2D array into a 2D sparse list, each (X) list contains a header node broken up Y elements
//each sparse list loops back to the header node of each row.
//each header node has 2 links, while each node in the sparse list has 1 link.
#include "data_containers.h"
#include <iostream>


struct sparse_node {
	int item = 0;
	sparse_node* row_next;
	sparse_node* col_next;

	sparse_node(int item2, sparse_node* row, sparse_node* col) {
		item = item2;
		row_next = row;
		col_next = col;
	}
};

void print_sparse_nodes(sparse_node* t) {
	//print nodes--------------------------
	//reset traversal node

	while (t != 0) {

		sparse_node* header = t;

		t = t->row_next;

		//at the last node, this is null
		if (t == 0) {
			break;
		}

		while (t != header) {
			std::cout << t->item << std::endl;
			t = t->row_next;
		}

		t = t->col_next;
	}
}

void arr_to_list_2D(sparse_node** s_node, int** arr2D, int x, int y) {
	//pointer used to traverse to each node,, append element from arr2D if element is non zero
	//copy all elements from 2D array into sparse list of 2D

	sparse_node* t = *s_node;

	for (int i = 0; i < x; i++) {

		sparse_node* head_node = t;

		for (int j = 0; j < y; j++) {

			if (arr2D[i][j] != 0) {
				//create a new node that points to first node in the row
				t = t->row_next = new sparse_node(arr2D[i][j], head_node, 0);
				std::cout << t->item << std::endl;
			}
		}

		t = t->row_next;

		std::cout << "end: " << t->item << std::endl;
		//create a new sparse header node for next row in column
		t = t->col_next = new sparse_node(0, 0, 0);
	}
}
int main_works() {
	//create an 2D array, 5 by 5
	int x = 3, y = 9;
	int ** arr2D =malloc2d(x, y);

	int count = 1;

	for (int i = 0; i < x; i++) {
		for (int j = 0; j < y; j++) {
			arr2D[i][j] = count;
			std::cout << count << std::endl;
			count++;
		}
	}

	//define pointer to start sparse list
	sparse_node* first_sparse_node = new sparse_node(0,0,0);

	//sparse list points to first node
	sparse_node** sparse_list = &first_sparse_node;
	(*sparse_list)->row_next = *sparse_list;
	
	//pointer used to traverse to each node
	sparse_node* t = *sparse_list;

	for (int i = 0; i < x; i++) {

	sparse_node* head_node = t;

		for (int j = 0; j < y; j++) {

			if (arr2D[i][j] != 0) {
				//create a new node that points to first node in the row
				t = t->row_next = new sparse_node(arr2D[i][j], head_node, 0);
				std::cout << t->item << std::endl;
			}
		}

		t = t->row_next;

		std::cout <<"end: " << t->item << std::endl;
		//create a new sparse header node for next row in column
		t = t->col_next = new sparse_node(0, 0, 0);
	}

	t = *sparse_list;

	print_sparse_nodes(t);

	return 0;
}

int main_3_66() {
	//create an 2D array, 5 by 5
	int x = 3, y = 9;
	int** arr2D = malloc2d(x, y);

	int count = 1;

	for (int i = 0; i < x; i++) {
		for (int j = 0; j < y; j++) {
			arr2D[i][j] = count;
			std::cout << count << std::endl;
			count++;
		}
	}

	//define pointer to start sparse list
	sparse_node* first_sparse_node = new sparse_node(0, 0, 0);

	//sparse list points to node pointer to first node of sparse list.
	sparse_node** sparse_list = &first_sparse_node;

	//first node pointer in sparse list points back to itself. 
	(*sparse_list)->row_next = *sparse_list;

	//used to traverse the sparse list for printing.
	sparse_node* t = *sparse_list;

	arr_to_list_2D(sparse_list, arr2D, x, y);

	print_sparse_nodes(t);

	return 0;
}