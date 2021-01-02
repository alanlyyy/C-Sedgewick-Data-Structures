#include <iostream>
#include "queue_array_interface.h"

void test_queue_array() {
	char string[] = { "FIRS*T*IN*" };

	int string_size = sizeof(string) / sizeof(string[0]);

	Queue_array<char> q(string_size);

	for (int i = 0; i < string_size; i++) {
		
		if (string[i] == '*' && (!q.empty()))
		{
			std::cout << q.get() << std::endl;
		}
		else {
			q.put(string[i]);
		}
	}

	q.print_elements();

}

int main_4_36() {
	test_queue_array();
	return 0;
}