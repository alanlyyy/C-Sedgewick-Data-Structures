#include "Stack_array.h"

int main_ex_4_21() {
	STACK_arr<char> s1(5);

	char string[] = { "LA*STI*N*FIR*ST**OU*T*******\t" };
	int i = 0;

	while (string[i] != '\t') {
		
		if (string[i] == '*') {
			std:: cout << s1.pop()  << " " <<  std::endl;
		}
		else {
			s1.push(string[i]);
		}

		i++;
	}

	//s1.print_elements();

	return 0;
}