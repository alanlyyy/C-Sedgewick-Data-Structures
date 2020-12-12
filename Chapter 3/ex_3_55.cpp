#include <iostream>

void char_occurence(char* word) {
	//print table of letters and occurrences.
	//assume all letters are lower case.

	char * letter_traverse = word;

	//store letter
	char* letter = new char[26]();

	//store number of times letter occured, array of 26, default initialize counts to 0
	int* occurence = new int[26]();


	//get seen letters and corresponding occurences
	while (*letter_traverse != '\0') {

		int index = (int(*letter_traverse) - 97);

		//has letter occured?
		if (occurence[index] == 0) {
			letter[index] = *letter_traverse;
			occurence[index] = 1;
		}
		else {
			occurence[index] += 1;
		}

		//update pointer to next letter
		letter_traverse += 1;
	}

	//print letter and occurence
	for (int i = 0; i < 26; i++) {

		if (occurence[i] != 0) {
			std::cout << letter[i] << ": " << occurence[i] << std::endl;
		}
	}
}

int main_3_55() {

	char mystring[] = "alphabet\0";
	char mystring2[] = "encyclopedia\0";
	char mystring3[] = "elephante\0";

	char_occurence(mystring);
	std::cout << std::endl;
	char_occurence(mystring2);
	std::cout << std::endl;
	char_occurence(mystring3);

	return 0;
}