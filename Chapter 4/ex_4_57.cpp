#include "stack_doubly_ex_4_57.h"

int main_4_57() {
	int N = 30;

	//create stack with N elements
	STACK_doubly_derived stack_int(N);

	stack_int.push(3);
	stack_int.push(3);
	stack_int.printNodes();
	stack_int.printNodes_through_array();
	stack_int.push(9);
	stack_int.push(4);
	stack_int.push(16);
	stack_int.push(5);
	stack_int.printNodes();
	stack_int.printNodes_through_array();
	stack_int.pop();
	stack_int.printNodes();
	stack_int.printNodes_through_array();

	return 0;
}