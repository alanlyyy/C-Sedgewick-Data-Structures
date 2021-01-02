#pragma once
#include "Stack_linked_list.h"

template <class Item>
class Stack_linked_list_nd : public STACK_ll<Item>
{
private:

public:

	Stack_linked_list_nd() :STACK_ll<Item>() {};
	void push(Item item) {

		bool flag = this->search_item(item);

		if (flag == false)
		{
			this->set_head(item);
		}
		else {
			std::cout << "Duplicate " << item << " found." << std::endl;
		}
	}
};