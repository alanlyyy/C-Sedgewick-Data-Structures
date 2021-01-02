#pragma once
#include<iostream>
template <class Item>
class Queue_array
{
private:
	Item* q;
	int N, head, tail;

	void deleteList() {
			delete [] q;
			std::cout << "destructor" << std::endl;
	}
public:
	Queue_array(int maxN);
	Queue_array();
	Queue_array(const Queue_array& other); //copy constructor
	~Queue_array(); //destructor
	Queue_array& operator=(const Queue_array& rhs); //copy operator
	int empty();
	void put(Item item);
	Item get();
	void print_elements();
	int error(int);
	bool search_element(Item);
	int get_size();
	void set_array(int);
};

template <class Item>
Queue_array<Item>::Queue_array(int maxN) {
	q = new Item[maxN+1];
	N = maxN+1;
	head = N;
	tail = 0;
}
template <class Item>
Queue_array<Item>::Queue_array() {
	q = 0;
	N = 0;
	head = N;
	tail = 0;
}

template <class Item>
Queue_array<Item>::Queue_array(const Queue_array& rhs) {
	q = new Item[rhs.N];

	N = rhs.N;
	head = rhs.head;
	tail = rhs.tail;

	//copy all elements from rhs to this queue array
	for (int i = 0; i < rhs.tail; i++) {
		q[i] = rhs.q[i];
	}
}
template <class Item>
Queue_array<Item>::~Queue_array() {
	std::cout << "destructor invoked" << std::endl;
	deleteList();
}
template <class Item>
Queue_array<Item>& Queue_array<Item>::operator=(const Queue_array& rhs) {

	//if both are the same queues return the queue
	if (this == &rhs) {
		return *this;
	}

	//clear all elements in current queue
	deleteList();
	
	this->set_array(rhs.get_size());

	// put rhs elements into current queue 
	for (int i = rhs.head; i < rhs.tail; i++) {
		q[i] = rhs.q[i];
	}

	return *this;
}

template<class Item>
void Queue_array<Item>::set_array(int val) {
	N = val+1;
	q = new Item[val+1];
	head = N;
	tail = 0;
}
template <class Item>
int Queue_array<Item>::empty() {
	return (head % N == tail);
}

template<class Item>
void Queue_array<Item>::put(Item item) {

	if (!error(2))
	{
	q[tail++] = item;
	tail = tail % N;
	}
}

template<class Item>
Item Queue_array<Item>::get() {

	if (!error(1))
	{
	head = head % N;
	return q[head++];
	}
}

template<class Item>
void Queue_array<Item>::print_elements() {

	std::cout <<"-----------------------" <<std::endl;
	if (tail > head) {
		//std::cout << "Head < Tail ";
		for (int i = head; i < tail; i++) {
			std::cout  << q[i] << " ";
		}
		std::cout << std::endl;
	}
	else {
		//std::cout << "Tail < Head ";
		int i;
		
		//if tail is less than head, that means array indexes has wrapped around.

		//break print loops into two halves, from head to N and 0 to tails
		for (i = head; i < N; i++) {
			std::cout  << q[i] << " ";
		}
		
		for (i = 0; i < tail; i++) {
			std::cout << q[i] << " ";
		}

		std::cout << std::endl;
	}
	std::cout << "-----------------------" <<std::endl;
}

template<class Item>
int Queue_array<Item>::error(int mode) {
	
	//if all elements are popped and head = tail
	if (empty() && (mode==1)) {

		//if first element is detected return 0
		if (head == N) {
			return 0;
		}
		else {
			std::cout << "Error, queue is empty." << std::endl;
			return 1;
		}
	}
	//if tail wraps back to head (tail leads head, queue is full)
	else if ((((tail%N) +1) == head) && (mode ==2)) {
		//if tail is at last node, don't insert node
		std::cout << "Error, queue is full." << std::endl;
		return 1;
	}
	else {
		return 0;
	}
}
template<class Item>
bool Queue_array<Item>::search_element(Item x) {

	int start = head;

	if (start == N)
		start = 0;

	for (int i = start; i <= tail; i++) {
		if (q[i] == x) {
			return 1;
		}
	}

	return 0;
}
template<class Item>
int Queue_array<Item>::get_size() {
	return N;
}