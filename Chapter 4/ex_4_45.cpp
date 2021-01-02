#include "deque_linked_list.h"
#include <iostream>

int main_4_45() {
	char string[] = { "EAs+Y+QUE**+st+" }; //AEs--Es--YEs -- Es -- QEs -- QEsu -- EQEsu -- EQE

	int len_str = sizeof(string) / sizeof(string[0]);

	Deque_linked_list<char> dq(len_str);

	for (int i = 0; i < len_str; i++) {

		//if uppercase
		if (((string[i] - 64) >= 1) && ((string[i] - 64) <= 26)) {
			dq.put_in_front(string[i]);
			std::cout << "upper case " << string[i] << std::endl;
		}
		//if lower case
		if (((string[i] - 96) >= 1) && ((string[i] - 96) <= 26)) {
			dq.put_in_back(string[i]);
			std::cout << "lower case: " << string[i] << std::endl;
		}

		if (string[i] == '*') {
			std::cout << dq.get_back() << std::endl;
			std::cout << "*" << std::endl;
		}

		if (string[i] == '+') {
			std::cout << dq.get_front() << std::endl;
			std::cout << "+" << std::endl;
		}
	}

	//dq.print_elements();
	return 0;
}