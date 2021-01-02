#pragma once
#include "queue_array_interface.h"
#include <iostream>

template <class Item>
class Queue_no_duplicates_derived : public Queue_array<Item>
{
	//Queue no duplicates derived is a derived class of Queue array
	//inherits all public members found in Queue array.
	//class uses the brute force method to check for duplicates.
	//if duplicate is found, ignore the current item.
public:

	//pass in maxN variable from Derived class into inherited constructor from Base class.
	Queue_no_duplicates_derived(int maxN) : Queue_array<Item>(maxN) {};

	void put2(Item item) {

		//if item does not exist add element to end of list.
		if ((this->search_element(item)) == 0) {

			//append item to end of queue
			this->put(item);
		}
		else {
			std::cout << "duplicate item found : " << " " << item << std::endl;
		}
		
	}
};

template <class Item>
class Queue_no_duplicates_derived_v2 : public Queue_array<Item>
{
	//Queue no duplicates derived is a derived class of Queue array
	//inherits all public members found in Queue array.
	//uses brute force method and forget the old item policy if a duplicate item is found.
public:

	//pass in maxN variable from Derived class into inherited constructor from Base class.
	Queue_no_duplicates_derived_v2(int maxN) : Queue_array<Item>(maxN) {};

	void put2(Item item) {

		if (!this->empty()) {

			//create a temp queue with same length as current queue
			Queue_array<Item> s(this->get_size());

			bool flag = 0;

			//pop first element of queue
			Item current_val;

			//continue to pop elements of queue until not empty?
			while ((!this->empty())) {
				current_val = this->get();
				s.put(current_val);
			}

			//add all elements from temp queue back into original queue
			while (!s.empty()) {

				current_val = s.get();

				//if value is found
				if (current_val == item) {
					std::cout << "Duplicate found ... " << current_val << std::endl;
					//item is found, so we pop duplicate item out of queue.

					//append new copy of item into queue
					this->put(item);

					flag = 1;
				}
				else {
					//otherwise duplicate does not exist, append item to back of list.
					this->put(current_val);
				}
			}

			//if item does not exist in the list append to end of queue.
			if (flag ==0) {
				this->put(item);
			}

		}
		else {
			this->put(item);
		}
	}
};