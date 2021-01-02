#pragma once
#include <iostream>
template <class Item>
class Queue 
{

private:

	struct node {

		Item item; node* next;

		node(Item x) {
			item = x; next = 0;
		}
	};

	typedef node* link;
	link head, tail;

public:
	Queue(int);
	~Queue();
	int empty();
	void put(Item);
	Item get();
	bool search_node(Item);
	void print_nodes();
};

template <class Item>
Queue<Item>::Queue(int) {
	head = 0;
};

template <class Item>
int Queue<Item>::empty() {
	return head == 0;
}

template <class Item>
void Queue<Item>::put(Item x) {
	link t = tail;

	tail = new node(x);

	if (head == 0) {
		head = tail;
	}

	else {
		t->next = tail;
	}
}


template <class Item>
Item Queue<Item>::get() {
	Item v = head->item;
	link t = head->next;
	delete head;
	head = t;
	return v;
}

template<class Item>
bool Queue<Item>::search_node(Item item) {

	node* t = head;

	bool flag = 0;

	//if t is null, no nodes are found in list
	while (t != 0) {

		//if current element = item return true
		if (t->item == item) {
			flag = 1;
			break;
		}
		t = t->next;
	}

	//return false;
	return flag;
}

template<class Item>
void Queue<Item>::print_nodes() {

	node* t = head;

	while (t != 0) {
		std::cout << t->item << " ";
		t = t->next;
	}

	std::cout << std::endl;
}
template<class Item>
Queue<Item>::~Queue() {
	//destructor to deallocate memory
	node* temp = head;
	while (temp != 0){
		temp = head->next;
		delete head;
		head = temp;
	}
}