#include "STACK_doubly_linked_list.h"
//#include <iostream>

int main_4_26() {

	STACK_ll_doubly<char> s1;

	char string2[] = { "LA*STI*N*FIR*ST**OU*T\t" };
	int i = 0;

	while (string2[i] != '\t') {

		if (string2[i] == '*') {
			std::cout << s1.pop() << " " << std::endl;
		}
		else {
			s1.push(string2[i]);
		}

		i++;
	}

	s1.printNodes();
	return 0;
}