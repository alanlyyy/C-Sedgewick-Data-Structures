#include "Stack_linked_list_array.h"
#include "Stack_array.h"
#include <iostream>

int main_ex_4_25() {
	STACK_ll_arr<char> s1(8);
	STACK_arr<char> s2(8);

	char string[] = { "LA*STI*N*FIR*ST**OU*T*******\t" };
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

	std::cout << "---------------" << std::endl;

	i = 0;
	while (string2[i] != '\t') {

		if (string2[i] == '*') {
			std::cout << s2.pop() << " " << std::endl;
		}
		else {
			s2.push(string2[i]);
		}

		i++;
	}
	std::cout << "-------------------"<<std::endl;
	s1.print_elements();
	s2.print_elements();
	return 0;
}