#include "deque_linked_list.h"
#include <iostream>

int main_4_47() {
	char string[] = { "EAs+Y+QUE**+st+" }; //AEs--Es--YEs -- Es -- QEs -- QEsu -- EQEsu -- EQE

	int len_str = sizeof(string) / sizeof(string[0]);

	Deque_linked_list<char> dq(len_str);

	for (int i = 0; i < len_str; i++) {

		//if uppercase
		if (((string[i] - 64) >= 1) && ((string[i] - 64) <= 26)) {
			dq.put_in_front(string[i]);
			//std::cout << "upper case " << string[i] << std::endl;
		}
		//if lower case
		if (((string[i] - 96) >= 1) && ((string[i] - 96) <= 26)) {
			dq.put_in_back(string[i]);
			//std::cout << "lower case: " << string[i] << std::endl;
		}

		if (string[i] == '*') {
			char current_char = dq.get_back();
			//std::cout << current_char << std::endl;
			std::cout << "* " << dq.dump(current_char) << std::endl;
		}
		else if (string[i] == '+') {
			char current_char = dq.get_front();
			//std::cout << current_char<< std::endl;
			std::cout << "+ " << dq.dump(current_char) << std::endl;
		}
		else {
			std::cout << string[i] << " " << dq.dump(0) << std::endl;;
		}
	}

	//dq.print_elements();
	return 0;
}