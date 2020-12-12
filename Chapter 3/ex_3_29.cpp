#include <iostream>
#include <stdlib.h>

struct node
{
	//stores node value
	int item;

	//stores pointer to next node
	node* next;

	//node constructor, t is next node
	node(int x, node* t) {

		item = x;

		next = t;
	}
};

typedef node* link;

int circ_list_j(int num_links, int interval) {
	int i;
	int N = num_links;
	int M = interval;

	//create a new node points to null
	link t = new node(1, 0);

	//new node points to itself
	t->next = t;

	link x = t;

	for (i = 2; i <= N; i++) {
		x = (x->next = new node(i, t));
	}

	while (x != x->next) {

		for (i = 1; i < M; i++) {
			x = x->next;
		}

		x->next = x->next->next;
	}

	//std::cout << x->item << std::endl;

	return x->item;
}

int circ_list_edit(int num_links, int interval) {
	int i;
	int N = num_links;
	int M = interval;

	//create a new node points to null, store first node
	link t = new node(1, 0);

	link x = t;

	for (i = 2; i <= N; i++) {

		//if last node, x points back to  t,first node.
		if (i == N) {
			x->next = new node(i, t);

			//set x back to t
			x = x->next;
		}
		//insert list linearly
		else {
			//update the next node to point to new node
			x->next = new node(i, 0);

			//t is now equal to new node
			x = x->next;
		}
	}

	while (x != x->next) {

		for (i = 1; i < M; i++) {
			x = x->next;
		}

		x->next = x->next->next;
	}

	//std::cout << x->item << std::endl;

	return x->item;
}

void circ_list_j_wrapper() {
	int M[] = { 2,3,5,10 };
	int N[] = { 10 * 10 * 10, 10 * 10 * 10 * 10, 10 * 10 * 10 * 10 * 10, 10 * 10 * 10 * 10 * 10 * 10 };

	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 4; j++) {
			std::cout << "M: " << M[j] << " N: " << N[i] << " last num: " << circ_list_j(N[i], M[j]) << " last_num_modified: " << circ_list_edit(N[i], M[j]) << std::endl;
		}
	}
}
int main_3_29() {
	//circ_list_j(15, 3);
	//circ_list_edit(15, 3);
	circ_list_j_wrapper();
	return 0;
}