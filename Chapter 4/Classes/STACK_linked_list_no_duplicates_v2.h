#pragma once
#include "Stack_linked_list.h"

template <class Item>
class Stack_linked_list_nd_v2 : public STACK_ll<Item>
{

public:

	Stack_linked_list_nd_v2() :STACK_ll<Item>() {};
	void push(Item item) {

		if (this->get_head() == 0) {

			//if item inserted is first element, set the head
			this->set_head(item);
			return;
		}

		bool flag = this->replace_node(item);

		if (flag == false)
		{
			this->set_head(item);
		}
		else {
			std::cout << "Duplicate " << item << " found." << std::endl;
		}
	}
};