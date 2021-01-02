#pragma once
#include <iostream>
class Queue_doubly_ll {

private:
	struct node
	{
		int item;
		node* next;
		node* prev;

		node(int x, node* p, node* t) {
			item = x;
			next = t;
			prev = p;
		}
	};

	typedef node* link;
	node* head = 0;
	node* tail = 0;
	int size = 0;
	int max_size = 0;
	node** node_array;

public:
	Queue_doubly_ll(int maxN)
	{
		node_array = new node * [maxN]();
		max_size = maxN;
	}

	int empty() {
		return head == 0;
	}

	void put(int x) {

		//if first node
		if (head == 0) {
			//create new node with value x
			head = new node(x, 0, 0);

			head->prev = head;
			head->next = head;
			tail = head;

			//node * pointer array element x contains a pointer to current node
			node_array[x] = head;
		}
		else {

			node* prev_node = tail;

			//if element does not exist in the linked list
			if (node_array[x] == 0) {

				//create new node points back to prev_node
				tail = new node(x, prev_node, 0);

				//if tail is not the first node
				if (tail->prev != 0) {

					//create pointer points to new node
					node* current_node = tail;

					//head traverses back to previous node
					tail = prev_node;

					//update pointer of next previous node with new node
					tail->next = current_node;

					//head pointer traverses back to new node (last node)
					tail = tail->next;
				}

				size += 1;

				//pointer at index x points to current tail node
				node_array[x] = tail;

				std::cout << "Adding element, not found: " << x << std::endl;
			}
			else {

				std::cout << "Updating existing element..." << " " << x << std::endl;
				//if node_array[x] points to an existing item, update item with current item.
				node_array[x]->item = x;
			}
		}
	}

	int get() {

		if (!empty()) {

			int v = head->item; link t = head->next;

			std::cout << "Deleting Element... " << v << std::endl;

			//index v of node array is now a nullptr
			node_array[v] = 0;

			//delete current head
			delete head;

			//update next node as head
			head = t;

			//head node previous pointer set to null
			head->prev = 0;

			size -= 1;
			return v;
		}
	}

	void printNodes() {

		node* t = head;

		while (t != 0) {
			std::cout << t->item << " ";

			t = t->next;
		}

		std::cout << std::endl;

	}

	void printNodes_through_array() {

		for (int i = 0; i < max_size; i++)
		{
			if (node_array[i] != 0) {
				std::cout << "index: " << i << " " << node_array[i]->item << std::endl;
			}
		}
		std::cout << std::endl;

	}

};