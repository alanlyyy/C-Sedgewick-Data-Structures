#pragma once
#pragma once
#include <new>
#include <iostream>

template  <class Item>
class STACK_ll_arr
{
private:

	//points to top of stack
	int head;

	//store total elements in array of nodes
	int MAX_size = 0;

	Item* val;
	int* next;

public:
	STACK_ll_arr(int MAX) {
		head = 0;
		MAX_size = MAX;
		next = new int[MAX];
		val = new Item[MAX];
	}

	int size() {
		return MAX_size;
	}

	int empty() {
		return head == 0;
	}

	void push(Item x) {

		if ((head+1) != MAX_size) {
			val[head] = x;
			next[head] = head + 1;
			head++;
		}
	}

	Item pop() {

		if (!empty()){
			return val[--head];
		}
	}

	void print_elements() {
		for (int i = 0; i < head; i++) {
			std::cout << val[i] << " " <<next[i] << std::endl;
		}
	}
};