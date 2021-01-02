#include <iostream>

struct node {
	char item = ' ';
	node* next = 0;
	node* prev = 0;

	node(char letter, node* prev_node,node* next_node) {
		item = letter;
		next = next_node;
		prev = prev_node;

	}
};
void check_pop_order(char* input_seq, char* resultant_seq, int size) {

	bool last_letter = false;

	//add elements to output arr of length size
	int index = 0;
	char* output_arr = new char[size + 1];

	//create a circular linked list to store input sequence.
	node* head_node = new node(input_seq[0], 0, 0);
	node* t = head_node;
	node* last_node;

	for (char val = 1; val < size; val++) {
		t = t->next = new node(input_seq[val], t, 0);
	}

	//last node pointer, contains last letter
	last_node = t;
	head_node->prev = last_node;
	last_node->next = head_node;

	//input char circles back to first character
	t = head_node;

	for (int i = 0; i < size; i++) {

		//if current char is last letter, create a flag for last letter is found
		if (resultant_seq[i] == (input_seq[size - 1])) {
			last_letter = true;
		}

		while (t != last_node) {

			if ((t->item == resultant_seq[i]) && (last_letter == true)) {

				//insert asterisk as new last node, circles back to first node
				last_node = last_node->next = new node('*', last_node, last_node->next);
				//std::cout << t->item << std::endl;
				break;
			}

			else if ((t->item == resultant_seq[i]) && (last_letter == false)) {
				//std::cout << t->item << std::endl;
				//insert asterisk into position t
				t = t->next = new node('*', t, t->next);
				break;
			}
			else {
				//traverse to next node
				t = t->next;
			}
		}
		//if we break out of the loop and t is a last node, t is also a char in resultant_seq, create asterisk node
		if ((t == last_node) && (t->item == resultant_seq[i])) {
			//std::cout << t->item << std::endl;
			//insert asterisk into position t
			t = t->next = new node('*', t, t->next);
			last_node = t;
		}

		//reset t to first node
		t = head_node;
	}

	while (index < 4) {

		while (t != last_node) {

			if (t->next->item == '*') {
				node* temp = t->next;

				output_arr[index] = t->item;

				index += 1;

				//t is now previous node
				t = t->prev;

				//t now points to asterisk
				t->next = temp;

				//asterisk points back to prev
				temp->prev = t;

				if (index == 4) {
					break;
				}
			}

			//t is now next node, and asterisk if asteerisk node is reached
			t = t->next;

			if (t->item == '*') {
				node* temp = t->next;

				//t is now previous node
				t = t->prev;

				//t now points to node after asterisk
				t->next = temp;

				//node after asterisk points back to previous node
				temp->prev = t;
			}

		}
		//reset t to first node 
		t = head_node;

	}
	output_arr[size] = '\t';

	//print nodes-------------------------------------
	std::cout << output_arr << std::endl;
	//std::cout << t->item << std::endl;
	//t = t->next;

	//while (t != head_node) {
	//	std::cout << t->item << std::endl;
	//	t = t->next;
	//}

	//t = last_node;

	//std::cout << "------------------" << std::endl;


	//while (t != head_node) {
	//	std::cout << t->item << std::endl;
	//	t = t->prev;
	//}

	//std::cout << t->item << std::endl;
}

void check_pop_order_2(char* input_seq, char* resultant_seq, int size) {

	bool last_letter = false;

	//add elements to output arr of length size
	int index = 0;
	int num_letters_before_current_result = 0;
	char* output_arr = new char[size+1];

	//create a circular linked list to store input sequence.
	node* head_node = new node(input_seq[0],0,0);
	node* t = head_node;
	node* last_node;

	for (char val = 1; val < size; val++) {
		t = t->next = new node(input_seq[val],t,0);
	}

	//last node pointer, contains last letter
	last_node = t;
	head_node->prev = last_node;
	last_node->next = head_node;

	//input char circles back to first character
	t = head_node;

	for (int i = 0; i < size; i++) {

		if (t->item == resultant_seq[i]) {
			t = t->next = new node('*', t, t->next);
		}

		else {

			//move to next item thats not resultant item
			while (t->item != resultant_seq[i]) {
				if (t->item != '*') {
					num_letters_before_current_result += 1;
				}

				t = t->next;
			}

			//std::cout << t->item << std::endl;
			//insert asterisk into position t
			int num_asterisks = 0;

			while (num_asterisks < num_letters_before_current_result) {
				t = t->next = new node('*', t, t->next); 
					num_asterisks += 1;
			}
			
			
		}

		num_letters_before_current_result = 0;
		//reset t to first node
		t = head_node;
	}

	while (index < 4) {

		while (t != last_node) {

			if (t->next->item == '*') {
				node* temp = t->next;

				output_arr[index] = t->item;

				index += 1;

				//t is now previous node
				t = t->prev;

				//t now points to asterisk
				t->next = temp;

				//asterisk points back to prev
				temp->prev = t;

				if (index == 4) {
					break;
				}
			}

			//t is now next node, and asterisk if asteerisk node is reached
			t = t->next;

			if (t->item == '*') {
				node* temp = t->next;

				//t is now previous node
				t = t->prev;

				//t now points to node after asterisk
				t->next = temp;

				//node after asterisk points back to previous node
				temp->prev = t;
			}

		}
		//reset t to first node 
		t = head_node;

	}
	output_arr[size] = '\t';

	//print nodes-------------------------------------
	std::cout << output_arr << std::endl;
	//std::cout << t->item << std::endl;
	//t = t->next;
	
	//while (t != head_node) {
	//	std::cout << t->item << std::endl;
	//	t = t->next;
	//}

	//t = last_node;

	//std::cout << "------------------" << std::endl;


	//while (t != head_node) {
	//	std::cout << t->item << std::endl;
	//	t = t->prev;
	//}

	//std::cout << t->item << std::endl;
}

int main_ex_411() {

	char seq1[] = { "EASY" };
	char seq2[] = { "AYES" };
	char seq3[] = { "YSAE" };
	char seq4[] = { "SAEY" };

	//check_pop_order(seq1, seq2,4);
	//check_pop_order(seq1, seq3, 4);
	check_pop_order(seq1, seq4, 4);

	return 0;
}