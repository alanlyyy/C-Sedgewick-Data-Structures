#include <iostream>

//char arr[] = { "4 5 + 7 2 * + 3 *" };
char arr[] = { "5 9 8 + 4 6 * * 7 + *" };
int index = 0;

int len_string =sizeof(arr) / sizeof(arr[0]);

int postfix_eval(int x1, int x2) {
	//1. if next operator is a sign, compute and return result with x1 and x2
	//2. otherwise next value in expression is not a sign, but a number.
	//evaluate the expression of the top 2 numbers and overwrite x2
	//once an operator is reached, evaluate the expression for old x1 and new x2.

	do {
		int x = 0;
		while (arr[index] == ' ') {
			index++;
		}

		if (arr[index] == '+') {
			index++;
			return x2 + x1;
		}
		if (arr[index] == '*') {
			index++;
			return x1 * x2;
		}

		while ((arr[index] >= '0') && (arr[index] <= '9')) {
			x = 10 * x + (arr[index++] - '0');
		}

		x2 = postfix_eval(x2, x); //where x is value at top of the stack
	} while (true);
}


int postfix_eval(int x1) {
	//taking the current value
	//get the next value found in the expression
	//evaluate the expression in postfix_eval(int x,int x2)

	int x = 0;
	while (arr[index] == ' ') {
		index++;
	}

	if (arr[index] == '+') {
		index++;
	}
	if (arr[index] == '*') {
		index++;
	}

	while ((arr[index] >= '0') && (arr[index] <= '9')) {
		x = 10 * x + (arr[index++] - '0');
	}

	return postfix_eval(x1,x);

}

int postfix_eval() {
	//driver program that initiates the traversing of the postfix expression.
	//returns the first number and passes that value into postfix_eval(val)

	int x = 0;
	while (arr[index] == ' ') {
		index++;
	}

	if (arr[index] == '+') {
		index++;
	}
	if (arr[index] == '*') {
		index++;
	}

	while ((arr[index] >= '0') && (arr[index] <= '9')) {
		x = 10 * x + (arr[index++] - '0');
	}

	return postfix_eval(x);

}

void postfix_eval_client() {
	//driver program that evaluates the expression traversing through the string.

	int x2 = postfix_eval();

	while (index < (len_string-1)) {
		x2 = postfix_eval(x2);
	}
	std::cout << x2 << std::endl;
}
int main_5_9() {
	postfix_eval_client();
	return 0;
}