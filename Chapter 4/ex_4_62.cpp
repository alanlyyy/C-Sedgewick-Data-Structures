#include "random_queue_no_duplicates.h"
void test_462a() {
	int N = 30;

	//create stack with N elements
	random_queue_derived<int> q(15);

	q.put2(2);
	q.put2(2);
	q.put2(3);
	q.put2(4);
	q.print_elements();
	q.get_random();
	q.print_elements();
	q.put2(14);
	q.put2(4);
	q.put2(8);
	q.print_elements();
	q.get_random();
	q.print_elements();
	q.put2(14);
	q.print_elements();
}

void test_462b() {
	int N = 30;

	//create stack with N elements
	random_queue_derived_v2<int> q(15);

	q.put2(2);
	q.put2(2);
	q.put2(3);
	q.put2(4);
	q.print_elements();
	q.get_random();
	q.print_elements();
	q.put2(14);
	q.put2(4);
	q.put2(8);
	q.print_elements();
	q.get_random();
	q.print_elements();
	q.put2(14);
	q.print_elements();
}

int main4_62() {
	test_462a();
	test_462b();
	return 0;
}