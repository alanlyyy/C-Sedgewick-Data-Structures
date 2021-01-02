#include "Stack_array.h"
#include "multi_stack_adt.h"

int main_4_27() {

	//declare a 2 stacks, each containing arrays of 30 elements.
	Multi_Stack_ADT<char> my_multi(100);

	char string2[] = { "LA*OU*T*\t" };
	char string3[] = { "LA*STI*N*FIR*ST**OU*T\t" };
	char string4[] = { "\t" };

	int i = 0;

	while (string2[i] != '\t') {

		if (string2[i] == '*') {
			//in the array pop the current element
			std::cout << my_multi.pop1() << " " << std::endl;
		}
		else {
			my_multi.push1(string2[i]);
		}

		i++;
	}

	i = 0;
	std::cout << std::endl;

	while (string3[i] != '\t') {

		if (string3[i] == '*') {
			std::cout << my_multi.pop2() << " " << std::endl;
		}
		else {
			my_multi.push2(string3[i]);
		}

		i++;
	}

	std::cout << std::endl;

	my_multi.printNodes();

	return 0;

}