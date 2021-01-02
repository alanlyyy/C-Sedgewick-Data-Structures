#include "Stack_array_no_duplicates.h"

int main_4_54() {
	STACK_arr_no_duplicates<char> no_duplicate_stack(30);

	char mystring[] = { "abcc" };

	no_duplicate_stack.push('a');
	no_duplicate_stack.push('b');
	no_duplicate_stack.push('c');
	no_duplicate_stack.push('c');
	no_duplicate_stack.push('d');
	no_duplicate_stack.pop();
	no_duplicate_stack.print_elements();

	return 0;
}