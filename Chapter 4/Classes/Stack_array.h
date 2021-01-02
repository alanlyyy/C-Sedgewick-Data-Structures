#pragma once
#include <iostream>
template <class Item>

class STACK_arr
{
private:
	Item* s;
	int N;	//position of top of the stack
	int total_array_elements = 0;
	int current_index = 0;
public:

	STACK_arr(int maxN) {
		s = new Item[maxN];
		N = 0;
		total_array_elements = maxN;
	}

	int empty() {
		return N == 0;
	}

	int get_size() {
		return N;
	}

	int get_current_element() {
		//extract current element bypassing private scope 
		return s[current_index];
	}

	int update_current_index() {
		current_index++;

		if (N != 0)
			current_index = current_index % N;
		else
			current_index = 0;

		return current_index;
	}

	int get_total_array_elements() {
		return total_array_elements;
	}

	void add_to_stack(Item item) {
		s[N++] = item;
	}

	void push(Item item)
	{
		if ((N+1) != total_array_elements){
			s[N++] = item;
		}
	}

	Item pop() {

		if (!empty()) {
			return s[--N];
		}
	}

	void print_elements() {
		for (int i = 0; i < N; i++) {
			std::cout << s[i] << " ";
		}
		std::cout << std::endl;
	}
};
