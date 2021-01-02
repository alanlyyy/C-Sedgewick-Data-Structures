#include "queue_array_interface.h"

int main_4_38() {

	char string[] = { "EAS*Y*QUE***ST***IO*N*********" };
	char string2[] = { "EASYadfsfdsfsd" };

	int string_size = sizeof(string) / sizeof(string[0]);
	int string_size2 = sizeof(string2) / sizeof(string2[0]);

	Queue_array<char> q(string_size);
	Queue_array<char> q2(string_size2 -5);

	for (int i = 0; i < string_size; i++) {

		if (string[i] == '*')
		{
			std::cout << q.get() << std::endl;
		}
		else {
			q.put(string[i]);
		}
	}

	std::cout << "---------------" << std::endl;

	for (int i = 0; i < string_size2; i++) {

		if (string2[i] == '*' )
		{
			std::cout << q2.get() << std::endl;
		}
		else {
			q2.put(string2[i]);
			std::cout << string2[i] << std::endl;
		}
	}


	//q.print_elements();
	//q2.print_elements();

	return 0;
}