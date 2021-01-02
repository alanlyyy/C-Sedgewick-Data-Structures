#pragma once
#include "random_queue.h"

template <class Item>
class random_queue_derived: public random_queue_array<Item>
{
	//random queue array class that inherits random queue function.
public:

	//pass in argument into derived class to pass parameter into base class.
	random_queue_derived(int maxN) : random_queue_array<Item>(maxN) {};

	void put2(Item item) {

		if (this->search_item(item) == 0) {
			this->put_in_back(item);
		}
		else {
			std::cout << "Duplicate item found: " << item << std::endl;
		}
	}
};

template <class Item>
class random_queue_derived_v2 : public random_queue_array<Item>
{
	//random queue array class that inherits random queue function.
public:
	
	random_queue_derived_v2(int maxN) : random_queue_array<Item>(maxN) {};

	void put2(Item item) {

		if (!this->empty()) {

			//create an array of N items
			Item* s = new Item[this->get_size()];
			int i = 0;
			int j = 0;

			bool flag = 0;

			//pop first element of queue
			Item current_val;

			//continue to pop elements of queue until not empty?
			while ((!this->empty())) {
				current_val = this->get_random();
				s[i] =current_val;
				i++;
			}

			//add all elements from array into back into queue
			while (j<i+1) {

				current_val = s[j];

				//if value is found
				if (current_val == item) {
					std::cout << "Duplicate found ... " << current_val << std::endl;
					//item is found, so we pop duplicate item out of queue.

					//append new copy of item into queue
					this->put_in_back(item);

					flag = 1;
				}
				else {
					//otherwise duplicate does not exist, append item to back of list.
					this->put_in_back(current_val);
				}
				j++;
			}

			//if item does not exist in the list append to end of queue.
			if (flag == 0) {
				this->put_in_back(item);
			}

			//clear memory for array s
			delete s;

		}
		else {
			this->put_in_back(item);
		}
	}
};