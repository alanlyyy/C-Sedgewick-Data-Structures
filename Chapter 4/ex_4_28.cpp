#include "multi_stack_adt.h"

int infix_2_postfix_v2(char* string, int size_string) {
	//store signs in char STACK
	//store nums in int stack

	Multi_Stack_ADT<char> m_stack(100);
	Multi_Stack_ADT<int> m_stack_int(100);

	for (int i = 0; i < size_string; i++) {
		if (string[i] == ')') {

			int num1 = m_stack_int.pop1(); 
			int num2 = m_stack_int.pop1();
			char sign = m_stack.pop1();

			if (sign == '+') {
				m_stack_int.push1(num1 + num2);
			}

			if (sign == '*') {
				m_stack_int.push1(num1 * num2);
			}
		}
		//push nums into int list
		if (string[i] >= '0' && string[i] <= '9') {

			int val = string[i] - '0';
			m_stack_int.push1(val);
		}
		//push signs into char list
		if (string[i] == '*' || string[i] == '+') {

			//std::cout << string[i] <<std::endl;
			m_stack.push1(string[i]);
		}

	}

	return m_stack_int.pop1();
}


int main_4_28() {
	char str1[] = { "((9+8)*(3+4))" };
	char str2[] = { "((9+8)+(7*(4+6)))" };
	char str3[] = { "(5*((9+8)+(7*(4+6))))" };
	char str4[] = { "(5*(((9+8)*(4*6))+7))" };
	int size_string1 = sizeof(str1) / sizeof(str1[0]);
	int size_string2 = sizeof(str2) / sizeof(str2[0]);
	int size_string3 = sizeof(str3) / sizeof(str3[0]);
	int size_string4 = sizeof(str4) / sizeof(str4[0]);

	std::cout << infix_2_postfix_v2(str1, size_string1) << '\n';
	std::cout << infix_2_postfix_v2(str2, size_string2) << '\n'; 
	std::cout << infix_2_postfix_v2(str3, size_string3) << '\n';
	std::cout << infix_2_postfix_v2(str4, size_string4) << '\n';

	return 0;
}