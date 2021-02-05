#include <iostream>

struct node2
{
	int item;
	node2* next;
	node2(int x, node2* t)
	{
		item = x;
		next = t;
	}
};

typedef node2* link;

//global node
link t = new node2(1, 0);
link x = t;

void print_nodes(node2* curr_node) {
	
	while (curr_node != 0) {
		std::cout << curr_node->item << " ";
		curr_node = curr_node->next;
	}

	std::cout << std::endl;
}

void create_list2(int N) {
	//create a list of N nodes
	for (int i = 2; i <= N; i++) {
		x = (x->next) = new node2(i, 0);
	}
}

int delete_last_node() {
	//recursively delete the last node

	if (x->next->next == 0) {
		int v = x->next->item;
		x->next = x->next->next;
		return v;
	}
	else {
		x = x->next;
		return delete_last_node();
	}
}

int main_5_14() {
	create_list2(9);
	x = t;
	std::cout << delete_last_node() << std::endl;
	x = t;
	print_nodes(x);
	x = t;
	std::cout << delete_last_node() << std::endl;
	x = t;
	print_nodes(x);
	x = t;

	return 0;
}