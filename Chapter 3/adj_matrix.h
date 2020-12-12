#pragma once
struct mult_list_pair_2 {
	int row = 0;
	int col = 0;
	mult_list_pair_2* next_pair;

	mult_list_pair_2(int row_num, int col_num, mult_list_pair_2* next);

};

struct mult_list_v2_adj_matrix {
	mult_list_pair_2* header;
	mult_list_pair_2* curr;

	void insertNode(int row, int col);

	mult_list_v2_adj_matrix(mult_list_pair_2* firstNode);

};

struct adj_list_node_2 {
	int v; adj_list_node_2* next;

	adj_list_node_2(int val, adj_list_node_2* next_node);

};

adj_list_node_2** fill_adj_list_2(int size, mult_list_v2_adj_matrix* pairs_list);
adj_list_node_2** fill_adj_list_2_directed_graph_2(int size, mult_list_v2_adj_matrix* pairs_list);
void print_adj_list_directed_graph(adj_list_node_2** list, int size);
void print_adj_list_2(adj_list_node_2** list, int size);

int** adjacency_matrix_2(int size, mult_list_pair_2* head_node);

void print_adjaceny_matrix_2(int** adj, int size);

int** adjacency_matrix_direct_graph_2(int size, mult_list_pair_2* head_node);

void print_adjaceny_matrix_direct_graph_2(int** adj, int size);
