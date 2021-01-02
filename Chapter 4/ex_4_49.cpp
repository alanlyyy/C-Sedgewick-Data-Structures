#include <iostream>
#include "random_queue_linked_list.h"


int main_4_49() {

	char string[] = { "EA*sY*QUE*stpao*" }; //AEs--Es--YEs -- Es -- QEs -- QEsu -- EQEsu -- EQE

	int len_str = sizeof(string) / sizeof(string[0]);

	random_queue_ll<char> dq(len_str);

	for (int i = 0; i < len_str; i++) {

		//if lower case
		if (string[i] != '*') {
			dq.put(string[i]);
			std::cout << string[i] << std::endl;
		}

		if (string[i] == '*') {
			std::cout << "*" << " " << dq.get_random() << std::endl;
		}
	}

	dq.print_elements();
	return 0;
}