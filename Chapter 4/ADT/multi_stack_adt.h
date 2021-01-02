#pragma once
#include "Stack_array.h"

template <class Item>

class Multi_Stack_ADT {

private:
	Item* arr;

	//store total elementsd in stack
	int MAX_SIZE;

	//stack is split in 2, top1 is element 0, top2 is last element
	int top1, top2;

public:
	Multi_Stack_ADT(int M) {
		MAX_SIZE = M;

		top1 = -1;

		top2 = MAX_SIZE - 1;

		arr = new Item [M];
	}

	void push1(Item x) {
		if (top1 < (top2 - 1)) {
			top1++;
			arr[top1] = x;
		}
		else {
			std::cout << "Stack OVerflow!" << std::endl;
			exit(1);
		}
	}

	void push2(Item x) {
		if (top1 < (top2 - 1)) {
			top2--;
			arr[top2] = x;
		}
		else {
			std::cout << "Stack OVerflow!" << std::endl;
				exit(1);
		}
	}

	Item pop2() {
		if (top2 < MAX_SIZE) {
			Item x = arr[top2];
			top2++;
			return x;
		}
		else {
			std::cout << "Stack underflow!" << std::endl;
			exit(1);
		}

	}

	bool empty1() {
		return (top1 == -1);
	}

	bool empty2() {
		return (top2 == (MAX_SIZE - 1));
	}

	Item pop1() {
		if (top1 >= 0) {
			Item x = arr[top1];
			top1--;
			return x;
		}
		else {
			std::cout << "Stack underflow!" << std::endl;
			exit(1);
		}

	}

	void printNodes() {
		for (int i = 0; i <= top1; i++) {
			std::cout << arr[i] << std::endl;
		}
		std::cout << std::endl;
		for (int i = top2; i < MAX_SIZE; i++) {
			std::cout << arr[i] << std::endl;
		}
	}
};