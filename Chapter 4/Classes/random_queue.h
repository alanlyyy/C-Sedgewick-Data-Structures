#pragma once
#include <iostream>
template <class Item>
class random_queue_array
{
private:
	Item* deque_arr;
	int head;
	int tail;
	int N;

public:
	random_queue_array(int);
	int empty();
	int get_size();
	void put_in_back(Item);
	void print_elements();
	Item get_random();
	bool search_item(Item);

};

template<class Item>
random_queue_array<Item>::random_queue_array(int maxN) {
	deque_arr = new Item[maxN];
	N = maxN;
	head = maxN;
	tail = 0;
}

template<class Item>
int random_queue_array<Item>::empty() {
	return (tail == 0);
}

template<class Item>
int random_queue_array<Item>::get_size() {
	return N;
}

template<class Item>
void random_queue_array<Item>::put_in_back(Item item) {
	deque_arr[tail++] = item;
	tail = tail % N;

	//if tail is at end of list.
	if (tail == 0) {
		tail = N - 1;
	}
}

template<class Item>
Item random_queue_array<Item>::get_random() {
	//get the current index, current index is empty, 
	//decrement to prev index with element and extract value

	//set the seed to randomize time
	//srand(time(NULL));

	int index;

	if (tail == 0)
	{
		index = rand() % (N); //grab random number from 0 to tail
		tail = N-1;
	}
	else
		index = rand() % (tail);

	Item val = deque_arr[index];

	//overwrite current index with value at end of queue
	deque_arr[index] = deque_arr[tail];

	//decrement the tail
	tail--;

	return val;

}

template<class Item>
void random_queue_array<Item>::print_elements() {

	std::cout << "-----------------------" << std::endl;
	if (tail > head) {
		for (int i = head; i < tail; i++) {
			std::cout << deque_arr[i] << std::endl;
		}
	}
	else {

		int index = head%N;

		while (index != (tail-1)) {

			if (index == N) {
				index = 0;
			}

			std::cout << deque_arr[++index] << std::endl;
		}

	}
	std::cout << "-----------------------" << std::endl;
}

template<class Item>
bool random_queue_array<Item>::search_item(Item item)
{
	int start = head;

	if (start == N)
		start = 0;

	for (int i = start; i <= tail; i++) {
		if (deque_arr[i] == item) {
			return 1;
		}
	}

	return 0;
}