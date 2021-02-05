#include "C:\Users\Alan\source\repos\Cpp_sedgewick\ch4_ADT\Stack_linked_list.h"
#include <iostream>

STACK_ll<char> operators;
STACK_ll<int> nums;

char expr[] = { "(5 * ( ( ( 9 + 8 ) * ( 4 * 6 ) ) + 7))" };
//char expr[] = { "( ( 9 + 8 ) * ( 4 * 6 ) )" };
int len_string2 = sizeof(expr)/sizeof(expr[0]);

int infix_eval(int i = 0, int str_len=0) {
	
	int x = 0;

	if (i >= (str_len-1)) {
		return nums.pop();
	}

	if (expr[i] == ' '){

		while (expr[i] == ' ') {
			i++;
		}

		return infix_eval(i, str_len);
	}

	if (expr[i] == '(') {

		while (expr[i] == '(') {
			i++;
		}

		return infix_eval(i, str_len);
	}

	if (expr[i] == ')') {
		
		char op = operators.pop();
		
		if (op == '+') {
			int val1 = nums.pop();
			int val2 = nums.pop();
			nums.push(val1 + val2);
			std::cout << i << " " << val1 << " " << val2 << std::endl;

		}

		if (op == '*') {

			int val1 = nums.pop();
			int val2 = nums.pop();
			nums.push(val1 * val2);
			std::cout << i << " " << val1 << " "<< val2 <<std::endl;

		}

		return infix_eval(i + 1, str_len);
	}

	if (expr[i] == '+') {
		operators.push('+');
		return infix_eval(i+1,str_len);
	}

	if (expr[i] == '*') {
		operators.push('*');
		return infix_eval(i+1,str_len);
	}

	if ((expr[i] >= '0') && (expr[i] <= '9')) {

		nums.push(0);

		while ((expr[i] >= '0') && (expr[i] <= '9')) {
			x = 10 * nums.pop() + (expr[i++] - '0');
			nums.push(x);
		}

		return infix_eval(i, str_len);
	}

}


int main_5_10() {
	std::cout << infix_eval(0,len_string2) << std::endl;
	return 0;
}