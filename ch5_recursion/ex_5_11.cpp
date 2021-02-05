#pragma warning(disable : 4996)
#include <iostream>
#include "C:\Users\Alan\source\repos\Cpp_sedgewick\ch4_ADT\Stack_linked_list.h"
#include <cstring>

//global variables
STACK_ll<char> signs;
STACK_ll<int> vals;
//char expression[] = "5 5 * 4 + 3 17 *";
static char expression[] = { "( ( ( 900 + 18 ) * ( 4 * 65 ) ) * 5 )" };
int len_string_5_11 = sizeof(expression) / sizeof(expression[0]);
static int j = 0;
char* output = new char[len_string_5_11];

int calc_num_decimals(int x) {
	int count = 1;

	while ((x / 10) != 0) {
		x /= 10;
		count++;
	}

	return count;
}
int infix_2_postfix(int expr_index,int N) {
	
	int x = 0;

	if (expr_index == (N - 1)) {
		return 0;
	}

	if (expression[expr_index] == ')') {

		//convert number to char
		int var1 = vals.pop();
		int num_dec_1 = calc_num_decimals(var1);
		char* num_str_1 = new char[num_dec_1];
		snprintf(num_str_1, var1, "%d", var1);

		//convert number to char accounts for numbers with more than 1 decimal place
		int var2 = vals.pop();
		int num_dec_2 = calc_num_decimals(var2);
		char* num_str_2 = new char[num_dec_1];
		snprintf(num_str_2, var2, "%d", var2);

		char op = signs.pop();

		if (var1 != 0 && var2 != 0)
		{
			for (int k = 0; k < num_dec_1; k++) {
				output[++j] = num_str_1[k];
			}

			output[++j] = ' ';

			for (int k = 0; k < num_dec_2; k++) {
				output[++j] = num_str_2[k];
			}

			output[++j] = ' ';
			output[++j] = op;
			output[++j] = ' ';
		}

		else if (var1 == 0 && var2 != 0) {

			for (int k = 0; k < num_dec_2; k++) {
				output[++j] = num_str_2[k];
			}
			output[++j] = ' ';
			output[++j] = op;
			output[++j] = ' ';
		}
		else if (var2 == 0 && var1 != 0) {
			for (int k = 0; k < num_dec_1; k++) {
				output[++j] = num_str_1[k];
			}
			output[++j] = ' ';
			output[++j] = op;
			output[++j] = ' ';
		}
		else {
			if (op != 0) {

				output[++j] = ' ';
				output[++j] = op;
				output[++j] = ' ';
			}
		}

		//std::cout << output << " " << j << std::endl;

		return infix_2_postfix(expr_index+1,N);
	}

	if (expression[expr_index] == '(' || expression[expr_index] == ' ') {
		return infix_2_postfix(expr_index+1, N);
	}

	if (expression[expr_index] == '*') {
		signs.push('*');
		return infix_2_postfix(expr_index+1, N);
	}

	if (expression[expr_index] == '+') {
		signs.push('+');
		return infix_2_postfix(expr_index+1, N);
	}

	if ((expression[expr_index] >= '0') && (expression[expr_index] <= '9'))
	{
		vals.push(0);
		while ((expression[expr_index] >= '0') && (expression[expr_index] <= '9')) {
			x = 10 * vals.pop() + (expression[expr_index++] - '0');
			vals.push(x);
		}

		return infix_2_postfix(expr_index, N);
	}
}


void test() {
	//convert number to char
	int var1 = 200;
	int num_dec_1 = calc_num_decimals(var1);
	char* num_str_1 = new char[num_dec_1];
	snprintf(num_str_1, var1, "%d", var1);

	std::cout << num_str_1 << std::endl;
}

int main_5_11() {
	
	//test();
	infix_2_postfix(0,len_string_5_11);
	std::cout << output << std::endl;
	return 0;
}