#pragma once
#include <iostream>
#include "Stack_array.h"

template <class Item>
class STACK_arr_no_duplicates_v2 : public STACK_arr<Item>
{
	//inherit all variables and functions from STACK_arr overload the push function
public:

	//inherit constructor from STACK_arr, pass value of STACK_arr_no_duplicates constructor into base
	//class STACK_arr constructor.
	STACK_arr_no_duplicates_v2(int v) : STACK_arr<Item>(v) {};

	void push(Item item)
	{
		//overload push function to include a rule to check for duplicates before inserting

		//create temp queue for storing popped elements afte item is found
		STACK_arr<Item> temp_stack(this->get_size());

		bool flag = false;

		int current_num_elements = this->get_size();

		for (int i = 0; i < current_num_elements; i++) {

			//if item exists in the stack 
			if (this->get_current_element() == item) {
				flag = true;
				std::cout << "Duplicate found in stack: " << item << std::endl;
			}
			//move to next element in the stack
			this->update_current_index();
		}

		if (flag == true) {

			Item popped_val = this->pop();
			temp_stack.push(popped_val);

			//continue to pop elements until item is found
			while (popped_val!= item) {

				//pop next element
				popped_val = this->pop();

				//append to end of the stack
				temp_stack.push(popped_val);
			}

			//continue to pop from temp stack to push elements into current stack
			while (!temp_stack.empty())
			{
				//if first item popped is old duplicate item
				if (popped_val == item) {

					//pop first item 
					temp_stack.pop();

					std::cout << "Adding new version to stack:" << " "<< item<< std::endl;
					//manually add new item to current stack
					this->add_to_stack(item);
				}
				else {
					//append popped element into stack
					this->push(temp_stack.pop());
				}
			}
		}

		else
		{
			//if we don't exceed total array elements append item to stack
			if ((this->get_size() + 1) != this->get_total_array_elements()) {
				this->add_to_stack(item);
			}
		}

		//reset the current index back to 0
		this->update_current_index();
	}

};
