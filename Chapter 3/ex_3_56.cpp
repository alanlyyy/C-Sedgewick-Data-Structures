#include <iostream>
#include "list.h"

bool is_str_palindrome(char* myword) {
	//checks if a string read forwards and backwards is the same.
	//assume string contains all letters that are lower case.

	char* letter_traverse = myword;
	int length = 0;
	//extract number of letters from string, exclude white space
	while (*letter_traverse != '\0') {

		if ((*letter_traverse) != ' ') {
			length += 1;
		}

		letter_traverse += 1;
	}

	char* word_strip_space = new char[length]();
	int index = 0;

	//reset letter traverse to first letter
	letter_traverse = myword;

	//traverse list and store each letter into array
	while (*letter_traverse != '\0') {

		if ((*letter_traverse) != ' ') {
			word_strip_space[index] = *letter_traverse;
			index++;
		}

		//move onto next letter
		letter_traverse +=1;
	}

	for (int i = 0; i < length; i++) {
		if (word_strip_space[i] != word_strip_space[length - i - 1]) {
			return false;
		}

	}

	return true;
}

int main_3_56() {

	//char mystring[] = "alphabet\0";
	char mystring2[] = "imi\0";
	char mystring3[] = "elep ha nt e\0";
	char mystring4[] = "if i had a hifi\0";

	std::cout << is_str_palindrome(mystring2);
	std::cout << std::endl;
	std::cout <<is_str_palindrome(mystring3);
	std::cout << std::endl;
	std::cout << is_str_palindrome(mystring4);

	return 0;
}