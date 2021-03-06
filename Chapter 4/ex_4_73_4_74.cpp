#include "push_down_stack_array_first_class.h"
#include <iostream>
int main_4_73_74() {

	Push_down_stack<int> s1(50);

	s1.push(1);
	s1.push(2);
	s1.push(3);
	s1.push(4);
	s1.push(5);
	s1.print_elements();
	std::cout << s1.pop() << std::endl;
	s1.print_elements();

	//test copy operator
	Push_down_stack<int> s2 = s1;

	s2.print_elements();
	s2.pop();
	std::cout << "s2" << " ";
	s2.print_elements();
	std::cout << "s1" << " ";
	s1.print_elements();

	//test copy constructor
	Push_down_stack<int> s3(s2);

	std::cout << "s3" << " ";
	s3.print_elements();


	return 0;
}