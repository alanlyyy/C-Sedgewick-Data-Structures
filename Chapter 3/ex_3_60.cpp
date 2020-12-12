#include <iostream>

bool is_string_equal_substr(char* arg_str, char* list_sub_str) {
	//take a argument string and sub string and check if substring is equal to argument string

	//pointer to first letter of sub string
	char* l1 = list_sub_str;

	//pointer to first letter of argument string
	char* l2 = arg_str;


	//keep track of length of argument string
	int length = 0;

	//keep track of string position, used to compare with argument string.
	int str_pos = 0;

	//get the leangth of the string from start position to first white space
	while (*l2 != '\0') {
		length++;
		l2++;
	}

	l2 = arg_str;

	//loop until end of arg_str and l1 != space
	while (*l2 != '\0' && *l1 != ' ') {

		//if l1 and l2 are equal
		if (*l1 == *l2) {

			//update to next letter of l1 
			l1++;

			str_pos += 1;
		}
		//if letter is not equal, break out of loop
		else {

			str_pos = 0;

			break;
		}

		//update l2
		l2++;
	}
	
	if (length == str_pos) {
		return true;
	}
	else {
		return false;
	}
}

void string_search(char* text_string, char* word) {
	//in a text_string, print the indexes of occurences if the argument word is equal to sub_string word.

	char* s_pointer = text_string;
	char* word_pointer = word;

	int index = 0;

	//loop until end of char array
	while (*text_string != '\0')
	{
		//if sub string word == argument word, and previous char is an empty space (indicating new word), print the index of occurence
		if (is_string_equal_substr(word, text_string) && *(text_string-1) == ' ') {
			std::cout << "current_index: " << index << std::endl;
		}

		//find the next first letter for the next substring
		index++;

		//move on to next letter in text_string
		text_string ++;
	}


}

int main3_60() {
	char mystring[] = { "Alphabet soup baba orange soup madonna kissed me soup soup so up s oup\0" }; // 9 , 26, 49, 54
	char myword[] = { "soup\0" };

	char mystring2[] = { "Alpcathabet soup cat ora c a t c at madonna kissed me soupcat\0" }; //17
	char myword2[] = { "cat\0" };

	string_search(mystring, myword);
	std::cout << "==================" << std::endl;
	string_search(mystring2, myword2);

	return 0;
}