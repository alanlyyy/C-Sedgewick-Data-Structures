#include "STACK_linked_list_no_duplicates.h"
#include "STACK_linked_list_no_duplicates_v2.h"

void test_1() {
	Stack_linked_list_nd<char> no_duplicate_stack;

	char mystring[] = { "abcc" };

	no_duplicate_stack.push('a');
	no_duplicate_stack.push('b');
	no_duplicate_stack.push('c');
	no_duplicate_stack.push('c');
	no_duplicate_stack.push('d');
	no_duplicate_stack.pop();
	no_duplicate_stack.push('e');
	no_duplicate_stack.push('e');
	no_duplicate_stack.push('f');
	no_duplicate_stack.push('g');
	no_duplicate_stack.pop();
	no_duplicate_stack.push('d');
	no_duplicate_stack.print_elements();
}

void test_2() {
	Stack_linked_list_nd_v2<char> no_duplicate_stack;

	char mystring[] = { "abcc" };

	no_duplicate_stack.push('a');
	no_duplicate_stack.push('b');
	no_duplicate_stack.push('c');
	no_duplicate_stack.push('c');
	no_duplicate_stack.push('d');
	no_duplicate_stack.pop();
	no_duplicate_stack.push('e');
	no_duplicate_stack.push('e');
	no_duplicate_stack.push('f');
	no_duplicate_stack.push('g');
	no_duplicate_stack.pop();
	no_duplicate_stack.push('d');
	no_duplicate_stack.print_elements();
}

int main_4_56() {
	test_1();
	std::cout << std::endl;
	test_2();
	return 0;
}