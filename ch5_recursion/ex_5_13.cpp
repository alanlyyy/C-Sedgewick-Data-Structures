#include <iostream>
#include <stdlib.h>

struct node
{
	int item;
	node* next;
	node(int x, node* t)
	{
		item = x;
		next = t;
	}
};

typedef node* link;


link t = new node(1, 0);
link x = t;

void create_list(int N) {

	t->next =t;

	for (int i = 2; i <= N; i++) {
		x = (x->next) = new node(i, t);
	}
}

int get_Mth_node(int i, int M) {

	if ((x->next == x) && (i ==0)) {
		return x->item;
	}

	else if ((i == (M-1))) {
		std::cout << x->next->item << std::endl;
		x->next = x->next->next;
		i=0;
		return get_Mth_node(i, M);
	}
	else {
		i += 1;
		x = x->next;
		return get_Mth_node(i, M);
	}
}

int main_5_13() {

	create_list(17);
	std::cout << "last_node: " << get_Mth_node(0, 6) << std::endl;

	return 0;
}