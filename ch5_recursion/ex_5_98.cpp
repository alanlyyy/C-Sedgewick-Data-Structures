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

void stack_depth_first_search(adj_node** adj_list, int k) {

	//performs depth first search with ignore new copies of item policy using a stack
	//k is the number of nodes found in the adjacency list.

	STACK_ll<adj_node*> s;
	
	s.push(adj_list[0]);

	//visited array all initialized to 0, tracks if node has been visited.
	int* visited = new int[k]();

	//used to store items that already in stack to prevent duplicates
	int* item_in_stack = new int[k]();

	visited[0] = 1;
	item_in_stack[0] = 1;
	std::cout << 0 << std::endl;

	while (!s.empty()) {
		
		//print popped item
		adj_node* t = s.pop();

		//print node if not been visited
		if (visited[t->val] == 0) {
			std::cout << t->val;
			visited[t->val] = 1;
		}

		//move to vals current list
		t = adj_list[t->val];

		//push all neighbors into the stack
		while (t != 0) {

			//if item has not been traversed push to stack
			if (visited[t->val] == 0 && item_in_stack[t->val] == 0) {
				s.push(t);
				std::cout << " | " << t->val << " ";

				item_in_stack[t->val] = 1;
			}

			t = t->next;
		}

		std::cout << std::endl;
	}
}
int main5_98() {

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
	adj_node** adj_arr = new adj_node*[8]();

	//store the head node of each row
	adj_node* t=0;
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
			std::cout  << arr2D[i][j] << " ";
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
	std::cout << std::endl;
	stack_depth_first_search(adj_arr, 8);
	return 0;
}