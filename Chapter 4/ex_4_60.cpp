#include "QUEUE_with_no_duplicates_doubly_template.h"

int main_4_60() {
	Queue_doubly_ll q(15);

	q.put(3);
	q.put(7);
	q.printNodes();
	q.printNodes_through_array();
	q.put(9);
	q.put(4);
	q.put(14);
	q.put(5);
	q.printNodes();
	q.printNodes_through_array();
	q.get();
	q.printNodes();
	q.printNodes_through_array();
	q.get();
	q.put(3);
	q.put(11);
	return 0;
}