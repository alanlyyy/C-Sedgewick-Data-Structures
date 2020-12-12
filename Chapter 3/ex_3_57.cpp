#include <iostream>
#include "list.h"

char* strcpy(char* word) {
	//return a copy of the word

	char* traverse = word;

	int length = 0;

	while (*traverse != '\0') {
		length += 1;
		traverse += 1;
	}

	//create a char array to store a copy of new word
	char* new_word = new char[length+1];

	//reset the pointer
	traverse = word;

	for (int i = 0; i < length+1; i++) {

		//append char to new_word char array
		new_word[i] = *traverse;

		//move to next node
		traverse += 1;
	}

	return new_word;

}

char* strcat(char* word1, char* word2) {
	//returns a copy of string, with appends of word2 after word1
	
	char* traverse1 = word1;
	char* traverse2 = word2;

	int length1 = 0;
	int length2 = 0;

	while (*traverse1 != '\0') {
		length1 += 1;
		traverse1 += 1;
	}

	while (*traverse2 != '\0') {
		length2 += 1;
		traverse2 += 1;
	}

	char* cat_word = new char[length1+length2 + 1];

	traverse1 = word1;
	traverse2 = word2;

	for (int i = 0; i < length1; i++) {
		cat_word[i] = *word1;
		word1 += 1;
	}

	for (int i = length1; i < length1+length1+1; i++) {
		cat_word[i] = *word2;
		word2 += 1;
	}

	return cat_word;

}

int main_3_57() {

	char mystring[] = "alphabet\0";
	char mystring2[] = "tiger\0";
	char mystring3[] = "mom\0";
	
	char* new_word = strcpy(mystring);
	std::cout << &mystring << " " << mystring << std::endl;
	std::cout << &new_word << " " << new_word <<std::endl;

	char* cat_word = strcat(mystring2, mystring3);
	std::cout << cat_word << std::endl;

	char* cat_word2 = strcat(cat_word, mystring);
	std::cout << cat_word2 << std::endl;
	

	return 0;
}

