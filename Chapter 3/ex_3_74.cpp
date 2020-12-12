#include <iostream>
#include "adj_matrix.h"

int count_vertex_c_unions(adj_list_node_2** adj_list, int size, int a, int b) {
	
	int count = 0;
	adj_list_node_2* a_list  = adj_list[a];
	adj_list_node_2* t = a_list;

	//iterate until end of a_list
	while (t != 0) {

		//c_list is the list pointed to by the value extracted from current node of a_list
		adj_list_node_2* c_list = adj_list[t->v];

		while (c_list != 0) {

			//if c val is a vertex to b, update counter
			if (c_list->v == b) {

				std::cout << t->v << "-->" << c_list->v << std::endl;
				count += 1;
			}

			//traverse to next node of c
			c_list = c_list->next;
		}

		//traverse to next node in a_list
		t = t->next;
	}

	return  count;
}

int main() {

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

	adj_list_node_2** adj = fill_adj_list_2(7, curr_list);

	print_adj_list_2(adj, 7);

	std::cout << count_vertex_c_unions(adj, size, a, b);

	return 0;
}