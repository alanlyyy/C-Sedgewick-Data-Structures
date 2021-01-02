#pragma once
#include <time.h>

template <class Item>
class random_queue_ll
{
	struct node {

		Item item; node* next;

		node(Item x) {
			item = x; next = 0;
		}
	};

	typedef node* link;
	link head, tail;
	int size = 0;

public:
	random_queue_ll(int);
	int empty();
	void put(Item);
	Item get_random();
	void print_elements();
};

template <class Item>
random_queue_ll<Item>::random_queue_ll(int) {
	head = 0;
};

template <class Item>
int random_queue_ll<Item>::empty() {
	return head == 0;
}

template <class Item>
void random_queue_ll<Item>::put(Item x) {
	link t = tail;

	tail = new node(x);

	if (head == 0) {
		head = tail;
	}

	else {
		t->next = tail;
	}

	size++;
}

template <class Item>
Item random_queue_ll<Item>::get_random() {

	if (!empty())
	{
		//set the seed to randomize time
		srand(time(NULL));

		int i = 1, remove_index = rand() % size;

		//search radius is from 1 to (size -1)
		if (remove_index == 0) {
			remove_index = 1;
		}

		node* t = head; //pointer to first node

		while (i < (remove_index - 1)) {
			t = t->next;
			i++;
		};

		Item v;
		link v_next;

		//if head node is being deleted
		if (t == head) {
			v = t->item;

			v_next = t->next;

			delete t;

			head = v_next;
		}
		else if (t == tail) {
			v = t->next->item;

			v_next = t->next->next;

			delete t->next;

			t->next = v_next;

			tail = v_next;
		}
		//if other node is being deleted
		else {
			v = t->next->item;

			v_next = t->next->next;

			delete t->next;

			t->next = v_next;
		}

		size--;


		return v;

	}
	else {
		return 0;
	}
}

template <class Item>
void random_queue_ll<Item>::print_elements() {
	node* t = head;

	while (t != 0) {
		std::cout << t->item << std::endl;
		t = t->next;
	}
}