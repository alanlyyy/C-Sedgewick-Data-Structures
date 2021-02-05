#pragma warning(disable : 4996)
#include <iostream>
#include "C:\Users\Alan\source\repos\Cpp_sedgewick\ch4_ADT\Stack_linked_list.h"
#include <cstring>

//global variables
STACK_ll<int> num_stack;

//test expressions
//char expression2[] = "5 5 * 4 + 3 17 *";
//static char expression2[] = { "50 8 * 6 7 + *" };
//static char expression2[] = { "50 8 * 6 17 + * 52 +" };
static char expression2[] = { "52 50 8 * 6 17 + * +" };

int len_string_5_12 = sizeof(expression2) / sizeof(expression2[0]);

//current output string position
static int pos = 0;

//create output string expression
char* output_2 = new char[len_string_5_12*2];

//count number of operators detected
int num_ops = 0;

int calc_num_decimals_2(int x) {
	int count = 1;

	while ((x / 10) != 0) {
		x /= 10;
		count++;
	}

	return count;
}

int postfix_2_infix(int expr_index, int N) {

	int x = 0;

	if (expr_index == (N - 1)) {
		return 0;
	}

	if (expression2[expr_index] == '*' || expression2[expr_index] == '+') {

		//convert number 1 to char
		int var1 = num_stack.pop();
		int num_dec_1 = calc_num_decimals_2(var1);
		char* num_str_1 = new char[num_dec_1];
		snprintf(num_str_1, var1, "%d", var1);

		//convert number 2 to char accounts for numbers with more than 1 decimal place
		int var2 = num_stack.pop();
		int num_dec_2 = calc_num_decimals_2(var2);
		char* num_str_2 = new char[num_dec_1];
		snprintf(num_str_2, var2, "%d", var2);

		char op = expression2[expr_index];

		//if we have 2 numbers and a operator case store ( num1 + num2 ) 
		if (var1 != 0 && var2 != 0)
		{
			output_2[++pos] = '(';
			for (int k = 0; k < num_dec_1; k++) {
				output_2[++pos] = num_str_1[k];
			}
			//output_2[++pos] = ' ';
			output_2[++pos] = op;
			//output_2[++pos] = ' ';
			for (int k = 0; k < num_dec_2; k++) {
				output_2[++pos] = num_str_2[k];
			}
			//output_2[++pos] = ' ';
			output_2[++pos] = ')';
			//output_2[++pos] = ' ';
			num_ops += 1;

		}

		//if we have 1 num and 1 operator store ( (.....) operator num2)
		else if (var1 == 0 && var2 != 0) {

			output_2[++pos] = op;

			for (int k = 0; k < num_dec_2; k++) {
				output_2[++pos] = num_str_2[k];
			}

			output_2[++pos] = ')';

			//advance all variables by one.
			for (int k = pos; k> 0; k--) {
				output_2[k+1] = output_2[k];
			}

			++pos;

			num_ops += 1;

		}
		//if we have 1 num and 1 operator store ( (.....) operator num1)
		else if (var2 == 0 && var1 != 0) {
			output_2[++pos] = op;

			for (int k = 0; k < num_dec_1; k++) {
				output_2[++pos] = num_str_1[k];
			}

			output_2[++pos] = ')';

			//advance all variables by one.
			for (int k = pos; k > 0; k--) {
				output_2[k+1] = output_2[k];
			}

			++pos;

			num_ops += 1;
		}

		//if we have no numbers and an operator store ( (.....) operator (......) )
		else {
			if (op != 0) {
				
				//counts the number of braces to add operation sign in middle of expression
				int count_brace = 0;

				//save current position of center brace
				int curr_position = 0;
				
				for (int k = pos; k > 0; k--) {

					if (output_2[k] == ')'){

						count_brace += 1;
						//if number operations is equal to number brace, position is found.
						if (count_brace == num_ops) {
							curr_position = k;
							break;
						}
					}
				}

				//advance all positions before x ')' current position by one
				for (int k = pos; k > curr_position; k--) {
					output_2[k+1] = output_2[k];
				}

				//store operator in center position between 2 subexpressions
				output_2[curr_position + 1] = op;

				//update pos last position
				++pos;
				output_2[++pos] = ')';

				//advance all variables by one.
				for (int k = pos; k > 0; k--) {
					output_2[k+1] = output_2[k];
				}

				++pos;

				num_ops += 1;

			}
		}

		std::cout << output_2 << " " << pos << std::endl;

		return postfix_2_infix(expr_index + 1, N);
	}

	if (expression2[expr_index] == ' ') {
		return postfix_2_infix(expr_index + 1, N);
	}

	if ((expression2[expr_index] >= '0') && (expression2[expr_index] <= '9'))
	{
		num_stack.push(0);
		while ((expression2[expr_index] >= '0') && (expression2[expr_index] <= '9')) {
			x = 10 * num_stack.pop() + (expression2[expr_index++] - '0');
			num_stack.push(x);
		}

		return postfix_2_infix(expr_index, N);
	}
}

int main_5_12() {

	postfix_2_infix(0, len_string_5_12);
	std::cout << output_2 << std::endl;
	return 0;
}