#pragma once
int*** malloc3d(int x, int y, int z);

int** malloc2d(int x, int y);

struct sparse_node_2 {
	int item = 0;
	int row_in = 0;
	int col_in = 0;
	sparse_node_2* next_node;

	sparse_node_2(int item2, int row_index, int col_index, sparse_node_2* n_node);
};

void arr_to_list_2D_2(sparse_node_2** s_node, int** arr2D, int x, int y);
void print_sparse_nodes_2(sparse_node_2* t);

struct mult_list {

	//used to store rows and dimensions and sparse node list 
	sparse_node_2** sparse_list;
	int num_rows = 0;
	int num_cols = 0;

	mult_list(sparse_node_2** s_list, int row, int col);

};