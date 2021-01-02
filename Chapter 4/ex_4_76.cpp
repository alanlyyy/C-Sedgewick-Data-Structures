#include "push_down_stack_array_first_class.h"
#include "Complex_actual.h"

void postfix_eval_complex(char* complex_string, int N){

	//char complex_string[] = "3+2i2+6i*3-4i";

	//int N = sizeof(complex_string)/sizeof(complex_string[0]);

	Push_down_stack<float> real(20);
	Push_down_stack<float> imag(20);

	Complex_actual store_complex_expression(0,0);

	for (int i = 0; i < N; i++) {

		if (complex_string[i] == '+') {

			Complex_actual temp(real.pop(),imag.pop());
			store_complex_expression += temp;

		}

		if (complex_string[i] == '-') {

			Complex_actual temp(real.pop(), imag.pop());
			store_complex_expression -= temp;

		}
		
		if (complex_string[i] == '*') {


			Complex_actual temp(real.pop(),imag.pop());
			store_complex_expression *= temp;

		}

		if ((complex_string[i] >= '0') && (complex_string[i] <= '9')){

			//by default push numbers into real stack
			real.push(0);
			while ((complex_string[i] >= '0') && (complex_string[i] <= '9')) {
				real.push(10 * real.pop() + (complex_string[i++] - '0'));
			}

			//if following index is imaginery pop value out of real stack
			//push value into imag stack.
			if (complex_string[i] == 'i') {
				imag.push(real.pop());
			}
			else {

				i--; //decrement i to not skip sign
			}
		}

		}

	std::cout <<store_complex_expression << std::endl;
}

int main_ex_476() {
	char s1[] = "1+1i+";

	int len_s1 = sizeof(s1)/sizeof(s1[0]);

	char s2[] = "1+1i 1+2i*";
	int len_s2 = sizeof(s2) / sizeof(s2[0]);

	char s3[] = "1+1i 0+1i + 1-2i * 3+4i+";
	int len_s3 = sizeof(s3) / sizeof(s3[0]);

	postfix_eval_complex(s1, len_s1);
	postfix_eval_complex(s2, len_s2);
	postfix_eval_complex(s3, len_s3);
	return 0;
}