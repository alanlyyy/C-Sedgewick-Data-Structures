#include <iostream>
#include "C:\Users\Alan\source\repos\Cpp_sedgewick\ch4_ADT\Stack_linked_list.h"

struct adj_node {
	int val;
	adj_node* next;

	adj_node(int v = 0, adj_node* n = 0) {
		val = v;
		next = n;
	}
};

//initialize all elements in array to 0, track nodes that have been visited
int* visited = new int[8]();

void traverse(adj_node** g, int k) {

	//print position since we are currently on
	std::cout << k << std::endl;

	//update the array so we dont visit same node
	visited[k] = 1;


	//print all node attached to current node
	for (adj_node* t = g[k]; t != 0; t = t->next) {

		//if next node has not been visited, traverse through all nodes found in subgroup.
		if (!visited[t->val]) {
			traverse(g, t->val);
		}
	}
}

int main(){

	int arr0[] = { 7,5,2,1,6 };
	int arr1[] = { 7,0 };
	int arr2[] = { 7,0 };
	int arr3[] = { 5,4 };
	int arr4[] = { 6,5,7,3 };
	int arr5[] = { 0,4,3 };
	int arr6[] = { 4,0 };
	int arr7[] = { 1,2,0,4 };

	int size[] = { 5,2,2,2,4,3,2,4 };

	int** arr2D = new int* [8];
	arr2D[0] = arr0;
	arr2D[1] = arr1;
	arr2D[2] = arr2;
	arr2D[3] = arr3;
	arr2D[4] = arr4;
	arr2D[5] = arr5;
	arr2D[6] = arr6;
	arr2D[7] = arr7;

	//build adj_arr	that store nodes to adj_list, by default all nodes are null ptrs
	adj_node** adj_arr = new adj_node * [8]();

	//store the head node of each row
	adj_node* t = 0;
	for (int i = 0; i < 8; i++) {

		for (int j = 0; j < size[i]; j++) {

			//head node is nullptr
			if (adj_arr[i] == 0) {
				adj_arr[i] = new adj_node(arr2D[i][j], 0);

				//store head node
				t = adj_arr[i];
			}
			//otherwise create new node at end of list
			else {
				adj_arr[i] = adj_arr[i]->next = new adj_node(arr2D[i][j], 0);
			}
		}

		if (adj_arr[i] != 0) {
			//point to head node
			adj_arr[i] = t;
		}
	}
	//print list for 2d array
	for (int i = 0; i < 8; i++) {

		std::cout << i << " ";
		for (int j = 0; j < size[i]; j++) {
			std::cout << arr2D[i][j] << " ";
		}
		std::cout << std::endl;

	}

	std::cout << std::endl;

	//print list for 2d array
	for (int i = 0; i < 8; i++) {

		std::cout << i << " ";

		adj_node* p = adj_arr[i];

		//print following nodes up to first node
		while (p != 0) {
			std::cout << p->val << " ";
			p = p->next;
		}

		std::cout << std::endl;

	}

	traverse(adj_arr, 7);
}