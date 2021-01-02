#pragma once
#include <iostream>


class String {

private:

	struct node {

		char item;
		node* next;
		node* prev;

		node(char x, node* p, node* n) {
			item = x; prev = p, next = n;
		}
	};

	typedef node* link;
	link head; //prev_head = null
	link tail; //tail_next =null
	int size;

	void clear_list() {
		//clear content/ deallocate resources from s
		for (link t = head; t != 0; head = t) {
			t = head->next;
			delete head;
		}
		//std::cout << "Destructor invoked!" << std::endl;
	}

public:
	String(int) {
		head = 0;
		tail = head;
		size = 0;
	}

	String(const String& other) {
		//copy constructor

		size = other.size;

		//delete all elements from current string
		clear_list();

		node* other_t = other.head;

		node* t = head;

		while (other_t != 0) {

			insert_char(other_t->item);

			other_t = other_t->next;
		}
	}
	
	~String() {
		//destructor
		clear_list();
	}

	String& operator=(const String& other) {
		//copy constructor

		size = other.size;

		if (this == &other) {
			return *this;
		}

		//delete all elements from current string
		clear_list();

		node* other_t = other.head;

		node* t = head;

		while (other_t != 0) {

			t = t->next = new node(other_t->item, t, 0);

			if (other_t->next == 0) {
				tail = t;
			}

			other_t = other_t->next;
		}
	}

	String& operator+=(const String& other) {
		//concatenate new string to end of current string

		size += other.size;


		node* other_t = other.head;

		node* t = tail;

		while (other_t != 0) {

			t = t->next = new node(other_t->item, t, 0);

			if (other_t->next == 0) {
				tail = t;
			}

			other_t = other_t->next;
		}

		return *this;
	}

	bool operator==(const String& other) {
		//compare 2 strings

		if (size != other.size) {
			return false;
		}

		node* other_t = other.head;

		node* t = head;

		while (other_t != 0) {

			if (t->item == other_t->item) {
				other_t = other_t->next;
				t = t->next;
			}
			else {
				return false;
			}

		}

		return true;
	}

	void insert_entire_string(char*first_letter, int size_of_string){
		//inserts entire char[] or string into String_mod object

		for (int i = 0; i < size_of_string; i++) {
			insert_char(*(first_letter+i));
		}
	}

	void insert_char(char var) {
		
		node* tempNode = new node(var, 0, 0);

		if (head == 0) {
			head = tempNode;
			tail = tempNode;
		}
		else {
			tail->next = tempNode;
			tempNode->prev = tail;
			tail = tempNode;
		}

		size++;
	}

	void delete_char(int position) {

		node* t = head;
		
		for (int i = 0; i < position; i++) {
			t = t->next;
		}

		node* previous_node = t->prev;
		node* next_node = t->next;

		previous_node->next = next_node;
		next_node->prev = previous_node;

		//deleter the node in current position
		delete t;

		size--;
	}

	int get_string_size() {
		return size;
	}

	void print_string() {

		node* tra = head;

		while (tra != tail) {

			std::cout << tra->item << " ";
			tra = tra->next;
		}

		//print last element in list
		std::cout << tra->item;

		std::cout << std::endl;
	}
	
};