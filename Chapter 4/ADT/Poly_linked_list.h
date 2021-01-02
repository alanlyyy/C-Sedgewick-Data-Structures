#pragma once
#include <iostream>

template <class Number>
class Poly_linked_list {

private:

	struct node {

		Number item; 
		node* next;
		node* prev;

		node(Number x,node* p, node* n) {
			item = x; prev = p, next = n;
		}
	};

	typedef node* link;
	link head; //prev_head = null
	link tail; //tail_next =null
	int n;
	int M = 0;

	void clear_list() {
		//clear content/ deallocate resources from s
			for (link t = head; t != 0; head = t) {
				t = head->next;
				delete head;
			}

		//std::cout << "Destructor invoked!" << std::endl;
	}

public:

	Poly_linked_list<Number>(Number c, int N, int exclude=0) {
		
		n = N+1;//user intiailizes polynomial class to ignore polynomials greater than order M

		//initialize head with first node
		head = new node(0, 0, 0);
		
		node* t = head;

		//append new nodes after head up to N nodes
		for (int i = 1; i < n; i++) {
			t = t->next = new node(0, t, 0);
		}

		//c = last node
		t->item = c;

		//update tail node
		tail = t;

		M = exclude;


	}

	Poly_linked_list<Number>(const Poly_linked_list& other) {
		//copy constructor

		n = other.n;

		M = other.M;

		node* other_head = other.head;

		head = new node(other_head->item, 0, 0);

		node* t = head;

		other_head = other_head->next;

		for (int i = 1; i < n; i++) {

			//create a new node with the item, new node prev points to t, t next points to new node, t = new node
			t = t->next = new node(other_head->item, t, 0);
			other_head = other_head->next;
		}
		
		//tail points to last node
		tail = t;

	}

	Poly_linked_list& operator=(const Poly_linked_list& other) {

		n = other.n;

		M = other.M;

		if (this == &other) {
			return *this;
		}

		node* other_head = other.head;

		head = new node(other_head->item, 0, 0);

		node* t = head;

		other_head = other_head->next;

		for (int i = 1; i < n; i++) {

			//create a new node with the item, new node prev points to t, t next points to new node, t = new node
			t = t->next = new node(other_head->item, t, 0);
			other_head = other_head->next;
		}

		//tail points to last node
		tail = t;

		return *this;
	}

	~Poly_linked_list<Number>() {
		//destructor

		clear_list();
	}

	const float eval(float x) {
		double t = 0.0;

		node* traverse = tail;

		//evaluate expression starting at x^0
		for (int i = n-1; i >= 0; i--) {
			t = t * x + traverse->item;
			traverse = traverse->prev;
		}

		return t;
	}

	void integrate() {

		//create a new node add to the head
		node* new_node = new node(0, 0,head);
		head->prev = new_node;
		head = new_node;
		n += 1;

		node* t = head;
		
		for (int i = 0; i < n-M; i++) {

			if (t->item != 0) {
				t->item = (t->item / (i));
			}

			t = t->next;
		}
	}

	void derive() {

		//create a new node add to the tail, highest power of polynomial
		node* new_node = new node(0, tail, 0);
		tail->next = new_node;
		tail = new_node;
		n += 1;

		//remove the constant value computing the derivate
		node* head_next = head->next;
		delete head;
		head = head_next;

		n -= 1;

		node* t = head;


		for (int i = 0; i < n-M; i++) {

			if (t->item != 0) {
				t->item = (t->item * (i+1));
			}

			t = t->next;
		}
	}

	friend Poly_linked_list operator+(Poly_linked_list& p, Poly_linked_list& q)
	{
		//choose the higher polynomial
		Poly_linked_list t(0, (p.n > q.n ? p.n - 1: q.n - 1));
		node* traverse_output = t.head;
		node* p_output = p.head;
		node* q_output = q.head;

		for (int i = 0; i < p.n; i++) {
			traverse_output->item += p_output->item;
			traverse_output = traverse_output->next;
			p_output = p_output->next;
		}

		traverse_output = t.head;

		for (int j = 0; j < q.n; j++) {
			traverse_output->item += q_output->item;
			traverse_output = traverse_output->next;
			q_output = q_output->next;
		}

		return t;
	}

	friend Poly_linked_list operator*(Poly_linked_list& p, Poly_linked_list& q)
	{
		//choose the hire polynomial
		Poly_linked_list t(0, (p.n-1) + (q.n-1));
		node* traverse_output = t.head;
		node* p_output = p.head;
		node* q_output = q.head;

		for (int i = 0; i < p.n; i++) {

			//iterate traverse pointer i times to account for the offset of i index.
			for (int k = 0; k < i; k++) {
				traverse_output = traverse_output->next;
			}

			for (int j = 0; j < q.n; j++) {
				
				traverse_output->item += (q_output->item) * (p_output->item);
				
				traverse_output = traverse_output->next;
				q_output = q_output->next;
			}

			//reset q output
			q_output = q.head;

			p_output = p_output->next;

			//reset traversal pointer
			traverse_output = t.head;

		}

		return t;
	}

