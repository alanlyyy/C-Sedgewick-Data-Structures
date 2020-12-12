#include <iostream>
#include "data_containers.h"
#include "adj_matrix.h"

mult_list_pair_2::mult_list_pair_2(int row_num, int col_num, mult_list_pair_2* next) {
	row = row_num;
	col = col_num;
	next_pair = next;
}

void mult_list_v2_adj_matrix::insertNode(int row, int col) {
		//given row and col, we insert data into mult_list pair list

		curr = curr->next_pair = new mult_list_pair_2(row, col, 0);
}

mult_list_v2_adj_matrix::mult_list_v2_adj_matrix(mult_list_pair_2* firstNode) {
		//constructor to initialize header of mult list
		header = firstNode;
		curr = firstNode;
}


int** adjacency_matrix_2(int size, mult_list_pair_2* head_node) {

	int i, j;
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

	mult_list_pair_2* curr_pair = head_node->next_pair;

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

void print_adjaceny_matrix_2(int** adj, int size) {

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

adj_list_node_2::adj_list_node_2(int val, adj_list_node_2* next_node) {
	v = val;
	next = next_node;
}

adj_list_node_2** fill_adj_list_2(int size, mult_list_v2_adj_matrix* pairs_list) {
	//creates an adj list with vertexes stored in an array of length size, and  vertices in a linked list.
	int i, j;

	//create an array of pointer to adj_list_nodes of length size
	adj_list_node_2** adj = new adj_list_node_2 * [size];

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
		adj[col] = new adj_list_node_2(row, adj[col]);
		adj[row] = new adj_list_node_2(col, adj[row]);

		t = t->next_pair;
	}

	return adj;
}

int** adjacency_matrix_direct_graph_2(int size, mult_list_pair_2* head_node) {
	//create an adjaceny matrix for directed graph.
	int i, j;
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

	mult_list_pair_2* curr_pair = head_node->next_pair;

	while (curr_pair != 0) {

		//set row and col equal to 1
		int row_index = curr_pair->row;
		int col_index = curr_pair->col;
		adj_matrix[row_index][col_index] = 1;

		//move onto next pair
		curr_pair = curr_pair->next_pair;
	}

	return adj_matrix;
}

void print_adjaceny_matrix_direct_graph_2(int** adj, int size) {
	/// <summary>
	/// print adj matrix for directed graph
	/// </summary>
	/// <param name="adj"></param>
	/// <param name="size"></param>
	int val = size * size + size / 2;
	char* directed_graph = new char[val];
	int count = 0;

	for (int i = 0; i < size; i++) {

		if (count >= (val - 4)) {
			std::cout << "Overflow" << std::endl;
			break;
		}

		for (int j = 0; j < size; j++) {

			std::cout << adj[i][j] << " ";

			if ((adj[i][j] == 1) && (i != j)) {

				directed_graph[count] = i + '0';
				count += 1;
				directed_graph[count] = '>';
				count += 1;
				directed_graph[count] = j + '0';
				count += 1;
				directed_graph[count] = '\n';
				count += 1;

			}
		}
		std::cout << std::endl;
	}

	for (int i = 0; i < count; i++) {
		std::cout << directed_graph[i] << " ";
	}

}

adj_list_node_2** fill_adj_list_2_directed_graph_2(int size, mult_list_v2_adj_matrix* pairs_list) {
	//creates an adj list with vertexes stored in an array of length size, and  vertices in a linked list.
	int i, j;

	//create an array of pointer to adj_list_nodes of length size
	adj_list_node_2** adj = new adj_list_node_2 * [size];

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
		adj[row] = new adj_list_node_2(col, adj[row]);

		t = t->next_pair;
	}

	return adj;
}

void print_adj_list_directed_graph(adj_list_node_2** list, int size) {
	//prints adj list for directed graph: row -> col

	for (int i = 0; i < size; i++) {

		if (list[i] != 0) {

			//print each node connected to the vertex in the circular list.
			adj_list_node_2* vertex = list[i];

			while (vertex != 0) {
				std::cout << i << " --> " << vertex->v << std::endl;
				vertex = vertex->next;
			}
		}

		std::cout << std::endl;
	}
}

void print_adj_list_2(adj_list_node_2** list, int size) {

	for (int i = 0; i < size; i++) {

		std::cout << i << " ";

		if (list[i] != 0) {

			//print each node connected to the vertex in the circular list.
			adj_list_node_2* vertex = list[i];

			while (vertex != 0) {
				std::cout << vertex->v << " ";
				vertex = vertex->next;
			}
		}

		std::cout << std::endl;
	}
}