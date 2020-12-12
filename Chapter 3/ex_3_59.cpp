#include <iostream>

char* replace_duplicate_blank_space(char* sub_string) {
	//loops through string removes all duplicate blank spaces.
	//returns a copy of sub_string with a single blank space

	char* point_string = sub_string;
	int index = 0;
	int length = 0;

	//find the length of the string
	while (point_string[index] != ' ') {
		length++;
		index++;
	}

	//allocate space for the string
	char* output_string = new char[length+2];

	//reset index
	index = 0;

	//copy elements from sub string into output string
	while (point_string[index] != ' ') {
		output_string[index] = point_string[index];
		index++;
	}

	//append a blank sace and char terminating escape character to end of string.
	output_string[length + 1] = ' ';
	output_string[length + 2] = '\0';

	//return a pointer to copy of sub string 
	return output_string;
}

int main_3_59() {

	char string1 [] = { 'a','l','p',' ', ' ', '\0' };
	char string2[] = { 'a','l','p', 'o',' ', ' ', ' ', '\0' };

	std::cout<< replace_duplicate_blank_space(string1) << "space" << std::endl;
	std::cout << replace_duplicate_blank_space(string2)<< "space" << std::endl;
	return 0;
}