	friend Poly_linked_list operator/(Poly_linked_list& p, Poly_linked_list& q)
	{
		//Compute long division with larger polynomial/smaller polynomial.
		//the division is treated as a window, where we iterate the larger polynomial (numerator)
		//up until we reach the order of the highest order found in the denominator

		//choose the larger polynomial
		int size = 0;
		bool p_flag = false;
		bool q_flag = false;
		if (p.n > q.n) {
			size = p.n;
			p_flag = true;
		}
		else {
			size = q.n;
			q_flag = true;
		}

		Poly_linked_list t(0, size-1);

		//store resulting polynomial after division 
		node* traverse_output = t.tail;

		//will store the remainder after computing divisions
		node* p_output = p.tail;
		node* q_output = q.tail;


		if (p_flag == true) {

			//loop polynomials up to before the constant value -->  x^0 
			for (int i = p.n; i >= q.n; i--) {

				//iterate traverse pointer i times to account for the offset of i index.
				for (int k = p.n; k > i; k--) {
					p_output = p_output->prev;
				}

				//smaller polynomial or divisor
				for (int j = q.n; j > 0; j--) {

					//if at highest order in smaller polynomial
					if (j == q.n) {

						//compute dvision between larger polynomial and smaller polynomial, save coefficient
						traverse_output->item += (p_output->item) / (q_output->item);

						//overwrite current value of larger polynomial subtracting coefficient
						p_output->item -= traverse_output->item;

					}
					else {
						//multiply coefficient with smaller polynomial, subtract from larger polynomial.
						p_output->item -= (traverse_output->item * q_output->item);

					}
					
					p_output = p_output->prev;


					//traverse to next small polynomial node
					q_output = q_output->prev;
				}

				//reset p_output to highest polynomial node
				p_output = p.tail;

				//traverse to next result node
				traverse_output = traverse_output->prev;

				//reset q output
				q_output = q.tail;

			}

		//print out polynomial division result
		t.print_coefficients();

		//print out remainder
		p.print_coefficients();
	}
		else {

			//loop polynomials up to before the constant value
			for (int i = q.n ; i >= q.n; i--) {

				//iterate traverse pointer i times to account for the offset of i index.
				for (int k = q.n ; k > i; k--) {
					q_output = q_output->prev;
				}

				//smaller polynomial or divisor
				for (int j = p.n; j > 0; j--) {

					//if highest order in the polynomial
					if (j == p.n) {

						//compute dvision between larger polynomial and smaller polynomial
						traverse_output->item += (q_output->item) / (p_output->item);

						//overwrite current value of larger polynomial
						q_output->item -= traverse_output->item;

					}
					else {
						q_output->item -= (traverse_output->item * p_output->item);

					}

					p_output = p_output->prev;

					//traverse to next small polynomial node
					q_output = q_output->prev;
				}

				//reset p_output to highest polynomial node
				p_output = p.tail;

				//traverse to next result node
				traverse_output = traverse_output->prev;

				//reset q output
				q_output = q.tail;
			}

			//print out polynomial division result
			t.print_coefficients();

			//print out remainder
			q.print_coefficients();
		}

		return t;
	}

	float composition(Poly_linked_list &function_g, float val) {
		//pass val into function g, pass the returned value into function f  --> f(g(val))
		return eval(function_g.eval(val));
	}

	Poly_linked_list& operator+=(const Poly_linked_list& other) {

		//if other list is larger than current list
		//append new nodes to front of list
		if (other.n > n) {

			int num_nodes = other.n - n;
			
			for (int z = 0; z < num_nodes; z++) {
				//create new node that points to tail (coefficients start at the tail)
				node* new_node = new node(0, tail, 0);
				tail->next = new_node;
				tail = new_node;
				n += 1;
			}
		}

		node* other_head = other.head;
		node* traverse_output = head;

		for (int i = 0; i < other.n; i++) {

			//add item to this
			traverse_output->item += other_head->item;

			//move onto next node for this
			traverse_output = traverse_output->next;

			//move onto next node for other
			other_head = other_head->next;
		}

		return *this;
	}

	Poly_linked_list& operator*=(const Poly_linked_list& other) {


		Poly_linked_list t(0, other.n +n -1);
		node* traverse_output = t.head;
		node* p_output = head;
		node* q_output = other.head;

		for (int i = 0; i < n; i++) {

			//iterate traverse pointer i times to account for the offset of i index.
			for (int k = 0; k < i; k++) {
				traverse_output = traverse_output->next;
			}

			for (int j = 0; j < other.n; j++) {

				traverse_output->item += (q_output->item) * (p_output->item);

				traverse_output = traverse_output->next;
				q_output = q_output->next;
			}

			//reset q output
			q_output = other.head;

			p_output = p_output->next;

			//reset traversal pointer
			traverse_output = t.head;

		}

		traverse_output = t.head;

		//add new nodes to end of list

		node* current_node = head;
		for (int i = 0; i < t.n-1; i++) {

			if (current_node == 0) {
				//create new node at tail (coefficients start at the tail)
				node* new_node = new node(traverse_output->item, tail, 0);
				tail->next = new_node;
				tail = new_node;
				n += 1;
				current_node = new_node->next;
			}
			else {
				//copy values
				current_node->item = traverse_output->item;
				//traverse to next node
				current_node = current_node->next;
			}

			traverse_output = traverse_output->next;
		}


		return *this;
	}

	void print_coefficients() {
		node* tra = head;

		int size = n - M;
		int i = 0;

		while (tra != tail) {

			if (i == size) {
				break;
			}

			std::cout << tra->item << " ";
			tra = tra->next;
			i++;
		}

		//print last element in list
		std::cout << tra->item;

		std::cout << std::endl;
	}
};
