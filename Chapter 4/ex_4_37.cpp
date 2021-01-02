#include "queue_array_interface.h"

int main_4_37() {

	char string[] = { "EAS*Y*QUE***ST***IO*N***" };

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

	return 0;
}