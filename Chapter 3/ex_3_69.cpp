#include <iostream>
#include "adj_matrix.h"

struct adj_list_node {
	int v; adj_list_node* next;

	adj_list_node(int val, adj_list_node* next_node) {
		v = val;
		next = next_node;
	}

};

adj_list_node** fill_adj_list(int size, mult_list_v2_adj_matrix* pairs_list) {
	//creates an adj list with vertexes stored in an array of length size, and  vertices in a linked list.
	int i, j;

	//create an array of pointer to adj_list_nodes of length size
	adj_list_node** adj = new adj_list_node*[size];
	
	//initialize all vertices to nullptr
	for (int i = 0; i < size; i++) {
		adj[i] = 0;
	}


	mult_list_pair_2* t = (pairs_list->header)->next_pair;

	//insert elements into adjacency list
	while (t != 0) {
		int row = t->row;
		int col = t->col;

		//create a new node for edge, new node points back to vertex 
		adj[col] = new adj_list_node(row, adj[col]);
		adj[row] = new adj_list_node(col, adj[row]);

		t = t->next_pair;
	}

	return adj;
}

void print_adj_list(adj_list_node** list, int size) {

	for (int i = 0; i < size; i++) {

		std::cout << i << " ";

		if (list[i] != 0) {

			//print each node connected to the vertex in the circular list.
			adj_list_node* vertex = list[i];

			while (vertex != 0) {
				std::cout << vertex->v  << " ";
				vertex = vertex->next;
			}
		}

		std::cout << std::endl;
	}
}
int main_3_69() {
	mult_list_pair_2* first_node = new mult_list_pair_2(0, 0, 0);
	mult_list_v2_adj_matrix* curr_list = new mult_list_v2_adj_matrix(first_node);

	curr_list->insertNode(0, 2);
	curr_list->insertNode(1, 4);
	curr_list->insertNode(2, 5);
	curr_list->insertNode(3, 6);
	curr_list->insertNode(0, 4);
	curr_list->insertNode(6, 0);
	curr_list->insertNode(1, 3);


	//print mult_list_pair inputs to adjacency matrix
	mult_list_pair_2* t = curr_list->header->next_pair;

	while (t != 0) {
		std::cout << " row: " << t->row << " col: " << t->col << std::endl;

		t = t->next_pair;
	}

	adj_list_node ** adj = fill_adj_list(7, curr_list);

	print_adj_list(adj, 7);

	return 0;
}