#pragma once
#pragma once
#include <new>
#include <iostream>

template  <class Item>
class STACK_ll_doubly
{
private:
	struct node
	{
		Item item;
		node* next;
		node* prev;

		node(Item x,node* p, node* t) {
			item = x;
			next = t;
			prev = p;
		}
	};

	typedef node* link;
	link head=0;
	int size = 0;

public:

	int get_size() {
		return size;
	}

	int empty() {
		return head == 0;
	}

	void push(Item x) {

		try {
			node* prev_node = head;

			//create new node points back to prev_node
			head = new node(x, prev_node,0);

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
		}
		catch (std::bad_alloc& ba) {
			std::cout << "bad allocation caught " << ba.what() << std::endl;
		}
	}

	Item pop() {

		if (!empty()) {
			Item v = head->item; link t = head->prev;
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
};