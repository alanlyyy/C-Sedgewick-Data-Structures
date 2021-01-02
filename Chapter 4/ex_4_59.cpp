#include "Queue_linked_list_no_duplicates.h"

//put2 method was accidentally made into recursive argument, instead of overloading original put method.
//changing derived classes function put to put2 fixed the problem.

void test_459a() {
	int N = 30;

	//create stack with N elements
	Queue_ll_derived<int> q(1);

	q.put2(2);
	q.put2(2);
	q.put2(3);
	q.put2(4);
	q.print_nodes();
	q.get();
	q.print_nodes();
	q.put2(14);
	q.put2(4);
	q.put2(8);
	q.print_nodes();
	q.get();
	q.print_nodes();
	q.put2(14);
	q.print_nodes();
}

void test_459b() {
	int N = 30;

	//create stack with N elements
	Queue_ll_derived_v2<int> q(1);

	q.put2(2);
	q.put2(2);
	q.put2(3);
	q.put2(4);
	q.print_nodes();
	q.get();
	q.print_nodes();
	q.put2(14);
	q.put2(4);
	q.put2(8);
	q.print_nodes();
	q.get();
	q.print_nodes();
	q.put2(14);
	q.print_nodes();
}

int main_459() {
	test_459a();
	test_459b();
	return 0;
}