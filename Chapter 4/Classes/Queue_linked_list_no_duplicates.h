#pragma once
#include "queue_interface_ll.h"
#include <iostream>

template <class Item>
class Queue_ll_derived : public Queue<Item> {

public:

	//inherit constructor from Queue
	Queue_ll_derived(int val) : Queue<Item>(val) {};

	void put2(Item x) {
		//overload put method to deny appending duplicate items, add new items to end of queue

		//if item does not exist on the list
		if ((this->search_node(x)) == 0) {

			//add item to back of list
			this->put(x);
		}
		else {
			std::cout << "Duplicate found for item: " << x << std::endl;
		}
	}
	
};

template <class Item>
class Queue_ll_derived_v2 : public Queue<Item> {

public:

	//inherit constructor from Queue
	Queue_ll_derived_v2(int val) : Queue<Item>(val) {};

	void put2(Item x) {
		//overload put method to replace duplicate items with newest item, non duplicate items added at end of queue.

		Queue<Item> temp_queue(1);

		bool flag = 0;

		//append all elements to temp queue
		while (this->empty() != 1) {
			temp_queue.put(this->get());
		}

		//append all elements back into temp queue
		while (temp_queue.empty() != 1)
		{
			Item current_val = temp_queue.get();

			//if duplicate found, append new copy of item x
			if (current_val == x) {
				std::cout << "Duplicate found for item: " << x << std::endl;
				this->put(x);
				flag = 1;
			}
			//if non duplicate found, append back to queue
			else {
				this->put(current_val);
			}

		}

		//if x is not a duplicate append to end of list
		if (flag == 0) {
			this->put(x);
		}
	}
};