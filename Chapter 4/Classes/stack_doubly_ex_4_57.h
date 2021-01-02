#pragma once
#include <iostream>

class STACK_doubly_derived 
{

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
	link head = 0;
	int size = 0;
	int max_size = 0;
	node** node_array;
public:

	STACK_doubly_derived(int maxN) {
		//constructor used to initialize node array of pointers all null pointers
		node_array = new node*[maxN]();
		max_size = maxN;
	}

	int get_size() {
		return size;
	}

	int empty() {
		return head == 0;
	}

	void push(int x) {


			node* prev_node = head;

			//if element does not exist in the linked list
			if (node_array[x] == 0) {

				//create new node points back to prev_node
				head = new node(x, prev_node, 0);

				//if head is not the first node
				if (head->prev != 0) {
					//create pointer points to new node
					node* current_node = head;

					//head traverses back to previous node
					head = prev_node;

					//update pointer of next previous node with new node
					head->next = current_node;

					//head pointer traverses back to new node
					head = head->next;
				}

				size += 1;

				//pointer at index x points to current head node
				node_array[x] = head;

				std::cout << "Adding element, not found: " << x << std::endl;
			}
			else {

				std::cout << "Updating existing element..." <<  " " << x << std::endl;
				//if node_array[x] points to an existing item, update item with current item.
				node_array[x]->item = x;
			}
	}

	int pop() {

		if (!empty()) {

			int v = head->item; link t = head->prev;

			std::cout << "Deleting Element... " << v << std::endl;

			//index v of node array is now a nullptr
			node_array[v] = 0;

			delete head;
			head = t;
			size -= 1;
			return v;
		}
	}

	void printNodes() {

		node* t = head;

		while (t != 0) {
			std::cout << t->item << " ";

			t = t->prev;
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