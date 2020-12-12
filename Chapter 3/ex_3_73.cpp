#include "adj_matrix.h"
#include <iostream>


int count_vertices_that_are_unions(int** adj_matrix,int size,int a, int b) {
	//counts the number of vertices c, that fufill the property if a->c, c->b;
	//for adjacency matrix works for both direct and undirect graphs.
	
	int count = 0;

	for (int j = 0; j < size; j++) {

		if (adj_matrix[a][j] == 1) {
			if (adj_matrix[j][b] == 1) {

				std::cout << a << "-->" << j  << " " << j << "-->" << b << std::endl;
				count += 1;
			}
		}
	}

	return count;

}

int main_3_73() {

	int size = 10;
	int a = 0;
	int b = 5;
	mult_list_pair_2* first_node = new mult_list_pair_2(0, 0, 0);
	mult_list_v2_adj_matrix* curr_list = new mult_list_v2_adj_matrix(first_node);

	curr_list->insertNode(0, 2);
	curr_list->insertNode(1, 4);
	curr_list->insertNode(2, 5);
	curr_list->insertNode(3, 6);
	curr_list->insertNode(0, 4);
	curr_list->insertNode(6, 0);
	curr_list->insertNode(1, 3);
	curr_list->insertNode(1, 5);
	curr_list->insertNode(0, 1);
	curr_list->insertNode(4, 5);


	//print mult_list_pair inputs to adjacency matrix
	mult_list_pair_2* t = curr_list->header->next_pair;

	while (t != 0) {
		std::cout << " row: " << t->row << " col: " << t->col << std::endl;

		t = t->next_pair;
	}

	//reset pointer to first pair
	t = curr_list->header;

	int** adj_mat = adjacency_matrix_2(size, t);

	print_adjaceny_matrix_2(adj_mat, size);

	std::cout<< count_vertices_that_are_unions(adj_mat, size, a, b)<< std::endl;

	return 0;
}