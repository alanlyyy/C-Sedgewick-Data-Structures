#include "queue_array_no_duplicates.h"

void test_458a() {
	int N = 30;

	//create stack with N elements
	Queue_no_duplicates_derived<int> q(15);

	q.put2(2);
	q.put2(2);
	q.put2(3);
	q.put2(4);
	q.print_elements();
	q.get();
	q.print_elements();
	q.put2(14);
	q.put2(4);
	q.put2(8);
	q.print_elements();
	q.get();
	q.print_elements();
	q.put2(14);
	q.print_elements();
}

void test_458b() {
	int N = 30;

	//create stack with N elements
	Queue_no_duplicates_derived_v2<int> q(15);

	q.put2(2);
	q.put2(2);
	q.put2(3);
	q.put2(4);
	q.print_elements();
	q.get();
	q.print_elements();
	q.put2(14);
	q.put2(4);
	q.put2(8);
	q.print_elements();
	q.get();
	q.print_elements();
	q.put2(14);
	q.print_elements();
}

int main_458() {
	test_458a();
	test_458b();
	return 0;
}