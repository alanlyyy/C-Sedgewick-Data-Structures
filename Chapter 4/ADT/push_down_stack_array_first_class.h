#pragma once
#include <iostream>

template <class Item>
class Push_down_stack {

private:
	Item* s;
	int N;	//position of top of the stack
	int total_array_elements = 0;
	int current_index = 0;

	void clear_stack() {
		//clear content/ deallocate resources from s
		delete[] s;

		std::cout << "Destructor invoked!" << std::endl;
	}
public:
	Push_down_stack(int maxN); 
	Push_down_stack(const Push_down_stack&); //copy constructor
	Push_down_stack& operator=(const Push_down_stack&); //copy operator
	~Push_down_stack();	//destructor
	int empty();
	void push(Item);
	Item pop();
	void print_elements();
};

template<class Item>
Push_down_stack<Item>::Push_down_stack(int maxN) {
	s = new Item[maxN];
	N = 0;
	total_array_elements = maxN;
}

template<class Item>
Push_down_stack<Item>::Push_down_stack(const Push_down_stack& other) {

	//deallocate existing resources
	clear_stack();

	//allocate new resources
	s = new Item[other.N];

	N = other.N;

	total_array_elements = other.total_array_elements;

	//copy elements from other stack to current stack
	for (int i = 0; i < N; i++) {
		s[i] = other.s[i];
	}
}

template<class Item>
Push_down_stack<Item>& Push_down_stack<Item>::operator =(const Push_down_stack& other) {
	//copy operator
	
	//if current object is equal to other object return current objet 
	if (this == &other) {
		return *this;
	}

	//deallocate existing resources
	clear_stack();

	s = new Item[other.N];

	N = other.N;

	total_array_elements = other.total_array_elements;

	//copy elements from other stack to current stack
	for (int i = 0; i < N; i++) {
		s[i] = other.s[i];
	}
}
template <class Item>
Push_down_stack<Item>::~Push_down_stack() {
	//deallocate resources from stack array
	clear_stack();
}

template <class Item>
int Push_down_stack<Item>::empty() {
	return N == 0;
}

template <class Item>
void Push_down_stack<Item>::push(Item item)
{
	if ((N + 1) != total_array_elements) {
		s[N++] = item;
	}
}

template <class Item>
Item Push_down_stack<Item>::pop() {

	if (!empty()) {
		return s[--N];
	}
	else {
		return 0;
	}
}

template < class Item>
void Push_down_stack<Item>:: print_elements() {
	for (int i = 0; i < N; i++) {
		std::cout << s[i] << " ";
	}
	std::cout << std::endl;
}