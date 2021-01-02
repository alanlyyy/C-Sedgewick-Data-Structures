#include <iostream>
#include "random_queue.h"
#include <time.h>

int main_4_48() {

	//set the seed to randomize time
	srand(time(NULL));

	char string[] = { "EA*sY**QUE**stpao*" }; //AEs--Es--YEs -- Es -- QEs -- QEsu -- EQEsu -- EQE

	int len_str = sizeof(string) / sizeof(string[0]);

	random_queue_array<char> dq(len_str);

	for (int i = 0; i < len_str; i++) {

		//if lower case
		if (string[i] != '*') {
			dq.put_in_back(string[i]);
			std::cout << string[i] << std::endl;
		}

		if (string[i] == '*') {
			std::cout << "*" << " "<<dq.get_random() << std::endl;
		}
	}

	dq.print_elements();
	return 0;
}