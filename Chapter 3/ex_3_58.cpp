#include <iostream>
#include "list.h"

int compare_string_with_substr(char* arg_str, char* list_sub_str) {
	//take a argument string and sub string and print substring if sub_string is found within the argument string.
	//return length of sub_string to iterate the char pointer, list_sub_str, by 'length' iterations.

	//pointer to first letter of sub string
	char* l1 = list_sub_str;

	//pointer to first letter of argument string
	char* l2 = arg_str;

	//flag to keep track if sub string is found in argument
	bool found = false;

	int length = 0;
	int index = 1;
	int str_pos = 0;
	
	//get the leangth of the string
	while (*l1 != ' ') {
		length++;
		l1++;
	}

	//reset l1 pointer to first letter
	l1 = list_sub_str;

	//loop until sub string is an empty space
	while (*l1 != ' ') {

		//loop until end of arg_str and l1 != space
		while (*l2 != '\0' && *l1 != ' ') {

			//if l1 and l2 are equal
			if (*l1 == *l2) {
				found = true;

				str_pos += 1;

				//if string position = end of string break out of loop
				if (str_pos == length) {
					break;
				}

				//update to next letter of l1 
				l1++;
			}
			else {
				found = false;

				//no letters match, reset str_pos 
				str_pos = 0;

				//if l1 and l2 are not equal reset l1 to first character
				l1 = list_sub_str;
			}

			//update l2
			l2++;
		}

		//keep track of number of iterations/ current letter
		index += 1;

		//reset l1 and l2 char pointers
		l1 = list_sub_str + index;
		l2 = arg_str;

		//if string position = end of string break out of loop
		if (str_pos == length) {
			break;
		}

	}

	//reset pointer to first element of string
	l1 = list_sub_str;

	//store output string for printing
	char* mystring = new char[length+1]();

	//if sub string is found within argument
	if (found == true) {

		int i = 0;

		while (i < length) {

			//append letter to char array to create string
			mystring[i] = *l1;

			//update pointer to next letter
			l1++;

			//update index to store next letter
			i++;

		}

		mystring[length + 1] = '\0';
		std::cout << mystring << std::endl;
	}
	else {
		std::cout << "NULL" << std::endl;
	}
	
	return length;
}

void print_string_in_sub_str(char* arg_str, char* sub_str) {
	//function is used to call the compare substring with argument method.

	char* arg = arg_str;
	char* sub = sub_str;

	while (*sub != '\0') {

		//return length of the string after performing comparison with sub string and argument
		//update the char pointer by length+1 positions
		sub += compare_string_with_substr(arg, sub)+1 ;
	}
}

int main_3_58() {

	char sub_str[] = { 'a','b','a', ' ','\0' };
	char argument[] = { 'a','b','a','l','o','n','e', '\0' };

	char sub_str2[] = { 'l','o','n', 'e', ' ','\0' };
	char argument2[] = { 'a','b','a','l','o','n','e', '\0' };

	char sub_str3[] = { 'l','o', 'e', ' ','\0' };
	char argument3[] = { 'a','b','a','l','o','n','e','\0' };

	char sub_str4[] = { 'o', 'e', ' ','\0' };
	char argument4[] = { 'a','b','a','l','o','n','e','\0' };


	char sub_str5[] = { 'z', 'e', ' ','\0' };
	char argument5[] = { 'a','b','a','l','o','n','e','\0' };


	char sub_str6[] = { 'a','b','a', ' ','z', 'e', ' ','l','o','n', 'e', ' ' , 'o', 'e', ' ', 'h', 'o', 'r', 'n', ' ', 'b','e','a','t','l', 'e', ' ', '\0'};
	compare_string_with_substr(argument, sub_str);
	compare_string_with_substr(argument2, sub_str2);
	compare_string_with_substr(argument3, sub_str3);
	compare_string_with_substr(argument4, sub_str4);
	compare_string_with_substr(argument5, sub_str5);


	print_string_in_sub_str(argument5, sub_str6);

	return 0;
}