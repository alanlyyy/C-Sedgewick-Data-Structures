#pragma once
#include <new>
#include <iostream>

template  <class Item>
class STACK_ll
{
protected:
	struct node
	{
		Item item; 
		node* next;

		node(Item x, node* t) {
			item = x;
			next = t;
		}
	};
	typedef node* link;

private:
	link head=0;
	link traverse = head;	//pointer used to traverse the linked list
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
			head = new node(x, head);
			size += 1;
		}
		catch (std::bad_alloc& ba) {
			std::cout << "bad allocation caught " << ba.what() << std::endl;
		}
	}

	Item pop() {

		if(!empty()) {
			Item v = head->item; link t = head->next;
			delete head;
			head = t;
			size -= 1;
			return v;
		}
	}

	node* get_head() {
		return head;
	}

	void set_head(Item item) {
		head = new node(item, head);
		size += 1;
	}

	void print_elements() {
		node* t = head;

		while (t != 0) {
			std::cout << t->item << " ";
			t = t->next;
		}
		std::cout << std::endl;
	}
	bool search_item(Item item) {

		traverse = head;
		while (traverse != 0) {

			if (traverse->item == item) {
				return 1;
			}
			traverse = traverse->next;
		}
		return 0;
	}

	bool replace_node(Item item) {

		traverse = head;

		while (traverse->next != 0) {

			if (traverse->item == item) {

				//update node with most current item if duplicate item is found
				traverse->item = item;

				return 1;
			}

			traverse = traverse->next;
		}

		return 0;
	}
};