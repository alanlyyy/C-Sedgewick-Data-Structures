#pragma once
#include <iostream>
#include "Stack_array.h"

template <class Item>
class STACK_arr_no_duplicates : public STACK_arr<Item>
{
	//inherit all variables and functions from STACK_arr overload the push function
public:

	//inherit constructor from STACK_arr, pass value of STACK_arr_no_duplicates constructor into base
	//class STACK_arr constructor.
	STACK_arr_no_duplicates(int v) : STACK_arr<Item>(v){};


	void push(Item item)
	{
		//overload push function to include a rule to check for duplicates before inserting
		bool flag = false;
		int current_num_elements = this->get_size();

		for (int i = 0; i < current_num_elements; i++){

			//if item exists in the stack 
			if (this->get_current_element() == item) {
				flag = true;
				std::cout << "Duplicate found in stack: " << item << std::endl;
				break;
			}
			//move to next element in the stack
			this->update_current_index();
		}

		//reset the current index back to 0
		this->update_current_index();

		//if element does not exist in the array,append to stack
		if (flag == false)
		{
			//if we don't exceed total array elements append item to stack
			if ((this->get_size() + 1) != this->get_total_array_elements()) {
				this->add_to_stack(item);
			}
		}
	}

};
